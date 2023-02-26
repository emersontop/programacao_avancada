#include <iostream>

using namespace std;

class Node{
    public:
        int data;   //Armazena o dado
        Node* next; //Armazena o local do proximo node
};

//funcao para printar a lista de nos
void pirntListNode(Node* no){
    while(no != NULL){
        cout<< no->data <<endl;
        no = no->next;
    }
}

int main(){

    //iniciando o no
    Node* head = NULL;

    //alocando memoria
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    //inserindo no 1
    first->data = 1;    //dado
    first->next = head; //ponteiro para o proximo
    head = first;       //atualizar o inicio

    //inserindo no 2
    second->data = 2;
    second->next = head;
    head = second;

    //inserindo no 3
    third->data =3;
    third->next = head;
    head = third;

    cout<<"printando a lista"<<endl;
    pirntListNode(head);


    return 0;
}