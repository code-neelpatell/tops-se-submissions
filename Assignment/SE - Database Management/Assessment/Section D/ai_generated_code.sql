-- Select database to use
USE foodapp_db_new;

-- Delete procedure if exists
DROP PROCEDURE IF EXISTS sp_restaurant_monthly_summary;

-- Create procedure
DELIMITER //

CREATE PROCEDURE sp_restaurant_monthly_summary(
    IN p_restaurant_id INT,
    IN p_month INT
)
BEGIN
    -- Validate month number
    IF p_month < 1 OR p_month > 12 THEN

        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Invalid month. Please enter a month between 1 and 12.';

    -- Check whether orders exist
    ELSEIF EXISTS (
        SELECT 1
        FROM orders
        WHERE restaurant_id = p_restaurant_id
          AND MONTH(order_date) = p_month
    ) THEN

        -- Generate monthly summary
        SELECT
            restaurant_id,
            MONTH(order_date) AS month_number,
            COUNT(order_id) AS total_orders,
            SUM(total_amount) AS total_revenue,
            ROUND(AVG(total_amount), 2) AS average_order_value
        FROM orders
        WHERE restaurant_id = p_restaurant_id
          AND MONTH(order_date) = p_month
        GROUP BY restaurant_id, MONTH(order_date);

    ELSE

        -- Handle case where no orders exist
        SELECT
            'No orders found for this restaurant in the selected month.'
            AS message;

    END IF;

END //

DELIMITER ;

-- Call procedure
CALL restaurant_monthly_sales_summary(1, 9);
CALL restaurant_monthly_sales_summary(2, 10);