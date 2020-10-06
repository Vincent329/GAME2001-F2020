#include <iostream>
#include "Array.h"
#include "OrderedArray.h"
using namespace std;

int main()
{
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

	return 0;
}