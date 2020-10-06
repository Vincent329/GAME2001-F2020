
#pragma once
#include <cassert>
#include "Array.h"

template <class T>
class OrderedArray /*: public Array */
{
public:
	// Constructor
	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)// if there's something in the arraay
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];	// Dynamically allocated new array
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	// Destructor
	~OrderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;		// Good programming practice to set unused pointers to NULL
		}
	}
	// Insertion - Big O = O(N)
	int push(T val)
	{
		assert(m_array != NULL);

		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		int i, k;
		// Step 1: Find the index to insert val
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index forward by one
		for (k = m_numElements; k > i; k--)	// Moving backwards through the array starting at m_numElements
		{
			m_array[k] = m_array[k - 1];
		}

		// Step 3: Insert val into index
		m_array[i] = val;

		m_numElements++;

		return i;
	}
	// Deletion (2 methods)
	// Remove the last item in the array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}
	void remove(int index)
	{
		assert(m_array != NULL);

		if (index >= m_numElements) 
		{
			return;
		}

		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}

		m_numElements--;
	}
	// Searching -- Binary Search -- Big O = O(log N), longer the array, the more efficient this gets
	int search(T searchKey)
	{
		return binarySearch(searchKey, 0, m_numElements - 1);
		// Binary Search Recursively
	}
	// Overloaded [] operator
	const T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}
	// Clear
	void clear()
	{
		m_numElements = 0;
	}
	// Gets and Sets
	int GetSize()
	{
		return m_numElements;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	void SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
private:
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(m_array != NULL);
		assert(lowerBound >= 0);
		assert(upperBound < m_numElements);

		// Bitwise
		int current = (lowerBound + upperBound) >> 1; // bit shift 1 in the right direction divides by 2
		if (m_array[current] == searchKey)
		{
			// we have found the searchKey in the array, return the index
			return current;
		}
		// are we done searching?
		else if (lowerBound > upperBound)
		{
			return -1; // did not find it in the array
		}
		// where's the key?
		else {
			if (m_array[current] < searchKey)
			{
				// search the upper half
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else {
				// search the lower half
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}
	}
	// Expand
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		T* temp = new T[m_maxSize + m_growSize];	// same as unordered array
		assert(temp != NULL);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;
		m_array = temp;
		temp = NULL;

		m_maxSize += m_growSize;

		return true;
	}
private:
	// Variables
	T* m_array;			// Pointer to the beginning of the array

	int m_maxSize;		// Maximum number of items the array can hold
	int m_growSize;		// How large will the array grow by
	int m_numElements;	// Number of elements currently in the array.
};

// TIP FOR THE ASSIGNMENT, SINCE BOTH UNORDERED AND ORDERED ARRAY HAVE VERY SAMEY FUNCTIONS, THIS LEADS TO INHERITANCE FROM A BASE ARRAY CLASS!!!!!!