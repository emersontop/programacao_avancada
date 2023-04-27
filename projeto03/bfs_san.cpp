#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
  int nbNodes;
  int **table = new int*[nbNodes];
  GNode* nodeList;

  // Create graph from a file, with a given number of nodes
  graph(string, int nbNodes);
  
  // // Breadth-first search algorithm from a given node
  void bfs(int);
  
  // // Print the path from the source to a given node
  // void printPath(int, int);
};

class Queue 
{
//Fila que seque o padrao de First in First outr (FIFO) e com lista ligada
public:
  //Atributos
  //instanciando as varaveis

  //front eh um ponteiro de QNode e aponta para a frente da Fila
  QNode *front;

  //front eh um ponteiro de QNode e aponta para o ultimo QNode da Fila
  QNode *rear;

  //construtor Queue
  Queue()
  {
    //Print para informar que a Fila foi criada
    cout<<"Fila criada"<<endl;
    
    //No inicio, a fila nao possui elementos, por isso seus atributos front e rear recebem NULL
    front = NULL;
    rear = NULL;
  };
}

graph::graph(string nome_arquivo,int nbNodes) 
{
   int *matriz = new int[nbNodes];

   for(int i = 0; i < nbNodes; i++)
   {
     table[i] = new int[nbNodes];
   }

   
   char* cValor;
   int intLine;
   string line;
   int k = 0;
   

   ifstream myfile(nome_arquivo);

   if(myfile.is_open())
    {
      while(getline(myfile,line))
      {
        for (int i = 0; i < nbNodes; i++)
        {            
           cValor = &line[2*i];
           matriz[i] = stoi(cValor);
           //cout<<matriz[i]<<' ';
        } 

        for (int j=0; j< nbNodes; j++)
        {
          table[k][j] = matriz[j];
          k++;
        }
 
        
      }

      cout<<" A matriz final eh:"<<endl;
      for (int i = 0; i < nbNodes; i++)
      {
        for (int j = 0; j < nbNodes; j++)
        {
        cout<<table[i][j]<<" ";
        }
        cout<<endl;
      }

    }
    myfile.close();
    
}


void bfs::enQueue(int valorDoNodeAdicionado){

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


    //O rear guarda a informacao do ultimo valor que foi adicionado, e pelo endereco dele conseguimos alterar o valor do atributo
    //do QNnode p_NextNode, passando o endereco de memoria do QNode que esta sendo adicionado agora.
    rear->p_NextNode = NodeAdicionado;

    //Depois que disso precisamos mudar o valor do rear para que ele guarde o valor do QNode que foi adicioando agora.
    rear = NodeAdicionado;

    cout<<"QNode adicionaodo ao final da fila, seu valor: "<<NodeAdicionado->valor<<endl;
  };

};

void bfs::deQueue(){

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

void bfs(int)
{
  nodeList = new GNode[startVertice];
  
  for(int i = 0; i < nbNodes; i++)
  {
    nodeList[i].color = 0;
    nodeList[i].distance = 100;
    nodeList[i].previous = NULL;
  }

    nodeList[startVertice].color = 1;
    nodeList[startVertice].distance = 0;
    nodeList[startVertice].previous = NULL;
}

int main()
{
  // Create a graph
  graph g("graph1.txt",9);

  // // Call Breadth-first search from node 0
  // g.bfs(0);
  //
  // // Print path to from 0 to 4
  // g.printPath(0,4);

  return 0;
}
