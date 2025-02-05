-- Create a University database with appropriate tables inputted with the required data.
\sql
\connect root@localhost
SHOW DATABASES;

CREATE DATABASE UniversityDB;
USE UniversityDB;

CREATE TABLE Department(
    dept_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    HOD VARCHAR(255) NOT NULL
);

CREATE TABLE Student(  
    stud_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    f_name Varchar(50) NOT NULL,
    1_name VARCHAR(50) NOT NULL,
    date_of_birth DATE,
    gender CHAR(1),
    dept_id INT,
    FOREIGN KEY(dept_id) REFERENCES Department (dept_id)
);

CREATE TABLE Faculty(
    fac_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    f_name VARCHAR(50) NOT NULL,
    1_name VARCHAR(50) NOT NULL,
    date_of_birth DATE,
    gender CHAR(1),
    date ofjoining DATE,
    dept_id INT,
    salary DECIMAL(10,2),
    FOREIGN KEY(dept_id) REFERENCES Department (dept_id)
);

CREATE TABLE Course(
    course_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    course_name VARCHAR(100) NOT NULL,
    credits INT,
    dept_id INT,
    fac_id INT,
    FOREIGN KEY (dept_id) REFERENCES Department (dept_id),
    FOREIGN KEY (fac_id) REFERENCES Faculty (fac_id)
);

SHOW TABLES;
-- ALTER TABLE STUDENT RENAME COLUMN data_of_birth TO date_of_birth;
-- ALTER TABLE STUDENT ADD CGPA DECIMAL(10, 2);

INSERT INTO Department (name, HoD) values
    ('Master of Computer Application', 'Dr. Anuj Jain'),
    ('Computer Science Engineering', 'Dr. Radha Mohan'),
    ('Bio Technology', 'Dr. Hari Prasad'),
    ('Data Analytics', 'Dr. Monika Suri')
;
DESCRIBE DEPARTMENT;
SELECT * FROM DEPARTMENT;


INSERT INTO STUDENT (f_name, 1_name, date_of_birth, gender, dept_id) VALUES 
    ('Khushal', 'Sachdeva', '2002-07-25', 'M', 1),
    ('Tushar', 'Katyal', '2003-03-20', 'M', 2), 
    ('Barun' 'Wason', '2003-01-18', 'M', 1), 
    ('Neha', 'Khandelwal', '2002-11-28', 'F', 1), 
    ('Pooja', 'Sharma', '2002-10-12', 'F', 3), 
    ('Akshit', 'Arora', '2001-11-01', 'M', 4), 
    ('Rishabh', 'Chopra', '2003-02-28', 'M', 4), 
    ('Mohit', 'Kumar', '2004-01-21', 'M', 3), 
    ('Yashika', 'Malhan', '2002-05-10', 'F', 2), 
    ('Paras', 'Behl', '2002-09-15', 'M', 2), 
    ('Srishti', 'Kashyap', '2003-02-14', 'F', 1)
;
DESCRIBE STUDENT;
SELECT * FROM STUDENT;

INSERT INTO Faculty(f_name, l_name, date_of_birth, gender, date_of_joining, dept_id, salary) VALUES 
    ('Dr. Anurag', 'Jain', '1982-04-03', 'M', '2011-06-02', 1, 150000.00), 
    ('Dr. Radha', 'Mohan', '1980-01-11', 'M', '2009-04-02', 2, 150000.00), 
    ('Prof. Rajesh', 'Kumar' '1991-11-14', "M", '2019-02-06', 2, 85000.00), 
    ('Dr. Monika', 'Suri', '1986-09-18', 'F', '2011-08-12', 4, 150000.00), 
    ('Dr. Hari', 'Prasad', '1989-07-25', 'M', '2010-05-23', 3, 150000.00), 
    ('Dr. Anuj', 'Jain', '1981-05-06', 'M', '2010-02-08', 1, 160000.00), 
    ('Prof. Rohit', 'Singh', '1995-12-23', 'M', '2021-04-01', 3, 50000.00), 
    ('Dr. Reena', 'Gupta', '1990-08-12', 'F', '2006-09-20', 1, 160000.00), 
    ('Prof. Sunita', 'Narang', '1934-11-15', 'F', '2020-06-14', 4, 60000.00)
;
DESCRIBE FACULTY;
SELECT * FROM FACULTY;

INSERT INTO Course (course_name, credits, dept_id, fac_id) VALUES 
    ('Database Management System', 10, 1, 1),
    ('Data Structures and Algorithms', 8, 1, 8),
    ('Computer Networks', 10, 2, 2),
    ('Agricultural Science', 5, 3, 5), 
    ('Power Bi and Data Analysis', 8, 4, 4), 
    ('Object Oriented Programming', 6, 1, 6), 
    ('Environmental Studies', 5, 3, 7)
;
DESCRIBE COURSE;
SELECT * FROM COURSE;
