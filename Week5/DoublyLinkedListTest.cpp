#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
	cout << "Doubly Linked List Example" << endl << endl;

	LinkedList<int> lList;

	lList.Push(101);
	lList.Push_Front(102);
	lList.Pop();
	lList.Push(201);
	lList.Push_Front(301);
	lList.Push(801);
	lList.Push(401);
	lList.Push(1);
	lList.Pop_Front();
	lList.Push(701);


	LinkIterator<int> it; // this is what we'll use for our traversal

	for (it = lList.Begin(); it != lList.End(); it++)
	{
		cout << " " << *it; // print out the items in our linked list
	}

	cout << endl << endl;

	for (it = lList.Last(); it != NULL; it--) // move backwards through the list and we'll start from the top, we'll be able to move through the previous pointers
	{
		cout << " " << *it;  // printing it backwards
	}

	cout << endl << endl;

	return 0;
}