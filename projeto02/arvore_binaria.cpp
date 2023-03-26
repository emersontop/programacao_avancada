#include <iostream>

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

public:
    //Atributos
    TNode* raiz;

    Tree(){
        raiz = NULL;
        cout<<"A arvore foi criada: "<<endl;
    }


};

int main(){

    return 0;
}