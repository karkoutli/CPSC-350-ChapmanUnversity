#include <iostream>
#include "student.h"

using namespace std;
//window class which contains a student object and has the needed variables/functions 
class Window{
public:

  Window();
//  Student(int arrivalTime1, int timeNeededWindow1);
  ~Window();
  bool isIdle();

int idleTime;
int longestTime;
Student student;


};
