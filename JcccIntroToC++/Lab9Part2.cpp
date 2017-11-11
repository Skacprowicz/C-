/*
@ 4/9/2017
@ Lab9Part2.cpp
@ Sam Kacprowicz
@ CS 200 Section 376
*/

#include <iostream>
using namespace::std;

//	Global Variables
const int MAX_SIZE = 15;     // Max word size of word, 14 chars plus  '\0'

//	Functions Prototypes
void reverse(char word[]);    // function prototype

int main()
{
	char word[MAX_SIZE];
	cout << endl << "Enter a word: ";  cin >> word;
	cout << "You entered the word: " << word << endl;
	reverse(word);
	cout << "The word in reverse order is " << word << endl;

	return 0;
}//END MAIN

void reverse(char word[])
{
	// you cannot have any local array variables inside this function
	int left = 0, right, eleCount = 0;

	for (int i = 0; word[i]; i++)
	{
		right = (eleCount);
		eleCount++;
	}
	//cout << "Element count: " << right << endl;
	for (right; right >= left; right--)
	{
		char temp = word[left];

		word[left] = word[right];
		word[right] = temp;
		left++;
	}
}

/*
Enter a word: itworks!
You entered the word: itworks!
The word in reverse order is !skrowti
Press any key to continue . . .
*/