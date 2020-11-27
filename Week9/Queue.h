#pragma once

#include "DoublyLinkedList.h"

template<class T>
class Queue
{
public:
	// Constructor
	Queue(int size) // set up queue by size
	{
		assert(size > 0); 
		m_size = size;
	}
	
	// Destructor
	~Queue() {} // no code in here

	// ------- QUEUE FUNCTIONS --------
	void push(T val) // if size of the queue currently less than max size we can push in a value using the Linked List push
	{
		if (m_elements.GetSize() < m_size)
		{
			m_elements.Push(val); // push to the back of the link list/ front of the queue
		}
	}

	// Looking at linked list properties, push and push front
	// where on the linked list is this being placed
	// Push Front means we are pushing the root node
	// but for Queue, front in the queue is the next possible place we can get into

	// first element we placed in the queue is called the back
	// front shifts everytime you push
	
	// when we pop we pop from the back, but in this case in the linked list we're gonna call the popfront function
	
	void pop(){
		m_elements.Pop_Front(); // front of linked list = back of the queue
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