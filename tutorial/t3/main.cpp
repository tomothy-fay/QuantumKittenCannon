#include <iostream>
#include <vector>

using namespace std;

#include "geometricfigure.h"
#include "rectangle2.h"
#include "square2.h"

int main()
{
	// A Rectangle is a GeometricFigure
    // (by inheritance). Therefore a GeometricFigure*
    // (pointer to GeometricFigure), can point to a
    // Rectangle.
    GeometricFigure* GF1ptr = new Rectangle2(2,3);
    
    // To access attributes and members of
    // a class pointed by PTR, we have to use
    // the syntax PTR-> instead of PTR.
    // Can you guess the equivalent (cumbersome)
    // expression to PTR-> ?
    cout << GF1ptr->area() << endl;
    
    delete GF1ptr; // Delete Rectangle2 pointed by GF1prt
    GF1ptr = nullptr; // Invalidate the pointer
    
    // A Rectangle is a GeometricFigure
    // (by inheritance). Therefore a GeometricFigure*
    // (pointer to GeometricFigure), can point to a
    // Rectangle.
    GeometricFigure* GF2ptr = new Square2(2);
    
    cout << GF2ptr->area() << endl;
    
    delete GF2ptr; // Delete Square2 pointed by GF2prt
    GF2ptr = nullptr; // Invalidate the pointer
    
    // Here is where polymorphism is interesting...
    // We create a vector of pointers to
    // GeometricFigures, which can contain any
    // GeometricFigure (as Rectangle2 or Square2)
    vector<GeometricFigure*> GFcollection;
    
    // We add a few GeometricFigures
    GFcollection.push_back( new Rectangle2(1,2) );
    GFcollection.push_back( new Square2(1) );
    
    cout << endl << endl;
    for(int i(0); i < GFcollection.size(); i++)
    {
        cout << GFcollection[i]->perimeter() << endl;
        cout << GFcollection[i]->area() << endl;
    }
    
    // Delete objects
    for(int i(0); i < GFcollection.size(); i++)
    {
        delete GFcollection[i];
        GFcollection[i] = nullptr;
    }

	return 0;
}
