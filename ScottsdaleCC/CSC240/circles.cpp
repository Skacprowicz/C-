/**
 * @file circles.cpp
 * @author Sam Kacprowicz
 * @brief This program declares a class for a circle that will have 
 * member functions that set the center, find the area, find 
 * the circumference and display these attributes. 
 * The program as written does not allow the user to input data, but 
 * rather has the radii and center coordinates of the circles 
 * (spheres in the program) initialized at definition or set by a function.
 * @version 0.1
 * @date 2020-05-02
 * 
 * 
 */

#include <iostream>
using namespace std;

class Circles
{
public:
	void setCenter(int x, int y);
	double findArea();
	double findCircumference();
	void printCircleStats();									// This outputs the radius and center of the circle. 
	Circles(int x_center, int y_center);						// Constructor that inits center fields only.
	Circles(float r, int x_center, int y_center);				// Constructor, inits radius, and center fields.
	Circles(float r);											// Constructor, intis radius only.
	Circles();													// Default constructor, inits w/DEFAULT values.
	~Circles(){cout << "This concludes the Circle class.\n";};	// Destructor - sends message to USER upon freeing memory.
private:
	float	radius;
	int	center_x;
	int	center_y;
};

const double PI = 3.14;

// Client section 

int main()
{
	Circles sphere(8);
	sphere.setCenter(9, 10);
	sphere.printCircleStats();

	cout << "The area of the circle is " << sphere.findArea() << endl;
	cout << "The circumference of the circle is "
		 << sphere.findCircumference() << endl;


	// EXERCISE 2 BEGINS
	Circles sphere1(2);
	Circles sphere2;

	cout << endl;

	sphere1.printCircleStats();
	cout << "The area of the circle is " << sphere1.findArea() << endl;
	cout << "The circumference of the circle is "
		 << sphere1.findCircumference() << endl;

	cout << endl;

	sphere2.printCircleStats();
	cout << "The area of the circle is " << sphere2.findArea() << endl;
	cout << "The circumference of the circle is "
		 << sphere2.findCircumference() << endl;

	cout << endl;

	// EXERCISE 3 BEGINS
	Circles sphere3(15, 16);
	sphere3.printCircleStats();
	cout << "The area of the circle is " << sphere3.findArea() << endl;
	cout << "The circumference of the circle is "
		 << sphere3.findCircumference() << endl;

	return 0;
}

// __________________________________________________________________
//
// Implementation section	Member function implementation

/**
 * @brief Construct a new Circles:: Circles object
 * 
 */
Circles::Circles()
{
	this->radius = 1;
	this->center_x = 0;
	this->center_y = 0;
}

// Fill in the code to implement the non-default constructor
/**
 * @brief Construct a new Circles:: Circles object
 * 
 * @param num the value to which this circle object's radius field will be set. 
 */
Circles::Circles(float r)
{
	this->radius = r;
	this->center_x = 0;
	this->center_y = 0;
}

Circles::Circles(int x_center, int y_center)
{
	this->radius = 1;
	this->center_x = x_center;
	this->center_y = y_center;
}

/**
 * @brief Construct a new Circles:: Circles object
 * 
 * @param r 
 * @param x_center 
 * @param y_center 
 */
Circles::Circles(float r, int x_center, int y_center)
{
	this->radius = r;
	this->center_x = x_center;
	this->center_y = y_center;
}

// Fill in the code to implement the findArea member function
/**
 * @brief This member function will calculate and return the value of the circle's area.
 * 
 * @return float 
 */
double Circles::findArea()
{
	return PI * (this->radius * this->radius);	
}

// Fill in the code to implement the findCircumference member function
/**
 * @brief This member function will calculate and return the circumference of the circle.
 * 
 * @return float 
 */
double Circles::findCircumference()
{
	return 2 * PI *this->radius;
}

/**
 * @brief This procedure prints out the radius and center coordinates of 
 * the circle object that calls it.
 * 
 */
void Circles::printCircleStats()
{
	cout << "The radius of the circle is " << radius << endl;
	cout << "The center of the circle is (" << center_x
		 << ", " << center_y << ")" << endl;
}

/**
 * @brief This procedure will take the coordinates of the center of the circle from
 * the user and place them in the appropriate member data.
 * 
 * @param x 
 * @param y 
 */
void Circles::setCenter(int x, int y)
{
	center_x = x;
	center_y = y;
}