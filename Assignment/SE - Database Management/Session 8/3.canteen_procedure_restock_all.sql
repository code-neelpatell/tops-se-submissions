-- Select database to use
USE canteen_db;

-- Delete selected procedure if exists
DROP PROCEDURE IF EXISTS restock_all;

-- Create selected procedure
DELIMITER $$

CREATE PROCEDURE restock_all(IN p_amount INT)
BEGIN
	DECLARE counter INT DEFAULT 1;
    WHILE counter <= 6 DO
		UPDATE menu_items 
			SET stock = stock + p_amount
            WHERE item_id = counter;
		SET counter = counter + 1;
	END WHILE;
END $$

DELIMITER ;

-- Call procedure to restock all items
CALL restock_all(25);

-- Varify 
SELECT * FROM menu_items;