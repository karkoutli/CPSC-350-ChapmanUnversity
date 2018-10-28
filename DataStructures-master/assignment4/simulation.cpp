#include <iostream>
#include "simulation.h"
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <algorithm>
using namespace std;

//constructor
Simulation::Simulation(){

  time1=0;

}

//destructor
Simulation::~Simulation(){}

//Opens the inputted file and reads each line into its respective variable
void Simulation::fileReader(string fileName){

  //file io and variable declarations
      ifstream file;
      string line = " ";
      int lineCounter=0;
      int totalLine=1;
      int numOfStudents=0;
      int numofStudentsCounter=0;
      int arrivalTime=0;
      int timeNeededWindow=0;
      numOfWindows=0;


      file.open(fileName);

//Open up the file
      while(getline(file, line)){
      if(totalLine==1){ //if the totalLine is 1 then save the number as the number of windows used in the simulation
        numOfWindows= atoi(line.c_str());
      //  cout << numOfWindows << endl;

      }
      else if(totalLine==2){ //if totalLine is 2 then save the number as the arrival time for the student/students
        arrivalTime= atoi(line.c_str());
        //  cout << arrivalTime << endl;
      }
      else if(totalLine==3){ //if totalline is 3 then save the number of students arriving at this specific time
        numOfStudents =  atoi(line.c_str()); //2
          //cout << numOfStudents << endl;
      }
      //if the numberofstudentsarriving counter is less than the number of students arriving then add the student to the queue
      else if(numofStudentsCounter < numOfStudents){
        timeNeededWindow= atoi(line.c_str());
      //  cout << timeNeededWindow << endl;
        Student student(arrivalTime, timeNeededWindow);
        studentQueue.enQueue(student);
        numofStudentsCounter++;
        studentCounter++;
      }
      else{
        //if the totalline is not equal to 1,2, or 3 and the numofStudentsCounter counter is not less than the number of students numberofstudentsarriving
        //then we are at the arrival time of the next batch of students
        //save this new arrival time and set the total line to 2 so that it is increased to 3 and starts over again from 3
        // Loops through the corresponding lines and stores the values into a new object.

        arrivalTime=atoi(line.c_str());
      //  cout << arrivalTime << endl;
        numOfStudents=0;
        numofStudentsCounter=0;

        totalLine=2;

      }

      totalLine++;

    }
    //create array of windows based on the first line
      windowArray = new Window[numOfWindows];
      for( int i = 0; i < numOfWindows; ++i){
        Window window;
        windowArray[i]= window;

      }


}
//This is where we run our full program.
void Simulation::runProgram(){

cout << endl;

//Student Array to be used in handling the stats after the simulation is over
Student studentStatsArray[studentCounter];


  while(true){
    time1++;
    timeNeededDecrement(); //check each window in the array and if there is a student then decrement its time needed

//loop through the windows
  for (int i = 0; i < numOfWindows; ++i) {
//Checks to see if student is done at window
    if (windowArray[i].student.timeNeededWindow == 0) {
//Checks to see that they have the correct arrival time above zero so that we know it is not an empty window
      if (windowArray[i].student.arrivalTime > 0) {
        if (studentStatsArray[i].arrivalTime == 0) { //if student array index is empty then assign the student who is finished at the window to the array
          studentStatsArray[i] = windowArray[i].student;
          windowArray[i].student.arrivalTime = 0;
          windowArray[i].student.waitTimeQueue = 0;

        }

        else { //if student array arrival time is not 0 and the window array arrival time is greater then check the rest of the student array to see if there are any empty spaces
          for (int j = 0; j < studentCounter; ++j) {
            if (studentStatsArray[j].arrivalTime == 0) {

              studentStatsArray[j] = windowArray[i].student;
              windowArray[i].student.arrivalTime = 0;
              windowArray[i].student.waitTimeQueue = 0;

            }
          }

        }
      }
    }
  }


  //loop through until there are no more students in the queue at the current time
      while (studentQueue.peek().arrivalTime == time1) {

        int a = emptyIndex(); //check to see if the window has any empty indexes
//We decided it was easier to simply call the method in a variable than to repeat it over and over.
        if (a != -1) { //if it is not full then dequee the student into the empty window
          windowArray[emptyIndex()].student = studentQueue.deQueue();

          if(!studentQueue.isEmpty1()) //if the student queue is not empty then check if the arrival time is less than the current time
          {
            if(studentQueue.peek().arrivalTime < time1)
              waitInQueueCounter(time1); //change the arrival time and update the wait time
          }
        }
        else { //if windows are all full then increase the arrival time and update the wait time

          waitInQueueCounter(time1);
        }
      }



    idleWindowCounter();

//If both the queue and the array is empty, break.
    if(studentQueue.isEmpty1()==1 && arrayCheck())
      break;
  }

cout << " -Final Results- " << endl;
cout << endl;
cout << "Window Results: " << endl;

//printing the windows
  for (int i =0; i< numOfWindows; ++i){

    cout << "Window Idle Time: "<< windowArray[i].idleTime <<   endl;
  }
  cout << endl;

cout << "Student Results: " << endl;
//printing array of students with arrival times and wait imes
  for(int i = 0; i < studentCounter; ++i){

    cout<< "Student Arrival Time: " << studentStatsArray[i].arrivalTime <<  " Student Wait time: " << studentStatsArray[i].waitTimeQueue<< endl;
    }

cout << endl;




//Stats variables.
  int waitTimeCounter=0;
  int waitTimeArray[studentCounter]; //student wait time array
  int meanSumStudent = 0;
  int countStudents = 0;
  int meanCalculateStudent = 0;
  int greaterThan10Wait= 0;
  int windowIdleArray[numOfWindows]; //window idle time array
  int greaterThan5Idle=0;
  int meanIdle=0;
  int meanSumIdle=0;

  for(int i = 0; i < studentCounter; ++i){
//Adding the wait time to another array for the stats
      waitTimeArray[i] = studentStatsArray[i].waitTimeQueue;
      meanSumStudent += studentStatsArray[i].waitTimeQueue;
      countStudents++;

// Counts the number of students with a wait time greater than 10.
    if(studentStatsArray[i].waitTimeQueue > 10){
      greaterThan10Wait++;
    }
  }


  for(int i = 0; i < studentCounter; ++i){
      //cout << waitTimeArray[i] << endl;
    }


    //sort student stats array and find the median
    int n = sizeof(waitTimeArray) / sizeof(waitTimeArray[0]); //n required for the sorting function and needed for the median
    sort(waitTimeArray, waitTimeArray + n); //using the built in sort fuction

    //median calculation

    if(n % 2 != 0){ //if it is even then calculate the median accordingly
      cout << "Median Student Wait Time: " << waitTimeArray[n/2] << endl; ;
    }
    else{ //if it is odd then calculate the median accordingly
      cout << "Median Student Wait Time: " << (waitTimeArray[(n-1)/2] + waitTimeArray[n/2]) / 2 << endl;
    }

    //grab the last index in the sorted array and print it since it is the largest
    meanCalculateStudent = meanSumStudent / countStudents;
    cout << "Mean Student Wait time: " << meanCalculateStudent << endl;
    cout << "Longest Student Wait Time: "  << waitTimeArray[studentCounter-1] << endl;
    cout << "Students waiting over 10 minutes: " << greaterThan10Wait<< endl;

    cout << endl;

//fill the window idle array
  for (int i = 0; i < numOfWindows; ++i){

      windowIdleArray[i]= windowArray[i].idleTime ;
      //cout << windowIdleArray[i] << endl;
      meanSumIdle+= windowArray[i].idleTime;

      //counts how many windows are idle over 5 minutes
      if(windowArray[i].idleTime > 5){
        greaterThan5Idle++;
      }
  }

  meanIdle= meanSumIdle / numOfWindows;

  int k = sizeof(windowIdleArray) / sizeof(windowIdleArray[0]); //k required for the built in sort function
  sort(windowIdleArray, windowIdleArray + k); //sort the window iddle array

  cout << "Mean Window Idle Time: " << meanIdle << endl;
  cout << "Longest Window Idle Time: " << windowIdleArray[numOfWindows-1] << endl;
  cout << "Number of Windows Idle for over 5 mins " << greaterThan5Idle << endl;

}


//Checks if window array is empty
//returns 1 if it is not empty
bool Simulation::arrayCheck()
{
  for(int i = 0;i<numOfWindows;i++)
  {
    if(windowArray[i].isIdle() == 0)
      return 0;

  }
  return 1;
}

//Checks if window is idle and returns the index of where it is idle
//the previous function simply returns if it is empty or ot
//this functions returns the index of where it is empty
int Simulation::emptyIndex()
{
  for(int i = 0; i < numOfWindows; ++i)
  {
    if (windowArray[i].isIdle()){

      return i;
    }

  }
  return -1;
}


//Counts how long a window is idle
void Simulation::idleWindowCounter(){

  for(int i = 0; i < numOfWindows; ++i)
  {
    if (windowArray[i].isIdle()){

      windowArray[i].idleTime+=1;
    }

  }
}

//Counts how the wait time for each student and updates the arrival time for a student who is waiting
void Simulation::waitInQueueCounter(int time1)
{

//create a pointer to the studentQueue's front
  Student *std = studentQueue.front();
  int diff = time1 +1;
  int original = std->arrivalTime; //save the origina time of a student

if(std->arrivalTime < time1){ //if the arrival time is less than the current time then perofrm the following equation
    int temp= time1 - std->arrivalTime; //difference between current and arrival
    std->waitTimeQueue+=temp+1; //add temp to the wait time plus one becaue the arrival time will be temp plus one so it will have had to wait that extra minute
    std->arrivalTime+=temp+1;


  }
  else{ //if the arrival time is equal to the current time then do the following equation
    int temp = (time1- original) + original+ 1;
    std->waitTimeQueue+=1;
    std->arrivalTime=temp;
  }


}


//Decrements student time in a window.
void Simulation::timeNeededDecrement(){

  for(int i = 0; i < numOfWindows; ++i)
  {
    if (!windowArray[i].isIdle()){

      windowArray[i].student.timeNeededWindow -= 1;

    }}
}
