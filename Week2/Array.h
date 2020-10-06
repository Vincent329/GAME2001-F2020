#pragma once
#include <cassert>

template <class T>
class Array
{
public:
	Array(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];	// Dynamically allocated new array
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
			growValue = 1;
		}
	}
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
	int getMaxSize()
	{
		return m_maxSize;
	}
	int getGrowSize()
	{
		return m_growSize;
	}
	int setGrowSize()
	{
		m_growSize += growValue; // IMPORTANT FOR THE ASSIGNMENT, AS IT NEEDS TO INCREMENT BY DOUBLE EACH TIME
		growValue *= 2;
		std::cout << "New growSize = " << m_growSize << std::endl;
	}

private:
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
		T* m_array; // points to the very first element of the array

		int m_maxSize; // maximum size of my array
		int m_growSize; // amount the array can grow thorugh expansion
		int m_numElements; // number of elements currently in the array
		int growValue;	// assignment purposes, will grow every time set grow size is called
};