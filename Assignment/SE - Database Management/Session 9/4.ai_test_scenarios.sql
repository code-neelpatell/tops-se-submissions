-- Select database to use
USE canteen_db;

-- Senario 1: Successful order insertion
-- Initial item 1 stock: 15
SELECT * FROM menu_items WHERE item_id = 1;
CALL place_order(1, 5);
SELECT * FROM menu_items WHERE item_id = 1;
-- ChatGPT expected: Item stock should be decreased from 15 to 10.
-- MySQL actual: Item stock successfully decreased from 15 to 10.

-- Senario 2: Order Exceeding Available Stock
-- Remaining item 1 stock: 10
CALL place_order(1, 20);
SELECT * FROM orders;
SELECT * FROM menu_items;
-- ChatGPT expected: Show error and roll back
-- MySQL actual: Error shown and transaction rollbacked successfully

-- Senario 3: Invalid Item ID
-- The item ids in menu table exists from 1 to 6
CALL place_order(10, 5);
SELECT * FROM orders;
-- ChatGPT expected: Show error and no data inserted
-- MySQL actual: Error shown no data inserted 

