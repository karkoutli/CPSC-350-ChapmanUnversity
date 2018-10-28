#include <iostream>
#include "runSorts.h"
#include <fstream>
#include <string>
#include <ctime>
#include<stdio.h>


using namespace std;

SimulationClass::SimulationClass(){

  arrayBubbleSort=0;
  arrayQuickSort=0;
  arrayInsertionSort=0;
  arraySelectionSort=0;
  arraySize=0;
  fileName1= "sort.txt";


}

SimulationClass::~SimulationClass(){
//delete dynamically allocated memory
delete[] arrayBubbleSort;
delete[] arrayQuickSort;
delete[] arrayInsertionSort;
delete[] arraySelectionSort;
}

void SimulationClass::readFile(string fileName)
{
  ifstream file;
  string line = " ";
  int lineCounter=0;
 file.open(fileName1);


 //read file in and grab the first line in order to set the array size
    while(getline(file, line))
    {
      if(lineCounter==0)
      {
        arraySize= atof(line.c_str());

      }
      lineCounter++;
    }

//close file to reset pointer to top of file
    file.close();
    file.open(fileName1);
    lineCounter=0;
    int numCount=0;
    //set the size of the arrays
    arrayBubbleSort = new double[arraySize];
    arrayQuickSort = new double[arraySize];
    arrayInsertionSort = new double[arraySize];
    arraySelectionSort= new double [arraySize];
    for (int i=0; i < arraySize ; ++i)
    {
      arrayBubbleSort[i] = 0;
      arrayQuickSort[i]=0;
      arrayInsertionSort[i]=0;
      arraySelectionSort[i]=0;
    }

//set the values in array to 0
    while(getline(file, line))
    {

      if(lineCounter==0)
      {

      }
      else{ //grab the lines after the first line and set them equal to each respective array

          arrayBubbleSort[numCount] = atof(line.c_str());
          arrayQuickSort[numCount]= atof(line.c_str());
          arrayInsertionSort[numCount]= atof(line.c_str());
          arraySelectionSort[numCount]= atof(line.c_str());
          numCount++; //increase the index counter for the arrays essentially for looping through the array

      }
      lineCounter++; //increase line counter

    }


}

void SimulationClass::runSimulation(string file)
{
fileName1= file;
readFile(fileName1);


//timing and printing of sorts
cout << endl;
cout << "------Bubble Sort----------------------" << endl;
clock_t begin = clock();
bubbleSort(arrayBubbleSort, arraySize);
clock_t end = clock();
for (int i=0; i < arraySize ; i++)
{
    cout << " "<< arrayBubbleSort[i] << " " ;

}
cout << endl;

  double seconds = double(end - begin) / CLOCKS_PER_SEC * 1000;

  cout <<"Time it took: " <<seconds  << " milliseconds"<< endl;
  cout << endl;


cout << "-------Quick Sort------------------------" << endl;
  int left= arraySize-1;
    clock_t begin2 = clock();
    quickSort(arrayQuickSort, 0, left);
    clock_t end2 = clock();
    double seconds2 = double(end2 - begin2) / CLOCKS_PER_SEC * 1000;
    for (int i=0; i < arraySize ; i++)
    {
      cout << " "<< arrayQuickSort[i] << " " ;
    }
    cout << endl;
  cout <<"Time it took: " <<seconds2  << " milliseconds"<< endl;
  cout << endl;

cout << "------Selection Sort----------------------" << endl;
clock_t begin3 = clock();
selectionSort(arraySelectionSort, arraySize);
clock_t end3 = clock();
double seconds3 = double(end3 - begin3) / CLOCKS_PER_SEC * 1000;
for (int i=0; i < arraySize ; i++)
{
  cout << " "<< arraySelectionSort[i] << " " ;
}
  cout << endl;
  cout <<"Time it took: " <<seconds3 << " milliseconds"<< endl;
  cout << endl;


  cout << "------Insertion Sort----------------------" << endl;
  clock_t begin4 = clock();
  insertionSort(arrayInsertionSort, arraySize);
  clock_t end4 = clock();
  double seconds4 = double(end4 - begin4) / CLOCKS_PER_SEC * 1000;
  for (int i=0; i < arraySize ; i++)
  {
    cout << " "<< arrayInsertionSort[i] << " " ;
  }
    cout << endl;
    cout <<"Time it took: " <<seconds3 << " milliseconds"<< endl;
      cout << endl;

}


//sorting algorithims

void SimulationClass::insertionSort(double array1[], int size)
{ //code referenced from class + Geeeks for geeks (needed to modify it  a bit)
  int i= 0;
  int temp = 0;
  int k= 0;

  for(i = 1; i < size; ++i){

    double temp = array1[i];
    k= i-1;

    while(k >=0 && array1[k] > temp)
    {
      array1[k+1] = array1[k];
      --k;
    }
    array1[k+1] = temp;
  }


}

void SimulationClass::selectionSort(double array1[], int size){ //code referenced from class + Geeks from geeks (needed to modify it a bit)
  int i= 0;
  int j= 0;
  int minIndex= 0;
  int tmp = 0;

  for (i= 0; i<size-1; ++i){
    minIndex=i;
    for(j=i+1; j< size; ++j){
      if(array1[j] < array1[minIndex]){
            minIndex=j;
      }
    }
    swap(&array1[minIndex],&array1[i]);

  }
}


void SimulationClass::bubbleSort(double array1[], int size) //bubble sort implemented in class
{

for (int i = 0; i < size; ++i)
{
  double temp = 0;

  for(int j = 0; j < size - 1; ++j)
  {
      if(array1[j] > array1[j+1])
      {
        temp = array1[j+1];
        array1[j+1] = array1[j];
        array1[j] = temp;

      }

    }

  }

}


double SimulationClass::partionPoint(double arraySort[], int firstIndex, int endIndex) //used to find the pivot and sort the data accordingly by putting lower date below the pivot and larger data above the pivot
{
  int  pivot = firstIndex; //set the pivot start
  int pivotIndex = arraySort[firstIndex]; //set the pivot value

    for(int j = firstIndex+1 ; j <= endIndex ; j++)
    {

        if(arraySort[j] <=pivotIndex)
        {
            pivot++;
            swap(&arraySort[j], &arraySort[pivot]); //using the pivot to sort sections of the array
        }
    }

    swap(&arraySort[pivot], &arraySort[firstIndex]); //swapping values to sort them in the right order

    return pivot;
}


void SimulationClass::quickSort(double arraySort[], int firstIndex, int endIndex)
{
  int pivotIndex=0;
  int newPartitionEnd= 0;
  int newPartitionStart =0;

   if(firstIndex > endIndex) //tales in first index and endindex of array to start the sort
   {
     //input error handling
     //dont do anything, if firstindex is ever greater than end index than there is an error and do not continue on with the sort
   }
   else{
     pivotIndex = partionPoint(arraySort, firstIndex, endIndex); //creates the pivot point to be used in sorting the array before and after the pivot
     newPartitionEnd= pivotIndex-1;
      newPartitionStart= pivotIndex+1;
     quickSort(arraySort, firstIndex, newPartitionEnd);
     quickSort(arraySort, newPartitionStart, endIndex);
   }

}

//used for quicksort and selection sort
void SimulationClass::swap(double* x, double* y) //used for swapping values in quick sort to arrange them in the correct order
{
    double  temp = *x;
    *x = *y;
    *y = temp;
}
