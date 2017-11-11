#include <iostream>
#include <string>

using namespace std;

//	Structures
struct Person
{
	string name;
	string bDay;
	int age;
};

//	Function Prototypes------
void setAge(struct Person &);
void getbDay(struct Person &);
void getName(struct Person &);
void displayInfo(struct Person);

int main()
{
	Person Bertram;

	getName(Bertram);
	setAge(Bertram);
	getbDay(Bertram);
	displayInfo(Bertram);

	return 0;
}	//	END MAIN

//	Function Definitions
void setAge(struct Person & Bertram)	 
{
	cout << "What is your age? " << endl;
	cin >> Bertram.age;
}

void getbDay(struct Person & Bertram)
{
	cout << "Enter your Birthday (MM/DD/YYYY): " << endl;
	cin >> Bertram.bDay;
}

void getName(struct Person & Bertram)
{
	cout << "What is your name? " << endl;
	cin >> Bertram.name;
}

void displayInfo(struct Person Bertram)
{
cout << "Your name is: " << Bertram.name << endl;
cout << "Your age is: " << Bertram.age << endl;
cout << "Your Birthday is: " << Bertram.bDay << endl;
}