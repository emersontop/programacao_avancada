#include "Ambiente.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// construtor
Ambiente::Ambiente(string entradas){
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
    printSetupAmbiente();
    alocarMemoriaMatriz();
    iniciarMatrizZeros();
    addObstaculosEntrada(); 
}

void Ambiente::printSetupAmbiente(){
    cout<<"O numero de linhas do ambiente: "<< dimAmbiente[0] <<endl;
    cout<<"O numero de colunas do ambiente: "<< dimAmbiente[1] <<endl;
    cout<<"A posicao inicial em x: "<< posicaoInicial[0] <<endl;
    cout<<"A posicao inicial em y: "<< posicaoInicial[1] <<endl;
    cout<<"Numero de obstaculos celula: "<< numObstaculoCelula <<endl;
    cout<<"Coordenadas x dos obstaculos celulas: ";
    for(int i=0;i<numObstaculoCelula;i++){
        cout<<obstaculoCelulaX[i]<<',';
    }
    cout<<endl;
    cout<<"Coordenadas y dos obstaculos celulas: ";
    for(int i=0;i<numObstaculoCelula;i++){
        cout<<obstaculoCelulaY[i]<<',';
    }
    cout<<endl;
    cout<<"Numero de obstaculos Retangulo: "<< numObstaculoRetangulo <<endl;
    cout<<"Coordenadas iniciais dos obstaculos retangulos: ";
    for(int i=0;i<(2*numObstaculoRetangulo);i++){
        cout<<obstaculoRecInicial[i]<<',';
    }
    cout<<endl;
    cout<<"Coordenadas finais dos obstaculos retangulos: ";
    for(int i=0;i<(2*numObstaculoRetangulo);i++){
        cout<<obstaculoRecFinal[i]<<',';
    }
    cout<<endl;
}

void Ambiente::limpaInformacao(string& informacao){
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

void Ambiente::separaTagInformacao(string line, string& tag, string& informacao){
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

void Ambiente::analisaTagInformacao(string& tag,string& informacao){
    int i;
    string auxIt;
    if(tag == "oNumeroDeLinhas"){
        dimAmbiente[0]=stoi(informacao);
    }else if (tag =="oNumeroDeColunas"){
        dimAmbiente[1]=stoi(informacao);
    }else if(tag == "posicaoInicialX"){
        posicaoInicial[0]=stoi(informacao);
    }else if(tag == "posicaoInicialY"){
        posicaoInicial[1]=stoi(informacao);
    }else if(tag == "numObstaculoCelula"){
        numObstaculoCelula=stoi(informacao);
    }else if(tag == "obstaculoCelulaX"){
        i=0;
        auxIt.clear();
        for (string::iterator it=informacao.begin(); it!=informacao.end(); ++it){
            if(*it==','){
                obstaculoCelulaX[i]=stoi(auxIt);
                auxIt.clear();
                i++;
            }else{
                auxIt += *it;
            }
        }
    }else if(tag == "obstaculoCelulaY"){
        i=0;
        auxIt.clear();
        for (string::iterator it=informacao.begin(); it!=informacao.end(); ++it){
            if(*it==','){
                obstaculoCelulaY[i]=stoi(auxIt);
                auxIt.clear();
                i++;
            }else{
                auxIt += *it;
            }
        }
    }else if(tag == "numObstaculoRetangulo"){
        numObstaculoRetangulo=stoi(informacao);
    }else if(tag == "obstaculoRecInicial"){
        i=0;
        auxIt.clear();
        for (string::iterator it=informacao.begin(); it!=informacao.end(); ++it){
            if(*it==','){
                obstaculoRecInicial[i]=stoi(auxIt);
                auxIt.clear();
                i++;
            }else{
                auxIt += *it;
            }
        }
    }else if(tag == "obstaculoRecFinal"){
        i=0;
        auxIt.clear();
        for (string::iterator it=informacao.begin(); it!=informacao.end(); ++it){
            if(*it==','){
                obstaculoRecFinal[i]=stoi(auxIt);
                auxIt.clear();
                i++;
            }else{
                auxIt += *it;
            }
        }
    }else{
        cout<< "nao identifiquei a tag" <<endl;
    }
}

void Ambiente::alocarMemoriaMatriz(){
    pp_ambiente=new int*[dimAmbiente[0]];
    for(int i=0;i<dimAmbiente[0];i++){
        pp_ambiente[i]=new int[dimAmbiente[1]];
    }
}

void Ambiente::iniciarMatrizZeros(){
    for(int i=0;i<dimAmbiente[0];i++){
        for(int j=0;j<dimAmbiente[1];j++){
            pp_ambiente[i][j]=0;
        }
    }
}

void Ambiente::printAmbiente(){
    for(int i=0;i<dimAmbiente[0];i++){
        for(int j=0;j<dimAmbiente[1];j++){
            cout<<pp_ambiente[i][j]<< "\t";
        }
        cout<<endl;
        cout<<endl;
    }
}

void Ambiente::addObstaculoCelula(int x, int y){
    if(x>dimAmbiente[0]||y>dimAmbiente[1]){
        cout<<"O OBSTACULO ESTA FORA DO AMBIENTE, NAO PODE SER COLOCADO"<< endl;
    }else if(x==posicaoInicial[0]&&y==posicaoInicial[1]){
        cout<<"O OBSTACULO ESTA NO PONTO DE CARREGAMENTO, NAO PODE SER COLOCADO"<< endl;
    }else{
        for(int i=0;i<dimAmbiente[0];i++){
            for(int j=0;j<dimAmbiente[1];j++){
                if(i==x && j==y){
                    pp_ambiente[i][j]=1;//como se um representasse o obstaculo
                }
            }
        }
    }
}

void Ambiente::addObstaculosEntrada(){
    //adicionando obstaculos celula
    for(int i=0;i<numObstaculoCelula;i++){
        addObstaculoCelula(obstaculoCelulaX[i],obstaculoCelulaY[i]);
    }

    //adicionando obstaculos retangulo
    for(int i=1;i<(2*numObstaculoRetangulo);i=i+2){
        addObstaculoRetangulo(obstaculoRecInicial[i-1],obstaculoRecInicial[i],obstaculoRecFinal[i-1],obstaculoRecFinal[i]);
    }
}

void Ambiente::addObstaculoRetangulo(int xi, int yi, int xf, int yf){
    for(int i=xi;i<=xf;i++){
        for(int j=yi;j<=yf;j++){
            addObstaculoCelula(i,j);
        }
    }
}