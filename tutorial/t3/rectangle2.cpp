// .cpp file containing the definition of the different methods
// of a class.

#include "rectangle2.h"

#include <cassert>
#include <iostream>

Rectangle2::Rectangle2(double l1_, double l2_)
: l1(l1_), l2(l2_) // We initialise here
{
    // Assert that sides are valid numbers
    assert(check_sides() == true);
}

double Rectangle2::perimeter() const
{
    std::cout << "Computing perimeter of Rectangle..." << std::endl;
    
    return 2*l1 + 2*l2;
}

double Rectangle2::area() const
{
    std::cout << "Computing area of Rectangle..." << std::endl;
    
    return l1 * l2;
}

bool Rectangle2::check_sides() const
{
    // Check if the sided are defined by positive numbers
    if(l1 < 0 or l2 < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
