#include <iostream>
#include <string>
#include <math.h>
#include "myfunctions_vect.h"

using namespace std;

struct vect{
  string name;
  int nbElement;
  float* p_vector;
};

void setVectorName(vect &estrutura_1, string nome_da_struct){
    vect *estrutura = &estrutura_1;
    (*estrutura).name = nome_da_struct;
}