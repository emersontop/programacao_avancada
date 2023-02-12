#ifndef PARACHOQUE_H
#define PARACHOQUE_H

class ParaChoque{
    public:
        //atributos
        bool choque;
        
        //metodos
        //construtor;
        ParaChoque();
        //bool CalcularColisao(int** matriz,int direcao, int* posicaoAtual);
        bool CalcularColisao(int** matriz,int posicaoFuturaX, int posicaoFuturaY);

};

#endif