#include <iostream>

#include "student.h"
#include "doubleLinkedList.h"


//faculty class


using namespace std;

class Faculty
{
public:
//Faculty constructors & destructor
  Faculty();
  Faculty(int facultyID1, string facultyName1, string facultyJob1, string facultyDepartment1);
  Faculty(int facultyID1);
  ~Faculty();


//Variables
  int facultyID;
  string facultyName;
  string facultyJob;
  string facultyDepartment;
//Make an instance of a linked list for storing list of students
  DoublyLinkedList<int> listOfStudents; //Ids

//overload operators for faculty objects
  bool operator < (const Faculty &facu)
  {
    return this->facultyID < facu.facultyID;

  }

  bool operator == (const Faculty &facu)
  {
    return this->facultyID == facu.facultyID;

  }

  bool operator != (const Faculty &facu)
  {
    return this->facultyID != facu.facultyID;

  }

  bool operator > (const Faculty &facu)
  {
    return this->facultyID > facu.facultyID;

  }

  friend ostream & operator << (ostream &out, const Faculty &facu) //for some reason it would not work without using the friend  key word which we research from stack overflow
  {
    //when a faculty object is printed, print the following information
     out << "Faculty id: "<<facu.facultyID << endl;
     out <<"Faculty Name: " << facu.facultyName << endl;
     out <<"Faculty Job: " << facu.facultyJob << endl;
     out <<"Faculty Department: " << facu.facultyDepartment << endl;

     return out;
  }


};
