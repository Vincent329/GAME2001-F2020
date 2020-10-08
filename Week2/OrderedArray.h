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
		m_duplicateFlag = true;
	}

	// Boolean Flag constructor
	OrderedArray(int size, bool duplicateFlag, int growBy = 1) : Array<T>(size, growBy)
	{
		m_duplicateFlag = duplicateFlag;
	}

	// Insertion - Big O = O(N)
	int push(T val)
	{
		assert(this->m_array != NULL);

		if (this->m_numElements >= this->m_maxSize)
		{
			this->SetGrowSize();
			this->Expand();
		}

		int i, k;
		// Step 1: Find the index to insert val
		// extra step, find out if this is a duplicate
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == val && !(m_duplicateFlag)) // if the value is the same and you don't want any duplicates
			{
				std::cout << val << " is a Duplicate.  Breaking out" << std::endl;
				return -1;
			}
			if (this->m_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index forward by one
		for (k = this->m_numElements; k > i; k--)	// Moving backwards through the array starting at this->m_numElements
		{
			this->m_array[k] = this->m_array[k - 1];
		}

		// Step 3: Insert val into index
		this->m_array[i] = val;

		this->m_numElements++;

		return i;
	}

	// Searching -- Binary Search -- Big O = O(log N), longer the array, the more efficient this gets
	int search(T searchKey)
	{
		return binarySearch(searchKey, 0, this->m_numElements - 1);
		// Binary Search Recursively
	}

	// getter and setter for duplicate flag
	bool getDuplicateFlag()
	{
		return m_duplicateFlag;
	}
	void setDuplicateFlag(bool duplicateFlag)
	{
		m_duplicateFlag = duplicateFlag;
	}
	
private:
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(this->m_array != NULL);
		assert(lowerBound >= 0);
		assert(upperBound < this->m_numElements);

		// Bitwise
		int current = (lowerBound + upperBound) >> 1; // bit shift 1 in the right direction divides by 2
		if (this->m_array[current] == searchKey)
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
			if (this->m_array[current] < searchKey)
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

	bool m_duplicateFlag;

};

// TIP FOR THE ASSIGNMENT, SINCE BOTH UNORDERED AND ORDERED ARRAY HAVE VERY SAMEY FUNCTIONS, THIS LEADS TO INHERITANCE FROM A BASE ARRAY CLASS!!!!!!