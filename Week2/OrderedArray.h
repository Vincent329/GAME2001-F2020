#pragma once
#include <cassert>
#include "Array.h"

template <class T>
class OrderedArray : public Array<T>
{
public: 
	// Default Constructor
	OrderedArray() : Array<T>()
	{
	}

	// Constructor
	OrderedArray(int size, int growBy = 1) : Array<T>(size, growBy)
	{
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

	// Searching -- Binary Search -- Big O = O(log N), longer the array, the more efficient this gets
	int search(T searchKey)
	{
		return binarySearch(searchKey, 0, m_numElements - 1);
		// Binary Search Recursively
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

};

// TIP FOR THE ASSIGNMENT, SINCE BOTH UNORDERED AND ORDERED ARRAY HAVE VERY SAMEY FUNCTIONS, THIS LEADS TO INHERITANCE FROM A BASE ARRAY CLASS!!!!!!