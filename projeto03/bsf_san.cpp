#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

  //Analisa se a fila esta vazia
  if(rear == NULL){

    //Como sera adicionado o primeiro QNode, a frente e o final da fila apontam para o mesmo local o endreco do QNode adicionado
    rear = NodeAdicionado;
    front = NodeAdicionado;

  }else{
    //Fila nao esta vazia

    //Como o sistam eh uma fila com lista ligada, e a lista nao esta vazia. 
    //O rear guarda a informacao do ultimo valor que foi adicionado, e pelo endereco dele conseguimos alterar o valor do atributo
    //do QNnode p_NextNode, passando o endereco de memoria do QNode que esta sendo adicionado agora.
    rear->p_NextNode = NodeAdicionado;

    //Depois que disso precisamos mudar o valor do rear para que ele guarde o valor do QNode que foi adicioando agora.
    rear = NodeAdicionado;

  };

};


//Remove o QNode mais antigo na Fila, por isso nao eh passado nenhum argumento.
void Queue::deQueue(){

  //Analisa se a lista esta vazia, se rear e front forem iguais a NULL a lita esta vazia
  if(rear==NULL && front==NULL){
    cout<<"A fila esta vazia"<<endl;
  //Analisa se a lista tem apenas um elemento, se ela tiver apenas um elemento o front e o rear apontam para o mesmo local
  }else if(rear == front){

    //front e rear recebem NULL
    front = NULL;
    rear = NULL;

  //se a fila nao estiver vazia e nao possuir apenas um elemento ela possui mais de 1.
  }else{

    //Mudamos o front de local e ele agora aponta para outro QNode
    front = front->p_NextNode;
  }
};




// ############################################################## GRAPH NODE ########################################################



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
  graph(string, int);
  
  // // Breadth-first search algorithm from a given node
  void bfs(int);
  
  // // Print the path from the source to a given node
  void printPath(int, int);
};

graph::graph(string nome_arquivo,int nbNodes) 
{
  this->nbNodes = nbNodes;

    table = new int*[nbNodes];

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
           table[k][i] = stoi(cValor);
           //cout<<matriz[i]<<' ';
        } 
        k++;
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

    nodeList = new GNode[nbNodes];
    
};



void graph::bfs(int startVertice)
{

  nodeList = new GNode[nbNodes];
 
  for(int i = 0; i < nbNodes; i++)
  {
    nodeList[i].color = 0;
    nodeList[i].distance = 1;
    nodeList[i].previous = -1;
  }

  nodeList[startVertice].color = 1;
  nodeList[startVertice].distance = 0;
  nodeList[startVertice].previous = -1;

  Queue *q  = new Queue();
  
  q->enQueue(startVertice);//adiciona o valor do vertice

  
  while(q->front != NULL) 
  {
    int j = q->front->valor;
    q->deQueue();
    for(int i = 0; i < nbNodes; i++) 
    {
      if(table[j][i] != 0 && nodeList[i].color == 0) 
      {
        nodeList[i].color = 1;
        nodeList[i].distance = nodeList[j].distance + 1;
        nodeList[i].previous = j;
        q->enQueue(i);
        cout<<"Loop do bfs"<<endl;
      }
      //cout<<"i :"<<i<<" j :"<<j<<endl;
    }
    nodeList[j].color = 2;

  }
  cout<<"Lopp bfs finalizado"<<endl;

};

//Printa o caminho da source para odestino
// void graph::printPath(int origem, int destino)
// {

//   //Checa se o edstino é alcancavel a partir da oringem
//   if (nodeList[destino].previous == -1)
//   {
//     cout << "Destino " << destino << " não pode ser atingido " << origem << endl;
//     //para o metodo aqui
//     return;
//   }

//   // Queue auxiliar
//   Queue *aux_q  = new Queue();

//   //Ponteiro auxiliar de QNode = o endereço da frente da Queue
//   QNode *aux_front = aux_q->front;

//   int atualNode = destino;
//   while (atualNode != origem)
//   {
//     //path.push(atualNode);
//     aux_q->enQueue(atualNode);
//     atualNode = nodeList[atualNode].previous;
//     cout<<"Atualnode: "<<atualNode<<endl;

//   }
//   aux_q->enQueue(origem);

//   // Imprimindo o caminho
//   cout << "Caminho de " << origem << " para " << destino << ":" << endl;
//   while (aux_front != aux_q->rear)
//   {
//     cout << aux_front->valor << " ";
//     aux_q->deQueue();
//   }
//   cout << endl;
// }

void graph::printPath(int origem, int destino)
{
  int * path = new int[nbNodes];
  if (destino == origem)
  {
    cout << "Caminho de " << origem << " ate o Gnode " << destino << endl;
    cout << origem << " ";
  }else if (nodeList[destino].previous == -1)
  {
    cout << "Nenhum caminho encontrado " << origem << " para o Gnode " << destino << endl;
  }else{
    int index = 0;
    int current = destino;

    // percorre o caminho percorrido a partir do no de destino e armazena em um vetor
    while (current != origem) {
      if (nodeList[current].previous != -1) {
        path[index++] = current;
      }
      current = nodeList[current].previous;
    }

    path[index] = origem;

    // ordem inversa
    cout << "Caminho de " << origem << " ate Gnode " << destino << endl;
    for (int i = index; i >= 0; i--) {
      if (path[i] != -1) {
        cout << path[i] << " ";
      }
    }
    cout << endl;
  }
}


int main()
{
  // Create a graph
  graph g("graph1.txt",9);

  //Call Breadth-first search from node 0
  g.bfs(0);

  //Print path to from 0 to 4
  g.printPath(0,4);

  return 0;
}
