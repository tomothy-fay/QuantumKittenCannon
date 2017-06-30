// These statements of the form "#include<...>" tell the compiler which libraries to link to
#include<iostream>
#include<cmath>
#include<time.h>

// This statement tells the compiler to include the header file for the DiscreteSineTransformer2D class
// This file contains the decalration of the class and all its members, and which libraries that class needs
#include "DiscreteSineTransformer2D.h"

// This tells the compiler that all variables are in the standard namespace this is just a way of organising code from
//  different libraries. Each library may have a different namespace if specified to avoid clashes. In this case all
//  functions and classes are in the standard std namespace so we have nothing to worry about.
using namespace std;

// This is the main program, it is a special function called "main" which must always return an integer. This is true
//  for all programs in c++.
int main()
{
  // This sets the number of dimensions on the x and y grids
  int num_x_grid_points = pow(2,9) - 1 ;
  int num_y_grid_points = pow(2,9) - 1 ;
  int num_grid_points = num_x_grid_points *  num_y_grid_points ;

  // This instantiates the DiscreteSineTransformer2D class with the specified number of x and y grid points
  DiscreteSineTransformer2D dst(num_x_grid_points, num_y_grid_points) ;

  // This creates a pointer to store the input function data
  double *input = new double [num_grid_points] ;

  // This sets the input function to f(x,y) = y/2 + 1 in a row major format
  for (int j = 0; j < num_y_grid_points; j++)
  {
    for (int i = 0 ; i < num_x_grid_points ; i++)
    {
      input[i + num_x_grid_points * j] = 0.5*j+1 ;
    }
  }

//  double *output = new double[num_grid_points];

  // timing the code
  clock_t start = clock() ;

  // Loops over 100 forward and backward sine transforms
  for (int i = 0 ; i < 100 ; i++)
  {
    // This sets the input for the transform
    dst.SetInputFromPointer(input);
    // This executes the transform
    dst.ExecuteTransform();
    // This sets the input function in dst to the output function
    dst.SetInputAsOutput();
    // This performs the transform again, inverting it
    dst.ExecuteTransform();
  }

  
//  output = dst.GetOutputAsPointer() ;
//  dst.TransformInputPointer(output) ;

//  for (int i = 0 ; i < num_grid_points ; i++)
//  {
//    cout << output[i] << " " ;
//  }
//  cout << endl ;
//  dst.TransformInputPointer(output) ;
//  cout << endl ;
//  for (int i = 0 ; i < num_grid_points ; i++)
//  {
//    cout << output[i] << " " ;
//  }
//  cout << endl;

  // finishes timing code
  clock_t stop = clock() ;
  double time =  ((double) stop - (double) start) / CLOCKS_PER_SEC ;
  cout << "Time elapsed: " << time << " seconds." << endl ;

  // These lines are required to free the memory of the created pointers to avoid all hell breaking loose.
  delete[] input ;
  delete[] output ;


  return 0;
}