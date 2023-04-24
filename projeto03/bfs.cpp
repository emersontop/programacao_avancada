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

  // Breadth-first search algorithm from a given node
  void bfs(int);

  // Print the path from the source to a given node
  void printPath(int, int);
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
