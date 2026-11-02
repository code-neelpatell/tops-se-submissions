-- ======================
-- TASK 1
-- ======================
-- DELETE databse if exists
DROP DATABASE IF EXISTS tuition_fee_db;

-- Create database
CREATE DATABASE tuition_fee_db;

-- Select database to use
USE tuition_fee_db;

-- Create database
CREATE TABLE students (
	student_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    class INT NOT NULL,
    city VARCHAR(50) NOT NULL,
    -- Ensures class is greater than zero
    CONSTRAINT chk_students_class_gt_zero
		CHECK (class > 0)
);

CREATE TABLE courses (
	course_id INT AUTO_INCREMENT PRIMARY KEY,
    course_name VARCHAR(100) NOT NULL,
    monthly_fee DECIMAL(5,0)
    -- Ensures monthly_fee is non-negative
    CONSTRAINT chk_courses_monthly_fee_non_negative
		CHECK (monthly_fee >= 0)
);

CREATE TABLE payments (
	payment_id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT NOT NULL, 
    course_id INT NOT NULL,
    amount DECIMAL(5,0),
    paid_on DATE DEFAULT (CURRENT_DATE),
	-- Ensures amount is non-negative
    CONSTRAINT chk_payments_amount_non_negative
		CHECK (amount >= 0),
	-- Creates foreign key relationship
    CONSTRAINT fk_payments_student_id
		FOREIGN KEY (student_id)
        REFERENCES students(student_id),
	-- Creates foreign key relationship
	CONSTRAINT fk_payments_course_id
		FOREIGN KEY (course_id)
        REFERENCES courses(course_id)
);


-- ======================
-- TASK 2
-- ======================
-- Insert data
INSERT INTO students (student_id, name, class, city) VALUES 
	(1, 'Rahul Patel', 10, 'Surat'),
	(2, 'Priya Shah', 12, 'Ahmedabad'),
	(3, 'Amit Kumar', 9, 'Vadodara'),
	(4, 'Neha Desai', 11, 'Surat'),
	(5, 'Karan Mehta', 10, 'Rajkot');
	
INSERT INTO courses (course_id, course_name, monthly_fee) VALUES
	(101, 'Mathematics', 800),
	(102, 'Science', 1500),
	(103, 'Computer Science', 2500);

INSERT INTO payments (student_id, course_id, amount, paid_on) VALUES
	(1, 101, 800, '2026-09-01'),
	(4, 101, 800, '2026-09-03'),
	(2, 103, 2500, '2026-09-05'),
	(5, 103, 2500, '2026-09-08'),
	(3, 102, 1500, '2026-09-10'),
	(3, 103, 2500, '2026-10-01'),
	(1, 102, 1500, '2026-10-03'),
	(4, 102, 1500, '2026-10-05'),
	(2, 101, 800, '2026-10-08'),
	(5, 101, 800, '2026-10-10');

-- Update one course's fee
UPDATE courses
	SET monthly_fee = 1000
    WHERE course_id = 101;

-- Delete one payment
DELETE FROM payments
		WHERE payment_id = 1;

-- Join query
SELECT s.name, c.course_name, p.amount, p.paid_on AS date
	FROM payments p
    JOIN students s ON s.student_id = p.student_id
    JOIN courses c ON c.course_id = p.course_id
    ORDER BY date;


-- ======================
-- TASK 3
-- ======================
-- Delete procedure if exists
DROP PROCEDURE IF EXISTS monthly_fee_summary;

-- Create procedure to show monthly payment summary
DELIMITER $$

CREATE PROCEDURE monthly_fee_summary(IN p_month INT, IN p_year INT)
BEGIN 
	-- Show fee summary for selected month and year
	SELECT c.course_name, COUNT(p.payment_id) AS no_of_payments, SUM(p.amount) AS total_collected
		FROM payments p 
        JOIN courses c ON c.course_id = p.course_id
        WHERE MONTH(p.paid_on) = p_month AND YEAR(p.paid_on) = p_year
        GROUP BY c.course_id, c.course_name;
	-- Show grand total
    SELECT SUM(amount) AS grabd_total
		FROM payments
        WHERE MONTH(paid_on) = p_month AND YEAR(paid_on) = p_year;
END $$

DELIMITER ;


-- ======================
-- TASK 4
-- ======================
-- Call procedure with both months
CALL monthly_fee_summary(9, 2026);
CALL monthly_fee_summary(10, 2026);