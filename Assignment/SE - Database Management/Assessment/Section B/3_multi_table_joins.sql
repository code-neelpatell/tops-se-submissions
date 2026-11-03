-- Select database to use
USE foodapp_db;

-- Delete table if exists
DROP TABLE IF EXISTS menu_items;

-- Create table
CREATE TABLE menu_items (
	item_id INT AUTO_INCREMENT PRIMARY KEY,
    restaurant_id INT NOT NULL,
    item_name VARCHAR(100),
    price DECIMAL(10, 2),
    category VARCHAR(50),
    -- Creates foreign key relationship
	CONSTRAINT fk_menu_items_restaurant_id
        FOREIGN KEY (restaurant_id)
		REFERENCES restaurants(restaurant_id)
);

-- Insert data
INSERT INTO menu_items (restaurant_id, item_name, price, category) VALUES
	(2, 'Margherita Pizza', 299.50, 'Main Course'),
	(2, 'Farmhouse Pizza', 450, 'Main Course'),
	(3, 'Veg Manchurian', 220.75, 'Starter'),
	(3, 'Hakka Noodles', 280, 'Main Course'),
	(4, 'Paneer Tikka', 350.50, 'Starter'),
	(4, 'Butter Chicken', 420, 'Main Course'),
	(5, 'California Sushi Roll', 550, 'Main Course'),
	(5, 'Veg Sushi', 380.25, 'Main Course'),
	(6, 'Classic Burger', 199, 'Fast Food'),
	(6, 'Cheese Burger', 250.50, 'Fast Food'),
	(7, 'Masala Dosa', 120, 'Breakfast'),
	(7, 'Chicken Biryani', 320.75, 'Main Course');
    
-- Listing all menu items
SELECT r.name, m.item_name, m.price 
	FROM menu_items m JOIN restaurants r
    ON r.restaurant_id = m.restaurant_id;
    
-- Show all restaurants with its menu items
SELECT r.name, m.item_name, m.price 
	FROM restaurants r LEFT JOIN menu_items m
    ON m.restaurant_id = r.restaurant_id;
    
-- Delete view if exists
DROP VIEW IF EXISTS restaurant_menu_summary;

-- Create view
CREATE VIEW restaurant_menu_summary AS
	SELECT r.name, COUNT(m.item_id) AS no_of_menu_items, ROUND(AVG(m.price), 2) AS avg_item_price 
		FROM menu_items m JOIN restaurants r
        ON r.restaurant_id = m.restaurant_id
        GROUP BY r.restaurant_id, r.name;

-- Call view
SELECT * FROM restaurant_menu_summary;