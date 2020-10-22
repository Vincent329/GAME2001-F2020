#include <iostream>
// #include "Stack.h"
// #include "StackArray.h"
#include "StackLinkedList.h"
using namespace std;

int main()
{
	cout << "Stack Linked List Example" << endl << endl;
	Stack<int> sList;
	sList.push(101); //101
	sList.push(501); //101 501
	sList.push(201); // 101 501 201
	sList.pop(); // 101 501
	sList.push(301); // 101 501 301 
	sList.push(401); // 101 501 301 401
	sList.push(901);
	sList.pop();
	cout << "Contents of the stack: ";
	while (sList.isEmpty() == false)
	{
		cout << " " << sList.top(); // 401 301 501 101, we're just reading the top of the stap
		sList.pop(); // whenever we pop something off the stack, we just remove it from the top of the stack
	}
	cout << endl << endl;
	return 0;
}