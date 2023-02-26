#include <iostream>

using namespace std;

// classe no da lista ligada
class Node{
    public:
        float x;    // valor1
        float y;    // valor2
        Node* p_NodeNext;   //aponta para o proximo no

        //construtor
        Node(float a, float b){
        x=a;
        y=b;
        cout<<"No criado"<<endl;
        cout<<"Valor de x: "<<x<<" Valor de Y: "<<y<<endl;
        };
};

class Lista{
    public:
        //Atributos
        Node* head;
        Lista(){
            cout<<"Lista criada"<<endl;
            head=NULL;
        }

        //metodos
        //insere no na lista
        void insereNodeNaLista(Node& no){
            no.p_NodeNext = head;
            head = &no;
        }
        //printa a lista
        void pirntListNode(){
            while(head != NULL){
                cout<< "Para esse no x= "<<head->x<<" e Y= "<<head->y <<endl;
                head = head->p_NodeNext;
            }
        }
};

int main(){
    //inicinaod a lista
    Lista lista1;

    //iniciando o no
    Node primeiroNo(10.0,12.5);
    
    //colocando na lista
    lista1.insereNodeNaLista(primeiroNo);

    Node segundoNo(11.0,13.5);
    lista1.insereNodeNaLista(segundoNo);

    Node terceiroNo(12.0,14.5);
    lista1.insereNodeNaLista(terceiroNo);

    Node quartoNo(13.0,15.5);
    lista1.insereNodeNaLista(quartoNo);

    cout<<"printando a lista"<<endl;
    lista1.pirntListNode();

    return 0;
}