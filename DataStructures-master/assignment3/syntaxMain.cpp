/*
Suleiman Karkoutli
ID: 2275013
karko101@mail.chapman.edu
CPSC-350-01
Assignment 3
*/

/*
This source file contains the main method which calls the checker file and implements the stack.
The genstack class was created using the code given in class and modified (added a resize function) accordingly.
The purpose of this program is accept an input file as a text or .cpp and to check if there are any errors in the file.
The program then alerts the user if they have any errors. If they do have errors it tells the user the location and what to fix.
*/

#include <iostream>
#include "checker.h"

using namespace std;

int main(int argc, char** argv){
string file= " ";
if (argc > 1){
  file= argv[1];
Checker check; //call the checker class and the function file checker to begin the program. 
check.fileChecker(file);
}
else{ //if the user did not input anything as an argument then ask them to type it in.
  cout << "You did not type in the file name. Please type it in: " << endl;
  cin >> file;
  Checker check;
  check.fileChecker(file);

}
  return 0;
}
