#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	cout << "Queue Data Structure Example " << endl << endl;

	// create and populate queue
	const int SIZE = 5;
	Queue<int> intQueue(SIZE);

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
	return 0;
}