//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\projeto01'
//g++ main.cpp Ambiente.cpp -o aula39_poo
//./main 

#include <iostream>
#include <string>

#include "Ambiente.h"
#include "Robo.h"

using namespace std;

int main(){
    Ambiente cozinha("entradas.txt");
    cozinha.printAmbiente();
    Robo obelix("obelix","entradas.txt");
    obelix.printAmbienteRobo();
    return 0;
}