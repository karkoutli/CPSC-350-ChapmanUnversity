/*
Karl Hickel
ID: 2278978
hicke111@mail.chapman.edu
CPSC-350-01
Assignment 5
*/


/*
Suleiman Karkoutli
ID: 2275013
karko101@mail.chapman.edu
CPSC-350-01
Assignment 5
*/

/*
The purpose of this program is make a data base for students and faculty members of a school. Students can be added, deleted, and attached to Faculty members as needed.
Faculty members can be added, deleted, and students can be assigned to them as needed.
This source file contains the main method whichs calls the run method in the simulation class which then uses
the the BST.h to create two BSTs for student and faculty databases. The doubleLinkedList.h is used for the list of student ids in the Faculty class.
*/

#include <iostream>
#include "simulation.h"
using namespace std;

int main()
{
simulation s;
s.run();
cout << endl;

  return 0;
}
