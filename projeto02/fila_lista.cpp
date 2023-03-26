#include <iostream>
#include <time.h>

using namespace std;

//Satus: feito!
//UFPE - CTG
//Alunos: Sanclay, Emerson

class QNode {
//No
public:
  //Atributos
  //Instanciando as variaveis

  //Valor guarda o valor do QNode
  int valor;
  
  //QNode como vamos usar uma fila com lista ligada, precisamos do endereco do proximo No.
  QNode* p_NextNode;

  //construtor QNode
  QNode(int valorNode){
    //Passa o valor passado como parametro ao atributo Valor
    valor = valorNode;

    //Inica o QNode como NuLL
    p_NextNode = NULL;
    cout<<"No criado. O valor do Node e: "<<valor<<endl;
  };

};

class Queue {
//Fila que seque o padrao de First in First outr (FIFO) e com lista ligada
public:
  //Atributos
  //instanciando as varaveis

  //front eh um ponteiro de QNode e aponta para a frente da Fila
  QNode *front;

  //front eh um ponteiro de QNode e aponta para o ultimo QNode da Fila
  QNode *rear;

  //construtor Queue
  Queue(){
    
    //Print para informar que a Fila foi criada
    cout<<"Fila criada"<<endl;
    
    //No inicio, a fila nao possui elementos, por isso seus atributos front e rear recebem NULL
    front = NULL;
    rear = NULL;
  };

  //metodos para a Fila

  //Insere um QNode na Fila com o valor passado
  void enQueue(int valor);

  //Remove o QNode mais antigo na Fila, por isso nao eh passado nenhum argumento.
  void deQueue();
};


//Adiciona QNode na Fila
void Queue::enQueue(int valorDoNodeAdicionado){

  //Cria um QNode com o valor passado como parametro da funcao
  QNode* NodeAdicionado;
  NodeAdicionado= new QNode(valorDoNodeAdicionado);
  cout<<"Processo de enQueue: "<<NodeAdicionado->valor<<endl;

  //Analisa se a fila esta vazia
  if(rear == NULL){

    //Fila esta vazia porque Rear esta como NULL, aqui existem outros metodos para analisar a fila esta vazia, mas foi escolhido esse
    cout<<"1) opcao: A Lista esta vazia"<<endl;

    //Como sera adicionado o primeiro QNode, a frente e o final da fila apontam para o mesmo local o endreco do QNode adicionado
    rear = NodeAdicionado;
    front = NodeAdicionado;
    cout<<"QNode adicionaodo ao final da fila, seu valor: "<<NodeAdicionado->valor<<endl;
  }else{
    //Fila nao esta vazia

    cout<<"2) opcao: Fila nao esta vazia"<<endl;

    //Como o sistam eh uma fila com lista ligada, e a lista nao esta vazia. 
    //O rear guarda a informacao do ultimo valor que foi adicionado, e pelo endereco dele conseguimos alterar o valor do atributo
    //do QNnode p_NextNode, passando o endereco de memoria do QNode que esta sendo adicionado agora.
    rear->p_NextNode = NodeAdicionado;

    //Depois que disso precisamos mudar o valor do rear para que ele guarde o valor do QNode que foi adicioando agora.
    rear = NodeAdicionado;

    cout<<"QNode adicionaodo ao final da fila, seu valor: "<<NodeAdicionado->valor<<endl;
  };

};


//Remove o QNode mais antigo na Fila, por isso nao eh passado nenhum argumento.
void Queue::deQueue(){

  cout<<"Processo de deQueue:"<<endl;
  //Analisa se a lista esta vazia, se rear e front forem iguais a NULL a lita esta vazia
  if(rear==NULL && front==NULL){
    cout<<"Valor de front e rear: "<<front<<" "<<rear<<endl;
    cout<<"1) opcao: A fila esta vazia"<<endl;
  //Analisa se a lista tem apenas um elemento, se ela tiver apenas um elemento o front e o rear apontam para o mesmo local
  }else if(rear == front){
    cout<<"Valor de front e rear: "<<front<<" "<<rear<<endl;
    cout<<"2) opcao) A fila possui apenas um QNode"<<endl;
    cout<<"Apagando QNode com o valor: "<<front->valor<<endl;

    //front e rear recebem NULL
    front = NULL;
    rear = NULL;

  //se a fila nao estiver vazia e nao possuir apenas um elemento ela possui mais de 1.
  }else{
    cout<<"Valor de front e rear: "<<front<<" "<<rear<<endl;
    cout<<"3) opcao: A fila possui mais de um QNode"<<endl;
    cout<<"Apagando QNode com o valor: "<<front->valor<<endl;

    //Mudamos o front de local e ele agora aponta para outro QNode
    front = front->p_NextNode;
  }
};


int main()
{

  // Initialize random seed to generate random numbers
  srand (time(NULL));
  int resposta;
  // Create a queue
  Queue q;

  do
  {
    if ((rand() % 100) < 50)
    {
        // Enqueue a random number between 1 and 100
        q.enQueue(rand() % 100 + 1);
    }
    else
    {
        // Dequeue the oldest entry
        q.deQueue();
    }
    // cout<<"Deseja continuar?"<<endl;
    // cin>>resposta;
  }
  // While the queue is not empty
  while(q.front != NULL);
}
