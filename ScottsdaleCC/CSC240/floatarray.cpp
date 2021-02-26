/**
 * @file floatarray.cpp
 * @author Sam Kacprowicz
 * 
 * @brief This program reads floating point data from a data file and places those 
 * values into the private data member called values (a floating point array) 
 * of the FloatList class. Those values are then printed to the screen. 
 * The input is done by a member function called GetList. The output 
 * is done by a member function called PrintList. The amount of data read in 
 * is stored in the private data member called length. The member function 
 * GetList is called first so that length can be initialized to zero.
 * 
 * @version 0.1
 * @date 2020-05-02
 * 
 * 
 */          

// Sam Kacprowicz

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_LENGTH = 50;		// MAX_LENGTH contains the maximum length of our list 
class FloatList					// Declares a class that contains an array of
								// floating point numbers
{
public:
	void getList(ifstream&);	// Member function that gets data from a file 
	void printList() const;		// Member function that prints data from that
								// file to the screen.
	void printAvg() const;		// Member function that computes and prints the
								// average temperature to the screen.
			

	FloatList();				// constructor that sets length to 0.
	~FloatList(){};				// destructor

private:
	int length;					//	Holds the number of elements in the array
	float values[MAX_LENGTH];	//	The array of values

};

int main()
{
	ifstream tempData;	// Defines a data file

	// Fill in the code to define an object called list of the class FloatList
	FloatList list;

	cout << fixed << showpoint;

	cout << setprecision(2);

	tempData.open("temperatures.txt");

	// Fill in the code that calls the getList function.
	list.getList(tempData);

	// Fill in the code that calls the printList function.
	list.printList();
	list.printAvg();

	return 0;
}

/**
 * @brief Construct a new Float List:: Float List object
 * 
 */
FloatList::FloatList()
{
	// Fill in the code to complete this constructor that
	// sets the private data member length to 0
	this->length = 0;
}

// Fill in the entire code for the getList function
// The getList function reads the data values from a data file
// into the values array of the class FloatList
/**
 * @brief Member function will read data in from a file, and store the data into the values array in the object.
 * 
 * @param stream name of ifstream object.
 */
void FloatList::getList(ifstream& stream)
{
	for(int i = 0; i < MAX_LENGTH && stream.good(); i++)
	{		
		stream >> this->values[i];	// Read data from file into the values array
		this->length++;				// Increment length field.
	}		
}

// Fill in the entire code for the printList function
// The printList function prints to the screen the data in
// the values array of the class FloatList
/**
 * @brief Member function will traverse through the values array and print the elements to the screen.
 * 
 */
void FloatList::printList() const
{
	for(int i = 0; i < length; i++)
	{
		cout << this->values[i] << endl;
	}
}

/**
 * @brief This method will calculate and print the average of the temperatures to the screen.
 * 
 */
void FloatList::printAvg() const
{
	float avg = 0;
	for(int i= 0; i < length; i++)
	{
		avg += this->values[i];
	}
	avg /= length;
	cout << "The average temperature is " << avg << endl;
}
