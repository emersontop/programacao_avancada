#ifndef BATERIA_H
#define BATERIA_H

class Bateria{
    public:
        //Atributos
        int nivel;
        int nivelMax = 50;

        //metodos
        //construtor
        Bateria();
        void Carregar();
        void Descarregar();

};

#endif