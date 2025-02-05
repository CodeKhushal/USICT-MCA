-- Write the SQL queries to demonstrate the application of DDL commands like ALTER, DROP, and TRUNCATE.

create table lab_faculty(
lab_fac_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, f_name varchar(10) NOT NULL,
1_name varchar(50) NOT NULL, date_of_joining DATE,
dept_id INT,
salary DECIMAL(10,2),
FOREIGN KEY(dept_id) REFERENCES Department(dept_id) );

DESCRIBE lab_faculty;

-- Altered the lab_faculty table to change the datatype of f_name attribute
ALTER TABLE lab_faculty
MODIFY f_name VARCHAR(50) NOT NULL;


-- Altered the lab_faculty table to add gender attribute
ALTER TABLE lab_faculty
ADD COLUMN gender VARCHAR(1);

DESCRIIBE lab_faculty;

-- Inserted Values into the lab_faculty Table

INSERT INTO lab_faculty(f_name, l_name, date_of_joining, dept_id, salary, gender) VALUES 
('Ram Prasad', 'Mishra','2012-05-15', 1, 80000.00, 'M'),
('Monica', 'Kapoor', '2010-03-02', 2, 85000.00, 'F'), 
('Rohini', 'Singh', '2015-01-01', 1, 75000.00, 'F'), 
('Manish', 'Arora', '2010-04-08', 3, 90000.00, 'M'), 
('Amrit', 'Kashyap', '2016-09-12', 4, 65000.00, 'M'), 
('Kanika', 'Grover', '2016-06-10', 4, 65000.00, 'F')
;

-- Truncated the lab_faculty table to delete the data inside it
TRUNCATE TABLE lab_faculty;
SELECT * FROM lab_faculty;

-- Dropped the lab_faculty table
DROP TABLE lab_faculty;