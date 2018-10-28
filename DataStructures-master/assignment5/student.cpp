
#include <iostream>
#include <string>

#include "student.h"

using namespace std;
//default constructor
Student::Student()
{
  studentID=0;
  studentName= " ";
  studentYear= " ";
  studentMajor= " ";
  studentGPA = 0;
  facultyID= 0;

}


//Destructor
Student::~Student(){

}

//Overloaded Constructor
Student::Student(int studentID1, string studentName1, string studentYear1, string studentMajor1, double studentGPA1, int facultyID1)
{

  studentID= studentID1;
  studentName= studentName1;
  studentYear= studentYear1;
  studentMajor= studentMajor1;
  studentGPA = studentGPA1;
  facultyID= facultyID1;

}
//Student ID constructor
Student::Student(int studentID1){
  studentID = studentID1;
  studentName = "";
  studentYear = "";
  studentMajor = "";
  studentGPA = 0;
  facultyID = 0;
}
