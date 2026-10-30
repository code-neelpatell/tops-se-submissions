-- Select database
USE school_db;

-- TASK 1
-- Query: Add foreign key in marks table
ALTER TABLE marks
	ADD CONSTRAINT fk_marks_student 
    FOREIGN KEY (roll_no) REFERENCES students(roll_no),
    ADD CONSTRAINT fk_marks_subject
    FOREIGN KEY (subject_id) REFERENCES subjects(subject_id);
-- Query: Insert invalid data
-- INSERT INTO marks (roll_no, subject_id, marks_obtained)
-- 	VALUES (99, 1, 89);
-- QUERY EXECUTION ERROR MESSAGE:
-- Error Code: 1452. Cannot add or update a child row: a foreign key constraint fails (`school_db`.`marks`, CONSTRAINT `fk_marks_student` FOREIGN KEY (`roll_no`) REFERENCES `students` (`roll_no`))

-- TASK 2
-- Query: Report card of student with roll number 1 using INNER JOIN
SELECT s.name, sub.subject_name, m.marks_obtained, sub.max_marks
	FROM students s
    JOIN marks m ON m.roll_no = s.roll_no
    JOIN subjects sub ON sub.subject_id = m.subject_id
    WHERE s.roll_no = 1
    ORDER BY sub.subject_name;    
    
-- TASK 3
-- Add new student with no entry in marks table
INSERT INTO students (name, class)
	VALUES ('Mona Ali', '10C');
-- LEFT JOIN from students to marks to list students with no marks
SELECT s.roll_no, s.name
	FROM students s
    LEFT JOIN marks m ON m.roll_no = s.roll_no
    WHERE m.marks_obtained IS NULL;

-- TASK 4
-- Insert new subject with no entry in marks table
INSERT INTO subjects (subject_name)
	VALUES ('Computer');
-- RIGHT JOIN that lists every subject with the number of marks recorded for it
SELECT sub.subject_id, sub.subject_name, COUNT(m.marks_id) AS no_of_marks_recorded
	FROM marks m 
    RIGHT JOIN subjects sub ON sub.subject_id = m.subject_id
    GROUP BY sub.subject_id, sub.subject_name;