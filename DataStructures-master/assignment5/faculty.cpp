#include <iostream>
#include <string>
#include "faculty.h"

using namespace std;
//Default Constructor
Faculty::Faculty()
{
  facultyID= 0;
  facultyName= " ";
  facultyJob= " ";
  facultyDepartment= " ";

}
//Overloaded Faculty constructor
Faculty::Faculty(int facultyID1, string facultyName1, string facultyJob1, string facultyDepartment1)
{
  facultyID= facultyID1;
  facultyName= facultyName1;
  facultyJob= facultyJob1;
  facultyDepartment= facultyDepartment1;


}
//Destructor
Faculty::~Faculty(){



}
//Faculty ID constructor
Faculty::Faculty(int facultyID1) //used when we only want to input the ID without have to input all of the other parameters
{
  facultyID = facultyID1;
  facultyName = "";
  facultyJob = "";
  facultyDepartment = "";
}
