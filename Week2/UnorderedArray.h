#pragma once
#include <cassert>
#include "Array.h"

template <class T>
class UnorderedArray : public Array<T>
{	
public:
	// Default Constructor
	UnorderedArray() : Array<T>()
	{
	}

	// Constructor
	UnorderedArray(int size, int growBy = 1) : Array<T>(size, growBy)
	{
	}
	// Insertion
	// Fast insertion for unordered array (Big O of O(1))

	void push(T val)		// some push functions will have an overload for boolean, just to check if push was successful 
	{
		assert(this->m_array != NULL);

		if (this->m_numElements >= this->m_maxSize)
		{
			this->SetGrowSize();
			this->Expand();
		}

		// my array has space for a new value
		this->m_array[this->m_numElements] = val;		// just inserting at the last point
		this->m_numElements++;					// increasing the size as we move
	}

	   
	// Searching (LINEAR SEARCH) -> big O of O(N)
	int search(T val)
	{
		assert(this->m_array != NULL);

		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == val)
			{
				return i;		// return the reference to object if you find the searched value
			}
		}
		return -1; // otherwise just return -1 if you didn't find anything to indicate not found
	}

	// ----------- SORTING ALGORITHMS -------------------
	// Bubble Sort -- Big = O(N^2)
	void BubbleSort()
	{
		assert(this->m_array != NULL);

		T temp;

		for (int k = this->m_numElements - 1; k > 0; k--)
		{
			// Comparing 2 adjacent elements
			for (int i = 0; i < k; i++)
			{
				if (this->m_array[i] > this->m_array[i + 1])
				{
					// Swap the elements
					temp = this->m_array[i];
					this->m_array[i] = this->m_array[i + 1];
					this->m_array[i + 1] = temp;
				}
			}
		}
	}
	// Selection Sort -- Big-O = O(N^2)
	void SelectionSort()
	{
		assert(this->m_array != NULL);

		T temp;
		int min = 0;

		// The lowest position to swap the smallest element too....
		for (int k = 0; k < this->m_numElements - 1; k++)
		{
			min = k;

			// Iterate through the array to find the smallest value
			for (int i = k + 1; i < this->m_numElements; i++)
			{
				if (this->m_array[i] < this->m_array[min])
				{
					// Store the index to the smallest element
					min = i;
				}
			}

			// Swapping of the lowest element with the lowest available index
			if (this->m_array[k] > this->m_array[min])
			{
				// Swap
				temp = this->m_array[k];
				this->m_array[k] = this->m_array[min];
				this->m_array[min] = temp;
			}
		}
	}
	// Insertion Sort -- Big-O = O(N^2)
	void InsertionSort()
	{
		assert(this->m_array != NULL);

		T temp;
		int i = 0;

		for (int k = 1; k < this->m_numElements; k++)
		{
			temp = this->m_array[k];
			i = k;

			// Shifting of elements if necessary. Create a space for an element
			// to be inserted in the correct location.
			while (i > 0 && this->m_array[i - 1] >= temp)
			{
				// Push elements to the right;
				this->m_array[i] = this->m_array[i - 1];
				i--;
			}

			// Place the item in the correct location
			this->m_array[i] = temp;
		}
	}
	// Merge Sort -- Big-O = O(N logN)
	void MergeSort()
	{
		assert(this->m_array != NULL);

		T* tempArray = new T[this->m_numElements];
		assert(tempArray != NULL);

		MergeSort(tempArray, 0, this->m_numElements - 1);
		delete[] tempArray;
	}

private:
	// Recursive Merge Sort
	void MergeSort(T* tempArray, int lowerBound, int upperBound)
	{
		// Base case
		if (lowerBound == upperBound)
		{
			return;
		}

		// Determine the middle of the array
		int mid = (lowerBound + upperBound) >> 1;

		MergeSort(tempArray, lowerBound, mid);		// Lower half MergeSort
		MergeSort(tempArray, mid + 1, upperBound);	// Upper half MergeSort

		// Merge
		Merge(tempArray, lowerBound, mid + 1, upperBound);
	}
	void Merge(T* tempArray, int low, int mid, int upper)
	{
		// LowerBound, Mid+1, Upperbound
		int tempLow = low, tempMid = mid - 1;
		int index = 0;

		while (low <= tempMid && mid <= upper)
		{
			// Lower of the 2 values is smaller, move it to the tempArray
			if (this->m_array[low] < this->m_array[mid])
			{
				tempArray[index++] = this->m_array[low++];
			}
			else
			{
				tempArray[index++] = this->m_array[mid++];
			}
		}

		while (low <= tempMid)
		{
			tempArray[index++] = this->m_array[low++];
		}
		while (mid <= upper)
		{
			tempArray[index++] = this->m_array[mid++];
		}

		// Place the stored tempArray into the main array in the correct locations
		for (int i = 0; i < upper - tempLow + 1; i++)
		{
			this->m_array[tempLow + i] = tempArray[i];
		}
	}


};