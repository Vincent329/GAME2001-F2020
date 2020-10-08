#pragma once
#include <cassert>
#include <iostream>

template <class T>
class Array
{
public:

	// Default Constructor
	Array() : 
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0), growValue(1)
	{
		std::cout << "Default Constructor Called" << std::endl;
	}

	// Constructor
	Array(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0), growValue(1)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];	// Dynamically allocated new array
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	// Destructor
	~Array()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;		// Good programming practice to set unused pointers to NULL
		}
	}

	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}

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
	void SetSize(int size)
	{
		m_numElements = size;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	void SetMaxSize(int maxSize)
	{
		m_maxSize = maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	void SetGrowSize()
	{
		m_growSize += growValue;
		growValue *= 2;
		std::cout << "Current numElements = " << m_numElements << std::endl;
		std::cout << "New Max Size = " << m_maxSize << std::endl;
		std::cout << "New Grow Size = " << m_growSize << std::endl;
	}

	// Variables
	T* m_array; // points to the very first element of the array

	int m_maxSize; // maximum size of my array
	int m_growSize; // amount the array can grow thorugh expansion
	int m_numElements; // number of elements currently in the array
	int growValue;	// assignment purposes, will grow every time set grow size is called
};