#include <iostream>
#include "DoubleEndedLinkedList.h"

using namespace std;

int main()
{
	cout << "Double-Ended Linked List Example" << endl << endl;
	LinkedList<int> lList;
	lList.Push(101); // push first
	lList.Push_Front(102); // 102 101
	lList.Pop(); // 102
	lList.Push(201); // 102 201
	lList.Push_Front(301); // 301 102 201
	lList.Push(801); // 301 102 201 801
	lList.Push(401); // 301 102 201 801 401
	lList.Push(1); // 301 102 201 801 401 1
	lList.Pop_Front(); // 102 201 801 401 1
	lList.Push(701); // 102 201 801 401 1 701
	LinkIterator<int> it;
	for (it = lList.Begin(); it != lList.End(); it++)
	{
		cout << " " << *it;
	}
	cout << endl << endl;
	return 0;
}
