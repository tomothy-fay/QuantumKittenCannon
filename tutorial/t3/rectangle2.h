#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "geometricfigure.h"

class Rectangle2 : public GeometricFigure // Define class
{
public: // Define functions accessible for user
    /// Constructor with two sides
    Rectangle2(double l1_, double l2_);
    
    // Compute perimeter of the rectangle
    // Implement the pure virtual function,
    // inherited from GeometricFigure.
    // This is denoted by the keyword override,
    // which is not mandatory!
    double perimeter() const override;
    
    // Computer area of the rectanlge
    // Implement the pure virtual function,
    // inherited from GeometricFigure.
    // This is denoted by the keyword override,
    // which is not mandatory!
    double area() const override;
    
    
protected: // Define internal variables/functions
    double l1;
    double l2;

private:
    bool check_sides() const; // Check validity of sides
    
};

#endif
