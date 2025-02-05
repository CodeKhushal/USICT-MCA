-- Procedure to Check if a Student is in a Specific Department

-- IF
DELIMITER $$
CREATE PROCEDURE CheckStudentDepartment(IN stud_id INT, IN dept_name VARCHAR(100))
 BEGIN
    DECLARE student_dept VARCHAR(100);
    SELECT D.name INTO student_dept
    FROM Department AS D
    JOIN Student AS S ON D.dept_id = S.dept_id
    WHERE S.stud_id = stud_id;
    IF student_dept = dept_name THEN
       SELECT CONCAT('The student is in the ', dept_name, ' department.') AS Message;
    ELSE
       SELECT CONCAT('The student is not in the ', dept_name, ' department.') AS Message;
    END IF;
 END$$
-- Query OK, 0 rows affected (0.01 sec)

DELIMITER ;
CALL CheckStudentDepartment(1, 'Master of Computer Application');



-- CASE
SELECT fac_id, f_name, l_name, salary,
    CASE
       WHEN salary < 30000 THEN 'Low'
       WHEN salary BETWEEN 30000 AND 60000 THEN 'Medium'
       WHEN salary BETWEEN 60001 AND 90000 THEN 'High'
       ELSE 'Very High'
    END AS Pay_Range
FROM Faculty;




-- IITERATE
DELIMITER //

CREATE PROCEDURE CountStudentsByDepartment()
    BEGIN
    DECLARE total_students INT DEFAULT 0;
    DECLARE done INT DEFAULT FALSE;
    DECLARE dept INT;

    DECLARE student_cursor CURSOR FOR SELECT dept_id FROM student;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN student_cursor;

    loop_label: LOOP
    FETCH student_cursor INTO dept;

    IF done THEN
      LEAVE loop_label;
    END IF;

    -- Skip any department ID that is NULL (if there are any)
    IF dept IS NULL THEN
      ITERATE loop_label;
    END IF;

    -- Increment total count
    SET total_students = total_students + 1;

    -- Output current department and total students counted so far
    SELECT dept AS department_id, total_students AS current_student_total;
    END LOOP;

    CLOSE student_cursor;

    -- Final total count
    SELECT total_students AS total_students_counted;
    END //
    
DELIMITER ;

CALL CountStudentsByDepartment();