#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "myfunctionsvect.h"

using namespace std;

int main ()
{
  // Declare 2 vectors;
  vect A;
  vect B;

  // Initialize vector A
  setVectorName(A, "A");
  setVectorDimension(A);
  allocateVectorMemory(A);
  assignVectorValues(A);
  printVector(A);

  // Initialize vector B
  setVectorName(B, "B");
  setVectorDimension(B);
  allocateVectorMemory(B);
  assignVectorValues(B);
  printVector(B);

  // Compute A*B
  float result = vectorialProduct(A,B);
  //cout << A.name << "*" << B.name << " = " << result << endl;
  return 0;
}
