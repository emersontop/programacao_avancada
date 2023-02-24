#include "Laser.h"

#include <iostream>

using namespace std;

Laser::Laser(){

}

void Laser::calcularColisao(int** matriz, int posicaoAtualRoboX, int posicaoAtualRoboY){
    alocarMemoria();
    prencherZeros();
    
}

void Laser::alocarMemoria(){
    pp_areaLaser=new int*[dimLaser[0]];
    for(int i=0;i<dimLaser[0];i++){
        pp_areaLaser[i]=new int[dimLaser[1]];
    }
}

void Laser::prencherZeros(){
    for(int i=0;i<dimLaser[0];i++){
        for(int j=0;j<dimLaser[1];j++){
            pp_areaLaser[i][j]=0;
        }
    }
}