-- Create database
CREATE DATABASE management;
-- Select database
USE management;
-- Create table
CREATE TABLE restaurants(
	id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    location VARCHAR(100) NOT NULL,
    rating DECIMAL(2,1)
);
-- View table
SELECT * FROM restaurants;