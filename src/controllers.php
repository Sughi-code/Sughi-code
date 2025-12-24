<?php
require_once 'models.php';

// Tenant controllers
function listTenants() {
    return getAllTenants();
}

function addTenantController($last_name) {
    if (!empty($last_name)) {
        return addTenant($last_name);
    }
    return false;
}

function deleteTenantController($id) {
    if (!empty($id)) {
        return deleteTenant($id);
    }
    return false;
}

// Property controllers
function listProperties() {
    return getAllProperties();
}

function addPropertyController($type, $monthly_rent) {
    if (!empty($type) && !empty($monthly_rent)) {
        return addProperty($type, $monthly_rent);
    }
    return false;
}

function deletePropertyController($id) {
    if (!empty($id)) {
        return deleteProperty($id);
    }
    return false;
}

// Lease controllers
function listLeases() {
    return getAllLeases();
}

function addLeaseController($tenant_id, $property_id, $start_date, $duration_months) {
    if (!empty($tenant_id) && !empty($property_id) && !empty($start_date) && !empty($duration_months)) {
        return addLease($tenant_id, $property_id, $start_date, $duration_months);
    }
    return false;
}

function deleteLeaseController($id) {
    if (!empty($id)) {
        return deleteLease($id);
    }
    return false;
}

// Report controllers
function getPropertiesByTypeController($type, $order = 'asc') {
    return getPropertiesByType($type, $order);
}

function getTenantsWithRentalCountController() {
    return getTenantsWithRentalCount();
}

function getUnrentedPropertiesController() {
    return getUnrentedProperties();
}

function getPropertiesRentedMoreThan3TimesController() {
    return getPropertiesRentedMoreThan3Times();
}

function getPropertiesRentedMoreThan2TimesAndYearController() {
    return getPropertiesRentedMoreThan2TimesAndYear();
}

function getPropertiesWithRentalStatsController() {
    return getPropertiesWithRentalStats();
}

function getTenantsWithRentalStatsController() {
    return getTenantsWithRentalStats();
}

function getPropertiesForQuarterController($year, $quarter) {
    return getPropertiesForQuarter($year, $quarter);
}

function getTenantsWithPropertyCountController() {
    return getTenantsWithPropertyCount();
}

function updatePropertyRentByTypeController($type, $increase_percent) {
    return updatePropertyRentByType($type, $increase_percent);
}
?>