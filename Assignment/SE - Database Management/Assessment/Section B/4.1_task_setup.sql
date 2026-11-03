-- Select database to use
USE foodapp_db;

-- Delete table if exists 
DROP TABLE IF EXISTS customers;

-- Create customer table
CREATE TABLE customers (
	customer_id INT AUTO_INCREMENT PRIMARY KEY,
    customer_name VARCHAR(30) NOT NULL,
	wallet_balance DECIMAL(10, 2) NOT NULL,
    -- Ensures wallet_balance is non-negative
    CONSTRAINT chk_customers_wallet_balance_non_negative
		CHECK (wallet_balance >= 0)    
);

-- Insert data in customers table
INSERT INTO customers (customer_name, wallet_balance) VALUES
	('Rahul Sharma', 5000),
	('Priya Patel', 5000),
	('Amit Shah', 5000),
	('Neha Verma', 5000),
	('Karan Mehta', 5000),
	('Sneha Joshi', 5000),
	('Vikas Kumar', 5000),
	('Anjali Desai', 5000),
	('Rohan Gupta', 5000),
	('Meera Shah', 5000),
	('Arjun Rao', 5000),
	('Pooja Mehta', 5000);
    
-- Modify order table
ALTER TABLE orders 
	ADD COLUMN customer_id INT;

-- Change customer_id column order
ALTER TABLE orders
	MODIFY COLUMN customer_id INT AFTER order_id;

-- Turn off safe mode
SET SQL_SAFE_UPDATES = 0;

-- Connnect the existing records with customers id
UPDATE orders o
	JOIN customers c
    ON  c.customer_name = o.customer_name
    SET o.customer_id = c.customer_id;
    
-- Turn on safe mode
SET SQL_SAFE_UPDATES = 1;

-- Remove customer_name field from orders table
ALTER TABLE orders
	DROP COLUMN customer_name;

-- Make customer_id is not null and foreign key
ALTER TABLE orders
	MODIFY customer_id INT NOT NULL;

ALTER TABLE orders
	ADD CONSTRAINT fk_orders_customer_id 
	FOREIGN KEY (customer_id)
    REFERENCES customers(customer_id);

-- Show tables
SELECT * FROM orders;
SELECT * FROM customers;