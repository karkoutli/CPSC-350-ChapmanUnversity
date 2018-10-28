#include <iostream>
//#include "student.h"
#include "queue.h"
#include "window.h"

using namespace std;

//Simulation class
class Simulation{
public:

//functions needed for thhe simulation 
  Simulation();
  ~Simulation();
  void fileReader(string fileName);
  void runProgram();
  int emptyIndex();
  void idleWindowCounter();
  void waitInQueueCounter(int time1);
  void timeNeededDecrement();
  bool arrayCheck();


  int meanSWT; //StudentWaitTime
  int medianSWT;
  int longestSWT;
  int numSWIL; //students waiting in line for over ten mins
  int meanWIT; //Window Idle time
  int longestWIT;
  int numWI; //number of windows idle for over 5 mins
  int studentCounter;

  int numOfWindows;

  int time1;

  queue<Student> studentQueue; //declare a student queue

  Window *windowArray; //declare an array pointer of type window



};
