#include <iostream>
#include "Array.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"
using namespace std;

int main()
{
	cout << "assignment 1 test" << endl;
	cout << "Recursive Binary Search Example" << endl;

	OrderedArray<int> array(3); // initial size is going to be 3

	// Test the expansion of the array
	array.push(43);
	array.push(8);
	array.push(23);
	array.push(94);
	array.push(17);
	array.push(83);
	array.push(44);
	array.push(28);

	cout << "Ordered Array Contents: ";

	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << " " << array[i];
	}

	cout << endl << endl;
	cout << "Search for 43 was found at index" << endl << endl;
	cout << array.search(43) << endl;
	cout << endl << endl;
	cout << "Current Size of OrderedArray: " << array.GetSize() << endl;
	cout << "calling SetGrow 3 Times" << endl << endl;
	array.SetGrowSize();
	cout << array.GetSize() << endl;
	array.SetGrowSize();
	cout << array.GetSize() << endl;
	array.SetGrowSize();
	cout << array.GetSize() << endl;


	
	cout << "Merge Sort Algorithm" << endl;

	UnorderedArray<int> uarray(5);
	uarray.push(80);
	uarray.push(64);
	uarray.push(99);
	uarray.push(76);
	uarray.push(5);

	cout << "Before sort: ";
	for (int i = 0; i < uarray.GetSize(); i++)
	{
		cout << " " << uarray[i];
	}

	cout << endl;

	uarray.MergeSort();

	cout << "After sort: ";
	for (int i = 0; i < uarray.GetSize(); i++)
	{
		cout << " " << uarray[i];
	}

	cout << endl << endl;

	return 0;
}