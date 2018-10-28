/*
Suleiman Karkoutli
ID: 2275013
karko101@mail.chapman.edu
CPSC-350-01
Assignment 4
*/

/*
Karl Hickel
ID: 2278978
hicke111@mail.chapman.edu
CPSC-350-01
Assignment 4
*/

/*
This source file contains the main method which calls the simulation file which then calls the queue and the needed functions
The DoubleLinkedList class was created using the code given in class and modified to create a templated interface which was then created to make a queue
The purpose of this program is accept an input file as text file and then conduct a simulation of students waiting in line. At the end some simple stat analysis is printed
out to the console so decisions can be made regarding the efficncy of the registrar's office.
*/

#include <iostream>
//#include "doubleLinkedList.h"
//#include "queue.h"
#include <fstream>
#include <stdlib.h>
#include "simulation.h"

using namespace std;

int main(int argc, char** argv){

string fileName= " ";

//Prompts user to type in file name.

if (argc >1 ){

    fileName= argv[1];

    if(fileName == " "){
    cout << "Please type a file name in : " << endl;
    cin>>fileName;
  }


//create a new instance of simulation
Simulation s;
//Function in simulation that reads and stores file objects
s.fileReader(fileName);
//Runs the full simulation.
s.runProgram();

}
else{

  cout << "Please type a file name in: " << endl;
  cin>>fileName;
  //create a new instance of simulation
  Simulation s;
  //Function in simulation that reads and stores file objects
  s.fileReader(fileName);
  //Runs the full simulation.
  s.runProgram();

}

  return 0;
}
