#ifndef MYFUNCTIONS_VECT_H
#define MYFUNCTIONS_VECT_H

#include <string>

using namespace std;

struct vect{
  string name;
  int nbElement;
  float* p_vector;
};

void setVectorName(vect A, string nome_da_struct);

#endif