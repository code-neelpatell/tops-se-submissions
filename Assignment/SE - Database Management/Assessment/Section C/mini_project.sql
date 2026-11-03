-- Delete database if exists
DROP DATABASE IF EXISTS foodapp_db_new;

-- Create database
CREATE DATABASE foodapp_db_new;

-- Select database to use
USE foodapp_db_new;

-- Create tables
CREATE TABLE restaurants (
	restaurant_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    city VARCHAR(30) NOT NULL,
    cuisine_type VARCHAR(20) NOT NULL,
    created_at DATE DEFAULT (CURRENT_DATE)
);

CREATE TABLE menu_items (
	item_id INT AUTO_INCREMENT PRIMARY KEY,
    restaurant_id INT NOT NULL,
    item_name VARCHAR(50) NOT NULL,
    price DECIMAL(7,2) NOT NULL,
    category VARCHAR(30) NOT NULL,
    -- Ensures price is non-negative
    CONSTRAINT chk_menu_items_price_non_negative
		CHECK (price >= 0),
	-- Creates foreign key relationship
    CONSTRAINT fk_menu_items_restaurant_id
		FOREIGN KEY (restaurant_id)
        REFERENCES restaurants(restaurant_id)
);

CREATE TABLE orders (
	order_id INT AUTO_INCREMENT PRIMARY KEY, 
    customer_name VARCHAR(50) NOT NULL, 
    restaurant_id INT NOT NULL, 
    item_id INT NOT NULL, 
    quantity INT NOT NULL,
	total_amount DECIMAL(10,2) NOT NULL, 
    order_date DATE DEFAULT (CURRENT_DATE),
    -- Ensures quantity is greater then zero
    CONSTRAINT chk_orders_quantity_gt_zero
		CHECK (quantity > 0),
	-- Ensures total_amount is non-negative
    CONSTRAINT chk_orders_total_amount_non_negative
		CHECK (total_amount >= 0),
	-- Creates foreign key relationships
    CONSTRAINT fk_orders_restaurant_id
		FOREIGN KEY (restaurant_id)
        REFERENCES restaurants(restaurant_id),
	CONSTRAINT fk_orders_item_id
		FOREIGN KEY (item_id)
        REFERENCES menu_items(item_id)
);

CREATE TABLE order_audit (
	audit_id INT AUTO_INCREMENT PRIMARY KEY, 
	order_id INT NOT NULL,
    restaurant_id INT NOT NULL,
    action ENUM('INSERT', 'UPDATE', 'DELETE') NOT NULL,
    log_time DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Insert data
INSERT INTO restaurants
    (restaurant_id, name, city, cuisine_type, created_at)
VALUES
    (1, 'The Spice Hub', 'Surat', 'Indian', '2025-01-10'),
    (2, 'Pizza Paradise', 'Mumbai', 'Italian', '2025-02-15'),
    (3, 'Dragon Bowl', 'Ahmedabad', 'Chinese', '2025-03-20');

INSERT INTO menu_items
    (item_id, restaurant_id, item_name, price, category)
VALUES
    -- The Spice Hub
    (1, 1, 'Paneer Butter Masala', 250.00, 'Main Course'),
    (2, 1, 'Veg Biryani', 200.00, 'Main Course'),
    (3, 1, 'Paneer Tikka', 180.00, 'Starter'),
    (4, 1, 'Gulab Jamun', 80.00, 'Dessert'),

    -- Pizza Paradise
    (5, 2, 'Margherita Pizza', 220.00, 'Main Course'),
    (6, 2, 'Farmhouse Pizza', 350.00, 'Main Course'),
    (7, 2, 'Garlic Bread', 120.00, 'Starter'),
    (8, 2, 'Cold Coffee', 100.00, 'Beverage'),

    -- Dragon Bowl
    (9, 3, 'Veg Hakka Noodles', 180.00, 'Main Course'),
    (10, 3, 'Manchurian', 150.00, 'Starter'),
    (11, 3, 'Chocolate Brownie', 100.00, 'Dessert'),
    (12, 3, 'Lemon Iced Tea', 90.00, 'Beverage');

INSERT INTO orders
    (customer_name, restaurant_id, item_id,
     quantity, total_amount, order_date)
VALUES
    -- The Spice Hub
    ('Aarav', 1, 1, 2, 500.00, '2026-09-05'),
    ('Priya', 1, 2, 1, 200.00, '2026-09-08'),
    ('Rahul', 1, 3, 2, 360.00, '2026-09-12'),
    ('Sneha', 1, 4, 3, 240.00, '2026-09-18'),
    ('Karan', 1, 1, 1, 250.00, '2026-09-25'),

    -- Pizza Paradise
    ('Neha', 2, 5, 2, 440.00, '2026-10-02'),
    ('Rohan', 2, 6, 1, 350.00, '2026-10-07'),
    ('Ananya', 2, 7, 2, 240.00, '2026-10-12'),
    ('Vikram', 2, 8, 3, 300.00, '2026-10-18'),
    ('Isha', 2, 5, 1, 220.00, '2026-10-25'),

    -- Dragon Bowl
    ('Arjun', 3, 9, 2, 360.00, '2026-10-28'),
    ('Meera', 3, 10, 1, 150.00, '2026-10-30'),
    ('Dev', 3, 11, 2, 200.00, '2026-10-31'),
    ('Kavya', 3, 12, 2, 180.00, '2026-11-01'),
    ('Aditya', 3, 9, 1, 180.00, '2026-11-02');

-- Create view for restaurant sales summary
CREATE VIEW restaurant_sales_summary AS
	SELECT r.name, COUNT(o.order_id) AS no_of_orders, SUM(o.total_amount) AS revenue
		FROM orders o JOIN restaurants r
		ON r.restaurant_id = o.restaurant_id
        GROUP BY r.restaurant_id, r.name;

-- Create procedure to add orders
DELIMITER $$

CREATE PROCEDURE add_order(IN p_customer_name VARCHAR(50), IN p_restaurant_id INT, IN p_item_id INT, IN p_quantity INT)
BEGIN 
    DECLARE l_total_amount DECIMAL(10, 2);
	-- Create error handler
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
		ROLLBACK;
        RESIGNAL; -- Shows ocuured error
    END;
	
	-- Calculate total_amount
    SELECT (price * p_quantity) INTO l_total_amount
		FROM menu_items WHERE item_id = p_item_id;
	
    -- Insert record  in orders table (table constraints automatically validates the record)
    INSERT INTO orders 
		(customer_name, restaurant_id, item_id, quantity, total_amount)
	VALUES
		(p_customer_name, p_restaurant_id, p_item_id, p_quantity, l_total_amount);
	
    -- Show success message
    SELECT 'Order addedd successfully' AS order_status;
END $$

DELIMITER ;

-- Create trigger to audit orders
DELIMITER $$

CREATE TRIGGER after_order_insert
AFTER INSERT ON orders
FOR EACH ROW
BEGIN
	-- Insert record in audit table
    INSERT INTO order_audit (order_id, restaurant_id, action)
		VALUES (NEW.order_id, NEW.restaurant_id, 'INSERT');	
END $$

DELIMITER ;

-- CALL procedure
CALL add_order('Neel', 3, 5, 3);

-- Call view
SELECT * FROM restaurant_sales_summary;