#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>


using namespace std;

class Simulation
{
public:

  Simulation();
  ~Simulation();

  void classicMode();
  void donutMode();
  void mirrorMode();
  void printGrid();
  void swap();
  char** grid;
  char** grid2;
  int uperLeftCorner(int i, int j);
  int uperRightCorner();
  int lowerRightCorner();
  int lowerLeftCorner();
  int upperRow();
  int lowerRow();
  int rightColumn();
  int leftColumn();






};
