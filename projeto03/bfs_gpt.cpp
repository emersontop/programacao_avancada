#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

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
  void bfs(graph,int);
  
  // // Print the path from the source to a given node
  // void printPath(int, int);
};

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

void graph::bfs(graph,int start)
{
  // Initialize all nodes
  for(int i=0; i<nbNodes; i++){
    nodeList[i].color = 0;
    nodeList[i].distance = -1;
    nodeList[i].previous = -1;
  }

  // Initialize queue and starting node
  queue<int> q;
  nodeList[start].color = 1;
  nodeList[start].distance = 0;
  q.push(start);

  // Start BFS algorithm
  while(!q.empty()){
    int current = q.front();
    q.pop();

    // Check all adjacent nodes of current node
    for(int i=0; i<nbNodes; i++){
      if(table[current][i] != 0 && nodeList[i].color == 0){
        nodeList[i].color = 1;
        nodeList[i].distance = nodeList[current].distance + 1;
        nodeList[i].previous = current;
        q.push(i);
      }
    }

    nodeList[current].color = 2;
  }
}


void printPath(graph &g, int start, int end) {
    if (start == end) {
        cout << start << endl;
    }
    else if (g.nodeList[end].previous == -1) {
        cout << "No path from " << start << " to " << end << endl;
    }
    else {
        printPath(g, start, g.nodeList[end].previous);
        cout << end << endl;
    }
}

int main()
{
  // Create a graph
  graph g("graph1.txt",9);

  // Call Breadth-first search from node 0
  g.bfs(g, 0);

  // Print path from 0 to 4
  printPath(g, 1, 4);

  return 0;
}