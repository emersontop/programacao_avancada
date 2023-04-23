#include <iostream>

using namespace std;

void ordenarArranjo(int* arranjo, int tamanho)
{
    int temp;
    int j = 0;
    while(j<(tamanho-2))
    {
        for(int i=0;i<(tamanho-j);i++)
        {
            if(arranjo[i]>arranjo[i+1])
            {
                temp=arranjo[i+1];
                arranjo[i+1]=arranjo[i];
                arranjo[i]=temp;
            }
        }
        cout<<"Arranjo na " <<(j+1)<<") ordenacao:"<<endl;
        for(int i=0;i<tamanho;i++)
        {
            cout<<arranjo[i]<<", ";
        }
        cout<<endl;
        cout<<endl;
        j++;
    }
};


int main(){
    int arranjo[10]={7,1,-4,2,5,2,9,6,3,0};
    int tamanho = 10;

    cout<<"Arranjo original"<<endl;
    for(int i=0;i<tamanho;i++)
    {
        cout<<arranjo[i]<<", ";
    }
    cout<<endl;
    cout<<endl;

    ordenarArranjo(arranjo,tamanho);

    return 0;
}