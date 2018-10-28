#include <iostream>

using namespace std;
//Generic stack implemented using templates
template<class T>
class GenStack{
public:
  GenStack(); //constructor
  GenStack(int maxSize ); //overloaded
  ~GenStack();

  void push(T value);
  T pop();
  T peek();

  bool isEmpty();
  bool isFull();
  int getSize();
  void resizeStack();

  T *myArray; //declares a pointer dynamically because we dont know the size, pointer not an array
 T *arrayNew; //new pointer array used for resizing of stack
  int top;
  int size;

};


template<class T>
GenStack<T>::GenStack() //implement default constructor
{

}
template<class T>
GenStack<T>::GenStack(int maxSize) //overloaded constructor
{
  myArray= new T[maxSize]; //allocating data dynamically and need to delete it with the delete statement
  size = maxSize;
  top= -1;
}
template<class T>
GenStack<T>::~GenStack(){ //destructor
  delete []myArray;  //deletes the array
}

template<class T> //add a value into the stack
void GenStack<T>::push(T value){

//if it is full then resize the stack
if(isFull()){
  resizeStack();
  myArray[++top] = value;
}
else {
  myArray[++top] = value;

}

}

template<class T> //remove the last inserted value off of the stack
T GenStack<T>::pop(){
if( isEmpty()){ //if it is empty then let the user know
  int i = 0;
cout << "The Stack is empty" << endl;
return i;

}
else{ //else reduce the size of the array
  return myArray[top--];
  }

}

template<class T>
void GenStack<T>::resizeStack(){ //resize the stack when it is full
  //triple size so it wont have to resize often
  size =size * 3;
   arrayNew = new T[size];
  for (int i = 0; i < size; i++){ //copy over the old stack into the new stack with more size
    arrayNew[i]= myArray[i];
  }
  myArray= arrayNew;
}

template<class T>
T GenStack<T>::peek(){ //show what is at the top of the stack

  return myArray[top];
}

template<class T>
bool GenStack<T>::isFull(){ //check if the stack is full

  return (top == size - 1);
}
template<class T>
bool GenStack<T>::isEmpty(){ //check if the stack is empty

  return (top == -1);
}
