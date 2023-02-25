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
                pp_ambienteRobo[i][j]=222;//como se um representasse o PONTO DE RECARGA
            }
        }
    }
}

void Robo::printAmbienteRobo(int robox,int roboy){
    for(int i=0;i<dimAmbiente[0];i++){
        for(int j=0;j<dimAmbiente[1];j++){
            if((i==robox)&&(j==roboy)){
                cout<<"88"<< "\t";
            }else{
                cout<<pp_ambienteRobo[i][j]<< "\t";
            }
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
    if((x==posicaoInicial[0])&&(y==posicaoInicial[1])){
        cout<<"Area limpa"<<endl;
    }else{
        pp_ambienteRobo[x][y]+=1;
        cout<<"Area limpa"<<endl;
    }
}

void Modelo01::DecideMovimento(){
    int menor;
    int posicaoMenor;
    int opcoes[4];
    if((posicaoAtualRobo[0]<dimAmbiente[0]&&(posicaoAtualRobo[1]+1)<dimAmbiente[1])&&(posicaoAtualRobo[0]>=0&&(posicaoAtualRobo[1]+1)>=0)){
        opcoes[0]=pp_ambienteRobo[posicaoAtualRobo[0]][posicaoAtualRobo[1]+1];
    }else{
        opcoes[0]=200;
    }

    cout<<"Vetor opcoes[0] vale: "<<opcoes[0]<<" Direita"<<endl;

    if(((posicaoAtualRobo[0]+1)<dimAmbiente[0]&&(posicaoAtualRobo[1])<dimAmbiente[1])&&((posicaoAtualRobo[0]+1)>=0&&(posicaoAtualRobo[1])>=0)){
        opcoes[1]=pp_ambienteRobo[posicaoAtualRobo[0]+1][posicaoAtualRobo[1]];
    }else{
        opcoes[1]=200;
    }
    
    cout<<"Vetor opcoes[1] vale: "<<opcoes[1]<<" Baixo"<<endl;

    if(((posicaoAtualRobo[0])<dimAmbiente[0]&&(posicaoAtualRobo[1]-1)<dimAmbiente[1])&&((posicaoAtualRobo[0])>=0&&(posicaoAtualRobo[1]-1)>=0)){
        opcoes[2]=pp_ambienteRobo[posicaoAtualRobo[0]][posicaoAtualRobo[1]-1];
    }else{
        opcoes[2]=200;
    }

    cout<<"Vetor opcoes[2] vale: "<<opcoes[2]<<" esquerda"<<endl;

    if(((posicaoAtualRobo[0]-1)<dimAmbiente[0]&&(posicaoAtualRobo[1])<dimAmbiente[1])&&((posicaoAtualRobo[0]-1)>=0&&(posicaoAtualRobo[1])>=0)){
        opcoes[3]=pp_ambienteRobo[posicaoAtualRobo[0]-1][posicaoAtualRobo[1]];
    }else{
        opcoes[3]=200;
    }

    cout<<"Vetor opcoes[3] vale: "<<opcoes[3]<<"cima"<<endl;

    cout<<"Vetor opcoes: "<<endl;

    for(int i=0;i<4;i++){
        if(opcoes[i]<menor){
            menor=opcoes[i];
            posicaoMenor = i;
        }
        cout<<opcoes[i]<<",";
    }
    cout<<endl;
    cout<<"O menor valor e: "<<menor<<endl;
    cout<<"na posicao: "<<posicaoMenor<<endl;

    switch (posicaoMenor){
    case 0:
        proximaPosicao[0]=posicaoAtualRobo[0];
        proximaPosicao[1]=posicaoAtualRobo[1]+1;
        cout<<"0 vou pra direita:"<<endl;
        cout<<"Proxima posicao linha: "<<proximaPosicao[0]<<endl;
        cout<<"Proxima posicao coluna: "<<proximaPosicao[1]<<endl;
        break;
    case 1:
        proximaPosicao[0]=posicaoAtualRobo[0]+1;
        proximaPosicao[1]=posicaoAtualRobo[1];
        cout<<"1 vou pra baixo:"<<endl;
        cout<<"Proxima posicao linha: "<<proximaPosicao[0]<<endl;
        cout<<"Proxima posicao coluna: "<<proximaPosicao[1]<<endl;
        break;
    case 2:
        proximaPosicao[0]=posicaoAtualRobo[0];
        proximaPosicao[1]=posicaoAtualRobo[1]-1;
        cout<<"2 vou pra esquerda:"<<endl;
        cout<<"Proxima posicao linha: "<<proximaPosicao[0]<<endl;
        cout<<"Proxima posicao coluna: "<<proximaPosicao[1]<<endl;
        break;
    case 3:
        proximaPosicao[0]=posicaoAtualRobo[0]-1;
        proximaPosicao[1]=posicaoAtualRobo[1];
        cout<<"3 vou pra cima:"<<endl;
        cout<<"Proxima posicao linha: "<<proximaPosicao[0]<<endl;
        cout<<"Proxima posicao coluna: "<<proximaPosicao[1]<<endl;
        break;
    default:
        break;
    }
}

bool Modelo01::mover(int** pp_ambienteReal,int novaPosicaoX, int novaPosicaoY){
    cout<<"O robo esta nessa posicao: x: "<<posicaoAtualRobo[0]<<" y:" <<posicaoAtualRobo[1]<<endl;
    cout<<"O robo vai tentar ir para posicao: x: "<< novaPosicaoX<<" e y: "<<novaPosicaoY<<endl;
    if(bateriaDoRobo.nivel>0){
        //Teste de nivel de bateria
        if((novaPosicaoX<dimAmbiente[0]&&novaPosicaoY<dimAmbiente[1])&&(novaPosicaoX>=0&&novaPosicaoY>=0)){
            //teste se a posição esta em um local valido
            if(ParaChoqueRobo.CalcularColisao(pp_ambienteReal,novaPosicaoX,novaPosicaoY)){
                //teste de obstaculo
                cout<<"O robo vai se mover"<<endl;

                Limpar(posicaoAtualRobo[0],posicaoAtualRobo[1]);

                posicaoAtualRobo[0]=novaPosicaoX;
                posicaoAtualRobo[1]=novaPosicaoY;

                bateriaDoRobo.Descarregar();
                return true;
            }else{
                cout<<"O robo nao pode se mover, tem obstaculo"<<endl;
                pp_ambienteRobo[novaPosicaoX][novaPosicaoY] = 111;
                return false;
            }
        }else{
            cout<<"O robo nao pode se mover, fora do mapa"<<endl;
            return false;
        }
    }else{
        cout<<"O robo nao pode se mover, bateria acabou"<<endl;
        return false;
    }
}

void Modelo01:: LigarUP(int** pp_ambienteReal){
    while(bateriaDoRobo.nivel>1){
        //LaserRobo.calcularColisao(pp_ambienteReal,posicaoAtualRobo[0],posicaoAtualRobo[1],dimAmbiente[0],dimAmbiente[1]);
        int respostarapida;
        cout<<"Deseja se mover? (0/1) "<<endl;
        cin>> respostarapida;
        if(respostarapida){
            DecideMovimento();
            mover(pp_ambienteReal,proximaPosicao[0],proximaPosicao[1]);
            printAmbienteRobo(posicaoAtualRobo[0],posicaoAtualRobo[1]);
        }
    }
    cout<<"O robo vai desligar"<<endl;
}


// classe robo> Modelo02
Modelo02::Modelo02(string nome, string entradas):Robo(nome,entradas){
    //usa o construtor padrao de robo
}

void Modelo02::Limpar(int x, int y){
    if((x==posicaoInicial[0])&&(y==posicaoInicial[1])){
        cout<<"Area limpa"<<endl;
    }else{
        pp_ambienteRobo[x][y]+=1;
        cout<<"Area limpa"<<endl;
    }  
}

void Modelo02::DecideMovimento(){
    
}

bool Modelo02::mover(int** pp_ambienteReal,int novaPosicaoX, int novaPosicaoY){
    cout<<"O robo esta nessa posicao: x: "<<posicaoAtualRobo[0]<<" y:" <<posicaoAtualRobo[1]<<endl;
    cout<<"O robo vai tentar ir para posicao: x: "<< novaPosicaoX<<" e y: "<<novaPosicaoY<<endl;
    if(bateriaDoRobo.nivel>0){
        //Teste de nivel de bateria
        if((novaPosicaoX<dimAmbiente[0]&&novaPosicaoY<dimAmbiente[1])&&(novaPosicaoX>=0&&novaPosicaoY>=0)){
            //teste se a posição esta em um local valido
            if(ParaChoqueRobo.CalcularColisao(pp_ambienteReal,novaPosicaoX,novaPosicaoY)){
                //teste de obstaculo
                cout<<"O robo vai se mover"<<endl;

                Limpar(posicaoAtualRobo[0],posicaoAtualRobo[1]);

                posicaoAtualRobo[0]=novaPosicaoX;
                posicaoAtualRobo[1]=novaPosicaoY;

                bateriaDoRobo.Descarregar();
                return true;
            }else{
                cout<<"O robo nao pode se mover, tem obstaculo"<<endl;
                pp_ambienteRobo[novaPosicaoX][novaPosicaoY] = 111;
                return false;
            }
        }else{
            cout<<"O robo nao pode se mover, fora do mapa"<<endl;
            return false;
        }
    }else{
        cout<<"O robo nao pode se mover, bateria acabou"<<endl;
        return false;
    }
}

void Modelo02:: Ligar(){
    
}