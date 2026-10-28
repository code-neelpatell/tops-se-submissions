-- Create Database (if not exists)
CREATE DATABASE IF NOT EXISTS spotify;
-- Select database
USE spotify;
-- Create table (if not exists)
CREATE TABLE IF NOT EXISTS playlists(
	id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(50) NOT NULL,
    created_by VARCHAR(50) NOT NULL,
    created_at DATE DEFAULT (CURRENT_DATE) -- Set current date as default
);
-- View table
SELECT * FROM playlists;