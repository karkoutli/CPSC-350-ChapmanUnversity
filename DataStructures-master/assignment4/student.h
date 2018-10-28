#include <iostream>

using namespace std;

//student class
class Student{
public:

  //functions needed for the student 
  Student();
  Student(int arrivalTime1, int timeNeededWindow1);
  ~Student();
  void printStudentInfo();
  void arrivalIncrease();
  void waitIncrease();
  void arrivalAndWaitIncrement(int time1);
  //void waitIncrement(int time1);

  int waitTimeQueue;
  int arrivalTime;
  int timeNeededWindow;


};
