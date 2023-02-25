#include "Laser.h"

#include <iostream>

using namespace std;

Laser::Laser(){
    alocarMemoria();
    prencherZeros();
}

void Laser::calcularColisao(int** matriz, int posicaoAtualRoboX, int posicaoAtualRoboY, int dimensaoAmbienteX,int dimensaoAmbienteY){
    int linha[9]={-1,-1,-1, 0,0,0,1,1,1};
    int linhaA[9] {0,0,0,1,1,1,2,2,2};
    int coluna[9]={-1,0,1,-1,0,1,-1, 0, 1};
    int colunaA[9] {0,1,2,0,1,2,0,1,2};
    //norte(0,+1)
    for(int n=0;n<9;n++){
        if((posicaoAtualRoboX+linha[n]<dimensaoAmbienteX&&posicaoAtualRoboX+linha[n]>=0)&&(posicaoAtualRoboY+coluna[n]<dimensaoAmbienteY&&posicaoAtualRoboY+coluna[n]>=0)){
            pp_areaLaser[linhaA[n]][colunaA[n]] =matriz[posicaoAtualRoboX+linha[n]][posicaoAtualRoboY+coluna[n]];
        }else{
            pp_areaLaser[linhaA[n]][colunaA[n]]=200;
        }
    }
    cout<<"Colisao calculada"<<endl;
    printAreaLaser();
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

void Laser:: printAreaLaser(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<pp_areaLaser[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}