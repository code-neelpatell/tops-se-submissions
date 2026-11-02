-- Select database to use
USE canteen_db;

-- Start transaction 
START TRANSACTION;

-- Insert valid orders
INSERT INTO orders (item_id, quantity)
	VALUES (2, 5), (4, 2);

-- Create savepoint
SAVEPOINT before_invalid_order;

-- Insert mistaken order
INSERT INTO orders (item_id, quantity)
	VALUES (6, 500);
    
-- Rollback to the savepoint
ROLLBACK TO before_invalid_order;

-- Show orders table
SELECT * FROM orders;

-- End transaction
COMMIT;
