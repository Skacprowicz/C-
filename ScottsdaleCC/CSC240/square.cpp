/**
 * @file square.cpp
 * @author Sam Kacprowicz
 * @brief This program will demonstrate the student's ability to build and use a class in C++. 
 * @version 0.1
 * @date 2020-05-02
 * 
 * 
 */

// This program declares the Square class and uses member functions to find
// the perimeter and area of the square

// Sam Kacprowicz

#include <iostream>
using namespace std;

// FILL IN THE CODE TO DECLARE A CLASS CALLED Square. TO DO THIS SEE
// THE IMPLEMENTATION SECTION.
class Square
{
	public:
		// CONSTRUCTORS
		Square( float s){ this->side = s;};	// Constructor w/USER initilization of FIELDS.
		Square(){ this->side = 1;};			// Default constructor. 
		
		// DESTRUCTOR
		~Square(){};						

		// MEMBER FUNCTIONS
		void setSide(float);				// Mutator method to change value of side field.
		float findArea();					// Calculates and returns area of square
		float findPerimeter();				// Calculates and returns the perimeter of the square
	
	private:
		float side;							// Stores the length of one side of the square.
};

int main()
{
	Square box;	// box is defined as an object of the Square class
	float size;	// size contains the length of a side of the square

	// FILL IN THE CLIENT CODE THAT WILL ASK THE USER FOR THE LENGTH OF THE
	// SIDE OF THE SQUARE. (This is stored in size)
	cout << "Please input the length of the side of the square" << endl;
	cin >> size; 

	// FILL IN THE CODE THAT CALLS SetSide.
	box.setSide(size);

	// FILL IN THE CODE THAT WILL RETURN THE AREA FROM A CALL TO A FUNCTION
	// AND PRINT OUT THE AREA TO THE SCREEN.
	cout << "The area of the square is " << box.findArea() << endl;

	// FILL IN THE CODE THAT WILL RETURN THE PERIMETER FROM A CALL TO A
	// FUNCTION AND PRINT OUT THAT VALUE TO THE SCREEN.
	cout << "The perimeter of the square is " << box.findPerimeter() << endl; 


	// EXERCISE 2 BEGINS HERE
	Square box1(9);							// Init box1.side == 9;
	cout << "The area of box1 is " << box1.findArea() << endl;
	cout << "The perimeter of box1 is " << box1.findPerimeter() << endl; 

	return 0;
}

// _______________________________________________________
//
// Implementation section	Member function implementation

//**************************************************
//  setSide
//
//  task:	 This procedure takes the length of a side and
//	         places it in the appropriate member data
//  data in: length of a side
//***************************************************

void Square::setSide(float length)
{
	side = length;
}

//**************************************************
//	findArea
//
//  task:	       This finds the area of a square
//  data in:       none (uses value of data member side)
//  data returned: area of square
//***************************************************

float Square::findArea()
{
	return side * side;
}

//**************************************************
//	findPerimeter
//
//  task:	       This finds the perimeter of a square
//  data in:       none (uses value of data member side)
//  data returned: perimeter of square
//***************************************************

float Square::findPerimeter()
{
	return 4 * side;
}

