#include <iostream>
#include "faculty.h"
#include "BST.h"
#include <fstream>



using namespace std;

class simulation {

public:
  simulation();
  ~simulation();
//Funcitons used to read write and store to file.
  void menu();
  void readFile();
  bool fileExist(string file1);
  void writeFileStudent1();
  void writeFileFaculty1();
  void writeFileStudent(TreeNode<Student>* root1, ofstream& writefile2);
  void writeFileFaculty(TreeNode<Faculty>* root1, ofstream& writefile1);
  string delimiter; //delimiters used to seperate the data in the text files and be able to read back the data correctly
  string delimiter1; //delimiter used for the list of students


  string studentFile;
  string facultyFile;



void run();

//BST Constructors with their respective type
  BST<Student> masterStudentBST;
  BST<Faculty> masterFacultyBST;
//Functions used to minimize mess in menu
void printStudent();
void printFaculty();
void studentInfo();
void facultyInfo();
void addFaculty();
void addStudent();
void deleteStudent();
void deleteFaculty();
void removeAdvisee();
void studentFacultyInfo();
void facultyStudentID();
void changeStudentAdvisor();
void changeStudentName();
void changeFacultyName();




};
