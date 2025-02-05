-- This trigger prevents any update to a faculty member's salary if the new salary is less than the current salary

DELIMITER //

CREATE TRIGGER before_faculty_salary_update
 BEFORE UPDATE ON faculty
 FOR EACH ROW
 BEGIN
     IF NEW.salary < OLD.salary THEN
         SIGNAL SQLSTATE '45000'
         SET MESSAGE_TEXT = 'New salary cannot be less than current salary';
     END IF;
 END //
-- Query OK, 0 rows affected (0.06 sec)

DELIMITER ;

-- Successful update where the new salary is greater than or equal to the old salary
UPDATE faculty
 SET salary = 155000.00
 WHERE fac_id = 1;
-- Query OK, 1 row affected (0.03 sec)

UPDATE faculty
 SET salary = 140000.00
 WHERE fac_id = 1;
-- ERROR 1644 (45000): New salary cannot be less than current salary