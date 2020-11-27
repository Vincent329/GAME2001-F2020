#include <iostream>
#include "PriorityQueue.h"
using namespace std;
//
//template<class T>
//class less_cmp { //less than compare with nonpointer types
//public:
//	inline bool operator()(T lVal, T rVal)
//	{
//		return (lVal < rVal);
//	}
//
//};
//
//template<class T>
//class less_cmp_pointer { //less than compare with nonpointer types
//public:
//
//	inline bool operator()(T lVal, T rVal)
//	{
//		return ((*lVal) < (*rVal));
//	}
//
//};
//template<class T>
//class greater_cmp { //greater than compare with nonpointer types
//public:
//
//	inline bool operator()(T lVal, T rVal)
//	{
//		return !(lVal < rVal); // if this is overloaded, we can just return the negated outcome
//	}
//
//};
//
//
//template<class T>
//class greater_cmp_pointer { //greater than compare with pointer types
//public:
//
//	inline bool operator()(T lVal, T rVal)
//	{
//		return !((*lVal) < (*rVal));
//	}
//
//};
//
//class NetworkMessage // recreate priority queue use for messaging
//{
//public:
//	NetworkMessage() : m_priority(0), m_id(0) {}
//	NetworkMessage(int p, int id) : m_priority(p), m_id(id) {}
//
//	int GetPriority()
//	{
//		return m_priority;	
//	}
//	int GetID()
//	{
//		return m_id;
//	}
//
//	// Overload operators
//	bool operator<(NetworkMessage& m) 
//	{
//		// check against priority level of both network messages
//		// how do we want these compared?
//		// compared based off priority first then ID value 2nd
//		// if 2 messages have the same priority, check the id value
//		if (m_priority < m.GetPriority())
//		{
//			return true;
//		}
//		else if (m_id < m.GetID()) // can optimize this to an or statement
//		{
//			return true;
//		}
//		return false;
//	}
//
//	bool operator>(NetworkMessage& m)
//	{
//		return !(*this < m); // calls the operator above us and returns the negated value of that
//	}
//
//private:
//	int m_priority;
//	int m_id; // just holds id value
//};

int main()
{
	cout << "Priority Queue Data Structure example" << endl << endl;

	const int SIZE = 20;
	//PriorityQueue <NetworkMessage, less_cmp<NetworkMessage> > que(SIZE);
	PriorityQueue<char> testQueue(SIZE);

	
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
