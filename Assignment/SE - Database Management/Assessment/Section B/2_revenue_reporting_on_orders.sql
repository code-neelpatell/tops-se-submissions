-- Select database to use
USE foodapp_db;

-- Delete table if exists
DROP TABLE IF EXISTS orders;

-- Create table
CREATE TABLE orders (
	order_id INT AUTO_INCREMENT PRIMARY KEY,
    restaurant_id INT NOT NULL,
    customer_name VARCHAR(30) NOT NULL,
    total_amount DECIMAL(10, 2),
    order_date DATE DEFAULT (CURRENT_DATE),
    -- Ensures total_amount is non-negative
    CONSTRAINT chk_orders_total_amount_non_negative
		CHECK (total_amount >= 0),
    -- Creates foreign key relationship
	CONSTRAINT fk_orders_restaurant_id
        FOREIGN KEY (restaurant_id)
		REFERENCES restaurants(restaurant_id)
);

-- Insert data
INSERT INTO orders (restaurant_id, customer_name, total_amount, order_date) VALUES
	(2, 'Rahul Sharma', 1250.50, '2026-10-01'),
	(3, 'Priya Patel', 2750, '2026-10-02'),
	(4, 'Amit Shah', 1800.75, '2026-10-03'),
	(5, 'Neha Verma', 3200, '2026-10-04'),
	(6, 'Karan Mehta', 950.25, '2026-10-05'),
	(7, 'Sneha Joshi', 2100, '2026-10-06'),
	(8, 'Vikas Kumar', 3850.90, '2026-10-07'),
	(2, 'Anjali Desai', 1650.50, '2026-10-08'),
	(3, 'Rohan Gupta', 2950, '2026-10-09'),
	(4, 'Meera Shah', 1100.25, '2026-10-10'),
	(5, 'Arjun Rao', 3999.99, '2026-10-11'),
	(6, 'Pooja Mehta', 850, '2026-10-12');
    
-- Show revenue summary
SELECT r.name AS restaurant, SUM(o.total_amount) AS total_revenue, ROUND(AVG(o.total_amount), 2) AS average_order_value
	FROM orders o JOIN restaurants r
    ON r.restaurant_id = o.restaurant_id
    GROUP BY r.restaurant_id, r.name;

-- Filter restaurants based on their total revenue
SELECT r.name AS restaurant, SUM(o.total_amount) AS total_revenue
	FROM orders o JOIN restaurants r
    ON r.restaurant_id = o.restaurant_id
    GROUP BY r.restaurant_id, r.name
    HAVING total_revenue > 5000;
    
-- Show 5 recent orders
SELECT * FROM orders 
	ORDER BY order_date DESC
    LIMIT 5;