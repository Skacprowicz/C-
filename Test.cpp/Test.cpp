#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//-----Structures------
struct Person
{
	string firstName;
	string lastName;
	string DOB;

};

//	Function Definitions
void setFirstName(Person & x);
void setLastName(Person &);
void setDOB(Person &);

int getNumberOfEmployees();
void displayInfo( Person x[]);


//-----GLOBAL VARIABLES------
int MAXSIZE;	// needs to be used for number of employees in Employee array

int main()
{
	getNumberOfEmployees();	//	Allows user to define MAXSIZE value
	Person * Employee = new Person[MAXSIZE];	//	Makes a pointer to an array
	
	for (int i = 0; i < MAXSIZE; i++)
	{
		setFirstName(Employee[i]);
		setLastName(Employee[i]);
		setDOB(Employee[i]);
	}

	displayInfo(Employee);

	delete [] Employee;	//	Frees memory 

	return 0;
}	//------END MAIN----

//------POSSIBLE MEMBER FUNCTIONS-----------
void setFirstName(Person & x)
{
	cout << "Enter employee's first name: ";
	cin >> x.firstName;
}
void setLastName(Person & x)
{
	cout << "Enter employee's last name: ";
	cin >> x.lastName;
}
void setDOB(Person & x)
{
	cout << "Enter employee's birthday (DD/MM/YYYY): ";
	cin >> x.DOB;
}
void displayInfo( Person x[])
{
	cout << endl << "Employee's Name: " << setw(20) << "Employee's DOB (DD/MM/YYYY): " << endl;
	for (int i = 0; i < MAXSIZE; i++)
	{
	cout << x[i].firstName << setw(10) << x[i].lastName << setw(15) << x[i].DOB << endl;
	}
}
int getNumberOfEmployees()
{
	cout << "How many employees?\n";
	cout << "Number of employees: ";
	cin >> MAXSIZE;
	return MAXSIZE;
}