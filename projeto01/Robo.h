#ifndef ROBO_H
#define ROBO_H

#include <string>
#include "Bateria.h"
#include "ParaChoque.h"

using namespace std;

class Robo{
    private:
        void alocarMemoriaMatriz();
        void separaTagInformacao(string line, string& tag, string& informacao);
        void limpaInformacao(string& informacao);
        void analisaTagInformacao(string& tag,string& informacao);
        void printSetup();
        void iniciarMatrizZeros();
        void addPontoDeRecarga();
    public:
        //Atributos
        string nomeRobo;
        int posicaoAtualRobo[2];
        int posicaoInicial[2];
        int dimAmbiente[2];
        //bateria;
        Bateria bateriaDoRobo;
        int** pp_ambienteRobo;
        //parachoque
        ParaChoque ParaChoqueRobo;

        //metodos
        //construtor
        Robo(string nome, string entradas);
        void parar();
        void printAmbienteRobo();
};


class Modelo01:public Robo{
    public:
        //atributos
        bool parachoque;


        //metodos
        //construtor
        Modelo01(string nome, string entradas);
        void Limpar(int x, int y);
        bool mover(int** pp_ambienteReal,int novaPosicaoX, int novaPosicaoY);
        void Ligar(int** pp_ambienteReal);
};

class Modelo02:public Robo{
    public:
        //atributos
        bool parachoque;
        bool laser;
        int oritentacao;

        //metodos
        //construtor
        Modelo02(string nome, string entradas);
        void Limpar(int x, int y);
        void mover(int** pp_ambienteReal,int novaPosicaoX, int novaPosicaoY);
        void Ligar();
};
#endif