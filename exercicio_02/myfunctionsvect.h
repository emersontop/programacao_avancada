// esse arquivo.h deve ser declarada as funcoes, e as estruturas.
// sendo aqui declara as estruturas, podemos usar elas no arquvi de funcoes.cpp e no programa principal

#ifndef MYFUNCTIONSVECT_H
#define MYFUNCTIONSVECT_H

#include <string>

using namespace std;

struct vect{
  string name;
  int nbElement;
  float* p_vector;
};

void setVectorName(vect &A, string nome_da_struct);

void setVectorDimension(vect &A);

void allocateVectorMemory(vect &A);

void assignVectorValues(vect &A);

void printVector(vect A);

float vectorialProduct(vect A, vect B);

#endif