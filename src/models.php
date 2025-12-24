<?php
require_once 'database.php';

// Model functions for tenants
function getAllTenants() {
    global $pdo;
    $stmt = $pdo->query("SELECT * FROM tenants ORDER BY last_name");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getTenantById($id) {
    global $pdo;
    $stmt = $pdo->prepare("SELECT * FROM tenants WHERE tenant_id = ?");
    $stmt->execute([$id]);
    return $stmt->fetch(PDO::FETCH_ASSOC);
}

function addTenant($last_name) {
    global $pdo;
    $stmt = $pdo->prepare("INSERT INTO tenants (last_name) VALUES (?)");
    return $stmt->execute([$last_name]);
}

function deleteTenant($id) {
    global $pdo;
    $stmt = $pdo->prepare("DELETE FROM tenants WHERE tenant_id = ?");
    return $stmt->execute([$id]);
}

// Model functions for properties
function getAllProperties() {
    global $pdo;
    $stmt = $pdo->query("SELECT * FROM properties ORDER BY type");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getPropertyById($id) {
    global $pdo;
    $stmt = $pdo->prepare("SELECT * FROM properties WHERE property_id = ?");
    $stmt->execute([$id]);
    return $stmt->fetch(PDO::FETCH_ASSOC);
}

function addProperty($type, $monthly_rent) {
    global $pdo;
    $stmt = $pdo->prepare("INSERT INTO properties (type, monthly_rent) VALUES (?, ?)");
    return $stmt->execute([$type, $monthly_rent]);
}

function deleteProperty($id) {
    global $pdo;
    $stmt = $pdo->prepare("DELETE FROM properties WHERE property_id = ?");
    return $stmt->execute([$id]);
}

// Model functions for leases
function getAllLeases() {
    global $pdo;
    $stmt = $pdo->query("SELECT l.*, t.last_name, p.type as property_type FROM leases l 
                         JOIN tenants t ON l.tenant_id = t.tenant_id 
                         JOIN properties p ON l.property_id = p.property_id 
                         ORDER BY l.start_date");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getLeaseById($id) {
    global $pdo;
    $stmt = $pdo->prepare("SELECT * FROM leases WHERE lease_id = ?");
    $stmt->execute([$id]);
    return $stmt->fetch(PDO::FETCH_ASSOC);
}

function addLease($tenant_id, $property_id, $start_date, $duration_months) {
    global $pdo;
    $stmt = $pdo->prepare("INSERT INTO leases (tenant_id, property_id, start_date, duration_months) VALUES (?, ?, ?, ?)");
    return $stmt->execute([$tenant_id, $property_id, $start_date, $duration_months]);
}

function deleteLease($id) {
    global $pdo;
    $stmt = $pdo->prepare("DELETE FROM leases WHERE lease_id = ?");
    return $stmt->execute([$id]);
}

// Report functions
function getPropertiesByType($type, $order = 'asc') {
    global $pdo;
    $order_sql = $order === 'desc' ? 'ORDER BY p.type DESC' : 'ORDER BY p.monthly_rent ASC';
    $stmt = $pdo->prepare("SELECT * FROM properties p WHERE p.type = ? $order_sql");
    $stmt->execute([$type]);
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getTenantsWithRentalCount() {
    global $pdo;
    $stmt = $pdo->query("SELECT t.tenant_id, t.last_name, COUNT(l.lease_id) as rental_count 
                         FROM tenants t 
                         LEFT JOIN leases l ON t.tenant_id = l.tenant_id 
                         GROUP BY t.tenant_id, t.last_name 
                         ORDER BY t.last_name");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getUnrentedProperties() {
    global $pdo;
    $stmt = $pdo->query("SELECT p.* FROM properties p 
                         LEFT JOIN leases l ON p.property_id = l.property_id 
                         WHERE l.property_id IS NULL");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getPropertiesRentedMoreThan3Times() {
    global $pdo;
    $stmt = $pdo->query("SELECT p.*, COUNT(l.lease_id) as rental_count 
                         FROM properties p 
                         JOIN leases l ON p.property_id = l.property_id 
                         GROUP BY p.property_id 
                         HAVING COUNT(l.lease_id) > 3");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getPropertiesRentedMoreThan2TimesAndYear() {
    global $pdo;
    $stmt = $pdo->query("SELECT p.*, COUNT(l.lease_id) as rental_count 
                         FROM properties p 
                         JOIN leases l ON p.property_id = l.property_id 
                         WHERE l.duration_months > 12 
                         GROUP BY p.property_id 
                         HAVING COUNT(l.lease_id) > 2");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getPropertiesWithRentalStats() {
    global $pdo;
    $stmt = $pdo->query("SELECT p.*, COUNT(l.lease_id) as rental_count, 
                         SUM(p.monthly_rent * l.duration_months) as total_rent 
                         FROM properties p 
                         LEFT JOIN leases l ON p.property_id = l.property_id 
                         GROUP BY p.property_id");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getTenantsWithRentalStats() {
    global $pdo;
    $stmt = $pdo->query("SELECT t.*, COUNT(l.lease_id) as rental_count, 
                         AVG(l.duration_months) as avg_duration 
                         FROM tenants t 
                         LEFT JOIN leases l ON t.tenant_id = l.tenant_id 
                         GROUP BY t.tenant_id");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getPropertiesForQuarter($year, $quarter) {
    global $pdo;
    $start_month = ($quarter - 1) * 3 + 1;
    $end_month = $quarter * 3;
    
    $stmt = $pdo->prepare("SELECT p.*, l.start_date, COUNT(l.lease_id) as rental_count 
                           FROM properties p 
                           JOIN leases l ON p.property_id = l.property_id 
                           WHERE YEAR(l.start_date) = ? AND MONTH(l.start_date) BETWEEN ? AND ? 
                           ORDER BY l.start_date");
    $stmt->execute([$year, $start_month, $end_month]);
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getTenantsWithPropertyCount() {
    global $pdo;
    $stmt = $pdo->query("SELECT t.*, COUNT(DISTINCT l.property_id) as different_properties_count 
                         FROM tenants t 
                         LEFT JOIN leases l ON t.tenant_id = l.tenant_id 
                         GROUP BY t.tenant_id");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function updatePropertyRentByType($type, $increase_percent) {
    global $pdo;
    $stmt = $pdo->prepare("UPDATE properties SET monthly_rent = monthly_rent * (1 + ? / 100) WHERE type = ?");
    return $stmt->execute([$increase_percent, $type]);
}
?>