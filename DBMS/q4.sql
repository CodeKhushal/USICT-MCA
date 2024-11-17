-- Primary Key Constraint (Key Constraint/ Entity Integrity Constraint)
-- Attempt to insert duplicate stud_id values in the Student table
INSERT INTO STUDENT(stud_id, f_name, l_name, date_of_birth, gender, dept_id) VALUES 
(11, 'Gaurav', 'Kumar', '2002-05-11', 'M', 1);

-- NOT NULL Constraint (Entity Integrity Constraint)
-- Attempt to insert a NULL value into a NOT NULL column like name or HOD in Department
INSERT INTO DEPARTMENT(dept_id, name, HoD) VALUES
(5, NULL, 'Manoj Madaan');

-- Check Constraint
-- Attempt to test wrong datatype for gender attribute in Student table
INSERT INTO STUDENT (f_name, l_name, date_of_birth, gender, dept_id) VALUES 
('Deepak', 'Arora', '2003-02-14', 'MMF', 2);

-- Foreign Key Constraint
-- Attempt to insert a dept_id in Student table that doesn't exist in the respective parent tables
INSERT INTO STUDENT(f_name, l_name, date_of_birth, gender, dept_id) VALUES 
('Deepak', 'Arora', '2003-02-14', 'M', 8);

-- Referential Integrity Constraint
-- Attempt to test wrong datatype for gender attribute in Student table
DELETE FROM DEPARTMENT WHERE dept_id = 3;