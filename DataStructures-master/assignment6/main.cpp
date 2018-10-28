/*
Suleiman Karkoutli
ID: 2275013
karko101@mail.chapman.edu
CPSC-350-01
Assignment 6
*/
/*
The point of this assignment is to see how different sorting algorthims work and the impact of their runtimes. While they all peform the same job, some of them are complicated to implement than others,
but they offer better run times than the ones that have straight forward implementations.  
*/

#include <iostream>
#include <stdlib.h>
#include <array>
#include "runSorts.h"

using namespace std;
void theBubbleSort(double array1[], int size);

int main(int argc, char** argv){

  string file= " ";

if(argc > 1){
  if(strcmp( argv[1], "" ) !=0){ //ensures that the typed in value is not an empty space
file = argv[1];
SimulationClass s;
s.runSimulation(file);
}
else{ //if the user did type in an empty space then ask them for the file name
  cout << "You did not type in a file name. Please type it in: " << endl;
  cin >> file;
  SimulationClass s;
  s.runSimulation(file);
  }
}
else{ //if the user did not enter anything prompt the user for the file
  cout << "You did not type in the file name. Please type it in: " << endl;
  cin >> file;
  SimulationClass s;
  s.runSimulation(file);


}


return 0;
}
