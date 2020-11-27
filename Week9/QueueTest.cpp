#include <iostream>
#include "Queue.h"
#include "Deque.H"

using namespace std;

int main()
{
	cout << "Queue Data Structure Example " << endl << endl;

	// create and populate queue
	const int SIZE = 5;
	Queue<int> intQueue(SIZE);
	Deque<int> intDeque(SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		intQueue.push(10 + i);
	}

	cout << "Queue Contents (size - " << intQueue.GetSize() << ") :";
	while (intQueue.isEmpty() == false)
	{
		cout << " " << intQueue.front();
		intQueue.pop();
	}

	cout << endl << endl;

	if (intQueue.isEmpty() == true)
	{
		cout << "the int queue is empty." << endl << endl;
	}
	else {
		cout << "the int queue is NOT empty" << endl << endl;
	}
	//-------------------------Deque Stuff

	cout << "Deque Test" << endl << endl;

	for (int i = 0; i < SIZE; i++)
	{
		intDeque.push_front(10 + i);
	}

	cout << "Queue Contents (size - " << intQueue.GetSize() << ") :";
	while (intDeque.isEmpty() == false)
	{
		cout << "Front: " << intDeque.front();
		cout << "Back: " << intDeque.back();
		cout << endl;
		intDeque.pop_front(); // the root is all updated already, but this is essentially getting rid of the back of the deque
	}

	cout << endl << endl;

	if (intDeque.isEmpty() == true)
	{
		cout << "the int queue is empty." << endl << endl;
	}
	else {
		cout << "the int queue is NOT empty" << endl << endl;
	}

	return 0;
}