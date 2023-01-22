// esse arquivo.h deve ser declarada as funcoes, e as estruturas.
// sendo aqui declara as estruturas, podemos usar elas no arquvi de funcoes.cpp e no programa principal

#ifndef MYFUNCTIONSMATRIX_H
#define MYFUNCTIONSMATRIX_H

#include <string>

using namespace std;

struct matrix{
  string name;
  int nbCol;
  int nbLin;
  float** p_matrix;
};

void setMatrixName(matrix &A, string nome_matriz);

void setMatrixDimensions(matrix &A);

void allocateMatrixMemory(matrix &A);

void assignMatrixValues(matrix &A);

void printMatrix(matrix A);

void multiplyMatrices(matrix A,matrix B,matrix &C);

#endif