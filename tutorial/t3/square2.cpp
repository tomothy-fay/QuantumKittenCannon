#include "square2.h"

#include <iostream>

Square2::Square2(double l_)
: Rectangle2(l_,l_) // Initialise the base class
{
    // Nothing to do here...
}

double Square2::perimeter() const
{
    std::cout << "Computing perimeter of Square..." << std::endl;
    
    return 2*l1 + 2*l2;
}

double Square2::area() const
{
    std::cout << "Computing area of Square..." << std::endl;
    
    return l1 * l2;
}
