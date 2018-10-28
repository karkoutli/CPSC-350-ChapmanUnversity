#include <iostream>

using namespace std;
//simulation class to run the sorts
class SimulationClass{
public:

  SimulationClass();
  ~SimulationClass();
void  runSimulation(string file); //runs the sorts


//dymanic array pointers for the sorts
  double *arrayBubbleSort;
  double *arrayQuickSort;
  double *arrayInsertionSort;
  double *arraySelectionSort;
  int arraySize; //size of dynamic arrays

  void readFile(string fileName); //read file in correctly

//sort algorithms
  void quickSort(double arraySort[], int firstIndex, int endIndex); //referenced using the textbook and online resources
  double partionPoint(double arraySort[], int firstIndex, int endIndex); //used for quick sort to set the pivot or partion point
  void swap(double* a, double* b); //swap used for quicksort and selection sort
  void selectionSort(double array1[], int size); //selection sort referenced using code given in class + online resources 
  void insertionSort(double array1[], int size); //insertion sort referenced using the code given in class
  void bubbleSort(double array1[], int size); //simple sort algorithm based off code given in class

  string fileName1;


};
