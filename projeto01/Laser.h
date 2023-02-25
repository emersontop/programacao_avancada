#ifndef LASER_H
#define LASER_H

class Laser{
    public:
        int dimLaser[2] = {3,3};
        int** pp_areaLaser;
        Laser();
        void calcularColisao(int** matriz, int posicaoAtualRoboX, int posicaoAtualRoboY, int dimensaoAmbienteX,int dimensaoAmbienteY);
        void alocarMemoria();
        void prencherZeros();
        void printAreaLaser();

};

#endif