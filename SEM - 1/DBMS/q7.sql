-- IN
-- Find the names of all students who belong to departments with more than 2 courses.
SELECT f_name, l_name 
FROM Student
WHERE dept_id IN (
  SELECT dept_id 
  FROM Course
  GROUP BY dept_idHAVIING COUNT(course_id) > 2
);

-- NOT IN
-- Find the names of all faculty members who are not teaching in the department of a specific course, say 'Object Oriented Programming'.
SELECT f_name, l_name 
FROM Faculty
WHERE dept_id NOT IN (
  SELECT dept_id FROM Course
  WHERE course_name = 'Object Oriented Programming'
);


-- ANY
-- Find the names of all faculty members whose salary is greater than that of any faculty member in the 'Computer Science Engineering' department.
SELECT f_name, l_name
FROM Faculty
WHERE salary > ANY (
     SELECT salary
     FROM Faculty
     WHERE dept_id = (
         SELECT dept_id
         FROM Department
         WHERE name = 'Computer Science Engineering'
     )
);

-- ALL
-- Find Students Older Than All Students in the "Master of Computer Application" Department.
SELECT stud_id, f_name, l_name, date_of_birth, dept_id
FROM Student AS S1
WHERE date_of_birth < ALL (
     SELECT date_of_birth
     FROM Student AS S2
     WHERE S2.dept_id = 1
);