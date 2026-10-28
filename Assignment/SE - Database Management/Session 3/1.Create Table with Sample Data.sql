-- Create database (if not exists)
CREATE DATABASE IF NOT EXISTS management;
-- Select database
USE management;
-- Create table (if not exists)
CREATE TABLE IF NOT EXISTS restaurants(
	id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    cuisine VARCHAR(50) NOT NULL,
    rating DECIMAL(2,1),
    city VARCHAR(100) NOT NULL
);
-- Insert data into table
INSERT INTO 
restaurants (name, cuisine, rating, city)
VALUES
('Spice Villa', 'Indian', 4.5, 'Ahmedabad'),
('Bella Italia', 'Italian', 4.2, 'Mumbai'),
('Sushi World', 'Japanese', 4.7, 'Delhi'),
('Dragon Palace', 'Chinese', 4.0, 'Pune'),
('Taco Fiesta', 'Mexican', 4.3, 'Bengaluru');
-- View table data
SELECT * FROM restaurants;