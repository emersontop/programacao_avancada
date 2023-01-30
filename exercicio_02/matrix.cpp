#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "myfunctionsmatrix.h"

using namespace std;


int main ()
{
  // Declare 3 matrices
  matrix A;
  matrix B;
  matrix C;

  // Initialize matrix A
  setMatrixName(A, "A");
  setMatrixDimensions(A);
  allocateMatrixMemory(A);
  assignMatrixValues(A);
  printMatrix(A);

  // Initialize matrix B
  setMatrixName(B, "B");
  setMatrixDimensions(B);
  allocateMatrixMemory(B);
  assignMatrixValues(B);
  printMatrix(B);

  // Compute C = A*B
  setMatrixName(C, "C");
  multiplyMatrices(A,B,C);
  cout << "Matriz c" << endl;
  printMatrix(C);
  return 0;
}
