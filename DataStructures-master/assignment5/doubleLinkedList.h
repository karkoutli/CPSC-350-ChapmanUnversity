#include <iostream>
#include "listnode.h"
#include <string>

using namespace std;
//Doubly linked list code that we were given during class
template <class T>
//Interface class.
class listInterface
{
public:
  virtual void insertBack(T data)=0;
  virtual T  removeFront()=0;
  virtual T remove(T pos) = 0;
  virtual void printList() = 0;
  virtual T find(T data) = 0;
  virtual bool isEmpty() = 0;
  virtual T getFront()=0;
  virtual T* FrontP()=0;

};


//doubly linked list code written up in class and converted into a template
// we added a getfront and front functions
template <class T>
class DoublyLinkedList : listInterface<T>
{
	private:
		ListNode<T> *front;
		ListNode<T> *back;
		unsigned int size;

	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		void insertFront(T data);
		void insertBack(T data);
		T removeFront();
		T removeBack();
    T getFront();
    T* FrontP();
    string doublyToString();
      T getBack();

		T remove(T pos);
		//T deletePos(T pos);

    ListNode<T>* frontPointer();
		void printList();
		T find(T data);
    bool findData(T data); //find data function added to see whether or not data is in the doubly, the same thing as contains in BST
		unsigned int getSize();
		bool isEmpty();
};



template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	size = 0;
	front = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	//You know the drill
	if(front != NULL)
		delete front;
}
template <class T>
unsigned int DoublyLinkedList<T>::getSize(){

  return size;
}
template <class T>
string DoublyLinkedList<T>::doublyToString() //converts the doubly list into a string seperated by commas
{
  ListNode<T> *curr = front;
  string s;

  while(curr!= NULL)
  {
    if(curr == front ){

      s+= to_string(curr->data)+ ","; //to_string converts data to a string (searched on stack overflow for thsi)
    //  cout << curr->data;
      //s += to_string(curr->data);
    }
    else{
  //  cout << curr -> data << ",";
    s+= to_string(curr->data) + ",";
  } // causing errors

    curr = curr -> next;
  }

  //cout << endl;
  return  s;

}
template <class T>
ListNode<T>* DoublyLinkedList<T>::frontPointer(){
return front;
}

template <class T>
T DoublyLinkedList<T>::getFront()
{
  if(isEmpty()){
    return T();
  }
	return front->data;
}

template <class T>
T DoublyLinkedList<T>::getBack()
{
  if(isEmpty()){
    return T();
  }
	return back->data;
}

template <class T>
T* DoublyLinkedList<T>::FrontP() //returns pointer to the front node
{
  if(isEmpty()){
    return NULL;
  }
  T *temp = &front->data;
	return temp;
}

template <class T>
void DoublyLinkedList<T>::printList() //print the doubly linked list, but insert a space in between each node
{
	ListNode<T> *curr = front;
string s = " ";

	while(curr != NULL)
	{
    cout << curr -> data << " ";
		curr = curr -> next;
	}
  cout << endl;

}


template <class T>
void DoublyLinkedList<T>::insertFront(T data)
{
	ListNode<T> *node = new ListNode<T>(data);
	if (isEmpty())
	{
		back = node;
	}
	else //not empty
	{
		front -> prev = node;
		node -> next = front;
	}
	front = node;
	++size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T data)
{
	ListNode<T> *node = new ListNode<T>(data);

	if(isEmpty())
	{
		front = node;
	}
	else //not empty
	{
		back -> next = node;
		node -> prev = back;
	}

	back = node;
	size++;
}

//remove from front of list

template <class T>
T DoublyLinkedList<T>::remove(T key)
{
	T temp = front -> data;
	ListNode<T> *curr = front;
	while(curr -> data != key)
	{
		curr = curr ->next;

		if(curr == NULL)
			return 0;
	}

	if(curr == front)
	{
		front = curr->next;
	}
	else
	{
		curr -> prev -> next = curr -> next;
	}

	if(curr == back)
	{
		back = curr -> prev;
	}
	else
	{
		curr -> next -> prev = curr -> prev;
	}

	curr -> next = NULL;
	curr -> prev = NULL;
	 temp = curr -> data;

	--size;

	delete curr;

	return temp;
}



template <class T>
T DoublyLinkedList<T>::find(T d)
{
  return d;

}

template <class T>
bool DoublyLinkedList<T>::findData(T d) //returns the data of found node
{
	//using the logic for contains in BST
	ListNode<T> *curr = front;
  while (curr->data != d ){

      curr= curr->next;

  if(curr==NULL){

    return false;
  }
}
  return true;

}



template <class T>
bool DoublyLinkedList<T>::isEmpty() {
    return(size == 0);
}

template <class T>
T DoublyLinkedList<T>::removeFront()
{
//  cout << "adding to my list" << endl;
if(!isEmpty()) {
	ListNode<T> *node = front;

	if(front -> next == NULL)
	{
		back = NULL;
		front = NULL;
	}

	else
	{
		front -> next -> prev = NULL;
		front = front->next;
	}

	//front = front -> next;
	--size;
	//node-> next = NULL;
	T temp = node -> data;

  //cout << size << endl;
	delete node;
	return temp;

}
else{
T empty = T (); //for some reason it did not like returning NULL so a stack over flow question said to do T () and it began working
cout << "empty" << endl;
	return empty; //?
}

}


template <class T>
T DoublyLinkedList<T>::removeBack(){

  if(!isEmpty())
  {
    ListNode<T> *node = back;
    if(back-> prev == NULL)
   {
    back= NULL;
    front= NULL;
   }
   else{

     back->prev->next = NULL;
     back= back -> prev;
   }
   --size;
   T temp = node ->data;

   delete node;
   return temp;

}
else{
  T empty = T (); //for some reason it did not like returning NULL so a stack over flow question said to do T () and it began working
  cout << "empty" << endl;
	return empty; //?
}


}
