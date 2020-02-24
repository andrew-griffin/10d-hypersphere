# include <stdio.h>
# include <stdlib.h>

int inside_sphere(double x1, double x2, double x3, double x4, double x5, double x6, double x7, double x8, double x9, double x10, double r0)
{
  // Equation of a 10-D hypersphere
  double radius2 = x1*x1 + x2*x2 + x3*x3 + x4*x4 + x5*x5 + x6*x6 + x7*x7 + x8*x8 + x9*x9 + x10*x10;

  // This part of the routine evaluates whether the input co-ordinates are inside the hypersphere
  if (radius2 < r0*r0)
    return 1;
  else
    return 0;
}  

int main(void)
{
  int i;
  double vol_sphere;
  double vol_box;

  // Radius of sphere
  double r0=1;

  // Loop over a million randomly generated co-ordinates
  for (i=1; i < 1000000; i++)
    {
      // Generate random numbers in the range [-1,1] for each co-ordinate
      double y1 = 2*((double)rand() / (double)RAND_MAX) - 1;
      double y2 = 2*((double)rand() / (double)RAND_MAX) - 1;
      double y3 = 2*((double)rand() / (double)RAND_MAX) - 1;
      double y4 = 2*((double)rand() / (double)RAND_MAX) - 1;
      double y5 = 2*((double)rand() / (double)RAND_MAX) - 1;
      double y6 = 2*((double)rand() / (double)RAND_MAX) - 1;
      double y7 = 2*((double)rand() / (double)RAND_MAX) - 1;
      double y8 = 2*((double)rand() / (double)RAND_MAX) - 1;
      double y9 = 2*((double)rand() / (double)RAND_MAX) - 1;
      double y10 = 2*((double)rand() / (double)RAND_MAX) - 1;

      // Add to volume of the sphere for each co-ordinate
      vol_sphere = vol_sphere + inside_sphere(y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,r0);
      // Add to volume of the box
      vol_box = vol_box + 1;
    }

  vol_box = vol_box/(2*2*2*2*2*2*2*2*2*2);

  printf("The volume of a 10-D hypersphere is %f \n", vol_sphere/vol_box);
  return 0;
}
    
      
