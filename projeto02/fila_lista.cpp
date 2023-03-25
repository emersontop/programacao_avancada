#include <iostream>

using namespace std;

class QNode {

public:

  //inicializando as varaveis
  int valor;
  QNode* p_NextNode;

  //construtor QNode
  QNode(int valorNode){
    valor = valorNode;
    cout<<"No criado"<<endl;
    cout<<"O valor do Node e: "<<valor<<endl;
  };

};

class Queue {

public:

  //inicializando as varaveis
  QNode *front;
  QNode *rear;

  //construtor Queue
  Queue(){
    cout<<"Lista criada"<<endl;
    front = NULL;
    rear = NULL;
  };

  //metodos
  void enQueue(int valor);
  void deQueue();
};


//Adiciona no na lista
void Queue::enQueue(int valorDoNodeAdicionado){

  //criando um no
  QNode NodeAdicionado(valorDoNodeAdicionado);

  if(rear == NULL){
    cout<<"A Lista esta vazia"<<endl;
    rear = front = &NodeAdicionado;
  }else{
    rear->p_NextNode = &NodeAdicionado;
    rear = &NodeAdicionado;
    cout<<
  };

  // NodeAdicionado.p_NextNode = rear;
  // rear = &NodeAdicionado;

};


//Remove no da lista
void Queue::deQueue(){


};


int main()
{

  // Initialize random seed to generate random numbers
  srand (time(NULL));

  // Create a queue
  Queue q;

  q.enQueue(1);
  q.enQueue(5);

  // do
  // {
  //   if ((rand() % 100) < 50)
  //   {
  //       // Enqueue a random number between 1 and 100
  //       q.enQueue(rand() % 100 + 1);
  //   }
  //   else
  //   {
  //       // Dequeue the oldest entry
  //       q.deQueue();
  //   }
  // }
  // // While the queue is not empty
  // while(q.front != NULL);
}
