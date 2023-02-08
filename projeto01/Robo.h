#ifndef ROBO_H
#define ROBO_H

#include <string>

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
        int bateria;
        int** pp_ambienteRobo;

        //metodos
        //construtor
        Robo(string nome, string entradas);
        void parar();
        void printAmbienteRobo();
};

#endif