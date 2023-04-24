#include <iostream>
#include <math.h>

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

void merge (int arranjo[],int front, int media ,int rear)
{
  int n1 = media - front +1;
  int n2 = rear - media;
  int *l = new int[n1 +1];
  int *r = new int[n2 +1];

  //preenche o arranjo l com a primeira metade do arranjo
  for( int i=0; i<n1; i++)
  {
    l[i] = arranjo[front + i];
  }

  //preenche o arranjo r com a ultima metade do arranjo
  for( int j=0; j<n2; j++)
  {
    r[j] = arranjo[media + j +1];
  }

  l[n1] = 1000;
  r[n2] = 1000;

  int i=0;
  int j=0;

  for(int k = front; k<=rear;k++)
  {
    if (l[i] <= r[j])
    {
      arranjo[k] = l[i];
      i = i + 1;
    }
    else
    {
      arranjo[k] = r[j];
      j = j + 1;
    }
  }
}

void merge_sort(int arranjo[],int front,int rear)
{
  int media = 0;

  if (front<rear)
  {
    media = ceil((front + rear)/2);

    merge_sort(arranjo, front, media);
    merge_sort(arranjo, media + 1, rear);
    merge( arranjo, front, media, rear);

  }
}

int main()
{
  int arranjo[20] = {31,9,4,7,3,18,23,54,99,87,54,35,90,1,22,30,49,77,5,76};
  int front = 0;
  int rear = sizeof(arranjo)/sizeof(arranjo[0]) -1;
  int media = ceil((front + rear)/2);
  int tamanho = sizeof(arranjo)/sizeof(arranjo[0]);

  cout<<"Arranjo inicial"<<endl;
  printArray(arranjo,tamanho);

  //merge(arranjo,front,media,rear);
  merge_sort(arranjo,front,rear);

  cout<<"Arranjo final"<<endl;

  printArray(arranjo,tamanho);

  return 0;
}
