#pragma once
#include <cassert>
#include "UnorderedArray.h"

template<class T>
class Stack
{
public:
	// constructor
	Stack(int size, int growBy = 1)
	{
		assert(size > 0 && growBy >= 0); // input validation
		m_container = new UnorderedArray<T>(size, growBy); // initialize Unordered Array
		assert(m_container != NULL);
	}
	
	// Destructor
	~Stack()
	{
		if (m_container != NULL)
		{
			delete m_container; // delete the contents of the array
			m_container = NULL; // makes sure to set pointer to null
		}
	}

	// ---------------------- STACK FUNCTIONS ---------------------
	void push(T val)
	{
		assert(m_container != NULL);
		m_container->push(val);
	}
	void pop()
	{
		assert(m_container != NULL);
		m_container->pop();

	}
	const T& top()
	{
		assert(m_container != NULL);
		
		// our stack should not have array notation, but it's okay to use it within the previous assignment
		// we don't have anything that points directly at the top, so how do we do it
		// our overloaded array operator can do it, we can also use GetSize() to get it

		// dereference our pointer to the unordered array
		// then use array notation to return the top element
		// myUnorderedArray[GetSize() - 1]
		return  (*m_container)[m_container->GetSize() - 1];


	}
	// ---------------------- END STACK FUNCTIONS --------------------

	int GetSize()
	{
		assert(m_container != NULL);
		return m_container->GetSize();
	}
	int GetMaxSize()
	{
		assert(m_container != NULL);
		return m_container->GetMaxSize();
	}
	bool isEmpty()
	{
		assert(m_container != NULL);
		return (m_container->GetSize() == 0);
	}

private:
	// Variables
	UnorderedArray<T>* m_container;
};