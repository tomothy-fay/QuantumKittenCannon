

#ifndef SINE_TRANSFORM_CPP_TEST_DISCRETESINETRANSFORMER_H
#define SINE_TRANSFORM_CPP_TEST_DISCRETESINETRANSFORMER_H

#include<fftw3.h>
#include<iostream>
#include<cmath>

using namespace std;

// This is the definition of the DiscreteSineTransformer2D class
//    This class performs 2D discrete sine transforms on input data.
//    Note: The transform is most efficient when 2*(n_x_grid_ + 1) = 2 ^ (M) for some integer M and likewise for n_y_grid_
class DiscreteSineTransformer2D
{
// These are the public member functions and variables
public:
    // This is the constructor for the DiscreteSineTransformer class
    DiscreteSineTransformer2D(int const num_x_grid_points, int const num_y_grid_points);
    // This is the default constructor for the DiscreteSineTransformer class if the grid sizes are not known
    DiscreteSineTransformer2D();
    // This is the destructor for the DiscreteSineTransformer class
    ~DiscreteSineTransformer2D();
    // This executes a discrete sine transform on the input function stored in the class array
    void ExecuteTransform(void);
    // This sets the input function from a pointer
    void SetInputFromPointer(double *input_pointer);
    // This gets the output function as a pointer
    double *GetOutputAsPointer(void);
    // This sets the input_function_ to the current output_function_
    void SetInputAsOutput(void);
    // This normalises the output function
    void NormaliseOutput(void);
    // This transforms a function input as a pointer
    void TransformInputPointer(double *input_pointer);
    // Sets a pointer equal to the output function
    void SetPointerToOutput(double *input_pointer);

// These are the protected member functions and variables
protected:
    // These variables store the number of x and y grid points and the total number of grid points
    int n_x_grid_, n_y_grid_, n_grid_ ;
    // This is the normalisation constant for the transform sqrt(1/(2(n_x_grid_+1)_)*sqrt(1/(2(n_y_grid_+1)_)
    double normalisation_constant ;
    // These are fftw pointers that store the input and output functions
    double *input_function_ , *output_function_ ;
    // This is an fftw plan, the transform is performed using this plan
    fftw_plan plan_sine_transform_ ;

};


#endif //SINE_TRANSFORM_CPP_TEST_DISCRETESINETRANSFORMER_H
