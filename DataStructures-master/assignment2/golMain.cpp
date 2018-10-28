
/*
Karl Hickel
ID:2278978
CPSC 350-01
Assignment 2
hicke111@mail.chapman.edu
*/

/*
Suleiman Karkoutli
ID:: 2275013
CPSC 350-01
Assignment 2
karko101@mail.chapman.edu
*/
//We worked together as partners for this assignment

/*
This source file contains alll of the code needed for Assignment 2. Functions were created when needed.
The use of classes escaped us on this assignment and will not happen again. The purpose of this program is to either input a grid or create a grid
of Xs and -s and to simulate the game of life through the Classic, Donut, and Mirror modes. The program also prints the generations to
the console or writes the generations to a file.  
*/


#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
using namespace std;


//Global variables used throughout the project
char decision;
int row = 0;
int column = 0;
int numberIndex;
double densityProbability;
int numX;
int numMinus;
int counterA = 0;
int counterB = 0;
int counterC = 0;
int counterX = 0;
int randR = 0;
int randC = 0;
int counterAlive = 0;
int arrayCounter = 0;
int Decider = 1;
int counterGen = 1;
int Loopdy = 0;
int emptyCount = 0;
int fullCount = 0;
char Enter;
char gameMode= ' ';

string outFile = "output.txt";
ofstream writeFile(outFile);

int userChoice = 0;
int userChoice2 = 0;
int userChoice3 = 0;
int writeToFile= 0;
int microseconds = 2000000;

//Declared functions for the project
void fillGrid(char**& grid, int row, int column, char fill);
void printGrid(char**& grid, int row, int column);
void copyGrid(char **temp, char **grid, char **grid2);
void classicMode(int row, int column, char**& grid, char decision);
void createGrid(char**& grid, int row, int column, double densityProbability);
void mirrorMode(int row, int column, char**& grid, char decision);
void donutMode(int row, int column, char**& grid, char decision);
void outputFile(char**& grid, int row, int column);
void inputFile(char**& grid);
char **grid;




int main(){
  //initializing grid
  grid = new char*[row];

  for (int i = 0; i < row; ++i) {
    grid[i] = new char[column];
  }


//Prompt the user on which mode they'd like to do
cout << "Type c for classic mode. Type m for mirror mode. Type d for donut mode" << endl;
cin >> gameMode;
//Prompts the user on whether or not they want to create a grid or import one from a file.
cout << "Type 1 if you want to input a grid. Type 2 if you want to create a grid" << endl;
cin >> decision;
//User created grid
if (decision== '2'){
  cout << "How many rows would you like?" << endl;
  cin >> row;

  cout << "How many columns would you like?" << endl;
  cin >> column;

  cout << "How dense do you want your grid to be? (.01-.99)" << endl;
  cin >> densityProbability;

  if(gameMode == 'c'){
  classicMode(row, column, grid, decision);
}
else if(gameMode== 'm'){
  mirrorMode(row, column, grid, decision);

}
else if(gameMode=='d'){
  donutMode(row, column, grid, decision);

}

else{

  cout <<"You did not enter m or c" << endl;
}

}
//Imports a file for the grid
else if( decision == '1'){
    //inputs the grid from a file that is then passed into each mode
    inputFile(grid);


    if(gameMode == 'c'){
        classicMode(row, column, grid, decision);
        }
  else if(gameMode== 'm'){
        mirrorMode(row, column, grid, decision);

            }
    else if(gameMode=='d'){
      donutMode(row, column, grid, decision);


}

}
else{
  cout <<"You did not enter m or c" << endl;
}


cout << "The game is finished!" << endl;
return 0 ;}


//Imports a file
/*
Function Name: inputFile
no value returned
Parameters: grid
Inputs the file and converts it into a 2d array saved into grid.
*/
void inputFile(char**& grid){
  ifstream file;
  string fileName;
  string line= " ";
  int rowCounter=0;

  cout << "Please enter the text files name: ";
  cin>> fileName;

  file.open(fileName);

if(file.is_open()){

  getline(file, line);
  row = atoi(line.c_str());
  getline(file, line);
  column = atoi(line.c_str());


    for (int i = 0; i < row; ++i) {
      grid[i] = new char[column];
    }
//Displays row and columns to user.
cout << "row: "<<  row << " column: " << column << endl;
    for(int i=0; i < row; ++i){
      getline(file, line);
      cout << line <<  endl;
      for(int j=0; j < column; ++j){
        grid[i][j] = line[j];
      }
      }
  }
}


//Function for donut mode.
/*
Function Name: donutMode
no value returned
Parameters: row, column, grid, and decision
Runs the donut mode version of the game
*/
void donutMode(int row, int column, char**& grid, char decision){

  //Grid 2 is initialized within main.
  char **grid2 = new char*[row];
  for (int i = 0; i < row; ++i) {
    grid2[i] = new char[column];
  }
  if(decision == '2'){
  createGrid(grid,row,column,densityProbability);
}

  printGrid(grid, row, column);


  //Prompts user on whether or not they wish to write to file or console.
  cout << "Would you like to print to the console or to a file? (1 = console, 2 = file)" << endl;
  cin >> writeToFile;
  if(writeToFile == 1){
  cout << "Would you like to click enter to create a new generation or " << endl;
  cout << "do you want a timer.  (1 = enter, 2 = timer) " << endl;
    cin >> userChoice3;
}

//Begin game and check for each index based on the donut mode rules
  while(Decider == 1)
  {

  for(int i = 0; i < row; ++i)
  {
      for(int j = 0; j < column; ++j)
      {

        //Checks upper left corner and the cell positions around it based on the donut mode
        counterAlive = 0;
        if (i == 0 && j == 0)
        {
          if(grid[0][1] == 'X')
          {
            counterAlive++;
          }
          if(grid[1][1] == 'X')
          {
            counterAlive++;
          }
          if(grid[1][0] == 'X')
          {
            counterAlive++;
          }
          //Checks bottom right corner
          if(grid[row-1][column-1] == 'X')
          {
            counterAlive++;
          }
          //Checks top right corner.
          if(grid[0][column - 1] == 'X')
          {
            counterAlive++;
          }
          //Checks bottom left corner.
          if(grid[row-1][0] == 'X')
          {
            counterAlive++;
          }
          //Checks bottom right second column.
          if(grid[row-1][1] == 'X')
          {
            counterAlive++;
          }
          //Right side second row.
          if(grid[1][column -1 ] == 'X')
          {
            counterAlive++;
          }
        }


        //Checks the top right  corner
        else if (i == 0 && j == column - 1)
        {
          if(grid[0][column - 2] == 'X')
          {
            counterAlive++;
          }
          if(grid[1][column - 2] == 'X')
          {
            counterAlive++;
          }
          if(grid[1][column - 1] == 'X')
          {
            counterAlive++;
          }
          //Checks bottom left corner
          if(grid[row-1][0] == 'X')
          {
            counterAlive++;
          }
          //Top left corner
          if(grid[0][0] == 'X')
          {
            counterAlive++;
          }
          //Checks left second row
          if(grid[1][0] == 'X')
          {
            counterAlive++;
          }
          //Bottom right corner
          if(grid[row-1][column-1] == 'X')
          {
            counterAlive++;
          }
          //Bottom right corner second to last column
          if(grid[row-1][column-2] == 'X')
          {
            counterAlive++;
          }

        }
        //Checks the lower left corner
        else if (i == row - 1 && j == 0)
        {
          if(grid[row - 1][1] == 'X')
          {
            counterAlive++;
          }
          if(grid[row - 2][0] == 'X')
          {
            counterAlive++;
          }
          if(grid[row - 2][1] == 'X')
          {
            counterAlive++;
          }
          //Top right corner
          if(grid[0][column-1] == 'X')
          {
            counterAlive++;
          }
          //Bottom right corner
          if(grid[row-1][column-1] == 'X')
          {
            counterAlive++;
          }
          //Bottom right second to last row
          if(grid[row-2][column-1] == 'X')
          {
            counterAlive++;
          }
          //Top left corner
          if(grid[0][0] == 'X')
          {
            counterAlive++;
          }
          //Top row second index
          if(grid[0][1] == 'X')
          {
            counterAlive++;
          }

        }

        //checks the bottom right corner
        else if (i == row - 1 && j == column - 1)
        {
          if(grid[row - 2][column - 1] == 'X')
          {
            counterAlive++;
          }
          if(grid[row - 1][column - 2] == 'X')
          {
            counterAlive++;
          }
          if(grid[row - 2][column - 2] == 'X')
          {
            counterAlive++;
          }
          //Top left corner
          if(grid[0][0] == 'X')
          {
            counterAlive++;
          }
          //Top right corner
          if(grid[0][column-1] == 'X')
          {
            counterAlive++;
          }
          //Top right second to last
          if(grid[0][column-2] == 'X')
          {
            counterAlive++;
          }
          //Bottom left corner
          if(grid[row-1][0] == 'X')
          {
            counterAlive++;
          }
          //Second to last row left side.
          if(grid[row-2][0] == 'X')
          {
            counterAlive++;
          }

        }

        //checks the upper horizontal line (cells between the two corners)
        else if (i == 0)
        {
          if (grid[i][j-1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i][j+1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][j+1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][j] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][j-1] == 'X')
          {
            counterAlive++;
          }
          //bottom row.
          if(grid[row-1][j] == 'X')
          {
            counterAlive++;
          }
          if(grid[row-1][j+1] == 'X')
          {
            counterAlive++;
          }
          if(grid[row-1][j-1] == 'X')
          {
            counterAlive++;
          }


        }


        //Checks the left vertical line (cells between the upper left corner and bottom left corner)
        else if (j == 0)
        {

          if (grid[i-1][0] == 'X')
          {
            counterAlive++;
          }

          if (grid[i-1][1] == 'X')
          {
            counterAlive++;
          }

          if (grid[i][1] == 'X')
          {
            counterAlive++;
          }

          if (grid[i+1][1] == 'X')
          {
            counterAlive++;
          }

          if (grid[i+1][0] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][column-1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][column-1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i][column-1] == 'X')
          {
            counterAlive++;
          }
        }


        //checks the bottom horizontal line
        else if (i == row - 1)
        {
          if (grid[row-2][j] == 'X')
          {
            counterAlive++;
          }
          if (grid[row-1][j+1] == 'X')
          {
            counterAlive++;
          }
          if (grid[row-1][j-1] == 'X')
          {
            counterAlive++;
          }
          if (grid[row-2][j+1] == 'X')
          {
            counterAlive++;
          }
          if (grid[row-2][j-2] == 'X')
          {
            counterAlive++;
          }
          //Top row
          if(grid[0][j] == 'X')
          {
            counterAlive++;
          }
          if(grid[0][j+1] == 'X')
          {
            counterAlive++;
          }
          if(grid[0][j-1] == 'X')
          {
            counterAlive++;
          }

        }

        //checks the cells between the upper right and lower right corners
        else if (j == column - 1)
        {
          if (grid[i+1][column-1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][column-2] == 'X')
          {
            counterAlive++;
          }

          if (grid[i][column-2] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][column-2] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][column-1] == 'X')
          {
            counterAlive++;
          }

          //left column
          if (grid[i-1][0] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][0] == 'X')
          {
            counterAlive++;
          }
          if (grid[i][0] == 'X')
          {
            counterAlive++;
          }
        }


        //checks all of the cells that are not corners or sides (basically the middle cells)
        else
        {
          if (grid[i+1][j+1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][j-1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][j] == 'X')
          {
            counterAlive++;
          }
          if (grid[i][j+1] =='X')
          {
            counterAlive++;
          }
          if (grid[i][j-1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][j+1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][j] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][j-1] == 'X')
          {
            counterAlive++;
          }


        }
        //Assign grid2 its new values based on the counts and donut rules

        //if the counter is 0 then that means the particular cell had 0 neighbors with an X and thus dies
        if (counterAlive == 0)
        {
          grid2[i][j] = '-';
        }

        else if (counterAlive == 1)
        {
          grid2[i][j] = '-';
        }
        else if (counterAlive == 2)
        {
          grid2[i][j] = grid[i][j];

        }
        else if (counterAlive == 3)
        {
          grid2[i][j] = 'X';
        }
        else
        {
          grid2[i][j] = '-';
        }
  }
}

//bools that tests if the grid is empty or identical to the previous generation. If either condition is true the game is stopped
   bool isEmpty = true;
   bool isIdentical = true;
   if(writeToFile == 1){
   cout << "Press the ENTER key"; //press the enter key to continue generating the generations

}

//loop through grid2 and check if its either empty or equal to the previous generation
     for(int i = 0; i < row; ++i)
     {
       for(int j = 0; j < column; ++j)
       {
         if (grid2[i][j] != '-')
         {
           isEmpty = false;

         }
         if(grid2[i][j] != grid[i][j])
         {
           isIdentical = false;
         }
       }
     }

     //Breaks the program if either condition is met
     if(isEmpty || isIdentical)
     {
       Decider = 0;
     }
     //Allows the user to click enter to create new generations
     if (userChoice3 == 1)
     {
       cin.get();
     }
     //Prints new generations by a number of seconds. 2 to be exact.
     else if (userChoice3 == 2)
     {
       usleep(microseconds);
     }



     //Counts the number of generations.
    counterGen++;

  //purely printing out changed grid

     cout << "This is generation: " << counterGen << endl;

     //Makes the grids equal to each other.

    for(int i = 0; i < row; ++i)
     {
       for(int j = 0; j < column; ++j)
       {
         grid[i][j] = grid2[i][j];
       }
     }

     if(writeToFile == 1){
     printGrid(grid2, row, column);
   }

   else if(writeToFile == 2){

//writes the grid to a file output.txt
     writeFile << "grid: " << counterGen << endl;
         for (int i=0; i < row; i++){

           for (int j= 0; j < column; j++){
               writeFile << grid[i][j];

           }

           writeFile<< endl;

   }
   }
}
}



//Mirror mode.
/*
Function Name: mirrorMode
no value returned
Parameters: row, column, grid, and decision
Runs the mirror mode version of the game
*/
void mirrorMode(int row, int column, char**& grid, char decision){
char **grid2 = new char*[row];
  for (int i = 0; i < row; ++i) {
    grid2[i] = new char[column];
  }
  if(decision == '2'){ //if decision == 2 then create a random grid
  createGrid(grid,row,column,densityProbability);
}
  printGrid(grid, row, column);
  cout << "Would you like to print to the console or to a file? (1 = console, 2 = file)" << endl;
  cin >> writeToFile;
    if(writeToFile == 1){ // writeToFile == 1 then ask the user if they want to  hit enter to produce each generation or automatically generate them
  cout << "Would you like to click enter to create a new generation or " << endl;
  cout << "do you want a timer.  (1 = enter, 2 = timer) " << endl;
    cin >> userChoice3;
}
  //Start mirror mode
  while(Decider==1){
  for(int i = 0; i < row; ++i)
  {
      for(int j = 0; j < column; ++j)
      {
        counterAlive = 0;

        //Checks upper left corner
        if (i == 0 && j == 0)
        {
          if(grid[0][1] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if(grid[1][1] == 'X')
          {
            counterAlive++;
          }
          if(grid[1][0] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if(grid[0][0] == 'X'){
            counterAlive +=3;
          }
        }


        //checks upper right corner
        else if (i == 0 && j == (column - 1))
        {
          if(grid[0][column - 2] == 'X')
          {
            counterAlive+=2;//Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if(grid[1][column - 2] == 'X')
          {
            counterAlive++;
          }
          if(grid[1][column - 1] == 'X')
          {
            counterAlive+=2;//Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if(grid[0][column - 1] == 'X')
          {
            counterAlive+=3; //Add 3 because the cell is refelected on itself so therefore there are three X's around it
          }


        }
        //checks the lower left corner
        else if (i == row - 1 && j == 0)
        {
          if(grid[row - 1][1] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if(grid[row - 2][0] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if(grid[row - 2][1] == 'X')
          {
            counterAlive++;
          }
          if(grid[row - 1][0] == 'X')
          {
            counterAlive+=3; //Add 3 because the cell is refelected on itself so therefore there are three X's around it
          }

        }

        //checks the bottom right corner
        else if (i == row - 1 && j == column - 1)
        {
          if(grid[row - 2][column - 1] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if(grid[row - 1][column - 2] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if(grid[row - 2][column - 2] == 'X')
          {
            counterAlive++;
          }
          if(grid[row - 1][column - 1] == 'X')
          {
            counterAlive+=3; //Add 3 because the cell is refelected on itself so therefore there are three X's around it
          }

        }

        //checks the top horizontal row (the cells between the upper right and left corners)
        else if (i == 0)
        {
          if (grid[i][j] == 'X')
          {
            counterAlive=0;
          }
          if (grid[i][j-1] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if (grid[i][j+1] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if (grid[i+1][j+1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][j] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][j-1] == 'X')
          {
            counterAlive++;
          }


        }
        //checks the left vertical column (the cells between the upper left and bottom left corners)
        else if (j == 0)
        {
          if (grid[i][j] == 'X')
          {
            counterAlive++;
          }

          if (grid[i-1][0] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }

          if (grid[i-1][1] == 'X')
          {
            counterAlive++;
          }

          if (grid[i][1] == 'X')
          {
            counterAlive++;
          }

          if (grid[i+1][1] == 'X')
          {
            counterAlive++;
          }

          if (grid[i+1][0] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
        }

//checks the bottom row (the cells between the lower left and lower right corners)
        else if (i == row - 1)
        {
          if (grid[row-1][j] == 'X')
          {
            counterAlive++;
          }
          if (grid[row-2][j] == 'X')
          {
            counterAlive++;
          }
          if (grid[row-1][j+1] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if (grid[row-1][j-1] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if (grid[row-2][j+1] == 'X')
          {
            counterAlive++;
          }
          if (grid[row-2][j-1] == 'X')
          {
            counterAlive++;
          }

        }

//checks the right column (the cells between the upper right corner and lower right corner)
        else if (j == column - 1)
        {
          if (grid[i][column-1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][column-1] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
          if (grid[i+1][column-2] == 'X')
          {
            counterAlive++;
          }

          if (grid[i][column-2] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][column-2] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][column-1] == 'X')
          {
            counterAlive+=2; //Add 2 because the cell is refelected on itself so therefore there are two X's
          }
        }


        //checks all of the cells that are not corners or sides. Basically the middle cells
        else
        {
          if (grid[i+1][j+1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][j-1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i+1][j] == 'X')
          {
            counterAlive++;
          }
          if (grid[i][j+1] =='X')
          {
            counterAlive++;
          }
          if (grid[i][j-1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][j+1] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][j] == 'X')
          {
            counterAlive++;
          }
          if (grid[i-1][j-1] == 'X')
          {
            counterAlive++;
          }


        }
        //make the neccessary changes to the grid based on the counts
        if (counterAlive == 0)
        {
          grid2[i][j] = '-';
        }
        else if (counterAlive == 1)
        {
          grid2[i][j] = '-';
        }
        else if (counterAlive == 2)
        {
          grid2[i][j] = grid[i][j];
        }
        else if (counterAlive == 3)
        {
          grid2[i][j] = 'X';
        }
        else
        {
          grid2[i][j] = '-';
        }


  }
}

//checks if the generation is empty or if it is equal to the previous generation
   bool isEmpty = true;
   bool isIdentical = true;
   if(writeToFile == 1){
   cout << "Press the ENTER key";
 }



//loops through grid2 and checks if the cells are equal to the previous generation or is empty
     for(int i = 0; i < row; ++i)
     {
       for(int j = 0; j < column; ++j)
       {
         if (grid2[i][j] != '-')
         {
           isEmpty = false;

         }
         if(grid2[i][j] != grid[i][j])
         {
           isIdentical = false;
         }
       }
     }

     //if the grids are equal or if the grid2 is empty then break the program
     if(isEmpty || isIdentical)
     {
       Decider = 0;
     }
     if (userChoice3 == 1)
     {
       cin.get();
     }
     else if (userChoice3 == 2)
     {
       usleep(microseconds);
     }
    counterGen++;

  //purely printing out changed grid
     cout << "This is generation: " << counterGen << endl;

//updating grid with grid2's information (copying the information over)

    for(int i = 0; i < row; ++i)
     {
       for(int j = 0; j < column; ++j)
       {
         grid[i][j] = grid2[i][j];
       }
     }
    if(writeToFile == 1){ //print to console
     printGrid(grid2, row, column);
   }
   else if(writeToFile == 2){ //write to file

     writeFile << "grid: " << counterGen << endl;
         for (int i=0; i < row; i++){

           for (int j= 0; j < column; j++){
               writeFile << grid[i][j];

           }

           writeFile<< endl;
   }
   }
}
}

//Classic mode method
/*
Function Name: classicMode
no value returned
Parameters: row, column, grid, and decision
Runs the classic mode version of the game
*/
void classicMode(int row, int column, char**& grid, char decision){
  char **grid2 = new char*[row];
  for (int i = 0; i < row; ++i) {
    grid2[i] = new char[column];
  }

//creates random grid
  if(decision == '2'){
  createGrid(grid,row,column,densityProbability);
}
printGrid(grid, row, column);

//Prompt if the user wants to print to console or write to a file
cout << "Would you like to print to the console or to a file? (1 = console, 2 = file)" << endl;
cin >> writeToFile;
  if(writeToFile == 1){
cout << "Would you like to click enter to create a new generation or " << endl;
cout << "do you want a timer.  (1 = enter, 2 = timer) " << endl;
cin >> userChoice3;

}

//Run the classic mode version of the game
  while(Decider == 1)
  {
       for(int i = 0; i < row; ++i)
       {
           for(int j = 0; j < column; ++j)
           {
             counterAlive = 0;

             //checks the upper left corner
             if (i == 0 && j == 0)
             {
               if(grid[0][1] == 'X')
               {
                 counterAlive++;
               }
               if(grid[1][1] == 'X')
               {
                 counterAlive++;
               }
               if(grid[1][0] == 'X')
               {
                 counterAlive++;
               }
             }
             //checks the upper right corner
             else if (i == 0 && j == column - 1)
             {
               if(grid[0][column - 2] == 'X')
               {
                 counterAlive++;
               }
               if(grid[1][column - 2] == 'X')
               {
                 counterAlive++;
               }
               if(grid[1][column - 1] == 'X')
               {
                 counterAlive++;
               }

             }
             //checks the bottom left corner
             else if (i == row - 1 && j == 0)
             {
               if(grid[row - 1][1] == 'X')
               {
                 counterAlive++;
               }
               if(grid[row - 2][0] == 'X')
               {
                 counterAlive++;
               }
               if(grid[row - 2][1] == 'X')
               {
                 counterAlive++;
               }

             }

             //checks the bottom right corner
             else if (i == row - 1 && j == column - 1)
             {
               if(grid[row - 2][column - 1] == 'X')
               {
                 counterAlive++;
               }
               if(grid[row - 1][column - 2] == 'X')
               {
                 counterAlive++;
               }
               if(grid[row - 2][column - 2] == 'X')
               {
                 counterAlive++;
               }

             }
             //checks the upper horizantal row (basically the cells between the upper right and left corners)
             else if (i == 0)
             {
               if (grid[i][j-1] == 'X')
               {counterAlive++;}
               if (grid[i][j+1] == 'X'){
                 counterAlive++;
               }
               if (grid[i+1][j+1] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i+1][j] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i+1][j-1] == 'X')
               {
                 counterAlive++;
               }

             }


             //checks the left column (basically the cells between the upper and lower left corners)
             else if (j == 0)
             {

               if (grid[i-1][0] == 'X')
               {
                 counterAlive++;
               }

               if (grid[i-1][1] == 'X')
               {
                 counterAlive++;
               }

               if (grid[i][1] == 'X')
               {
                 counterAlive++;
               }

               if (grid[i+1][1] == 'X')
               {
                 counterAlive++;
               }

               if (grid[i+1][0] == 'X')
               {
                 counterAlive++;
               }
             }


             //checks the the bottom horizontal row (basically the cells between the lower left and right corners)
             else if (i == row - 1)
             {
               if (grid[row-2][j] == 'X')
               {
                 counterAlive++;
               }
               if (grid[row-1][j+1] == 'X')
               {
                 counterAlive++;
               }
               if (grid[row-1][j-1] == 'X')
               {
                 counterAlive++;
               }
               if (grid[row-2][j+1] == 'X')
               {
                 counterAlive++;
               }
               if (grid[row-2][j-2] == 'X')
               {
                 counterAlive++;
               }

             }

             //checks the right column (the cells between the upper right and lower right corners)
             else if (j == column - 1)
             {
               if (grid[i+1][column-1] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i+1][column-2] == 'X')
               {
                 counterAlive++;
               }

               if (grid[i][column-2] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i-1][column-2] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i-1][column-1] == 'X')
               {
                 counterAlive++;
               }
             }


             //checks the all of the cells that are corners or sides (basically the middle cells)
             else
             {
               if (grid[i+1][j+1] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i+1][j-1] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i+1][j] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i][j+1] =='X')
               {
                 counterAlive++;
               }
               if (grid[i][j-1] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i-1][j+1] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i-1][j] == 'X')
               {
                 counterAlive++;
               }
               if (grid[i-1][j-1] == 'X')
               {
                 counterAlive++;
               }


             }
             //Assigns the new changes to grid2
             if (counterAlive == 0)
             {
               grid2[i][j] = '-';
             }
             else if (counterAlive == 1)
             {
               grid2[i][j] = '-';
             }
             else if (counterAlive == 2)
             {grid2[i][j] = grid[i][j];}
            else if (counterAlive == 3)
             {grid2[i][j] = 'X';}
            else if(counterAlive >= 4 )
             {grid2[i][j] = '-';}
       }

     }

     cout << endl;
    //tests if the grid is equal to the previous generation or is empty
   bool isEmpty = true;
   bool isIdentical = true;
   if(writeToFile == 1){
   cout << "Press the ENTER key";
 }
    //loop through the new grid and check to see if its all empty or equal to the previous generation
     for(int i = 0; i < row; ++i)
     {
       for(int j = 0; j < column; ++j)
       {
         if (grid2[i][j] != '-')
         {
           isEmpty = false;

         }
         if(grid2[i][j] != grid[i][j])
         {
           isIdentical = false;
         }
       }
     }

     // if the grid is equal to the previous generation  or is empty end the game
     if(isEmpty || isIdentical)
     {
       Decider = 0;
     }
     if (userChoice3 == 1)
     {
       cin.get();
     }
     else if (userChoice3 == 2)
     {
       usleep(microseconds);
     }
    counterGen++;

  //purely printing out changed grid

     cout << "This is generation: " << counterGen << endl;

//copy over grid2 into grid
    for(int i = 0; i < row; ++i)
     {
       for(int j = 0; j < column; ++j)
       {
         grid[i][j] = grid2[i][j];
       }
     }
     if(writeToFile == 1){
      printGrid(grid2, row, column);
    }
    else if(writeToFile == 2){
      //write the generations to the a file output.txt
      writeFile << "grid: " << counterGen << endl;
          for (int i=0; i < row; i++){

            for (int j= 0; j < column; j++){
                writeFile << grid[i][j];

            }

            writeFile<< endl;
    }
    }
}
}


//Creates new grid
/*
Function Name: createGrid
no value returned
Parameters: grid, row , column, densityProbability
Takes user input for row, column and density and creates a grid that is saved to grid
*/
void createGrid(char**& grid, int row, int column, double densityProbability){
  //Random placement of X's.
  srand(time(NULL));
  double densityNumber= 0;
  densityNumber= densityProbability * 100;
  double randomNumber= rand() % 100;
    for (int i = 0; i < row; ++i) {
      grid[i] = new char[column];
    }

    for (int i=0; i < row; i++){
        //cout << "test3 " << endl;

       for (int j= 0; j < column; j++){
         double randomNumber= rand() % 100;
         if(randomNumber < densityNumber){
             grid[i][j]= 'X';
            }
     else{
       grid[i][j] = '-';

     }
   }
 }

}
//Prints new grid
/*
Function Name: printGrid
no value returned
Parameters: grid, row, column
Takes the grid, row and column and prints the grid to the console
*/
void printGrid(char**& grid, int row, int column){

  cout << "grid: " << endl;
      for (int i=0; i < row; i++){

        for (int j= 0; j < column; j++){

            //grid[i][j]='x';
            cout << grid[i][j];

        }

        cout<< endl;

}
}
//Copies grids.
/*
Function Name: copyGrid
no value returned
Parameters: temp, grid, grid2
Takes a temp pointer and copies over grid2 to grid and then saves grid's information into grid2
*/
void copyGrid(char **temp, char** grid, char**  grid2){

  temp= grid;
  grid = grid2;
  grid2= temp;
}
