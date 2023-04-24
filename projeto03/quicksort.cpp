#include <iostream>

using namespace std;

//UFPE - CTG
//Alunos: Emerson e Sanclay

void printArray(int arr[],int tamanho)
{
    //Printa o arranjo
    for(int i =0;i<tamanho;i++)
    {
        cout<< arr[i]<<" ";
    }
    cout<< endl;
};

int partition(int arranjo[],int front, int rear)
{
  int aux = 0;
  int i=0;
  int auxArranjo = 0;

  aux = arranjo[rear];
  i = front -1;

  for (int j=front; j < rear  ; j++)
  {
    if (arranjo[j] <= aux)
    {
      i = i +1;
      swap(arranjo[i],arranjo[j]);
    }
  }
  
  swap(arranjo[i+1],arranjo[rear]);

  return i + 1;
}


void quicksort(int* arranjo,int front, int rear)
{
  if (front < rear)
  {
    int aux = 0;

    aux = partition(arranjo,front,rear);
    quicksort(arranjo,front,aux -1);
    quicksort(arranjo,aux +1,rear);
  }
}

int main(){
  int arranjo[20]={31, 9, 4, 7, 3, 18, 23, 54, 99, 87, 54, 35, 90, 1, 22, 30, 49, 77, 5, 76};
  int tamanho = sizeof(arranjo)/sizeof(arranjo[0]);

  cout<<"Arranjo inicial"<<endl;
  printArray(arranjo,tamanho);

  quicksort(arranjo, 0, tamanho-1);
  cout<<"Arranjo final"<<endl;
  printArray(arranjo,tamanho);

  return 0;
}
