#include <iostream>
#include "genstack.h"
using namespace std;

/*
Class Name: Checker
This class implements the checker.
It's method filechecker will take a file in and use a stack to see if there are any errors.
If there are errors it will use the print methods to print the errors and their locations/resolutions.
*/
class Checker{
public:
  Checker(); //constructor
  ~Checker();

  void fileChecker(string fileName);
  void print(int lineCounter, int charPos, char endChar,char foundChar);
  void printClosing(int lineCounter, int charPos, char openChar, char foundChar);
  void printNoErrors();
  void printEnd(char endChar);

};
