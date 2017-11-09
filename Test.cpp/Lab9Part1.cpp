/*
@ 4/9/2017
@ Lab9Part1.cpp
@ Sam Kacprowicz
@ CS 200 Section 376
*/

#include <iostream>

using namespace std;

//	Function Prototypes
void addLetterS(const char orig[], char plural[]);

//	Global Variables
const int MAXSIZE = 15;

int main()
{
	char school[MAXSIZE];

	cout << "Enter a word:\n";
	cin >> school;

	char word[10];
	addLetterS(school, word); // copy word into school and add an 's' to the end
	cout << word << endl;      // will output the contents of word i.e. "schools"

	return 0;
}

//	Function Definitions
void addLetterS(const char orig[], char plural[])
{
	int i = 0;
	for ( i; orig[i]; i++)
	{
		/*
		if (!orig[i])
		{
			plural[i] = "s";
		}
		*/
		plural[i] = orig[i];
		if ( orig[i] == (char)0 )
		{
			plural[i] = 's';
			i =12;
		}
	}
	

}
/*
Enter a word:
school
school?s????????????school
Press any key to continue . . .
*/