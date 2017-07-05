#ifndef GOEMETRICFIGURE_H
#define GOEMETRICFIGURE_H

class GeometricFigure
{
public:
    // Compute perimeter of the rectangle
    // The function is declared as a pure (=0)
    // vistual function. This means that this function
    // has not to be implemented in this class.
    // This class can't be instanciated (i.e. we can't
    // create objects of this class in the program),
    // and its purpose is of concept abstraction.
    virtual double perimeter() const = 0;
    
    // Computer area of the rectanlge
    // Another pure virtual function.
    virtual double area() const = 0;
    
    // The class GeometricFigure contains multiple
    // pure virtual function. Derived classes have to
    // implement these functions in order to be used
    // in the main program. If a derived classes does
    // not implement all pure virtual functions (but none
    // only a few), they remain virtual classes.
    
    // For classes containing virtual functions, the
    // constructor has to be virtual as well!
    // Here the constructor is declared and implemented
    // (notice the empty body delimited by {}), so that
    // we don't have to create a .cpp file.
    // (Ok here, but always better to stick to the
    // .h/.cpp convention).
    virtual ~GeometricFigure() {};
};

#endif
