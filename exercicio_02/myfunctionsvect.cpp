#include <iostream>
#include <string>
#include <math.h>
#include "myfunctionsvect.h"

using namespace std;

void setVectorName(vect &A, string nome_da_struct){
  //argumentos (endereco da estrutura, string pela qual vamos alterar o nome da estrutura)
  vect *p_estrutura = &A;
  (*p_estrutura).name = nome_da_struct;
}

void setVectorDimension(vect &A){
  //argumentos (endereco da estrutura)
  vect *p_estrutura = &A;
  cout << "Digite o tamanho do vetor?" << endl;
  cin >> (*p_estrutura).nbElement;
}

void allocateVectorMemory(vect &A){
  
  vect *p_estrutura = &A;
  (*p_estrutura).p_vector = new float[(*p_estrutura).nbElement];
  //cout <<(*p_estrutura).nbElement << endl;
}

void assignVectorValues(vect &A){
  vect *p_estrutura = &A;

  for(int i=0;i<(*p_estrutura).nbElement;i++){
    cout << "Digite um numero: " << endl;
    cin >> (*p_estrutura).p_vector[i];
  }
}

void printVector(vect A){
  for(int i=0;i<A.nbElement;i++){
    cout << A.p_vector[i] << ", ";
  }
  cout << endl;
}

float vectorialProduct(vect A, vect B){
  // analisa se são do mesmo tamanho
  if(A.nbElement != B.nbElement){
    cout << "Tamanhos diferentes";
    return 404;
  }
  else{
    float *p_result = new float[A.nbElement];
    float *p_soma = new float[A.nbElement];
    float *p_sub = new float[A.nbElement];
    float *p_va = new float[A.nbElement];
    float *p_vb = new float[A.nbElement];

    //soma
    //ajustando o vetor va
    for(int i=1;i<A.nbElement;i++){
      p_va[i-1]=A.p_vector[i];
    }
    p_va[A.nbElement-1] = A.p_vector[0];

    //Ajustando o vetor vb
    for(int i=2;i<B.nbElement;i++){
      p_vb[i-2]=B.p_vector[i];
    }
    p_vb[B.nbElement-2] = B.p_vector[0];
    p_vb[B.nbElement-1] = B.p_vector[1];

    //soma
    for(int i=0;i<A.nbElement;i++){
      p_soma[i]=p_va[i]*p_vb[i];
    }

    // sub
    //ajustando o vetor va
    for(int i=0;i<(A.nbElement-1);i++){
      p_va[i+1]=A.p_vector[i];
    }
    p_va[0] = A.p_vector[A.nbElement-1];

    //Ajustando o vetor vb
    for(int i=0;i<(B.nbElement-2);i++){
      p_vb[i+2]=B.p_vector[i];
    }
    p_vb[0] = B.p_vector[B.nbElement-2];
    p_vb[1] = B.p_vector[B.nbElement-1];

    //sub
    for(int i=0;i<A.nbElement;i++){
      p_sub[i]=p_va[i]*p_vb[i];
    }

    //resultado
    for(int i=0;i<A.nbElement;i++){
      p_result[i]=p_soma[i]-p_sub[i];
    }

    //print
    cout << "Vetor resultado da multiblicacao da matriz "<< A.name << "pela matriz " <<B.name <<"É: " <<endl;
    for(int i=0;i<A.nbElement;i++){
      cout << p_result[i] << ", ";
    }
    cout << endl;
  }
}