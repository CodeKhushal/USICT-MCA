#include <iostream>
using namespace std;

// Base class
class Student
{
protected:
    int roll_no;
    string name;

public:
    void setStudentDetails(int r, string f, string l)
    {
        roll_no = r;
        name = f+ " " + l;
    }
};

// Derived class 1 from Student
class Exam : virtual public Student
{
protected:
    int exam_marks;

public:
    void setExamMarks(int marks)
    {
        exam_marks = marks;
    }
};

// Derived class 2 from Student
class Sports : virtual public Student
{
protected:
    int sports_marks;

public:
    void setSportsMarks(int marks)
    {
        sports_marks = marks;
    }
};

// Derived class from both Exam and Sports
class Result : public Exam, public Sports
{
public:
    void displayTotal()
    {
        int total = exam_marks + sports_marks;
        cout << "\n\tStudent Name: " << name << endl;
        cout << "\tRoll Number: " << roll_no << endl;
        cout << "\tExam Marks: " << exam_marks << endl;
        cout << "\tSports Marks: " << sports_marks << endl;
        cout << "\tTotal Marks: " << total << endl;
    }
};

int main()
{
    Result student;

    // Set student details
    string Fname, Lname;
    int rollNum;
    cout << "Enter student's roll number: ";
    cin >> rollNum;
    cout << "Enter student's first name: ";
    cin >> Fname;
    cout << "Enter student's last name: ";
    cin >> Lname;
    student.setStudentDetails(rollNum, Fname, Lname);

    // Set exam and sports marks
    student.setExamMarks(95);
    student.setSportsMarks(28);

    // Display total marks
    student.displayTotal();

    return 0;
}
