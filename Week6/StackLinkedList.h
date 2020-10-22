#pragma once

#include <cassert>
#include "DoublyLinkedList.h"

template<class T>
class Stack
{
public:
	// Constructor & Destructor
	Stack() {}
	~Stack() {}
	// ------------ STACK FUNCTIONS ------------------
	void push(T val)
	{
		m_container.Push(val); // this is gonna push to the back of the linked list, keeping LIFO order
	}
	void pop()
	{
		m_container.Pop(); // pop the last item on the list, PRESERVE LIFO
	}
	const T& top()
	{
		LinkIterator<T> it; // our iterator is used to read values stored in our linked list, it'll just point to our last point
		it = m_container.Last(); // position it so that it points to our last node
		return *it; // dereference it to return the actual data value
	}

	// ---------- END STACK FUNCTIONS ----------------
	int GetSize()
	{
		return m_container.GetSize();
	}
	bool isEmpty()
	{
		return (m_container.GetSize() == 0);
	}
private:
	LinkedList<T> m_container; // create the container to our linked list
								// note we don't need to create it as a pointer because LinkedList is already 
								// relying on LinkIterator here
};