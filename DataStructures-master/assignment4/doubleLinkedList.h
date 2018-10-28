#include <iostream>
#include "listnode.h"

using namespace std;
//Doubly linked list
template <class T>
//Interface class.
//We couldn't get some of the functions to override, so we commented them out.
//We realize that they should be overridden but it would not work
class listInterface
{
public:
  virtual void insertBack(T data)=0;
  virtual T  removeFront()=0;
  //virtual T remove(T pos) = 0;
  //virtual T deletePos(T pos) = 0;
  virtual void printList() = 0;
  //virtual T find(T data) = 0;
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

		T remove(T pos);
		//T deletePos(T pos);


		void printList();
		// find(T data);
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
T DoublyLinkedList<T>::getFront()
{
  if(isEmpty()){
    return T();
  }
	return front->data;
}

template <class T>
T* DoublyLinkedList<T>::FrontP()
{
  if(isEmpty()){
    return NULL;
  }
  T *temp = &front->data;
	return temp;
}

template <class T>
void DoublyLinkedList<T>::printList()
{
	ListNode<T> *curr = front;
	while(curr ->next != NULL)
	{
		//cout << curr -> data << endl; causing errors
		curr = curr -> next;
	}
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
/*
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
*/


/*template <class T>
T DoublyLinkedList<T>::find(T d)
{
	int idx = -1;
	ListNode<T> *curr = front;

	while(curr -> next !=NULL)
	{
		++idx;
		if(curr -> data == d)
		{
			break;
		}

		else
		{
			curr = (curr -> next);
		}
	}

	if(curr == NULL)
	{
		idx = -1;


	}
  cout << "found at: " << idx << endl;
	return T();
}
*/


/*template <class T>
T removeAt(T data)
{
	int pos = find(data);
	deletePos(pos);

}
*/
/*template <class T>
T DoublyLinkedList<T>::deletePos(int pos)
{
	int idx = 0;

	ListNode<T> *curr = front;
	ListNode<T> *prev = front;


	while (idx != pos)//Update pointers
	{
		prev = curr;
		curr = curr -> next;
		idx++;
	}

	prev -> next = curr ->next;
	curr -> next = NULL;
	int td = curr -> data;

	delete curr;
	size--;
	return td;

}*/

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
