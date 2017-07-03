#include "square.h"

Square::Square(double l_)
: Rectangle(l_) // Initialise the base class
// The base class is initialised calling the base
// class constructor.
{
    // Nothing to do here...
    // The base class Rectangle is in charge
    // to check the validity of the square side l_
    // (via the private member check_sizes())
}
