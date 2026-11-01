-- Delete database if exists
DROP DATABASE IF EXISTS canteen_db;

-- CREATE Database
CREATE DATABASE canteen_db;

-- Select database to use
USE canteen_db;

-- Create tables
CREATE TABLE menu_items (
	item_id INT AUTO_INCREMENT PRIMARY KEY,
    item_name VARCHAR(100) NOT NULL,
    price DECIMAL(7,2),
    stock INT NOT NULL DEFAULT 0,
    -- Ensures price is non-negative
    CONSTRAINT chk_menu_items_price_non_negative 
		CHECK (price >= 0),
    -- Ensures stock is non-negative
    CONSTRAINT chk_menu_items_stock_non_negative 
		CHECK (stock >= 0)
	-- Ensures
);

CREATE TABLE orders (
	order_id INT AUTO_INCREMENT PRIMARY KEY,
    item_id INT NOT NULL,
    quantity INT NOT NULL,
    order_date DATE DEFAULT (CURRENT_DATE),
    -- Ensures quantity is greater than zero
    CONSTRAINT chk_orders_qty_gt_zero 
		CHECK (quantity > 0),
    -- Creates foreign key relationship
    CONSTRAINT fk_orders_item_id 
		FOREIGN KEY (item_id) 
		REFERENCES menu_items(item_id)
);

-- Insert data
INSERT INTO menu_items (item_name, price, stock)
VALUES
	('Samosa', 15, 50),
    ('Veg Sandwich', 40, 30),
    ('Masala Chai', 10, 100),
    ('Veg Puff', 25, 60),
    ('Cold Coffee', 80, 20),
    ('Poha', 30, 75);

-- View tables structure and data
SELECT * FROM menu_items;
SELECT * FROM orders;