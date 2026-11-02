-- Select database to use
USE canteen_db;

-- Delete procedure if exists
DROP PROCEDURE IF EXISTS place_order;

-- Create procedure for place order
DELIMITER $$

CREATE PROCEDURE place_order(IN p_item_id INT, IN p_qty INT)
BEGIN
	-- Exit handler
	DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
		ROLLBACK;
        SELECT 'Order failed' AS Error;
    END;
    START TRANSACTION;
    -- Insert into orders
    INSERT INTO orders (item_id, quantity)
		VALUES (p_item_id, p_qty);
	-- Update into menu items
    UPDATE menu_items
		SET stock = stock - p_qty
        WHERE item_id = p_item_id;
	COMMIT;
END $$

DELIMITER ;

-- Call procedure
CALL place_order(1, 2);
CALL place_order(99, 3);

-- Show orders and menu table
SELECT * FROM orders;
SELECT * FROM menu_items;