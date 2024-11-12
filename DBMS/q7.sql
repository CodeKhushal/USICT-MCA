-- IN


-- NOT IN
SELECT f_name, l_name FROM Faculty
WHERE dept_id NOT IN (
  SELECT dept_id FROM Course
  WHERE course_name = 'Object Oriented Programming'
);


-- ANY
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
SELECT stud_id, f_name, l_name, date_of_birth, dept_id
FROM Student AS S1
WHERE date_of_birth < ALL (
     SELECT date_of_birth
     FROM Student AS S2
     WHERE S2.dept_id = 1
);