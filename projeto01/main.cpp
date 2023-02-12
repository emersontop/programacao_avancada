//cd '.\Documents\02estudo\programacao_avancada\projeto01'
//g++ main.cpp Ambiente.cpp Robo.cpp -o main
//g++ main.cpp Ambiente.cpp Robo.cpp Bateria.cpp -o main
//g++ main.cpp Ambiente.cpp Robo.cpp Bateria.cpp ParaChoque.cpp -o main
//./main 

#include <iostream>
#include <string>

#include "Ambiente.h"
#include "Robo.h"
#include "Bateria.h"
#include "ParaChoque.h"

using namespace std;

int main(){
    Ambiente cozinha("entradas.txt");
    //cozinha.printAmbiente();
    Modelo01 obelix("obelix","entradas.txt");
    //obelix.printAmbienteRobo();
    cout<<"Esse e o nivel de bateria do robo: "<<obelix.bateriaDoRobo.nivel<<endl;
    obelix.mover(1,1);
    obelix.printAmbienteRobo();
    cout<<"Esse e o nivel de bateria do robo"<<obelix.bateriaDoRobo.nivel<<endl;
    obelix.mover(2,1);
    obelix.printAmbienteRobo();
    cout<<"Esse e o nivel de bateria do robo"<<obelix.bateriaDoRobo.nivel<<endl;
    return 0;
}