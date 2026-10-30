-- Select database
USE school_db;

-- TASK 1
-- Query 1: Students of class 10A sorted by name
SELECT * FROM students 
WHERE class = '10A'
ORDER BY name;
--  Query 2: Marks of 80 or more
SELECT student_id, marks_obtained AS marks
FROM marks
WHERE marks_obtained >= 80
ORDER BY marks DESC;
-- Query 3: The three highest marks
SELECT student_id, marks_obtained AS marks
FROM marks
ORDER BY marks DESC
LIMIT 3;
-- Query 4: All student names with an alias
SELECT name AS student_name FROM students;

-- TASK 2
-- Query 1: Total marks of roll number 1
SELECT SUM(marks_obtained) AS total_marks
FROM marks WHERE student_id = 1;
-- Query 2: Average marks of subject 1
SELECT ROUND(AVG(marks_obtained),2) AS avg_marks
FROM marks WHERE subject_id = 1;
-- Query 3: Number of students in class 10A
SELECT COUNT(id) AS students_count
FROM students WHERE class = '10A';

-- TASK 3
-- Query 1: Average marks per subject_id
SELECT subject_id, ROUND(AVG(marks_obtained), 2) AS avg_marks_obtained
FROM marks 
GROUP BY subject_id;
-- Query 2: Total marks per roll_no sorted highest first
SELECT student_id AS roll_no, SUM(marks_obtained) AS total_marks
FROM marks 
GROUP BY student_id
ORDER BY total_marks DESC;
-- Query 3: Number of marks rows per subject
SELECT subject_id, COUNT(id) AS no_of_marks
FROM marks
GROUP BY subject_id;

-- TASK 4
-- Query: The roll number of topper with the highest total marks
SELECT student_id AS roll_no, SUM(marks_obtained) AS total_marks_obtained
FROM marks
GROUP BY student_id
ORDER BY total_marks_obtained DESC
LIMIT 1;