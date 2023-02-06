#include <iostream>
#include <fstream> //nao sei ainda pra que e usada
#include <string>

using namespace std;

//variaveis globais
int dimAmbiente[2];
int posicaoInicial[2];
int numObstaculoCelula;
int obstaculoCelulaX[10];
int obstaculoCelulaY[10];
int numObstaculoRetangulo;
int obstaculoRecInicial[4];
int obstaculoRecFinal[4];

void limpaInformacao(string& informacao){
    string informacaoAuxiliar;
    for (string::iterator it=informacao.begin(); it!=informacao.end(); ++it){
        //Analisa se existe algum caracter errado
        if((*it!= '0' && *it!='1' && *it!='2' && *it!='3' && *it!='4' && *it!='5' && *it!='6' && *it!='7' && *it!='8' && *it!='9')){
            //nao faz nada
        }else{
            informacaoAuxiliar+=*it;
        }
    }
    informacao = informacaoAuxiliar;
}

void separaTagInformacao(string line, string& tag, string& informacao){
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

    /*cout << "Linha: "<<line<<endl;
    cout<<"TAG: "<< tag <<endl;
    cout<<"informacao: "<< informacao <<endl;
    cout<<endl;*/
};

void analisaTagInformacao(string& tag,string& informacao){
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
        for (string::iterator it=informacao.begin(); it!=informacao.end(); ++it){
            auxIt.clear();
            auxIt = *it;
            obstaculoCelulaX[i]=stoi(auxIt);
            i++;
        }
    }else if(tag == "obstaculoCelulaY"){
        i=0;
        for (string::iterator it=informacao.begin(); it!=informacao.end(); ++it){
            auxIt.clear();
            auxIt = *it;
            obstaculoCelulaY[i]=stoi(auxIt);
            i++;
        }
    }else if(tag == "numObstaculoRetangulo"){
        numObstaculoRetangulo=stoi(informacao);
    }else if(tag == "obstaculoRecInicial"){
        i=0;
        for (string::iterator it=informacao.begin(); it!=informacao.end(); ++it){
            auxIt.clear();
            auxIt = *it;
            obstaculoRecInicial[i]=stoi(auxIt);
            i++;
        }
    }else if(tag == "obstaculoRecFinal"){
        i=0;
        for (string::iterator it=informacao.begin(); it!=informacao.end(); ++it){
            auxIt.clear();
            auxIt = *it;
            obstaculoRecFinal[i]=stoi(auxIt);
            i++;
        }
    }else{
        cout<< "nao identifiquei a tag" <<endl;
    }
}

int main(){
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
    return 0;
}