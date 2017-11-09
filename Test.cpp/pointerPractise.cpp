#include <iostream>

using namespace std;
 
//	Function Prototypes
int getArraySize();

//	Global Variables
int MAX_SIZE;

int main()
{
	getArraySize();

	int a[MAX_SIZE];
	int * p;
	p = a;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		int in;
		cout << "Enter element No." << ( i + 1 ) << "'s value: ";
		cin >> in;
		*p = in;
		p++;
	}
	for ( int j = 0; j < MAX_SIZE; j++)
	{
		cout << "The value of element No." << ( j + 1 ) << " equals: " << a[j] << endl;
	}

	return 0;
}	//	ENDMAIN

//	Function definitions
int getArraySize()
{
cout << "How many elements would you like your array to have?\n";
	cout << "Number of Elements: ";
	cin >> MAX_SIZE;
	return MAX_SIZE;
}