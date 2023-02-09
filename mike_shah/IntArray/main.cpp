//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\mike_shah\aula39'
//g++ aula39_poo.cpp Array.cpp -o aula39_poo
//./aula39_poo 

#include <iostream>
#include <string>

#include "IntArray.h"

using namespace std;

IntArray foo(){
    IntArray result("foo created array");
    return result;
}

int main(){

    vector<IntArray> myArrays;
    myArrays.reserve(10);
    for(int i=0;i<10;i++){
        IntArray temp(to_string(i));
        myArrays.push_back(move(temp));
    }
    //foo();

    return 0;
}