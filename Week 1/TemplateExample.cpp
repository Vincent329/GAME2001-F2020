#include <iostream>
using namespace std;

// Check 2 things and return the smallest

template <class T>

T min_func(T lVal, T rVal) // Takes 2 values of type T. when this function is called, all these Ts are of the same type
{
	if (lVal > rVal)
	{
		return rVal;
	}
	return lVal;
}

// check 2 things, return the largest

template <class T>
T max_func(T lVal, T rVal)
{
	if (lVal < rVal)
	{
		return rVal;
	}
	return lVal;
}

// implement a template class here

template <class T>
class TemplateClass
{
public:
	TemplateClass(T val)
	{
		m_val = val;
	}
	
	// overload > amd < operators
	bool operator<(TemplateClass& rVal)
	{
		return m_val < rVal.getVal();
	}
	bool operator>(TemplateClass& rVal)
	{
		return m_val > rVal.getVal();
	}

	T getVal()
	{
		return m_val;
	}
private:
	T m_val; // creating objects of type template class
};

// main
int main()
{
	cout << "Template Sample" << endl << endl;
	cout << "Min = " << min_func('c', 'd') << endl;
	cout << "Max = " << max_func(56.1, 43.6) << endl;

	// create 2 "TemplateClass" objects and compare them
	// when doing a comparison, if it not one of the C++ built in data types, C++ will have no idea

	cout << "Max (objects) = " << max_func(TemplateClass<int>(7), TemplateClass<int>(4)).getVal() << endl;
	return 0;
}