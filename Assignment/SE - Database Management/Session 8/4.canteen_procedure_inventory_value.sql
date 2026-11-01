-- Select database to use
USE canteen_db;

-- Delete selected procedure if exists
DROP PROCEDURE IF EXISTS inventory_value;

-- Create selected procedure
DELIMITER $$

CREATE PROCEDURE inventory_value(OUT p_total DECIMAL(10,2))
BEGIN
	-- Declare variables
    DECLARE i_price DECIMAL(7,2);
    DECLARE i_stock INT;
    DECLARE isDone BOOL DEFAULT FALSE;
    
    -- Declare cursor
    DECLARE fetch_items CURSOR FOR
		SELECT price, stock FROM menu_items;
	
    -- Declare handler to find when records ends
    DECLARE CONTINUE HANDLER FOR NOT FOUND
		SET isDone = true;
        
	-- Initialize the total value
    SET p_total = 0;
    
	-- Open cursor
    OPEN fetch_items;
    
    -- Start loop
    read_loop: LOOP
		-- Fetch a row
        FETCH fetch_items INTO i_price, i_stock;
        -- Check weather records are finished
        IF isDone THEN
			LEAVE read_loop;
		END IF;
        -- Calculate item value and add into total
        SET p_total = p_total + (i_price * i_stock);
    END LOOP;
    
    -- Close cursor
    CLOSE fetch_items;
END $$

DELIMITER ;

-- Call procedure to get inventory value
CALL inventory_value(@total);
SELECT @total;

-- Calling aggregate function to verify the value
SELECT SUM(price * stock) FROM menu_items;