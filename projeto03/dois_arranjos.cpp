#include <iostream>
#include <math.h>

using namespace std;

//UFPE - CTG
//Alunos: Emerson e Sanclay

void dois_array(int* arranjo_A, int* arranjo_B, int tam_A, int tam_B)
{


  int i=tam_A;
  int j=tam_B;

  for(int k = tam_B; k>=0;k--)
  {
    if ((arranjo_A[i] <= arranjo_B[j - tam_A -1])&&(j - tam_A -1 >= 0) )
    {
      arranjo_B[k] = arranjo_B[j - tam_A -1];
      j = j - 1;

      cout<<"Posicao B"<<k<<" eh : "<<arranjo_B[k]<<endl;
    }
    else
    {
      arranjo_B[k] = arranjo_A[i];
      i = i - 1;

      cout<<"Posicao A"<<k<<" eh : "<<arranjo_B[k]<<endl;
    }
  }


    for (int i = 0; i <= tam_B; i++)
    {
      cout<<arranjo_B[i]<<" ";
    }
    cout<<endl;
}


int main()
{
  int arranjo_A[] = {100,101,102,103,104};
  int arranjo_B[] = {7,8,9,10,11,10000,10000,10000,10000,10000};

  int tam_A = sizeof(arranjo_A)/sizeof(int) -1;
  int tam_B = sizeof(arranjo_B)/sizeof(int) -1;

  cout<<"Tamanho de A: "<<tam_A<<endl;
  cout<<"Tamanho de B: "<<tam_B<<endl;

  dois_array(arranjo_A, arranjo_B, tam_A,tam_B);


  return 0;
}
