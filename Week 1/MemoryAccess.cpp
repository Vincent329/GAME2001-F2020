#include <time.h>
#include <iostream>
using namespace std;

const int n = 750;
float TestData[n][n][n];

// Create helper class, to figure out a difference in time
// compare access time by doing operations on the same data
// how many operations to complete it

// Helper function to convert clock ticks to milliseconds
// get 2 clock ticks in between doing an operation and converting to ms
double diffClock(clock_t clock1, clock_t clock2)
{
	double diffticks = clock1 - clock2; // difference between 2 separate clock ticks
	double diffms = (diffticks * 10) / CLOCKS_PER_SEC;
	return diffms;
}

// add values row by row
void row_ordered()
{
	for (int i = 0;  i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++) // rows
			{
				TestData[i][j][k] = 1;
			}
		}
	}
}

// add values column by column

void column_ordered()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++) // rows
			{
				TestData[k][j][i] = 1;
			}
		}
	}
}

int main()
{
	clock_t begin = clock();
	column_ordered();
	clock_t end = clock();
	cout << " time elapsed (rows): " << diffClock(end, begin) << " ms" << endl;
	
	return 0;
}