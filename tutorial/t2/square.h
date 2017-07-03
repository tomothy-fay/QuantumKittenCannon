#ifndef SQUARE_H
#define SQUARE_H

// Include definition of the class Rectangle
#include "../t1/rectangle.h"

class Square : public Rectangle
{
public:
    // Constructor for a square
    // Needs only to know one side
    Square(double l_);
    
    // No need to re-define the functions
    // perimeter() and area(), since they are
    // inherited from the class Rectangle.
    
protected:
    // No need to re-define the members
    // l1 and l2 (sides), since they are inherited from
    // the class Rectangle.
};

#endif
