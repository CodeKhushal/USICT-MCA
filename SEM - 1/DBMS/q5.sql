-- GROUP BY
-- COUNT (Find the total number of students in each department)
SELECT department, COUNT(*) AS total_students
FROM students 
GROUP BY department;

-- SUM (Calculate the total salary of faculty in each department)
SELECT dept_id, SUM(salary) AS total_salary
FROM Faculty
GROUP BY dept_id;

-- AVG (Calculate the average number of credits for courses offered by each department)
SELECT dept_id, AVG(credits) AS avg_credits
FROM Course
GROUP BY dept_id;

-- MIN/MAX (Calculate the minimum & maximum credits for courses offered by each department)
SELECT dept_id, MIN(credits) AS min_credits, MAX(credits) AS max_credits
FROM Course
GROUP BY dept_id;


-- HAVING
--  COUNT (Find departments with more than 2 students)
SELECT department, COUNT(*) AS total_students
FROM students
GROUP BY dept_id
HAVING COUNT(*) > 2;

-- AVG (Get departments where the average faculty salary is greater than 50,000 and 1,05,000)
SELECT dept_id, AVG(salary) AS avg_salary
FROM Faculty
GROUP BY dept_id
HAVING AVG(salary) > 50000;

SELECT dept_id, AVG(salary) AS avg_salary
FROM Faculty
GROUP BY dept_id
HAVING AVG(salary) > 105000;

-- ORDER BY
SELECT course_id, course_name, credits
FROM Course
ORDER BY credits DESC;