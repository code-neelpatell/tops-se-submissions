-- Create database
CREATE DATABASE IF NOT EXISTS school_db;

-- Select database
USE school_db;

-- Create tables
CREATE TABLE IF NOT EXISTS students(
	id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    class VARCHAR(3) NOT NULL
);

CREATE TABLE IF NOT EXISTS subjects(
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE IF NOT EXISTS marks(
	id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT,
    subject_id INT,
    marks_obtained INT CHECK(marks_obtained>=0),
    FOREIGN KEY (student_id) REFERENCES students(id),
    FOREIGN KEY (subject_id) REFERENCES subjects(id)
);

-- Show tables
SELECT * FROM students;
SELECT * FROM subjects;
SELECT * FROM marks;