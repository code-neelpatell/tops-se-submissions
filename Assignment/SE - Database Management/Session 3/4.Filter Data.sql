-- Select database
USE management;
-- Filter data
SELECT * FROM restaurants
WHERE city = 'Ahmedabad' AND rating > 4.0
ORDER BY rating DESC
LIMIT 2;