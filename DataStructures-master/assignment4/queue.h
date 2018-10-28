#include <iostream>
#include "doubleLinkedList.h"
using namespace std;
//This is where we call the functions from our doubly linked list class
//to perform the functions of our queue. 
template <class T>
class queue{
public:
  void enQueue(T data);
  T deQueue();
  T peek();
  T* front();
  bool isEmpty1();

  DoublyLinkedList<T> mylist;


};
template <class T>
void queue<T>::enQueue(T data){

  mylist.insertBack(data);

}
template <class T>
T queue<T>::peek(){



  return mylist.getFront();
}


template <class T>
T* queue<T>::front()
{
  return mylist.FrontP();
}

template <class T>
T queue<T>::deQueue(){

if(!mylist.isEmpty()){
   return mylist.removeFront();
}

else{

  return T();
}
}


template <class T>
bool queue<T>::isEmpty1(){
  return mylist.isEmpty();

}
