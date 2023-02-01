//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\testes'
//g++ aula37_poo.cpp Student.cpp -o aula37_poo
//./aula37_poo 

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main(){
    //An instance of a 'Sudent'
    Student mike("Mikes Stvem");
    mike.printname();
    return 0;
}