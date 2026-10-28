-- Select database
USE management;
-- Add new column in table restaurants
ALTER TABLE restaurants
ADD COLUMN average_cost INT NOT NULL;
-- View table
SELECT * FROM restaurants;