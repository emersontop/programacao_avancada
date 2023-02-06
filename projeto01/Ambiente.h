#ifndef AMBIENTE_H
#define AMBIENTE_H

#include <string>

using namespace std;

class Ambiente {
    private:

        void limpaInformacao(string& informacao);
        void separaTagInformacao(string line, string& tag, string& informacao);
        void analisaTagInformacao(string& tag,string& informacao);
        void alocarMemoriaMatriz();
        void iniciarMatrizZeros();
        void addObstaculosEntrada();
        void printSetupAmbiente();

    public:
        string entradas;
        int dimAmbiente[2];         //dimensao do amnbiente (linha,coluna)
        int posicaoInicial[2];      //posicai inicial do robo e do ponto de carregamento
        int numObstaculoCelula;     //numero de obstaculos celula
        int obstaculoCelulaX[10];   //coordenadas x dos obstaculos celula
        int obstaculoCelulaY[10];   //coordenadas y dos obstaculso celula
        int numObstaculoRetangulo;  //numero de obstaculos retangulo
        int obstaculoRecInicial[4]; //coordendas de inicio do retangulo
        int obstaculoRecFinal[4];   //coordenadas do fim do retangulo
        int** pp_ambiente;        //guarda a matriz

        //constructor
        Ambiente(string);
        //metodo para printar ambiente
        void printAmbiente();
        //metodo para adicionar um obstaculo
        void addObstaculoCelula(int x, int y);
        void addObstaculoRetangulo(int xi, int yi, int xf, int yf);
};      


#endif