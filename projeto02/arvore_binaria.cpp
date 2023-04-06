#include <iostream>
#include<string>
#include <fstream>

using namespace std;

class TNode{

public:
    //Atributos
    int chave;
    TNode* P;
    TNode* Esquerda;
    TNode* Direita;

    //Construtor
    TNode(int ValorDoTNode){
        chave = ValorDoTNode;
        P = NULL;
        Esquerda = NULL;
        Direita = NULL;

        cout<<"TNode criado com o valor de : "<<chave<<endl;
    }   

};

class Tree{

private:


public:
//Atributos
    TNode* raiz;  

    Tree(){
        raiz = NULL;
        cout<<"A arvore foi criada: "<<endl;
    }

    void Tinsert(int novoNoh);
    void Tprint(TNode* raiz);
    TNode* Tsearch(TNode* raiz, int valorBusca);


};

void Tree::Tinsert(int valorAdicionado){

    //Cria o noh
    TNode* NodeAdicionado;
    NodeAdicionado = new TNode(valorAdicionado);

    TNode* auxNo1 = raiz;
    TNode* auxNo2 = NULL;

    while (auxNo1 != NULL)
    {
        auxNo2 = auxNo1;
        if ( NodeAdicionado->chave < auxNo1->chave)
        {
            auxNo1 = auxNo1->Esquerda;
        }else{
            auxNo1 = auxNo1->Direita;
        }
        
    }

    //Indicao o pai
    NodeAdicionado->P = auxNo2;

    if (auxNo2 == NULL) //testa de o noh tem pai ou nao, caso nao ele eh a raiz
    {
        raiz = NodeAdicionado;
    }
    //Verifica se o valor eh menor ou maior e decide se vai para esquerda ou direita
    else if(NodeAdicionado->chave < auxNo2->chave)
    {
        auxNo2->Esquerda = NodeAdicionado;
    }
    else
    {
        auxNo2->Direita = NodeAdicionado;
    }
          
}

void Tree::Tprint(TNode* auxPrint)
{

    if (auxPrint != NULL)
    {
        Tree::Tprint(auxPrint->Esquerda);
        cout<<auxPrint->chave<<endl;
        Tree::Tprint(auxPrint->Direita);
    }
    
}

TNode* Tree::Tsearch(TNode* auxSearch, int valorObjetivo)
{
    while (auxSearch != NULL && valorObjetivo != auxSearch->chave)
    {
        if (valorObjetivo < auxSearch->chave)
        {
            auxSearch = auxSearch->Esquerda;
        }
        else
        {
           auxSearch = auxSearch->Direita; 
        }
        
    }
    cout<<"Encontrei o valor de "<< auxSearch->chave <<endl;
    return auxSearch;
    
}

   

int main(){

    Tree carvalho;

    int intLine;
    string line;
    
    ifstream myfile("data.txt");

    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {
            intLine = stoi(line);
            carvalho.Tinsert(intLine);
        }
    }

    carvalho.Tprint(carvalho.raiz);

return 0;
}