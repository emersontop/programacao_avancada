#include "Robo.h"

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

Robo::Robo(string nome, string entradas){
    // preenche o nome do robo
    nomeRobo=nome;
    // variaveis
    string informacao;
    string tag;
    string line;

    // abertura do arquivo
    ifstream myfile("entrada.txt");

    //inicio da leitura do arquivo
    if(myfile.is_open()){

        //enquanto existir linhas no arquivo, extrai a linha e salva na variavel line
        while(getline(myfile,line)){

            //funcao que separa a tag da informacao
            separaTagInformacao(line, tag, informacao);

            //analisa a tag e a inforacao
            analisaTagInformacao(tag,informacao);

        }
        myfile.close();
    }
    else{
        cout <<"Unable to opne file"<<endl;
    }
    printSetup();
    alocarMemoriaMatriz();
    iniciarMatrizZeros();
    addPontoDeRecarga();
    posicaoAtualRobo[0]=posicaoInicial[0];
    posicaoAtualRobo[1]=posicaoInicial[1];
}

void Robo::separaTagInformacao(string line, string& tag, string& informacao){
    bool flag_info;
    string::iterator it=line.begin();
    //Limpa as strings
    tag.clear();
    informacao.clear();

    //separa tag e informacao
    //seta a flag como false
    flag_info = false;
    while(it!=line.end()){
        if(*it==':'){
            flag_info = true;
        }
        if(flag_info){
            informacao +=*it;
        }
        else{
            tag+=*it;
        }
        ++it;
    }
    limpaInformacao(informacao);
}

void Robo::limpaInformacao(string& informacao){
    bool caracterErrado;
    string informacaoAuxiliar;
    for (string::iterator it=informacao.begin(); it!=informacao.end(); ++it){
        //Analisa se existe algum caracter errado
        if((*it!= '0' && *it!='1' && *it!='2' && *it!='3' && *it!='4' && *it!='5' && *it!='6' && *it!='7' && *it!='8' && *it!='9'&& *it!=',')){
            cout<<"APRESENTA CARACTER ERRADO NA INFORMACAO"<<endl;
        }else{
            informacaoAuxiliar+=*it;
        }
    }
    informacao = informacaoAuxiliar;
}

void Robo::analisaTagInformacao(string& tag,string& informacao){
    if(tag == "oNumeroDeLinhas"){
        dimAmbiente[0]=stoi(informacao);
    }else if (tag =="oNumeroDeColunas"){
        dimAmbiente[1]=stoi(informacao);
    }else if(tag == "posicaoInicialX"){
        posicaoInicial[0]=stoi(informacao);
    }else if(tag == "posicaoInicialY"){
        posicaoInicial[1]=stoi(informacao);
    }else{
        cout<< "nao identifiquei a tag" <<endl;
    }
}

void Robo::printSetup(){
    cout<<"O numero de linhas do ambiente: "<< dimAmbiente[0] <<endl;
    cout<<"O numero de colunas do ambiente: "<< dimAmbiente[1] <<endl;
    cout<<"A posicao inicial em x: "<< posicaoInicial[0] <<endl;
    cout<<"A posicao inicial em y: "<< posicaoInicial[1] <<endl;
}

void Robo::parar(){
    cout<<"O robo parou e vai desligar"<<endl;
}

void Robo::alocarMemoriaMatriz(){
    pp_ambienteRobo=new int*[dimAmbiente[0]];
    for(int i=0;i<dimAmbiente[0];i++){
        pp_ambienteRobo[i]=new int[dimAmbiente[1]];
    }
}

void Robo::iniciarMatrizZeros(){
    for(int i=0;i<dimAmbiente[0];i++){
        for(int j=0;j<dimAmbiente[1];j++){
            pp_ambienteRobo[i][j]=0;
        }
    }
}

void Robo::addPontoDeRecarga(){
    //ACHO QUE NAO PRECISA DO FOR, SO PRECISA PASSA AS COORDENADAS QUE VAO SER PRENCHIDAS COMO PONTO DE RECARGA.
    for(int i=0;i<dimAmbiente[0];i++){
        for(int j=0;j<dimAmbiente[1];j++){
            if(i==posicaoInicial[0] && j==posicaoInicial[1]){
                pp_ambienteRobo[i][j]=111;//como se um representasse o PONTO DE RECARGA
            }
        }
    }
}

void Robo::printAmbienteRobo(){
    for(int i=0;i<dimAmbiente[0];i++){
        for(int j=0;j<dimAmbiente[1];j++){
            cout<<pp_ambienteRobo[i][j]<< "\t";
        }
        cout<<endl;
        cout<<endl;
    }
}

// classe robo> Modelo01
Modelo01::Modelo01(string nome, string entradas):Robo(nome,entradas){
    //usa o construtor padrao de robo
}

void Modelo01::Limpar(int x, int y){
    cout<<"Area limpa"<<endl;
}

void Modelo01::mover(int** pp_ambienteReal,int novaPosicaoX, int novaPosicaoY){
    if(ParaChoqueRobo.CalcularColisao(pp_ambienteReal,novaPosicaoX,novaPosicaoY)){
        cout<<"O robo vai se mover"<<endl;
        pp_ambienteRobo[posicaoAtualRobo[0]][posicaoAtualRobo[1]]=2;
        posicaoAtualRobo[0]=novaPosicaoX;
        posicaoAtualRobo[1]=novaPosicaoY;
        bateriaDoRobo.Descarregar();
        pp_ambienteRobo[novaPosicaoX][novaPosicaoY] = 88;
    }else{
        cout<<"O robo nao pode se mover"<<endl;
    }
}

void Modelo01:: Ligar(){

}





// classe robo> Modelo02
Modelo02::Modelo02(string nome, string entradas):Robo(nome,entradas){
    //usa o construtor padrao de robo
}

void Modelo02::Limpar(int x, int y){
    cout<<"Area limpa"<<endl;
}

void Modelo02::mover(int** pp_ambienteReal,int novaPosicaoX, int novaPosicaoY){
    if(ParaChoqueRobo.CalcularColisao(pp_ambienteReal,novaPosicaoX,novaPosicaoY)){
        cout<<"O robo vai se mover"<<endl;
        pp_ambienteRobo[posicaoAtualRobo[0]][posicaoAtualRobo[1]]=2;
        posicaoAtualRobo[0]=novaPosicaoX;
        posicaoAtualRobo[1]=novaPosicaoY;
        bateriaDoRobo.Descarregar();
        pp_ambienteRobo[novaPosicaoX][novaPosicaoY] = 88;
    }else{
        cout<<"O robo nao pode se mover"<<endl;
    }
}

void Modelo02:: Ligar(){
    
}