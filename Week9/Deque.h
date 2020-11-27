#pragma once

#include "DoublyLinkedList.h"

template<class T>
class Deque
{
public:
	// Constructor
	Deque(int size) // set up queue by size
	{
		assert(size > 0);
		m_size = size;
	}

	// Destructor
	~Deque() {} // no code in here

	// ------- DEQUEUE FUNCTIONS --------
	
	// one way af adding
	void push_front(T val)
	{
		if (m_elements.GetSize() < m_size)
		{
			/* call one of the two push functions associated with linked list*/
			m_elements.Push_Front(val); // will introduce a little caveat
										// whenever we add items to the front of deque, we add to the front root of the linked list
										// when we call pushfront, is gonna be added where the root is, to the front
										// adding to the front of the linklist/back of the queue
										// whenever we add items to the front of the deque, we add to the front of our link list
										
		}
	}

	void pop_front()
	{
		m_elements.Pop(); // how do we process the oldest node in the list?
						  // call the regular pop function
						  // navigates to the last node of our linked list
		                  // located at the back of the queue

	}

	// another way of adding
	void push_back(T val)
	{
		if (m_elements.GetSize() < m_size)
		{
			m_elements.Push(val); // this navigates to the last node and makes the node there
								  // adds it to the back of the linklist
		}
	}

	void pop_back() {
		m_elements.Pop_Front(); // popping the root, 
								// note that this function name is pop_back
								// as we add stuff to the function, we add to the front of the linked list (back of the queue)
								// so by calling pop front, we pop the front of the linked list (back of the queue)
	}

	T& front()
	{
		LinkIterator<T> it;
		it = m_elements.Begin(); // set the iterator equal to the begin function -> returns reference to root node
		return *it; // because of how we set up our link iterator, we're returning the data based on where the node is pointed to
	}

	T& back()
	{
		LinkIterator<T> it; // do not point to End(), as that returns null, in a linked list when pionting to Null that's the end of the list
		it = m_elements.Last(); // grabs the last element for us
		return *it;
	}



	int GetSize()
	{
		return m_elements.GetSize();// wrapping around different functions that already exist in linked list
	}
	int GetMaxSize()
	{
		return m_size;
	}
	bool isEmpty()
	{
		return (m_elements.GetSize() == 0); // true if there's nothing, false if not
	}

	void Resize(int size)
	{
		assert(size > 0);
		m_size = size;

	}
private:
	LinkedList<T> m_elements; // holds the Doubly Linked List
	int m_size;

};