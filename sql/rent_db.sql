-- Database: rent
CREATE DATABASE IF NOT EXISTS rent DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE rent;

-- Table structure for table tenants
CREATE TABLE tenants (
    tenant_id INT AUTO_INCREMENT PRIMARY KEY,
    last_name VARCHAR(100) NOT NULL
);

-- Table structure for table properties
CREATE TABLE properties (
    property_id INT AUTO_INCREMENT PRIMARY KEY,
    type VARCHAR(100) NOT NULL,
    monthly_rent DECIMAL(10, 2) NOT NULL
);

-- Table structure for table leases
CREATE TABLE leases (
    lease_id INT AUTO_INCREMENT PRIMARY KEY,
    tenant_id INT NOT NULL,
    property_id INT NOT NULL,
    start_date DATE NOT NULL,
    duration_months INT NOT NULL,
    FOREIGN KEY (tenant_id) REFERENCES tenants(tenant_id),
    FOREIGN KEY (property_id) REFERENCES properties(property_id)
);

-- Insert sample data for tenants
INSERT INTO tenants (last_name) VALUES 
('Иванов'),
('Петров'),
('Сидоров'),
('Козлов'),
('Морозов'),
('Волков'),
('Лебедев'),
('Смирнов'),
('Кузнецов'),
('Попов');

-- Insert sample data for properties
INSERT INTO properties (type, monthly_rent) VALUES 
('Квартира', 25000.00),
('Квартира', 30000.00),
('Квартира', 22000.00),
('Дом', 45000.00),
('Дом', 55000.00),
('Офис', 35000.00),
('Офис', 40000.00),
('Магазин', 50000.00),
('Магазин', 60000.00),
('Квартира', 28000.00),
('Дом', 70000.00),
('Офис', 42000.00);

-- Insert sample data for leases
INSERT INTO leases (tenant_id, property_id, start_date, duration_months) VALUES 
(1, 1, '2023-01-15', 6),
(2, 2, '2023-02-20', 12),
(3, 3, '2023-03-10', 8),
(4, 4, '2023-04-05', 18),
(5, 5, '2023-05-12', 24),
(6, 6, '2023-06-18', 10),
(7, 7, '2023-07-22', 15),
(8, 8, '2023-08-30', 9),
(9, 9, '2023-09-14', 20),
(10, 10, '2023-10-01', 7),
(1, 4, '2023-11-05', 12),
(2, 5, '2023-12-10', 14),
(3, 1, '2024-01-15', 6),
(4, 2, '2024-02-20', 10),
(5, 3, '2024-03-01', 8),
(6, 11, '2024-04-10', 22),
(7, 12, '2024-05-15', 16),
(8, 6, '2024-06-20', 11),
(9, 7, '2024-07-05', 13),
(10, 8, '2024-08-12', 17),
(1, 9, '2024-09-18', 9),
(2, 10, '2024-10-25', 14),
(3, 11, '2024-11-30', 18),
(4, 12, '2024-12-05', 12);