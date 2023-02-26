#include <iostream>

using namespace std;

// classe no da lista ligada
class Node{
    public:
        float x;    // valor1
        float y;    // valor2
        Node* p_NodeNext;   //aponta para o proximo no

        //construtor
        Node(){

        };
        Node(float a, float b){
            x=a;
            y=b;
            cout<<"No criado"<<endl;
            cout<<"Valor de x: "<<x<<" Valor de Y: "<<y<<endl;
        };

        void printNode(){
            cout<<"O valor do no"<<endl;
            cout<<"Valor de x: "<<x<<" Valor de Y: "<<y<<endl;
        }
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
            Node* inicio = head;    //Salvar o inicio
            while(head != NULL){
                cout<< "Para esse no x= "<<head->x<<" e Y= "<<head->y <<endl;
                head = head->p_NodeNext;
            }
            head = inicio;          //retornar para o inicio
        }

        //procurar no
        Node* procuraNode(Node nodeProcurado){
            cout<<"Vou procurar o no"<<endl;
            Node* inicio = head;    //salvar o inicio
            Node* retorno;
            while(head != NULL){
                //cout<<"Entrei no loop"<<endl;
                if(head->x==nodeProcurado.x&&head->y==nodeProcurado.y){
                    cout<<"No encontrado"<<endl;
                    //cout<<"Valor de x: "<<head->x <<" Valor de Y: "<< head->y<<endl;
                    retorno= head;
                }
                head = head->p_NodeNext;
            }
            head = inicio;          //retornar para o inicio
            return retorno;
        }

        //excluir no
        void excluirNode(Node nodeExcluido){
            Node* inicio = head;
            Node* Anterior = head;

            while(head!=NULL){
                if(head->x==nodeExcluido.x&&head->y==nodeExcluido.y){
                    cout<<"No encontrado, vai ser excluido"<<endl;
                    Anterior->p_NodeNext=head->p_NodeNext;
                    // o no anterior aponta para o sucessor do no atual
                }
                Anterior = head; 
                head = head->p_NodeNext;
            }
            head = inicio;
        }
};

int main(){
    //inicinaod a lista
    Lista lista1;

    //alocando memoria para o No
    Node* busca;

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

    busca = lista1.procuraNode(primeiroNo);
    busca->printNode();

    lista1.excluirNode(segundoNo);
    lista1.pirntListNode();

    return 0;
}