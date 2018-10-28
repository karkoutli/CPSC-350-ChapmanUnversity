#include <iostream>
#include "student.h"

using namespace std;

//Basic variables we wanted to store to student.
Student::Student(){
  waitTimeQueue=0;
  arrivalTime= 0;
  timeNeededWindow= 0;


}
// The function of student.
Student::Student(int arrivalTime1, int timeNeededWindow1){
    waitTimeQueue=0;
    arrivalTime= arrivalTime1;
    timeNeededWindow= timeNeededWindow1;

}

Student::~Student(){


}
//We used this function to test whether our values were being stored correctly
  void Student::printStudentInfo(){
    cout << "Wait time " << waitTimeQueue << endl;
    cout << "Arrival time " << arrivalTime << endl;
    cout << "Time Needed " << timeNeededWindow << endl;


  }
//Increases arrival time. (didnt use)
void Student::arrivalIncrease(){
      arrivalTime++;

    }
//Increases wait time.
void Student::waitIncrease(){
  waitTimeQueue++;

}
//Our logic for addressing the wait time. 
void Student::arrivalAndWaitIncrement(int time1){
  int d = 0;
  d = time1 - arrivalTime;
  arrivalTime += d;
  waitTimeQueue = waitTimeQueue + d;
}
