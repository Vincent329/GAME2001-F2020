#pragma once

#include "DoublyLinkedList.h"

template<class T>
class Queue
{
public:
	// Constructor
	Queue(int size)
	{
		assert(size > 0);
		m_size = size;
	}
	
	// Destructor
	~Queue() {}


	void push(T val)
	{
		if (m_elements.GetSize() < m_size)
		{
			m_elements.Push(val);
		}
	}
	
	void pop(){
		m_elements.Pop_Front();
	}

	T& front()
	{
		LinkIterator<T> it;
		it = m_elements.Begin();
		return *it;
	}

	T& back()
	{
		LinkIterator<T> it; // do not point to end, as that returns null
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
		return (m_elements.GetSize() == 0);
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