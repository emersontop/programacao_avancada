#include <iostream>
#include <string>
#include <math.h>
#include "myfunctionsmatrix.h"

using namespace std;

void setMatrixName(matrix &A, string nome_matriz){
  matrix *p_matrix_a = &A;
  (*p_matrix_a).name = nome_matriz;
}

void setMatrixDimensions(matrix &A){
  matrix *p_matrix_a = &A;
  cout << "Quantas colunas voce quer?" << endl;
  cin >> (*p_matrix_a).nbCol;
  cout << "Quantas linhas voce quer?" << endl;
  cin >> (*p_matrix_a).nbLin;
  cout << "Essa sera uma matrix " << (*p_matrix_a).nbLin << " X " << (*p_matrix_a).nbCol << endl;
}

void allocateMatrixMemory(matrix &A){
  matrix *p_matrix_a = &A;
  //linhas
  //p_matriz dentro da struct e um ponteiro de ponteiros ela aponta para um endereco que aponta para outro endereco
  //entao primeiro fazemos uma alocacao de memoria para a quantidade de ponteiros que ela vai apontar por isso ela recebe new float* (um vetor de ponteiros)
  (*p_matrix_a).p_matrix = new float*[(*p_matrix_a).nbLin];
  for(int i=0;i<(*p_matrix_a).nbLin;i++){
    (*p_matrix_a).p_matrix[i]= new float [(*p_matrix_a).nbCol];
  }
}

void assignMatrixValues(matrix &A){
  matrix *p_matrix_a = &A;

  // for para as linhas
  for(int i=0;i<(*p_matrix_a).nbLin;i++){
    //for para as colunas
    for(int j=0;j<(*p_matrix_a).nbCol;j++){
      cout << "Digite o valor de ordem: [" << i << "] e [" << j << "]" << endl;
      cin >> (*p_matrix_a).p_matrix[i][j];
      //aqui, (*p_matrix_a) ess trexo, representa que eu estou alterando dentro do valor da struct, para altera os valores da matriz eu nao preciso do **, pois ja usamos o [][] que e semelhante ao uso de ponteiros
    }
  }
}

void printMatrix(matrix A){
  for(int i=0;i<A.nbLin;i++){
    for(int j=0;j<A.nbCol;j++){
      cout << A.p_matrix[i][j] << "\t";
    }
    cout << endl;
  }
}

void multiplyMatrices(matrix A,matrix B,matrix &C){
  if(A.nbCol!=B.nbLin){
    cout << "Temos um erro, matrizes nao podem ser muitiplicadas"<<endl;
  }
  else{
    matrix *p_matrix_c = &C;
    (*p_matrix_c).nbLin = A.nbLin;
    (*p_matrix_c).nbCol = B.nbCol;
    allocateMatrixMemory(C);
    float aux;
    //linha
    for(int i=0;i<A.nbLin;i++){
    
      for(int j=0;j<B.nbCol;j++){

        for(int k=0;k<B.nbLin;k++){
          aux += A.p_matrix[i][k]*B.p_matrix[k][j];
        }
        (*p_matrix_c).p_matrix[i][j] = aux;
        aux=0;
      }
    }
  }
}