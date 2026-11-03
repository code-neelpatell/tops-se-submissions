-- Delete database if exists
DROP DATABASE IF EXISTS foodapp_db;

-- Create database
CREATE DATABASE foodapp_db;

-- Select database to use
USE foodapp_db;

-- Create table
CREATE TABLE restaurants (
	restaurant_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    city VARCHAR(30) NOT NULL,
    cuisine_type VARCHAR(20) NOT NULL,
    rating DECIMAL(3, 1),
    -- Ensures rating is non-negative
    CONSTRAINT chk_restaurants_rating_non_negative
		CHECK (rating >= 0)
);

-- Insert data 
INSERT INTO restaurants (name, city, cuisine_type, rating) VALUES
	('The Spice House', 'Ahmedabad', 'Indian', 4.5),
	('Pizza Paradise', 'Mumbai', 'Italian', 4.2),
	('Dragon Palace', 'Delhi', 'Chinese', 4.0),
	('Tandoori Nights', 'Ahmedabad', 'North Indian', 4.7),
	('Sushi World', 'Bangalore', 'Japanese', 4.6),
	('Burger Junction', 'Mumbai', 'American', 3.9),
	('South Spice', 'Bangalore', 'South Indian', 4.3),
	('Royal Biryani', 'Delhi', 'Mughlai', 4.8);	
    
-- Update data
UPDATE restaurants
	SET rating = 4.2
    WHERE restaurant_id = 1;

-- Delete data
DELETE FROM restaurants
	WHERE restaurant_id = 1;

-- Show all table data sorted by rating
SELECT * FROM restaurants ORDER BY rating DESC;