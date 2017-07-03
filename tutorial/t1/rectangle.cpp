// .cpp file containing the definition of the different methods
// of a class.

#include "rectangle.h"

#include <cassert>

Rectangle::Rectangle(double l1_, double l2_)
: l1(l1_), l2(l2_) // We initialise here
{
    // Assert that sides are valid numbers
    assert(check_sides() == True);
}

Rectangle::Rectangle(double l_)
: l1(l_), l2(l_)
{    
    // Assert that sides are valid numbers
    assert(check_sides() == true);
}

double Rectangle::perimeter() const
{
    return 2*l1 + 2*l2;
}

double Rectangle::area() const
{
    return l1 * l2;
}

bool Rectangle::check_sides() const
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