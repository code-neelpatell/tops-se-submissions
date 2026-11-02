-- Select database to use
USE canteen_db;

-- Delete procedure to create again
DROP PROCEDURE IF EXISTS place_order;

-- Create procedure to update
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
END $$

DELIMITER ;

-- Delete trigger if exists
DROP TRIGGER IF EXISTS trg_reduce_stock;

-- Create trigger to automatically reduce stock after order creation
DELIMITER $$

CREATE TRIGGER trg_reduce_stock
AFTER INSERT ON orders
FOR EACH ROW
BEGIN
	-- Update item stock
	UPDATE menu_items
		SET stock = stock - NEW.quantity
        WHERE item_id = NEW.item_id;
END $$

DELIMITER ;

-- Call procedure
CALL place_order(2, 3);

-- Show menu table
SELECT * FROM menu_items;
