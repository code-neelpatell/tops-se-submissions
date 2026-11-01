-- Select database to use
USE canteen_db;

-- Delete selected procedure if exists
DROP PROCEDURE IF EXISTS show_item_status;

-- Create stored procedure to check stock status
DELIMITER $$

CREATE PROCEDURE show_item_status(IN p_item_id INT)
BEGIN 
	DECLARE item_stock INT;
    SELECT stock INTO item_stock 
		FROM menu_items 
        WHERE item_id = p_item_id;
	IF item_stock >= 20 THEN
		SELECT 'In stock';
	ELSEIF item_stock > 0 THEN
		SELECT 'Low stock';
	ELSE 
		SELECT 'Out of stock';
	END IF;
END $$

DELIMITER ;

-- Set stock values
UPDATE menu_items SET stock = 0 WHERE item_id = 1;
UPDATE menu_items SET stock = 10 WHERE item_id = 2;
UPDATE menu_items SET stock = 50 WHERE item_id = 3;

-- Call procedure to check given items stock status
CALL show_item_status(1);
CALL show_item_status(2);
CALL show_item_status(3);
    