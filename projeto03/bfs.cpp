#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//UFPE - CTG
//Alunos: Emerson e Sanclay

//codigo da fila lista

class QNode
{
  //Classe no da Fila lista
public:
  //construtor
  QNode(int valorQNode)
  {
    valor = valorQNode;
    p_NextQNode = NULL;
    cout<<"QNode criado!"<<endl;
    printValorQnode();
  };

  void printValorQnode()
  {
    cout<<"Valor do Qnode: "<<valor<<endl;
  }

  // valor recebe o valor do no
  int valor;
  // p_NextQNode ponterio que aponta para o poximo elemento da Queue
  QNode* p_NextQNode;
};

class Queue
{
public:
//construtor
  Queue()
  {
    //No inicio, a fila nao possui elementos, por isso seus atributos front e rear recebem NULL
    front = NULL;
    rear = NULL;

    cout<<"Fila criada"<<endl;
  };

  //metodos para a Fila

  //Insere um QNode na Fila com o valor passado
  void enQueue(int valor);

  //Remove o QNode mais antigo na Fila, por isso nao eh passado nenhum argumento.
  void deQueue();

  //imprime a Fila
  void printQueue();

  //front eh um ponteiro de QNode e aponta para a frente da Fila
  QNode *front;
  //front eh um ponteiro de QNode e aponta para o ultimo QNode da Fila
  QNode *rear;
};

void Queue::enQueue(int valorDoNodeAdicionado)
{

  QNode* NodeAdicionado;
  NodeAdicionado= new QNode(valorDoNodeAdicionado);
  cout<<"Processo de enQueue"<<endl;
  NodeAdicionado->printValorQnode();

  //Analisa se a fila esta vazia
  if(rear == NULL){
    cout<<"1) opcao: A Fila esta vazia"<<endl;
    rear = NodeAdicionado;
    front = NodeAdicionado;
    cout<<"QNode adicionaodo ao final da fila!"<<endl;
    NodeAdicionado->printValorQnode();
  }else{
    cout<<"2) opcao: Fila nao esta vazia"<<endl;
    rear->p_NextQNode = NodeAdicionado;
    rear = NodeAdicionado;

    cout<<"QNode adicionaodo ao final da fila!"<<endl;
    NodeAdicionado->printValorQnode();
  };

};

void Queue::deQueue(){

  cout<<"Processo de deQueue:"<<endl;
  if(rear==NULL && front==NULL)
  {
    cout<<"1) opcao: A fila esta vazia"<<endl;
  }else if(rear == front)
  {
    cout<<"2) opcao) A fila possui apenas um QNode"<<endl;
    cout<<"Apagando QNode com o valor: "<<front->valor<<endl;

    front = NULL;
    rear = NULL;

  }else
  {
    cout<<"3) opcao: A fila possui mais de um QNode"<<endl;
    cout<<"Apagando QNode com o valor: "<<front->valor<<endl;

    front = front->p_NextQNode;
  }
};

void Queue::printQueue()
{
  QNode* queuePrint;
  cout<<"Processo de impressão da Queue:"<<endl;
  if(rear==NULL && front==NULL)
  {
    cout<<"1) opcao: A fila esta vazia"<<endl;
  }else if(rear == front)
  {
    cout<<"2) opcao) A fila possui apenas um QNode"<<endl;
    queuePrint = front;
    while(queuePrint!=NULL)
    {
      cout<<queuePrint->valor<<" ";
      queuePrint = queuePrint->p_NextQNode;
    }
    cout<<endl;
  }else
  {
    cout<<"3) opcao: A fila possui mais de um QNode"<<endl;
    queuePrint = front;
    while(queuePrint!=NULL)
    {
      cout<<queuePrint->valor<<" ";
      queuePrint = queuePrint->p_NextQNode;
    }
    cout<<endl;
  }

};

// Graph node
struct GNode
{
  int color; // 0 white 1 grey 2 black
  int distance;
  int previous;
};


class graph
{
public:
  int nbNodes;      //Numero de Gnodes
  int** table;      //Matriz com o graph
  GNode* nodeList;  // lista de nodes

  // Create graph from a file, with a given number of nodes
  graph(string, int);

  // Breadth-first search algorithm from a given node
  void bfs(int);

  // Print the path from the source to a given node
  void printPath(int, int);
};

graph::graph(string grapharquivo, int nodes)
{
  nbNodes = nodes;
  // alocar memoria para a matriz
  table = new int*[nbNodes];
  for(int i = 0; i < nbNodes; i++)
  {
    table[i] = new int[nbNodes];
  }

  
};

int main()
{
  // Create a graph
  graph g("graph1.txt",9);

  // Call Breadth-first search from node 0
  g.bfs(0);

  // Print path to from 0 to 4
  g.printPath(0,4);

  return 0;
}
