#include <iostream>
using std::cout; // Enable the use of cout without std::
using std::endl; // Enable the use of endl without std::

// To enable all the content of <iostream> you can use:
// using namespace std;

// Include header for Class Rectangle
# include "rectangle.h"

int main() // Main program
{
	// Create an instance of the Rectangle class named r
	// with sides of length 2 and 4
	Rectangle r(2,4);
	
	cout << "P: " << r.perimeter() << endl;
	cout << "A: " << r.area() << endl;

	return 0; // Return value of main() to the system
}