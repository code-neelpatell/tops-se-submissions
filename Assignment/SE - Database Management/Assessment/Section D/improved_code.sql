-- Select database to use
USE foodapp_db_new;

-- Delete procedure if exists
DROP PROCEDURE IF EXISTS restaurant_monthly_sales_summary;

-- Create procedure, to check selected restaurant's monthly sales summary
DELIMITER $$

CREATE PROCEDURE restaurant_monthly_sales_summary(IN p_restaurant_id INT, IN p_month INT)
BEGIN
	-- Create variables
    DECLARE v_restaurant_exists INT DEFAULT 0;
    DECLARE v_result_record_count INT DEFAULT 0;
    DECLARE v_error_msg VARCHAR(255);
    
	-- Error handler
	DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
		-- Reads the error message
        GET DIAGNOSTICS CONDITION 1
			v_error_msg = MESSAGE_TEXT;
		-- Prints error message
        SELECT v_error_msg AS status;
    END;

    -- Check if months value is null, or outsude of valid month numbers
    IF p_month IS NULL OR p_month NOT BETWEEN 1 AND 12 THEN
		-- Raise error for invalid argument
        SIGNAL SQLSTATE '45001'
			SET MESSAGE_TEXT = 'Invalid argument: Month should be between 1 to 12';
	END IF;
	-- Check if given restaurant id is valid
    SELECT COUNT(restaurant_id) INTO v_restaurant_exists
		FROM restaurants 
		WHERE restaurant_id = p_restaurant_id;
	-- Raise error for runtime error
	IF v_restaurant_exists = 0 THEN
		SIGNAL SQLSTATE '45002'
			SET MESSAGE_TEXT = 'No restaurant found for given id';
	END IF;
    
    -- Check if summary records exists
	SELECT COUNT(restaurant_id) INTO v_result_record_count
		FROM orders
        WHERE restaurant_id = p_restaurant_id AND MONTH(order_date) = p_month;
    IF v_result_record_count = 0 THEN
		SELECT 'No records found for the selected month' AS status;
	ELSE 	
		-- Fetch summary
		SELECT r.name AS restaurant, MONTH(o.order_date) AS month, COUNT(o.order_id) AS total_orders, SUM(o.total_amount) AS revenue, ROUND(AVG(o.total_amount), 2) AS avg_order_value
			FROM orders o JOIN restaurants r
			ON r.restaurant_id = o.restaurant_id
			WHERE o.restaurant_id = p_restaurant_id AND MONTH(o.order_date) = p_month
			GROUP BY o.restaurant_id, month;
	END IF;	
END $$

DELIMITER ;

-- Call procedure
CALL restaurant_monthly_sales_summary(1, 9);
CALL restaurant_monthly_sales_summary(2, 10);