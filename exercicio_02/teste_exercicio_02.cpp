//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\exercicio_02'
//g++ teste_exercicio_02.cpp myfunctions_vect.cpp -o prog
//./prog 

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "myfunctions_vect.h"

using namespace std;

int main ()
{
  // Declare 2 vectors;
  vect A;
  vect B;
  setVectorName(A,"alberto");
  cout << A.name;
  return 0;
}
