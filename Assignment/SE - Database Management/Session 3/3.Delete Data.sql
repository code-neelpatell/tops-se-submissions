-- Select database
USE management;
-- Delete data
DELETE FROM restaurants
WHERE rating < 3.5;
-- View table data
SELECT * FROM restaurants;