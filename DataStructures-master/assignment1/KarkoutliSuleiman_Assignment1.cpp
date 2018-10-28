/*
Suleiman Karkoutli
ID: 2275013
karko101@mail.chapman.edu
CPSC-350-01
Assignment 1
*/

/*
This source file contains all of the code for the assigment.
Functions were created when needed. The purpose of this program is accept
an input file that contains DNA strings. The program then analyzes the DNA Strings
and summarizes the results in an output file.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

//declare standard deviation and variance variables
double standardD1;
double variance1;
const double PI= 3.14159265359;
char decision = 'y';

//declare and initialize the global variables
string stringLine = " ";
double countLine; double sumOfChars; int startIndex = 0; int sumOfLine=0;
int intTrue= 1; string line=""; int foundIndex=0; double meanResult=0; double topPart=0; double sumOfTop= 0;

//declare and initialize the global variables for each nucleotide/bigram count and probability
char charC= 'C'; char charA= 'A'; char charT= 'T'; char charG= 'G';
int countC=0; int countA=0; int countT=0; int countG=0;

double probC=0; double probA=0; double probT=0; double probG=0;

double probAT=0;double probAA=0; double probAC=0; double probAG=0;
double probTT=0; double probTA=0; double probTC=0; double probTG=0;
double probCT=0; double probCA=0; double probCC=0; double probCG=0;
double probGT=0; double probGA=0; double probGC=0; double probGG=0;

string AT= "AT"; string AA= "AA"; string AC= "AC"; string AG = "AG";
string TA = "TA"; string TT = "TT"; string TC = "TC"; string TG = "TG";
string CA = "CA"; string CT = "CT"; string CC = "CC"; string CG = "CG";
string GA = "GA"; string GT = "GT"; string GC = "GC"; string GG = "GG";

int countAT=0; int countAA=0; int countAC=0; int countAG=0;
int countTA=0;int countTT=0; int countTC=0; int countTG=0;
int countCA=0;int countCT=0; int countCC=0; int countCG=0;
int countGA=0; int countGT=0; int countGC=0; int countGG=0;


//Function declarations
double sumCharMinusMeanSquared(int sumOfLine , double meanResult);
int countNucleotide(string line, char letter, int i, int counter);
int countBigram(string line, int foundIndex, int startIndex, int counter, string bigram);
double variance(double sumOfToptopPart, double countLine);
double standardD(double variance1);
double mean(double sumOfChars, double countLine);
double nucleotideProb(int count, double sumOfChars);
double bigramProb(int count, double sumOfChars, double countLine);
string newLine(double numA, double numT, double numC, double numG, double randomNumber);
double equationC();
int equationD(double c, double standardD1, double meanResult);
void reset();

int main(int argc, char** argv){

  srand(time(NULL)); //seed for random numbers

  if (argc > 1){ //check to see if an input file was typed if so then continue the program

    string fileName= argv[1]; //grab the input file typed name and assign it to a variable
    ifstream file;
    string outFile = "suleimankarkoutli.out.txt";
    ofstream writeFile(outFile);

    //write to the output file
    writeFile<< "Suleiman Karkoutli" << endl;
    writeFile << "ID: 2275013" << endl;
    writeFile << "Assignment 1" << endl;
    writeFile << endl;

  while(tolower(decision) == 'y'){ //main loop that keeps looping the program
    file.open(fileName); //open the specific file

    while(getline(file,line)){ //using the getline function to get the line in the file
      countLine++;
      sumOfLine= 0; //total number of chars in a line

      //count each character in the line
      for(int i=0; i < line.size(); ++i){
        sumOfChars++; //total number of chars in the file
        sumOfLine++;
        countC= countNucleotide(line, charC, i, countC);
        countT= countNucleotide(line, charT, i, countT);
        countA= countNucleotide(line, charA, i, countA);
        countG= countNucleotide(line, charG, i, countG);
      }

    writeFile << line << " - sum of line: " << sumOfLine << endl;

    //call count function for the bigrams
    countAT= countBigram(line,foundIndex,startIndex, countAT, AT);
    countAA= countBigram(line, foundIndex, startIndex, countAA, AA);
    countAC= countBigram(line, foundIndex, startIndex, countAC, AC);
    countAG= countBigram(line, foundIndex, startIndex, countAG, AG);

    countTT= countBigram(line, foundIndex, startIndex, countTT, TT);
    countTA= countBigram(line, foundIndex, startIndex, countTA, TA);
    countTC= countBigram(line, foundIndex, startIndex, countTC, TC);
    countTG= countBigram(line, foundIndex, startIndex, countTG, TG);

    countCT= countBigram(line, foundIndex, startIndex, countCT, CT);
    countCA= countBigram(line, foundIndex, startIndex, countCA, CA);
    countCC= countBigram(line, foundIndex, startIndex, countCC, CC);
    countCG= countBigram(line, foundIndex, startIndex, countCG, CG);

    countGT= countBigram(line, foundIndex, startIndex, countGT, GT);
    countGA= countBigram(line, foundIndex, startIndex, countGA, GA);
    countGC= countBigram(line, foundIndex, startIndex, countGC, GC);
    countGG= countBigram(line, foundIndex, startIndex, countGG, GG);


        }


        meanResult = mean(sumOfChars, countLine);

        //call probability function for each nucleotide/bigram
        probA= nucleotideProb(countA, sumOfChars);
        probC= nucleotideProb(countC, sumOfChars);
        probT= nucleotideProb(countT, sumOfChars);
        probG= nucleotideProb(countG, sumOfChars);

        probAT= bigramProb(countAT,sumOfChars,countLine);
        probAC= bigramProb(countAC,sumOfChars,countLine);
        probAG= bigramProb(countAG,sumOfChars,countLine);
        probAA= bigramProb(countAA,sumOfChars,countLine);

        probTT= bigramProb(countTT,sumOfChars,countLine);
        probTC= bigramProb(countTC,sumOfChars,countLine);
        probTG= bigramProb(countTG,sumOfChars,countLine);
        probTA= bigramProb(countTA,sumOfChars,countLine);

        probCT= bigramProb(countCT,sumOfChars,countLine);
        probCC= bigramProb(countCC,sumOfChars,countLine);
        probCG= bigramProb(countCG,sumOfChars,countLine);
        probCA= bigramProb(countCA,sumOfChars,countLine);

        probGT= bigramProb(countGT,sumOfChars,countLine);
        probGC= bigramProb(countGC,sumOfChars,countLine);
        probGG= bigramProb(countGG,sumOfChars,countLine);
        probGA= bigramProb(countGA,sumOfChars,countLine);

        //Close file so that standard D and variance can be calculated.
        //Right now the loop will not work as the program is at the end of the file
        file.close();

        //open file again so that program can loop from the beginning of the file
        file.open(fileName);



        while(getline(file,line)){ //loop through the file again
            sumOfLine= 0;
          for(int i=0; i < line.size(); ++i){
            sumOfLine++;
          }
          //top part of the variance equation
          topPart = sumCharMinusMeanSquared(sumOfLine, meanResult); //sum of chars in a specific line minus the mean squared
          sumOfTop= sumOfTop + topPart; //add the previous calculation (top half of variance equation) to a running total


        }
        //calcualte variance & standard deviation
        variance1= variance(sumOfTop, countLine);
        standardD1= standardD(variance1);

        //write summary stats to the output file

        writeFile << endl;
        writeFile << "Sum of all characters: "<< sumOfChars << endl;
        writeFile << "Number of lines in the file: " << countLine << endl;
        writeFile << "Mean: " << meanResult << endl;
        writeFile  << "Variance: " << variance1 << endl;
        writeFile << "Standard Deviation: " <<standardD1 << endl;

        writeFile <<  " " << endl;

        writeFile << "Count of C: " <<countC << "  Probability: " <<probC * 100 << "%" <<endl;
        writeFile << "Count of G: " <<countG << "  Probability: " <<probG * 100 << "%" <<endl;
        writeFile << "Count of T: " <<countT << "  Probability: " <<probT * 100 << "%" << endl;
        writeFile << "Count of A: " <<countA << " Probability: " <<probA * 100 << "%" << endl;

        writeFile <<  endl;

        writeFile << "Count of AT: "<< countAT <<" Probability: " << probAT * 100 << "%" <<endl;
        writeFile << "Count of AA: "<< countAA <<" Probability: " << probAA * 100 << "%" << endl;
        writeFile << "Count of AC: "<< countAC <<" Probability: " << probAC * 100 << "%" << endl;
        writeFile << "Count of AG: "<< countAG <<" Probability: " << probAG * 100 << "%" << endl;
        writeFile <<endl;

        writeFile  << "Count of TT: "<< countTT << "  Probability: " << probTT * 100 << "%" << endl;
        writeFile  << "Count of TA: "<< countTA << "  Probability: " << probTA * 100 << "%" <<  endl;
        writeFile  << "Count of TC: "<< countTC << "  Probability: " << probTC * 100 << "%" << endl;
        writeFile << "Count of TG: "<< countTG << "  Probability: " << probTG  * 100 << "%" << endl;

        writeFile <<endl;

        writeFile  << "Count of CT: "<< countCT << "   Probability: " << probCT * 100 << "%" << endl;
        writeFile  << "Count of CA: "<< countCA << "   Probability: " << probCA * 100 << "%" << endl;
        writeFile  << "Count of CC: "<< countCC << "   Probability: " << probCC * 100 << "%" << endl;
        writeFile  << "Count of CG: "<< countCG << "   Probability: " << probCG * 100 << "%" << endl;

        writeFile <<endl;

        writeFile  << "Count of GT: "<< countGT << " Probability: " << probGT * 100 << "%"  << endl;
        writeFile  << "Count of GA: "<< countGA << " Probability: " << probGA * 100 << "%" << endl;
        writeFile  << "Count of GC: "<< countGC << " Probability: " << probGC * 100 << "%" << endl;
        writeFile  << "Count of GG: "<< countGG << " Probability: " << probGG * 100 << "%" << endl;

        writeFile << endl;

        //create the 1000 new strings
        writeFile<< "1000 Strings: " << endl;

        //declare the local variables needed
        double c=0;
        int d= 0;
        //convert decimal probability into full numbers
        double numA= probA * 100;
        double numT= probT * 100;
        double numC= probC * 100;
        double numG= probG * 100;

        int counterLines; //keeps track of number of lines generated
        int j = 0;

  while ( j < 1000){
      //calculate the Gaussian distrubution using the c & d equations
      c= equationC();
      d= equationD(c, standardD1, meanResult);

      //if d is less than 1 (example: 0.7) then round up to length of 1
      if (d < 1) {
        d= 1;
      }

        stringLine= " "; //reset string for every iteration
        for (int i = 0; i < d; ++i) {
          double randomNumber= rand() % 100; //number between 0-100
          stringLine+= newLine(numA, numT, numC, numG,randomNumber); //call the new line function
      }
      counterLines++;
      writeFile  << counterLines  << stringLine << endl;
      j = j+ 1;
  }
    file.close(); //deallocate memory and close the file


  cout << "Would you like to process another list? (type y/n)";
  cin >> decision;
  if (tolower(decision) == 'y'){
    cout << "Please enter the new file's name: ";
    cin >> fileName;
    writeFile<< endl;
    writeFile << "New File info: " << endl;
    reset(); //reset the variables so that they can used again for the new iteration
    counterLines=0; //reset the count to 0
  }

}

}
  else {
    cout << "Enter correct file name" << endl;
  }

return 0;
}

/*
Function Name: reset
No values returned
No parameters
No exceptions thrown
The function essentially resets the global variables before they are used again
*/
void reset(){

  countLine=0; sumOfChars=0; startIndex=0; sumOfLine=0; string line= ""; foundIndex=0;
  meanResult=0; topPart=0; sumOfTop=0; countC=0; countA=0; countT=0; countG=0;
  probC=0; probA=0; probT=0; probG=0; probCT=0; probCA=0; probCC=0;
  probCG=0; probGT=0; probGA=0; probGC=0; probGG=0; countAT=0; countAA=0;
  countAC=0; countAG=0; countTA=0; countTT=0; countTC=0; countTG=0; countCA=0; countCT=0;
  countCC=0; countCG=0; countGA=0; countGT=0; countGC=0; countGG=0;

}

/*
Function Name: equationC
Double value returned
No parameter
No exceptions thrown
The function essentially calculates equation C used in the Gaussian distrubution
*/
double equationC(){
  double c;
  double randomC= (double) rand() / RAND_MAX;
  double randomA= (double) rand() / RAND_MAX;
  double randomB= (double) rand() / RAND_MAX;

  return c= sqrt(-2 * log(randomA))* cos(2 * PI  * randomB);
}

/*
Function Name: equationD
Int value returned
Parameters: value from the c function, standard deviation, and mean
No exceptions thrown
The function essentially calculates equation D which is used as the lemgth of the new line
*/

int equationD(double c, double standardD1, double meanResult){
  int d;
  d= (standardD1 * c) + meanResult;
  return d;
}
/*
Function Name: newLine
string value returned
Parameters: numA, numT, numC, numG which are the probabilities
times 100 and the randomNumber generated
No exceptions thrown
The function essentially generates the new line given the following probabiltiies and random number
*/
string newLine(double numA, double numT, double numC, double numG, double randomNumber){
  double aPlusT= numA+ numT;
  double tPlusC= aPlusT+ numC;
  double cPlusG= tPlusC + numG;
  string stringLine;
  //random number is between 0-100
  if (randomNumber <= numA) {
    //if the random number is less than or equal to A then the letter is an A
    return stringLine+= "A"; //append string
  }
  else if ( randomNumber > numA && randomNumber <= aPlusT){
    //If the rand num is greater than A but is less than or equal to the sum of  A+T then the letter is a T
    return stringLine+=  "T";
  }

  else if(randomNumber > aPlusT && randomNumber <= tPlusC){
    //If the rand num is greater than A+T but is less than or equal to T + C then the letter is a C

    return stringLine+= "C";
  }
  else if(randomNumber > tPlusC && randomNumber <= cPlusG){
    //If the rand num is greater than T+C but is less than or equal to C+G then the letter is a G
    return stringLine += "G";
  }
  return stringLine;
  }
  /*
  Function Name: sumCharMinusMeanSquared
  double value returned
  Parameters: sumOfLine, meanResult
  No exceptions thrown
  The function calculates the top half of the variance equation (sum of chars in a line - mean squared)
  */
double sumCharMinusMeanSquared(int sumOfLine, double meanResult) {
  double result = pow(sumOfLine - meanResult, 2);
  return result;
}

/*
Function Name: variance
double value returned
Parameters: sumOfTopPart, countLine
No exceptions thrown
The function calculates the variance by taking the sum of the result of the previous function
and dividing it by the total number of lines in the file
*/
double variance(double sumOfTopPart, double countLine){
  double result = sumOfTopPart / countLine;
  return result;

}
/*
Function Name: standardD
double value returned
Parameters: variance1
No exceptions thrown
Takes the value generated by the variance function and square roots it to get the standard deviation
*/
double standardD(double variance1){
  double result = sqrt(variance1);
  return result;
}

/*
Function Name: mean
double value returned
Parameters: sumOfChars, countLine
No exceptions thrown
Calculates mean by taking total sum of chars divided by total number of lines in the file
*/
double mean(double sumOfChars, double countLine){
  double results = sumOfChars / countLine;
  return results;
}

/*
Function Name: nucelotideProb
double value returned
Parameters: count, sumOfChars
No exceptions thrown
Calculates the probability of each nucleotide
*/
double nucleotideProb(int count, double sumOfChars){
  double results= count / sumOfChars;
  return results;
}
/*
Function Name: bigramProb
double value returned
Parameters: count, sumOfChars, countLine
No exceptions thrown
Calculates the probability of each bigram by taking the total number of a specific Bigram and
divides it by sum of total chars minus total lines in the file. The reason being is that one has
to minus each line's length by one to get the total number of bigrams on that line. If one sums
all of the characters in the file and minuses it by the total number of lines this also is equivalent to total bigrams.
*/
double bigramProb(int count, double sumOfChars, double countLine){
  double results= count / (sumOfChars - countLine);
  return results;
}

int countNucleotide(string line, char letter, int i, int counter){

if(toupper(line[i]) == letter){ //maybe make this a function
  counter++;
  }
  return counter;
}

/*
Function Name: countBigram
int value returned
Parameters: line, foundIndex, startIndex, counter, bigram
No exceptions thrown
Calculates the count of each bigram by finding one instance of the bigram and
then adds one to the start index to find the rest of the instances
*/
int countBigram(string line, int foundIndex, int startIndex, int counter, string bigram){
  //create a new variable s to store the newly formatted uppercase line
  string s;
  for (int i = 0; i < line.size(); i++) {
    s += toupper(line[i]);
  }
  while(intTrue){

  foundIndex= s.find(bigram,startIndex);
  startIndex = foundIndex + 1; //increase the start index by 1 to search for the other instances

  if(foundIndex != -1){ //if the index is found add 1 to the counter
    counter ++;
  }
  else {
    break;
  }
}
  return counter;
}
