#include <iostream>
using namespace std;

void printArray(int arr[],int tamanho)
{
    //Printa o arranjo
    for(int i =0;i<tamanho;i++)
    {
        cout<< arr[i]<<" ";
    }
    cout<< endl;
};

void merge(int A[], int B[], int sizeA, int sizeB) {
    int i = sizeA - 1;
    int j = sizeB - 1;
    int k = sizeA + sizeB - 1;

    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k--] = A[i--];
        } else {
            A[k--] = B[j--];
        }
    }

    // Lidar com elementos restantes em B
    while (j >= 0) {
        A[k--] = B[j--];
    }
}

int main() {
    int A[] = {17, 32, 51, 72, 99, 0, 0, 0, 0,0};
    int B[] = {10, 12, 15, 16,110};
    int sizeA = sizeof(A)/sizeof(A[0]);
    int sizeB = sizeof(B)/sizeof(B[0]);

    merge(A, B, sizeA - sizeB, sizeB);

    printArray(A,sizeA);

    return 0;
}
