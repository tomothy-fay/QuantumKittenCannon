#include <iostream>

// Include definition of the class Square
#include "square.h"

int main()
{
    // Create an instance of the classe Square
    Square s(3);
    
    // Here we use std::cout and std::endl since we didn't
    // decleared one of the following:
    //     using std::cout; using std::endl;
    // or
    //     using namespace std;
    std::cout << "P: " << s.perimeter() << std::endl;
    std::cout << "A: " << s.area() << std::endl;
    
    return 0;
}
