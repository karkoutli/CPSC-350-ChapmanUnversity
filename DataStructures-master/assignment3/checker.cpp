#include <iostream>
#include "checker.h"
#include <fstream>
using namespace std;
//the constructor
Checker::Checker(){

}
// the destructor
Checker::~Checker(){

}

/*
Function Name: print
no value returned
Parameters: int lineCounter, int charPos, char openChar, char foundChar
No exceptions thrown
This print function prints out where the mistmatch error occurs and which closing delimiter it needs to fix the error
*/
void Checker::print(int lineCounter, int charPos, char endChar, char foundChar){
  cout << "Error on line " << lineCounter << " at position "<< charPos<< " Found: '"<<foundChar<< "' when it was supposed to be a '" << endChar << "'" << endl;

}
/*
Function Name: printClosing
no value returned
Parameters: int lineCounter, int charPos, char openChar, char foundChar
No exceptions thrown
This print function prints out where the closing bracket error occurs and which opening delimiter it needs to fix the error
*/
void Checker::printClosing(int lineCounter, int charPos, char openChar, char foundChar){
  cout << "Error on line " << lineCounter << " at position "<< charPos<<" " << foundChar<< " Needs an opening  '" << openChar <<"'"<< endl;
}
/*
Function Name: printNoErrors
no value returned
Parameters: none
No exceptions thrown
This print function prints out that there were no errors in the file
*/
void Checker::printNoErrors(){
  cout << "There were no errors in the file. Have a nice day!" << endl;
}
/*
Function Name: printEnd
no value returned
Parameters: char endChar
No exceptions thrown
This print function prints out when there is an end of line error and prints out the missing end char
*/
void Checker::printEnd(char endChar){
  cout << "End of line error. Missing '" << endChar << "'" << endl;
}
/*
Function Name: fileChecker
no value returned
Parameters: string fileName
No exceptions thrown
Takes a text or .cpp file and checks if there are any syntax errors and
then calls other methods to print the location of the errors
*/
void Checker::fileChecker(string fileName){
    GenStack<char> stack1(8); //set the stack size to an arbitruary size since the stack size can be changed if more space is needed
    ifstream file;
    string line = " ";
    int lineCounter=0;
    int charPos=0; //character position
    file.open(fileName);
    int control=0;
    char endChar = ' ';
    char foundChar= ' ';
    char openChar= ' ';



    while(getline(file, line)){ //iterate through the text file or cpp
      lineCounter++;
      charPos=0;

      //iterate through each line
      for(int i=0; i < line.size(); ++i){

        charPos++;

        //push opening braces into the stack
        if((line[i] == '{')|| (line[i]=='(') || (line[i]=='[')){
          stack1.push(line[i]);
        }
        //If there are no errors then pop each brace pair
        if (line[i]== '}' && stack1.peek()=='{'){
          stack1.pop();
        }
        else if( line[i]== ')' &&  stack1.peek()== '('){
          stack1.pop();
        }
        else if(line[i]== ']' && stack1.peek()== '['){
          stack1.pop();
        }
          //check if there are mismatches with the pairs and print the error
        else if (stack1.peek()=='(' && line[i]== '}'){
          //pass in the correct end char and the found error
          endChar= ')'; foundChar='}'; control = 1; //control=1 will break with the loop
          print(lineCounter, charPos, endChar, foundChar);
          break;
        }
        else if (stack1.peek()=='(' && line[i]== ']'){
          endChar= ')'; foundChar=']'; control = 1;
          print(lineCounter, charPos, endChar, foundChar);
          break;
        }
        else if (stack1.peek()=='{' && line[i]== ')'){
          endChar= '}'; foundChar=')'; control = 1;
          print(lineCounter, charPos, endChar, foundChar);
          break;
        }
        else if (stack1.peek()=='{' && line[i]== ']'){
          endChar= '}'; foundChar= ']'; control = 1;
          print(lineCounter, charPos, endChar, foundChar);
          break;

        }
        else if (stack1.peek()=='[' && line[i]== '}'){
          endChar= ']'; foundChar='}'; control = 1;
          print(lineCounter, charPos, endChar, foundChar);
          break;
        }
        else if (stack1.peek()=='[' && line[i]== ')'){
        endChar= ']'; foundChar=')'; control= 1;
        print(lineCounter, charPos, endChar, foundChar);
        break;
        }

        //check if there any closing braces that do not correspond to an opening brace
        else if(stack1.isEmpty() && line[i]== ']'){
          foundChar= line[i];
          openChar= '[';
          control=1;
          printClosing(lineCounter, charPos, openChar, foundChar);

        }
        else if(stack1.isEmpty() && line[i]== '}'){
            foundChar= line[i]; openChar= '{'; control=1;
            printClosing(lineCounter, charPos, openChar, foundChar);

        }
        else if(stack1.isEmpty() && line[i]== ')'){
            foundChar= line[i]; openChar= '('; control=1;
            printClosing(lineCounter, charPos, openChar, foundChar);
        }
      }

      //break out of the while loop if there is an error (control==1)
      if(control ==1 ){
        break;
      }
    }


//if the program runs and doesnt find an error then check for end of line missing error
if(control ==0 ){
    if(!stack1.isEmpty()){ //if the stack is not empty then  there is an end of line missing error
      control =1; //set control to 1 so that the no error message is not printed
      if( stack1.peek() =='{'){ //if the stack contains this delimiter then print the error
        endChar= '}'; printEnd(endChar);
    }
  else  if( stack1.peek() =='['){
    endChar= ']'; printEnd(endChar);
    }
  else  if( stack1.peek() =='('){
      endChar= ')'; printEnd(endChar);
      }
    }
    else{ //if the stack is empty then print no errors
      printNoErrors();
    }
  }


}
