#include "matrix.h"
#include "test_matrix_mult.h"
int main ()
{

  matrix A(msize);
  matrix B(msize);
  for (unsigned int i = 0; i < msize; ++i)
    {
      A(i,i) = 10.0;
      A(i,msize-1) = 30.0;
      B(i,0) = 1.0;
      B(i,i) = 3.0;
    }

  std::cout << "msize = " << msize << std::endl;
  // matrix A(2);
  // matrix B(2);
  // B(1,0) = 4;
  // B(0,1) = 5;
  // B(1,1) = 9;
  // B(0,0) = 15;
  // A(1,0) = 6;
  // A(0,1) = 23;
  // A(1,1) = 56;
  // A(0,0) = 90;


  tic ();
  // matrix a = A.transpose();
  matrix C = A * B;
  toc ("multiply_time = ");
  //C.printmat();



  return 0;
}
