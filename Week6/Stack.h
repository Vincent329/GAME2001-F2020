#pragma once
#include <cassert>

template<class T>
class Stack
{
public:

	// Constructor
	Stack(int size, int growBy = 1) :
		m_array(NULL), m_size(0), m_top(-1), m_growSize(0)
	{	// top set to -1 to let us know that we don't have an array yet
		if (size)
		{
			m_size = size;
			m_array = new T[m_size];	// Dynamically allocating an array to m_size
			memset(m_array, 0, sizeof(T) * m_size);	// Explicitly allocating memory based on the type T

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	// Destructor
	~Stack()
	{
		if (m_array != NULL)
		{
			delete[] m_array; // delete contents of array
			m_array = NULL; // point the array to null
		}
	}

	// ---------------- STACK FUNCTIONS --------------------
	// what are the stack functions?
	// 3 prominent functions
	// push to the top
	void push(T val)
	{
		// say we have a stack of plates
		assert(m_array != NULL);
		if (isFull())
		{
			Expand();
		}

		m_array[++m_top] = val; // postfix notation, increment m_top then insert val into the stack
	}
	// take what's at the top and pop it off
	void pop()
	{
		// similar to the array, we can just ignore it
		// just refer the top back down to the previous stack
		// if we push anything, it'll overwrite what's on top anyway
		if (!isEmpty())
		{
			m_top--;
		}
	}
	// peeking at the stack without taking it off of the stack
	const T& top() // const ensures that I'm not changing anything, and we're going to return the original value instead of the copy
	{
		assert(m_array != NULL); // just to make sure there's something
		assert(m_top >= 0); // checking to see if m_top is pointing to an actual element in the stack
		return m_array[m_top]; // expecting to peek at the top of the stack
	}

	// ---------------- END STACK FUNCTIONS ---------------------

	// Gets and Sets
	int GetSize()
	{
		return m_top + 1;
	}
	int GetMaxSize()
	{
		return m_size;
	}
	bool isEmpty()
	{
		return (m_top == -1); // m_top, if it was at 0, it would have pointed to the first index of the array, but if it's -1, there's nothing
	}
	bool isFull() { 
		return (m_top == m_size - 1); // check number of items in the stack to the value of m_top
	}
private:
	
	// Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		// Create the new array
		T* temp = new T[m_size + m_growSize];
		assert(temp != NULL);

		// Copy the contents of the original array to the new array
		memcpy(temp, m_array, sizeof(T) * m_size);

		// Delete the old array
		delete[] m_array;

		// Clean up variable assignments
		m_array = temp;
		temp = NULL;

		m_size += m_growSize;

		return true;
	}
private:
	// Variables
	T* m_array;			// Pointer to the beginning of the array
	
	// Variables for stack
	int m_top;			// top of our stack
	int m_size;			// Size of our stack
	int m_growSize;		// how much the stack grows by
};