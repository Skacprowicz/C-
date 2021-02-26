/**
 * @file inventory.cpp
 * @author Sam Kacprowicz
 * 
 * @brief This program declares a class called Inventory that has itemnNumber (which 
 * contains the id number of a product) and numOfItem (which contains the 
 * quantity on hand of the corresponding product) as private data members. 
 * The program will read these values from a file and store them in an 
 * array of objects (of type Inventory). It will then print these values to the screen. 
 * 
 * @version 0.1
 * @date 2020-05-02 
 * 
 */
#include <iostream>
#include <fstream>
using namespace std;

// Example: Given the following data file:
//		986 8
//		432 24
//
// This program reads these values into an array of objects and prints the
// following:
//		Item number 986 has 8 items in stock
//		Item number 432 has 24 items in stock

const int NUMOFPROD = 10;		// This holds the number of products a store sells 

class Inventory
{
public:
	void getId(int item);		// This puts item in the private data member
								// itemNumber of the object that calls it. 

	void getAmount(int num);	// This puts num in the private data member
								// numOfItem of the object that calls it.

	void display();				// This prints to the screen
								// the value of itemNumber and numOfItem of the
								// object that calls it.

private:
	int	itemNumber;				// This is an id number of the product 
	int	numOfItem;				// This is the number of items in stock

};

int main()
{
	ifstream infile;	// Input file to read values into array 
	infile.open("Inventory.dat");

	if(infile.is_open()) cout << "\nFile opened successfully\n";
	else cout << "\nFile-open failure.\n";


	// Fill in the code that defines an array of objects of class Inventory
	// called products. The array should be of size NUMOFPROD
	Inventory products[NUMOFPROD];

	int pos;	// loop counter
	int id;		// variable holding the id number
	int total;	// variable holding the total for each id number

	// Fill in the code that will read inventory numbers and number of items
	// from a file into the array of objects. There should be calls to both
	// getId and getAmount member functions somewhere in this code.
	// Example: products[pos].getId(id); will be somewhere in this code
	while(infile.good())
	{
		infile >> id;
		products[pos].getId(id);
		infile >> total;
		products[pos].getAmount(total);
		pos++;
	}

	// Fill in the code to print out the values (itemNumber and numOfItem) for
	// each object in the array products.
	// This should be done by calling the member function display within a loop
	
	int len = sizeof(products)/sizeof(products[0]);	// This will give us the length of the array.
	for(int pos = 0; pos < len; pos++)
	{
		products[pos].display();
	}

	return 0;
}

// Write the implementations for all the member functions of the class.

/**
 * @brief 
 * 
 * @param item 
 */
void Inventory::getId(int item)
{
	this->itemNumber = item;
}

/**
 * @brief 
 * 
 * @param num 
 */
void Inventory::getAmount(int num)
{
	this->numOfItem = num;
}

/**
 * @brief This method will print the value of itemNumber and numOfItem of the object 
 * that calls it.
 * 
 */
void Inventory::display()
{
	cout << "Item number " << this->itemNumber << " has " << this->numOfItem << " in stock" << endl;
}