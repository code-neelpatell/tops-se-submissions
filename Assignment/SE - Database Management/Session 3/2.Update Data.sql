-- Select database
USE management;
-- Update data
UPDATE restaurants
SET rating = 4.7
WHERE name = 'Spice Villa';
-- View table data
SELECT * FROM restaurants;