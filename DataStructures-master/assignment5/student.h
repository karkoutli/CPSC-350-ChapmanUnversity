
#include <iostream>
#include <string>
//#include "faculty.h"

using namespace std;

//student class
class Student
{

public:
//constructors
  Student();
  Student(int studentID1);
  Student(int studentID1, string studentName1, string studentYear1, string studentMajor1, double studentGPA1, int facultyID1);
  ~Student();
//Variables used to store values for student type.
  int studentID;
  string studentName;
  string studentYear;
  string studentMajor;
  double studentGPA;
  int facultyID;
//Overide operators required for student objects
  bool operator == (const Student &stu)
  {
    return this->studentID == stu.studentID;

  }
  bool operator != (const Student &stu)
  {
    return this->studentID != stu.studentID;

  }

  bool operator < (const Student &stu)
  {
    return this->studentID < stu.studentID;

  }
  bool operator > (const Student &stu)
  {
    return this->studentID > stu.studentID;

  }
  friend ostream & operator << (ostream &out, const Student &stu) //for some reason it would not work without using the friend  key word which we research from stack overflow
  {

    //when printing a student object print out the following information
    out << "Student id: "<<stu.studentID << endl;
    out << "Student name: "<<stu.studentName << endl;
    out << "Student Year: "<<stu.studentYear << endl;
    out << "Student Major: "<<stu.studentMajor << endl;
    out << "Student GPA: "<<stu.studentGPA << endl;
    out << "Faculty ID: "<<stu.facultyID<< endl;
    return out;
  }


};
