/*
4/21/2017
Sam Kacprowicz
CS 200 Section 376
Lab10Part2.cpp
*/

#include <iostream>

using namespace std;

//	Function Prototypes
void printArray(const char *, ostream &, const int *, int howMany);

int main()
{
	int * info;
	int used;
	cout << "How many elements in the array? ";
	cin >> used;
	while (used <= 0)
	{
		cout << "Enter a value of 1 or more" << endl;
		cin >> used;
	}
	// 3 - WRITE THE CODE TO ACQUIRE THE MEMORY FOR THE ARRAY FROM THE HEAP
	int * xxx;
	xxx = new int [20];
	// 4 - USING SUBSCRIPTS WRITE THE CODE TO FILL THE ARRAY WITH MULTIPLES OF 3 -
	// - i.e. cell 0 holds 0, cell 1 holds 3, cell 2 holds 6, etc.
	for (int i = 0; i < used; i++)
	{
		xxx[i] = (i * 3);
	}

	//printArray("Array of data", cout, info, used);	<---- ASK DON IF THIS SHOULD REMAIN UNCHANGED
	printArray("Array of data", cout, xxx, used);

	// 5 - WRITE THE CODE TO RETURN THE MEMORY TO THE HEAP
	delete[] xxx;

	return 0;
}//ENDMAIN

void printArray(const char * m, ostream & Out, const int * p, int hm)
{
	Out << m << endl;
	for (int i = 0; i < hm; i++)
	{
		Out << p[i] << endl;
	}
}

/* --------------SAMPLE_OUTPUT-----------------
How many elements in the array? 10
Array of data
0
3
6
9
12
15
18
21
24
27
Press any key to continue . . .
*/