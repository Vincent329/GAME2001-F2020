#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main()
{
	cout << "Priority Queue Data Structure example" << endl << endl;

	const int SIZE = 20;
	//PriorityQueue <NetworkMessage, less_cmp<NetworkMessage> > que(SIZE);
	PriorityQueue<int> testQueue(SIZE);

	
	testQueue.push(100, 3); 
	testQueue.push(286, 2);
	testQueue.push(362, 1);
	testQueue.push(435, 3);
	testQueue.push(65, 4);
	testQueue.pop(); // pops 362, priority 1 
	testQueue.push(522, 1);
	testQueue.push(566, 5);
	testQueue.push(32, 2);
	testQueue.push(56, 3);
	testQueue.pop(); // pops 522, priority 1 
	testQueue.pop(); // pops 286, priority 2 
	testQueue.pop(); // pops 32, priority 2 
	testQueue.push(3, 1);
	
	// display the priority queue
	cout << "Priority queue content (size - " << testQueue.GetSize() << ") : " << endl;


	while (testQueue.isEmpty() == false)
	{
		cout << "	Priority: " << testQueue.frontNode()->GetPriority();
		cout << "	Data: " << testQueue.frontNode()->getData();
		
		cout << endl;

		testQueue.pop();
	}
	cout << endl;
	cout << "Cleaned out the previous queue" << endl;
	cout << "Adding four items to the priority queue" << endl << endl;
	testQueue.push(52, 1);
	testQueue.push(56, 5);
	testQueue.push(32, 4);
	testQueue.push(86, 2);

	cout << "Testing next and previous pointers" << endl;

	cout << "Next to the first node has these values..." << endl;
	cout << "Priority: " << testQueue.frontNode()->GetNext()->GetPriority() << endl;
	cout << "Data: " << testQueue.frontNode()->GetNext()->getData() << endl << endl; 
	// block of code above should return priority: 2 and data 86

	cout << "Previous to the last node has these values..." << endl;
	cout << "Priority: " << testQueue.lastNode()->GetPrevious()->GetPriority() << endl;
	cout << "Data: " << testQueue.lastNode()->GetPrevious()->getData() << endl;
	// block of code above should return priority: 4 and data 32

	cout << endl;
	if (testQueue.isEmpty() == true)
	{
		cout << "The container is empty" << endl;
	}
	else
	{
		cout << "The container is NOT empty" << endl;
	}
	return 0;
}
