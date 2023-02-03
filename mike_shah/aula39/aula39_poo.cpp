//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\mike_shah\aula39'
//g++ aula39_poo.cpp Array.cpp -o aula39_poo
//./aula39_poo 

#include <iostream>
#include <string>

#include "Array.h"

using namespace std;

void printAnArray(const Array& a) {
    //fazer nada
}

int main(){

    Array myArray;
    
    myArray.SetData(0,1234567);
    
    Array myArray2= myArray;

    //myArray.Printingdata();
    //myArray2.Printingdata();

    printAnArray(myArray);

    return 0;
}