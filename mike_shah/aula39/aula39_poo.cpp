//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\mike_shah\aula39'
//g++ aula39_poo.cpp Array.cpp -o aula39_poo
//./aula39_poo 

#include <iostream>
#include <string>

#include "Array.h"

using namespace std;

int main(){

    Array myArray;
    
    myArray.SetData(0,100000);
    myArray.SetData(1,77);
    myArray.SetData(2,200);
    
    Array myArray2;
    myArray2 = myArray;

    myArray.Printingdata();
    myArray2.Printingdata();

    return 0;
}