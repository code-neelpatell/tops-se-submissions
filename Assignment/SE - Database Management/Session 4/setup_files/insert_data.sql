USE school_db;

-- Insert data
INSERT INTO students
	(name, class)
VALUES
	('Aarav Sharma', '10A'),
	('Diya Patel', '10A'),
	('Rohan Mehta', '10B'),
	('Ananya Shah', '10A'),
	('Vivaan Desai', '10b'),
	('Isha Joshi', '10A'),
	('Kabir Singh', '10C'),
	('Meera Patel', '10b');

INSERT INTO subjects (subject_name)
VALUES
    ('Mathematics'),
    ('Science'),
    ('English');
    
INSERT INTO marks (student_id, subject_id, marks_obtained)
VALUES
    (1, 1, 95),
    (1, 2, 88),
    (1, 3, 92),

    (2, 1, 82),
    (2, 2, 85),
    (2, 3, 79),

    (3, 1, 76),
    (3, 2, 80),
    (3, 3, 75),

    (4, 1, 91),
    (4, 2, 94),
    (4, 3, 89),

    (5, 1, 68),
    (5, 2, 72),
    (5, 3, 70),

    (6, 1, 88),
    (6, 2, 90),
    (6, 3, 86),

    (7, 1, 79),
    (7, 2, 83),
    (7, 3, 77),

    (8, 1, 97),
    (8, 2, 95),
    (8, 3, 93);

-- Show tables
SELECT * FROM students;
SELECT * FROM subjects;
SELECT * FROM marks;

    
    