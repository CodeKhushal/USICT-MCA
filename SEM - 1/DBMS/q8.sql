-- Views Using Single Table:
-- View to show basic student information
CREATE VIEW student_basic_info AS
SELECT stud_id, f_name, l_name, gender, date_of_birth
FROM Student;

-- View to show faculty names and their salaries
CREATE VIEW faculty_info AS
SELECT fac_id, f_name, l_name, salary
FROM Faculty;

-- Views Using Multiple Table:
-- View to show students with their respective department names
CREATE VIEW student_dept_info AS
SELECT s.stud_id, s.f_name, s.l_name, d.name AS department_name
FROM Student s
JOIN Department d ON s.dept_id = d.dept_id;

-- View to show course details along with the faculty assigned to teach them
CREATE VIEW course_faculty_info AS
SELECT c.course_id, c.name, c.crediits,
f.f_name AS faculty_first_name, F.l_name AS faculty_last_name
FROM Course c
JOIN Faculty f ON c.fac_id = f.fac_id;