-- Select database to use
USE foodapp_db;

-- Delete procedure if exists
DROP PROCEDURE IF EXISTS place_order;

-- Create procedure
DELIMITER $$

CREATE PROCEDURE place_order(IN p_customer_id INT, IN p_restaurant_id INT, IN p_amount DECIMAL(10, 2))
BEGIN
	DECLARE p_wallet_balance DECIMAL(10, 2) DEFAULT 0;
    
    -- Declare error handler, if orders insert query fails
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
		ROLLBACK;
		RESIGNAL;
    END;
    
    START TRANSACTION;
    -- Fetch customer's wallet balance
    SELECT wallet_balance INTO p_wallet_balance
		FROM customers WHERE customer_id = p_customer_id;
        
	-- Check for sufficient balance in customer's wallet
    IF p_wallet_balance >= p_amount THEN    
		-- Deduct amount from customer's wallet
		UPDATE customers
			SET wallet_balance = wallet_balance - p_amount
            WHERE customer_id = p_customer_id;
		-- Insert record in orders table
		INSERT INTO orders (customer_id, restaurant_id, total_amount)
			VALUES (p_customer_id, p_restaurant_id, p_amount);
		-- Commit transaction
        COMMIT;
        SELECT 'Order placed successfully' AS status; 
	ELSE
		ROLLBACK;
        SELECT 'Insufficient wallet balance' AS status;
	END IF;
END $$

DELIMITER ;

-- Call procedure
CALL place_order(1, 2, 500);
CALL place_order(1, 3, 5000);