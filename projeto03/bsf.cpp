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
  int** table;
  GNode* nodeList;

  // Create graph from a file, with a given number of nodes
  graph(string, int);
  //
  // // Breadth-first search algorithm from a given node
  // void bfs(int);
  //
  // // Print the path from the source to a given node
  // void printPath(int, int);
};



graph::graph(string nome_arquivo,int nbNodes) {

   int *matriz = new int(nbNodes);

   table = new int*[nbNodes];

   for(int i = 0; i < nbNodes; i++)
   {
     table[i] = new int(nbNodes);
   }

   // ate aqui ok

   int intLine;
   string line;

   ifstream myfile(nome_arquivo);

   if(myfile.is_open())
     {
       while(getline(myfile,line))
       {
         for (int j = 0; i < nbNodes; i++)
         {
           valor = line //pegar valor por valor
         }

         for (int i = 0; i < nbNodes; i++)
         {
             cout<<intLine[i]<<" ";
             // table[i][j] = stoi(valor);
             // cout<<matriz[i]<<" ";
         }
         cout<<endl;
       }
     }
}

// void bfs::enQueue(int valorDoNodeAdicionado){
//
//
//   QNode* NodeAdicionado;
//   NodeAdicionado= new QNode(valorDoNodeAdicionado);
//
//   if(rear == NULL){
//     rear = NodeAdicionado;
//     front = NodeAdicionado;
//
//   }else{
//
//     rear->p_NextNode = NodeAdicionado;
//
//     rear = NodeAdicionado;
//
//   };
//
// };
//
//
//
// void graph::deQueue(){
//
//   cout<<"Processo de deQueue:"<<endl;
//
//   if(rear==NULL && front==NULL){
//     // cout<<"Valor de front e rear: "<<front<<" "<<rear<<endl;
//      cout<<"A fila esta vazia"<<endl;
//
//   }else if(rear == front){
//
//     front = NULL;
//     rear = NULL;
//
//
//   }else{
//
//     front = front->p_NextNode;
//   }
// };


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
