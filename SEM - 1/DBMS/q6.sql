-- Inner Join
SELECT 5.stud_id, S.f_name, S.1_name, D.name AS department_name 
FROM Student S
INNER JOIN Department D ON S.dept_id = D.dept_id;

-- Left Outer Join
SELECT F.fac_id, F.f_name, F.l_name, D.name AS HOD_of_department 
FROM Faculty F
LEFT JOIN Department D ON CONCAT(F.f_name, F.1_name) = D.HOD;

-- Right Outer Join
SELECT C.Course_id, C.Course_name, CONCAT(F.f_name, ' ', F.l_name) AS Faculty 
FROM Course C
RIGHT JOIN Faculty F ON C.fac_id = F.fac_id;

-- Full Outer Join

SELECT C.Course_id, C.Course_name, CONCAT(F.f_name, '', F.1_name) AS Faculty 
FROM Course C
LEFT JOIN Faculty F ON C.fac_id = F.fac_id

UNION

SELECT C.Course_id, C.Course_name, CONCAT(F.f_name, ' ', F.l_name) AS Faculty 
FROM Course C
RIGHT JOIN Faculty F ON C.fac_id = F.fac_id;

-- Natural Join
SELECT C.course_id, C.course_name, C.credits, D.name AS department_name 
FROM Course C
NATURAL JOIN Department D;