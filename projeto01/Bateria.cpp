#include "Bateria.h"

#include <iostream>

using namespace std;

Bateria::Bateria(){
    nivel=nivelMax;
}

void Bateria::Carregar(){
    if(nivel<nivelMax){
        nivel = nivelMax;
    }else{

    }
    cout<< "Bateria carregada, "<<"Nivel atual da bateria: " << nivel<<endl;
}

void Bateria::Descarregar(){
    nivel=nivel-1;
    cout<<"Nivel atual da bateria: " << nivel<<endl;
}