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

DESCRIBE STUDENT;
SELECT * FROM STUDENT;

DESCRIBE FACULTY;
SELECT * FROM FACULTY;

DESCRIBE COURSE;
SELECT * FROM COURSE;
