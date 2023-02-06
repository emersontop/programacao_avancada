//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\projeto01'
//g++ main.cpp Ambiente.cpp -o aula39_poo
//./main 

#include <iostream>
#include <string>

#include "Ambiente.h"

using namespace std;

int main(){
    Ambiente cozinha("entradas.txt");
    //cozinha.printAmbiente();
    //cozinha.addObstaculo(1,1);
    //cozinha.addObstaculo(2,2);
    cozinha.printAmbiente();
    return 0;
}