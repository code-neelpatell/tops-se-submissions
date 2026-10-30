-- Select database
USE school_db;

-- Setup: Schema and data changes for session
ALTER TABLE students
	RENAME COLUMN id TO roll_no;
ALTER TABLE subjects
	RENAME COLUMN id TO subject_id,
    RENAME COLUMN name TO subject_name,
    ADD COLUMN max_marks INT NOT NULL DEFAULT 100;
ALTER TABLE marks
	RENAME COLUMN id TO marks_id,
    RENAME COLUMN student_id TO roll_no;
UPDATE subjects
	SET max_marks = 100
    WHERE subject_id IN(1, 2, 3);
UPDATE students
	SET class = '10B'
    WHERE roll_no IN (5,8);

-- View tables data
SELECT * FROM students;
SELECT * FROM subjects;
SELECT * FROM marks;