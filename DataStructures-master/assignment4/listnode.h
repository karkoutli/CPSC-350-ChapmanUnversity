#include <iostream>
//For organiztion we seperated our list node class from the rest of the
//of the linked list.
using namespace std;
//templated list node written in class 
template <class T>
class ListNode
{
	public:
		ListNode(); //Default
		ListNode(T d); //Overloaded
		~ListNode();


		T data;
		ListNode<T> *next;
    ListNode<T> *prev;


};

template <class T>
ListNode<T>::ListNode()
{
	//default constructor
	//you can build character here
}

template <class T>
ListNode<T>::~ListNode()
{


	//build character
	//and get your money's worth.
}

template <class T>
ListNode<T>::ListNode(T d)//overloaded
{
	data = d;
  prev= NULL;
	next = NULL;

}
