//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\exercicio_02'
//g++ teste_exercicio_02.cpp myfunctions_vect.cpp -o prog
//./prog 

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "myfunctionsmatrix.h"

using namespace std;

int main ()
{
  // Declare 2 vectors;
  matrix A;
  matrix B;
  matrix C;

  setMatrixName(A, "A");
  setMatrixDimensions(A);
  allocateMatrixMemory(A);
  assignMatrixValues(A);
  printMatrix(A);

  return 0;
}
