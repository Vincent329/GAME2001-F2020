#pragma once

#include "PriorityQueueLinkedList.h" // include the linked list with priority queue functions

template<class T> // a new class called CMP which is what we'll use to compare.  Like T, it's just a placeholder, called it CMP just to visualize to us that this is used to compare
class PriorityQueue
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}
	~PriorityQueue() {}

	// PRIORITY QUEUE FUNCTIONS
	// ASSIGNMENT NOTE, added priority order to compare other link nodes

	void push(T val, int priorityOrder) // pushing by comparing values
	{
		assert(m_elements.GetSize() < m_size);

		if (m_elements.GetSize() == 0) // if the queue is empty
		{
			m_elements.Push(val, priorityOrder);
		}

		else {
			LinkIterator<T> it;
			it = m_elements.Begin(); // set the iterator and point it at the root node

			//CMP cmp; // placeholder for the comparisons we will be making
				       // some advanced stuff

			while (it.isValid()) // go through the linked list. Move iterator to correct spot (or null)
			{
				// Iterates through the list
				// if iterated node's priority is greater than the parameter
				// break out of loop
				if (it.GetNode()->GetPriority() > priorityOrder)
				{
					break;
				}
				it++;
			}
			
			
			if (it.isValid())
			{
				// insert element before what's pointed to the iterator
				// priority value also added to node
				m_elements.Insert_Before(it, val, priorityOrder);
			}
			else // if it's pointing to the end of the list
			{
				// push to the queue
				// priority value also added to node
				m_elements.Push(val, priorityOrder); 
			}
		}
	}

	void pop()
	{
		m_elements.Pop_Front(); // gets rid fo the back of the queue
	}

	T& front() // returns the node itself rather than just the data
	{
		LinkIterator<T> it;
		it = m_elements.Begin();
		return *it;
	}

	T& back()
	{
		LinkIterator<T> it;
		it = m_elements.Last();

		return *it;
	}

	LinkNode<T>* frontNode() // returns the NODE to the first element in the LinkedList/Queue
	{
		return m_elements.Begin();
	}

	LinkNode<T>* lastNode() // returns the NODE to the first element in the LinkedList/Queue
	{
		return m_elements.Last();
	}
	// Helper functions

	int GetSize() // returns current size
	{
		return m_elements.GetSize();
	}

	int GetMaxSize() // returns max size
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
	LinkedList<T> m_elements;
	int m_size;
};