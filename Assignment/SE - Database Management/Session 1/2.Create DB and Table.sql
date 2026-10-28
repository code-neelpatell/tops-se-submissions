-- Create database
CREATE DATABASE InstaClone;
-- Select database to perform operations 
USE InstaClone;
-- Create table
CREATE TABLE Users(
	user_id INT PRIMARY KEY,
    username VARCHAR(30) NOT NULL,
    email VARCHAR(125) NOT NULL,
    followers_count INT NOT NULL
);
