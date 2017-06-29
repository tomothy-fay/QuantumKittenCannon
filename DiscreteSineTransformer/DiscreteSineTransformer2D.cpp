#include "DiscreteSineTransformer2D.h"

// This is the DiscreteSineTransformer class constructor when the number of x grid poits and y grid points are known
//    at instantiation.
// The transform is most efficient when 2*(n_x_grid_ + 1) = 2 ^ (M) for some integer M and likewise for n_y_grid_
DiscreteSineTransformer2D::DiscreteSineTransformer2D(int const num_x_grid_points, int const num_y_grid_points)
{
  // Sets the number of x grid and y grid points
  n_x_grid_ = num_x_grid_points ;
  n_y_grid_ = num_y_grid_points ;
  n_grid_ = n_x_grid_ * n_y_grid_ ;
  // This calculates the normalisation constant for the transform sqrt(1/(2(n_x_grid_+1)_)*sqrt(1/(2(n_y_grid_+1)_)
  normalisation_constant = 0.5 * sqrt( 1.0 / ( (n_y_grid_+ 1) * (n_x_grid_ + 1) ) ) ;

  // Allocates the input and output function dimensions
  input_function_ = (double*) fftw_malloc(n_grid_ * sizeof(double)) ;
  output_function_ = (double*) fftw_malloc(n_grid_ * sizeof(double)) ;

  // Creates the fftw plan for the 2D discrete sine transform
  plan_sine_transform_ = fftw_plan_r2r_2d(n_x_grid_, n_y_grid_, input_function_, output_function_ ,
                                          FFTW_RODFT00, FFTW_RODFT00, FFTW_PATIENT);

  return ;
}

// The default constructor for the DiscreteSineTransform2D class default size is 1
DiscreteSineTransformer2D::DiscreteSineTransformer2D()
{
  // Sets the number of x grid and y grid points defaults to 1
  n_x_grid_ = 1 ;
  n_y_grid_ = 1 ;
  n_grid_ = n_x_grid_ * n_y_grid_ ;

  // Allocates the input and output function dimensions
  input_function_ = (double*) fftw_malloc(n_grid_ * sizeof(double)) ;
  output_function_ = (double*) fftw_malloc(n_grid_ * sizeof(double)) ;

  // Creates the fftw plan for the 2D discrete sine transform
  plan_sine_transform_ = fftw_plan_r2r_2d(n_x_grid_, n_y_grid_, input_function_, output_function_ ,
                                          FFTW_RODFT00, FFTW_RODFT00, FFTW_ESTIMATE);
}

// The destructor for the DiscreteSineTransform class to free memory
DiscreteSineTransformer2D::~DiscreteSineTransformer2D()
{
  // To avoid a terrible fate, all memory must be freed when an instantiation of a class is deleted ...
  fftw_free(input_function_) ;
  fftw_free(output_function_) ;
  fftw_destroy_plan(plan_sine_transform_) ;
}

// This normalises the output function
void DiscreteSineTransformer2D::NormaliseOutput()
{
  for (int i = 0 ; i < n_grid_ ; i++)
  {
    output_function_[i] *= normalisation_constant;
  }
  return;
}

// This executes the 2D discrete sine transform on whatever the input function is
void DiscreteSineTransformer2D::ExecuteTransform()
{
  // This executes the plan defined in the constructor
  fftw_execute(plan_sine_transform_);
  // This normalises the output function
  NormaliseOutput();
  return;
}

// Set the input data as a pointer
void DiscreteSineTransformer2D::SetInputFromPointer(double *input_pointer)
{
  // This loop sets each value of the input function to that of the input function in the pointer passed
  for (int i = 0 ;  i < n_grid_ ; i++)
  {
    input_function_[i] = input_pointer[i];
  }
  return ;
}

// Gets the output function as a pointer
double *DiscreteSineTransformer2D::GetOutputAsPointer()
{
  // Creates the output pointer
  double *output_pointer = new double [n_grid_] ;
  // Sets the output pointer to the output function values
  for (int i = 0 ; i < n_grid_ ; i++)
  {
    output_pointer[i] = output_function_[i];
  }
  // This returns the output pointer
  return output_pointer ;
}

// Sets the input function as the current output function
void DiscreteSineTransformer2D::SetInputAsOutput()
{
  // This loops over all elements of the input_function_ and sets it equal to the value of the output_function_
  for (int i = 0 ; i < n_grid_ ;  i++)
  {
    input_function_[i] = output_function_[i] ;
  }
  return;
}

// Transforms the function passed to it as a pointer
void DiscreteSineTransformer2D::TransformInputPointer(double *input_pointer)
{
  // This sets the input function to what it is in the input function
  SetInputFromPointer(input_pointer) ;
  // This executes the 2D discrete sine transform
  ExecuteTransform() ;
  // This sets the input pointer to the output pointer
  SetPointerToOutput(input_pointer) ;
  return;
}

// Set an pointer equal to the output function
void DiscreteSineTransformer2D::SetPointerToOutput(double *input_pointer)
{
  for (int i = 0 ; i < n_grid_ ; i++)
  {
    input_pointer[i] = output_function_[i] ;
  }
  return;
}