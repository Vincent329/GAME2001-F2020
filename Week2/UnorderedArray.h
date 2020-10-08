#pragma once
#include <cassert>
#include "Array.h"

template <class T>
class UnorderedArray : public Array<T>
{	
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1) : 
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0), growValue(1)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize);	// explicitly state to compiler that we're setting aside a set of memory based on type of T
														// assuming T is int, there's 4 bytes of memory * the size amount of the array.  This will allocate that amount of memory
			m_growSize = ((growBy > 0) ? growBy : 0);	// prevent array from shrinking, keep it growing, checks if growBy is a value greater than 0, otherwise it will be 0
		}
	}
	// Destructor
	~UnorderedArray()
	{
		if (m_array != NULL)		// if the array has some memory inside it
		{
			delete[] m_array;		// delete array
			m_array = NULL;			// make sure the array isn't pointing to anything 
		}
	}
	// Insertion
	// Fast insertion for unordered array (Big O of O(1))

	void push(T val)		// some push functions will have an overload for boolean, just to check if push was successful 
	{
		assert(m_array != NULL);

		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		// my array has space for a new value
		m_array[m_numElements] = val;		// just inserting at the last point
		m_numElements++;					// increasing the size as we move
	}
	
	// Deletion (2 methods)
	 // remove the last item inserted into the array (Big O is O(1) too)
	 void pop()		// not responsible for returning what's popped, just removing the top element
	 {
	 	if (m_numElements > 0)		// making sure there is something there
	 	{
	 		m_numElements--;
	 	}
	 }
	 // remove an item given an index
	 // (almost) brute force execution -> Big O = O(N) -> larger array = slower performance
	 void remove(int index)		// searches for array element based on index
	 {
	 	assert(m_array != NULL);
	   
	 	if (index >= m_numElements) // if index surpasses the number of elements we search, just back out of the program
	 	{
	 		return;
	 	}
	 	
		for (int i = index; i < m_numElements; i++) // stays O(N)
	 	{
	 		if (i + 1 >= m_numElements)
	 		{
	 			m_array[i] = m_array[i + 1]; // jump over to exact index and overwrite the data, therefore just moving memory back  
	 		}
	 	}
	 	m_numElements--; // REMEMBER TO SUBTRACT THE NUMBER OF ELEMENTS
	 }
	   
	// Searching (LINEAR SEARCH) -> big O of O(N)
	int search(T val)
	{
		assert(m_array != NULL);

		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
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
		assert(m_array != NULL);

		T temp;

		for (int k = m_numElements - 1; k > 0; k--)
		{
			// Comparing 2 adjacent elements
			for (int i = 0; i < k; i++)
			{
				if (m_array[i] > m_array[i + 1])
				{
					// Swap the elements
					temp = m_array[i];
					m_array[i] = m_array[i + 1];
					m_array[i + 1] = temp;
				}
			}
		}
	}
	// Selection Sort -- Big-O = O(N^2)
	void SelectionSort()
	{
		assert(m_array != NULL);

		T temp;
		int min = 0;

		// The lowest position to swap the smallest element too....
		for (int k = 0; k < m_numElements - 1; k++)
		{
			min = k;

			// Iterate through the array to find the smallest value
			for (int i = k + 1; i < m_numElements; i++)
			{
				if (m_array[i] < m_array[min])
				{
					// Store the index to the smallest element
					min = i;
				}
			}

			// Swapping of the lowest element with the lowest available index
			if (m_array[k] > m_array[min])
			{
				// Swap
				temp = m_array[k];
				m_array[k] = m_array[min];
				m_array[min] = temp;
			}
		}
	}
	// Insertion Sort -- Big-O = O(N^2)
	void InsertionSort()
	{
		assert(m_array != NULL);

		T temp;
		int i = 0;

		for (int k = 1; k < m_numElements; k++)
		{
			temp = m_array[k];
			i = k;

			// Shifting of elements if necessary. Create a space for an element
			// to be inserted in the correct location.
			while (i > 0 && m_array[i - 1] >= temp)
			{
				// Push elements to the right;
				m_array[i] = m_array[i - 1];
				i--;
			}

			// Place the item in the correct location
			m_array[i] = temp;
		}
	}
	// Merge Sort -- Big-O = O(N logN)
	void MergeSort()
	{
		assert(m_array != NULL);

		T* tempArray = new T[m_numElements];
		assert(tempArray != NULL);

		MergeSort(tempArray, 0, m_numElements - 1);
		delete[] tempArray;
	}

	// Overload the [] Array
	T& operator[](int index)						// return a  reference to object to not create a copy of item that we're looking at, looking for actual access to that particular item
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}
	// Clear - Big O of O(1) because all we're doing is completely ignoring everything in the array
	void clear()
	{
		m_numElements = 0;	// just ignore everything in the array, and no operations can be done with the array values
	}						// no need to delete anything, we just basically ignored everything
	
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
	int SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val*growValue; // IMPORTANT FOR THE ASSIGNMENT, AS IT NEEDS TO INCREMENT BY DOUBLE EACH TIME
		growValue *= 2;
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
			if (m_array[low] < m_array[mid])
			{
				tempArray[index++] = m_array[low++];
			}
			else
			{
				tempArray[index++] = m_array[mid++];
			}
		}

		while (low <= tempMid)
		{
			tempArray[index++] = m_array[low++];
		}
		while (mid <= upper)
		{
			tempArray[index++] = m_array[mid++];
		}

		// Place the stored tempArray into the main array in the correct locations
		for (int i = 0; i < upper - tempLow + 1; i++)
		{
			m_array[tempLow + i] = tempArray[i];
		}
	}
	// Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		// Create the new array
		T* temp = new T[m_maxSize + m_growSize]; // Creating new array which is expanded by our grow size, so this will be a larger array
		assert(temp != NULL);
		
		// copy contents of original array into new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize); // copy contents from m_array into temp array
													 // what this is doing is take the memory size from the original array and putting it into temp 
		// delete the old array
		delete[] m_array;		// if we just leave this, it's going to fall out of scope
		
		// clean up variable assignments
		m_array = temp; // makes sure we keep working with m_array;
		temp = NULL;	// we're done with temp, now point it to null so that it doesn't dangle around memory
		m_maxSize += m_growSize; // add m_maxSize on top of grow size

		return true;
	}
private:
	// Variables
	T* m_array; // points to the very first element of the array
	
	int m_maxSize; // maximum size of my array
	int m_growSize; // amount the array can grow thorugh expansion
	int m_numElements; // number of elements currently in the array
	int growValue;	// assignment purposes, will grow every time set grow size is called
};