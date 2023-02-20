#include "ParaChoque.h"

#include<iostream>

using namespace std;

ParaChoque::ParaChoque(){

}

/*bool ParaChoque::CalcularColisao(int** matriz,int direcao,int* posicaoAtual){
    //int** pp_matriz = matriz;

    //consideranco 4 direçoes
    int posicaoFutura[2];

    if(direcao==1){
        //subindo
        posicaoFutura[0]=posicaoAtual[0]+1;
        posicaoFutura[1]=posicaoAtual[1]+0;
        if(matriz[posicaoFutura[0]][posicaoFutura[1]]!=0){
            return false;
            // tem obstaculo
            cout<<"Tem obstaculo em cima"<< endl;
        }else{
            return true;
            // Nao tem obstaculo
            cout<<"Nao em obstaculo em cima"<< endl;
        }
    }else if(direcao==2){
        //direita
        posicaoFutura[0]=posicaoAtual[0]+0;
        posicaoFutura[1]=posicaoAtual[1]+1;
        if(matriz[posicaoFutura[0]][posicaoFutura[1]]!=0){
            return false;
            // tem obstaculo
            cout<<"Tem obstaculo a direita"<< endl;
        }else{
            return true;
            // Nao tem obstaculo
            cout<<"Nao tem obstaculo a direita"<< endl;
        }
    }else if(direcao==3){
        //baixo
        posicaoFutura[0]=posicaoAtual[0]-1;
        posicaoFutura[1]=posicaoAtual[1]+0;
        if(matriz[posicaoFutura[0]][posicaoFutura[1]]!=0){
            return false;
            // tem obstaculo
            cout<<"Tem obstaculo a baixo"<< endl;
        }else{
            return true;
            // Nao tem obstaculo
            cout<<"Nao tem obstaculo a baixo"<< endl;
        }
    }else if(direcao==4){
        //esquerda
        posicaoFutura[0]=posicaoAtual[0]+0;
        posicaoFutura[1]=posicaoAtual[1]-1;
        if(matriz[posicaoFutura[0]][posicaoFutura[1]]!=0){
            return false;
            // tem obstaculo
            cout<<"Tem obstaculo a esquerda"<< endl;
        }else{
            return true;
            // Nao tem obstaculo
            cout<<"Nao em obstaculo a esquerda"<< endl;
        }
    }else{
        // nada
    }
}*/

bool ParaChoque::CalcularColisao(int** matriz,int posicaoFuturaX, int posicaoFuturaY){
    if(matriz[posicaoFuturaX][posicaoFuturaY]!=0){
        cout<<"Tem obstaculo"<<endl;
        return false;
    }else{
        cout<<"Nao tem obstaculo"<<endl;
        return true;
    }
}