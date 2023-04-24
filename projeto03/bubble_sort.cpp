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

void bubbleSort(int* arranjo, int tamanho)
{
    for(int i=0;i<tamanho-1;i++)
    {
        for(int j=0;j<tamanho-i-1;j++)
        {
            if(arranjo[j]>arranjo[j+1])
            {
                swap(arranjo[j],arranjo[j+1]);
            }
        }
    }
    cout<<"Arranjo organizado via bubble sort"<<endl;
    printArray(arranjo,tamanho);
};

int main(){
    int arranjo[20]={31, 9, 4, 7, 3, 18, 23, 54, 99, 87, 54, 35, 90, 1, 22, 30, 49, 77, 5, 76};

    int tamanho = sizeof(arranjo)/sizeof(arranjo[0]);

    cout<<"Arranjo original"<<endl;
    printArray( arranjo, tamanho);

    bubbleSort(arranjo,tamanho);

    return 0;
}