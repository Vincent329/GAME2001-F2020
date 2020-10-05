#include <iostream>
using namespace std;

// print down from  a given number until we reach 1

void PrintNumReverse(int x)
{
	// base case, the one that breaks out of the value
	if (x <= 0)
	{
		return;
	}

	// the actual work this function does

	cout << " " << x;

	// tail recursion
	PrintNumReverse(x - 1);
}

int main()
{
	cout << "recursion example" << endl;
	cout << "Here's our recursive call" << endl;
	PrintNumReverse(10);
	return 0;
}