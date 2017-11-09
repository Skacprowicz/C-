/*
4/21/2017
Sam Kacprowicz
CS 200 Section 376
Lab10Part1.cpp
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

//	Function prototypes
void printArray(const char * m, ostream & Out, const int * p, int hm);
void fillArray(int * p, int howMany);
int largeArray(const int data[], int howMany);
int largePointer(const int * data, int howMany);

/*
int largeArray(const int[], int);
int largePointer(const int *, int);
void fillArray(int *, int howMany);
void printArray(const char *, ostream &, const int *, int howMany);
*/

//	Global Variables
const int low = 50;
const int high = 90;

int main()
{
	const int MAX_SIZE = 40;
	int info[MAX_SIZE];
	int used;
	int * p1;
	p1 = info;

	cout << "How many elements in the array? ";
	cin >> used;
	while (used <= 0 || used > MAX_SIZE)
	{
		cout << "Enter a value between 1 and " << MAX_SIZE << "How many elements in the array? ";
		cin >> used;
	}
	fillArray(info, used);
	printArray("Array of data", cout, info, used);

	cout << "The largest element using subscripts is " << largeArray(info, used) << endl;
	cout << "The largest element using pointers is " << largePointer(info, used) << endl;

	return 0;
}

//ENDMAIN

void printArray(const char * m, ostream & Out, const int * p, int hm)
{
	Out << m << endl;
	for (int i = 0; i < hm; i++)
	{
		Out << p[i] << endl;
	}
}

void fillArray(int * p, int howMany) // as parameters, pointers and arrays are one and the same
{
	int range = high - low + 1;
	srand(time(0));
	for (int i = 0; i < howMany; i++)
	{
		p[i] = rand() % range + low;
	}
}

int largeArray(const int data[], int howMany) // use subscripts
{
	int largest = 0;
	// 1 - WRITE THE CODE TO FIND THE LARGEST NUMBER - USE SUBSCRIPTS TO ACCESS THE ELEMENTS 
	for (int i = 0; i < howMany; i++)
	{
		if (data[i] > largest)
		{
			largest = data[i];
		}
	}
	return largest;
}

int largePointer(const int * data, int howMany) // use pointers
{
	int largest = 0;
	// 2 - WRITE THE CODE TO FIND THE LARGEST NUMBER - USE POINTERS TO ACCESS THE ELEMENTS
	for ( int i = 0; i < howMany; i++ )
	{
		if ( (*data) > largest )
		{
			largest = (*data);
		}
		data++;
	}
	return largest;
}
/*
How many elements in the array? 10
Array of data
64
77
53
90
80
70
70
52
66
86
The largest element using subscripts is 90
The largest element using pointers is 90
Press any key to continue . . .
*/