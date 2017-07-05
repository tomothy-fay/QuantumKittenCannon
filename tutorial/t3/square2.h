#ifndef SQUARE_H
#define SQUARE_H

// Include definition of the class Rectangle
#include "rectangle2.h"

class Square2 : public Rectangle2
{
public:
    Square2(double l_);
    
    // In a real application, no need to re-define
    // these function for Square2: the ones
    // inherited by Rectangle2 are already ok.
    // However we want to re-define them in order to
    // print that the perimeter and area are computed
    // for the Square, in order to show how
    // polymorphism works.
    double perimeter() const override;
    double area() const override;
};

#endif
