#pragma once
#pragma once
#include <cassert>

template<class T>
class UnorderedArray
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];	// Dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize);	// Explicitly allocating memory based on the type T

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	// Destructor
	~UnorderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
	// Insertions
	// Fast insertion for UnorderedArray -- Big-O is O(1)
	void push(T val)
	{
		assert(m_array != NULL);	// Debugging purposes

		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		// My array has space for the new value
		m_array[m_numElements] = val;
		m_numElements++;
	}
	// Deletion (2 ways)
	// Remove the last item inserted into the array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}
	// Remove an item given an index
	// (Almost) Brute-force execution -- Big-O = O(N)
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
	// Searching (Linear serach) -- Big O = 
	int search(T val)
	{
		assert(m_array != NULL);

		// Brute-force search
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i;
			}
		}

		return -1;
	}
	// ----------- SORTING ALGORITHMS -------------------
	// Bubble Sort -- Big = O(N^2)
	void BubbleSort()
	{
		assert(m_array != NULL);

		T temp;

		// starting from the right to left, so that the largest item goes straight to the last element of the array
		for (int k = m_numElements - 1; k > 0; k--) 
		{
			// Comparing 2 adjacent elements
			// i less than k because we want to examine the ones prior to the last element in the comparison
			for (int i = 0; i < k; i++)
			{
				if (m_array[i] > m_array[i + 1]) // if it's greater than the next value in the array
				{
					// Swap the elements
					temp = m_array[i]; // make a temp variable to store the value to be swapped
					m_array[i] = m_array[i + 1]; // override m_array[i+1] with the current value
					m_array[i + 1] = temp; // get the previous value and swap it with the temp value
				}
			}
		}
		// Ideally here, the largest item should be on the right sidde
		// so what we do is we keep swapping items in the array until the largest goes all the way to the right
		// we keep going downwards until all the elements get organized right to left from top to bottom

	}
	// Selection Sort -- Big-O = O(N^2)
	// swap from the lowest point
	void SelectionSort()
	{
		assert(m_array != NULL);

		T temp;
		int min = 0;

		// The lowest position to swap the smallest element too....
		for (int k = 0; k < m_numElements - 1; k++) // left to right sort
		{ 
			// keeping track of the smallest instead of the largest
			min = k;

			// Iterate through the array to find the smallest value
			for (int i = k + 1; i < m_numElements; i++)
			{
				if (m_array[i] < m_array[min])
				{
					// Store the index to the smallest element
					min = i;
					// will keep updating the smallest value until it goes through the last element in the array. 
				}
			}

			// Swapping of the lowest element with the lowest available index
			// see if the value of k is greater than than the minimum value being held
			if (m_array[k] > m_array[min])
			{
				// Swap
				temp = m_array[k];
				m_array[k] = m_array[min];
				m_array[min] = temp;
			}
		}

		// basically, we're going to go through an index at a time, and from that index we check the elements after it
		// we'll keep checking for the lowest number past that index
		// if that selected index is less than the index we start from
		// we swap the two
	}

	
	// Insertion Sort -- Big-O = O(N^2)
	void InsertionSort()
	{
		assert(m_array != NULL);

		T temp; 
		int i = 0;

		for (int k = 1; k < m_numElements; k++) // k = 1, because technically the item at index 0 is already "sorted"
		{
			temp = m_array[k]; // point to index k, whatever it is, we store into temp
			i = k; // make i equal to k right now

			// Shifting of elements if necessary. Create a space for an element
			// to be inserted in the correct location.
			while (i > 0 && m_array[i - 1] >= temp) // i value greater than 0, but also a condition that makes sure the that we still have a larger number than the stored temp variable
			{
				// Push elements to the right;
				// making space for the item
				m_array[i] = m_array[i - 1]; 
				i--;
			}
			// Place the item in the correct location
			m_array[i] = temp;
		}

		// inside the loop, we are determining if there are elements that need to be pushed to the right, until we reach a point 
		// set a k = 1, k is the 2nd index, and an i value, originally set to 0, then made k 
		// while i is greater than 0, and while m_array[i-1] >= temp, push things over to the right
		// if the value of m_array[i-1] (left side) is greater than the temp variable, then we shift variables over to the right.
		// if temp is greater than the prior value, this is the correct position to place it, so then we place it
		// 
	}
	// Merge Sort -- Big-O = O(N logN)
	void MergeSort()
	{
		assert(m_array != NULL);

		T* tempArray = new T[m_numElements]; // a temporary array to facilitate the merge sort
		assert(tempArray != NULL);

		MergeSort(tempArray, 0, m_numElements - 1); // pass in lower bound index = 0, and number of elements -1
		delete[] tempArray; // in the end, the array we'll have will be fully sorted
							// once the merge sort is done, we don't need the temp array anymore 
	}

	// Overload the [] operator
	T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}
	// Clear - Big O = O(1)
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
	// Recursive Merge Sort
	void MergeSort(T* tempArray, int lowerBound, int upperBound)
	{
		// Base case
		// makes sure we break out of the recursion
		// if we don't have anything else to split down
		if (lowerBound == upperBound)
		{
			return; // just return
		}

		// Determine the middle of the array
		int mid = (lowerBound + upperBound) >> 1; // divide by 2
												  // break the array index into 2 parts

		// call Merge Sort twice
		// once for the lower half, and then for the upper half
		MergeSort(tempArray, lowerBound, mid);		// Lower half MergeSort
		MergeSort(tempArray, mid + 1, upperBound);	// Upper half MergeSort

		// when we have the individual elements, we have to merge them back up
		// from line 242 to 258, this does all the cutting up of the array into pieces
		// first time merge sort is called, it's with a full array, the lower bound at 0 and the upper bound at the highes tindex
		// will keep calling this over and over again, then merge the individual pieces back together

		// Merge
		// sole job is to take the bounds of the array and merge them all together
		Merge(tempArray, lowerBound, mid + 1, upperBound);
	}

	// the merging
	// this is going to take in pointer to the temp array, the low point, mid point, and high point
	// we are passing along 2 ints, the different sections that we have here
	
	void Merge(T* tempArray, int low, int mid, int upper)
	{
		// LowerBound, Mid+1, Upperbound
		// temp mid is going to be the real mid from before
		// get an int index to keep track of the current index we are at
		int tempLow = low, tempMid = mid - 1;
		int index = 0;

		// 4 loops to go through
		// first to check  and see if the low is less than the current mid index
		// makes sure we're not past the left side

		// check if the right side is less than the upper as well
		// makes sure that the pointer values are in the correct spots
		// so we're going to check through both sides of the split array
		// walking through the list
		// when one of the values go past their bound, we've exhausted everything in the list
		// so then we clean up
		while (low <= tempMid && mid <= upper)
		{
			// Checking if the lower of the 2 values is smaller, move it to the tempArray
			// if 
			if (m_array[low] < m_array[mid])
			{
				// we're filling the values of our temp array	
				tempArray[index++] = m_array[low++];
				// increment the index for the next value, then point to the next value in the low array
			}
			else
			{
				// if the index at mid is lower than the index at low, then the value at mid gets placed into temp array
				tempArray[index++] = m_array[mid++];
				// increment the index for the next value, then point to the next value in the mid array
			}
		}

		// the first while loop we exit out, so now we fill in the rest of the list
		// similar structure to the previous while loop
		// comparing the values together and setting them in the appropriate spot
		
		while (low <= tempMid) // clean up the low array if there's still values in the mid list
		{
			tempArray[index++] = m_array[low++];
			// clear out whatever is in the low array first if there is any leftover values in the low array
			// into the temp array
		}
		while (mid <= upper) // clean up the mid part if there's still any leftover values in the mid array
		{
			tempArray[index++] = m_array[mid++]; 
			// clear out whatever is in the mid array if there's any leftover values 
			// in the mid array to the temp array
		}


		// Place the stored tempArray into the main array in the correct locations
		// assume we're not putting the whole array, only a section of the array in there
		// but these are ordered
		for (int i = 0; i < upper - tempLow + 1; i++) // so the section of the array has an upper bound, from tempLow +1 to the upper bound
		{
			m_array[tempLow + i] = tempArray[i]; // we have a temp low which starts at 0 so we are still basically going through 0
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
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);

		// Copy the contents of the original array to the new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		// Delete the old array
		delete[] m_array;

		// Clean up variable assignments
		m_array = temp;
		temp = NULL;

		m_maxSize += m_growSize;

		return true;
	}
private:
	// Variables
	T* m_array;			// Pointer to the beginning of the array

	int m_maxSize;		// Maximum size of my array
	int m_growSize;		// Amount the array can grow through expansion
	int m_numElements;	// Number of items currently in my array
};