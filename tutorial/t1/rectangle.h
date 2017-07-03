// Header file. Here goes the definition of a Class.
// The implementation of the various methods (functions
// of the class) is made separately in a .cpp file.

// Preptocessor directives to avoid multiple inclusions
#ifndef RECTANGLE_H
#define RECTANGLE_H

/// Class Rectangle
///
/// This class defines the geometric figure Rectangle,
/// characterised by two sides of (possibly) different length
/// and defines the functions to compute the perimeter and the
/// area of the rectangle.
class Rectangle // Define class
{
public: // Define functions accessible for user
    /// Constructor with two sides
    Rectangle(double l1_, double l2_);
    
    /// Constructor for a square
    Rectangle(double l_);
    
    // Compute perimeter of the rectangle
    // No argument are necessary: the class already knows (owns)
    // all the data necessary to compute the perimeter.
    // The const keyword tells that the function can't modify
    // the members (variables) of the class (i.e. l1 and l2
    // can't be modified by this function).
    double perimeter() const;
    
    // Computer area of the rectanlge
    // No argument are necessary: the class already knows (owns)
    // all the data necessary to compute the area.
    // The const keyword tells that the function can't modify
    // the members (variables) of the class (i.e. l1 and l2
    // can't be modified by this function).
    double area() const;
    
    
protected: // Define internal variables/functions
    double l1; // First side of the rectangle
    double l2; // Second side of the rectangle

private:
    // The call to this function make sense only within
    // the class. This is why is declared as a private method.
    // This is an utility function for the class and can't be called
    // externally.
    //
    // [Remark for T2][Also, since this call is made only in the
    // constructor, there is no need to make it protected since
    // it won't be used by the derived class.]
    bool check_sides() const; // Check validity of sides
    
}; // Don't forget the semicolon!

#endif
