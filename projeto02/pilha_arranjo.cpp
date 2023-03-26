#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Finalizado
//UFPE-CTG 
//Alunos: Sanclay e Emerson

class stack
{

private:

  int elementos;
  int topo;
  int* arranjo;
public:
  stack(int numElementos){
    elementos = numElementos;
    arranjo = new int[elementos];
    topo = -1;
  }

  int push(int numPush);

  int pop();
};


int stack::push(int numPush){
  topo = topo + 1;
  if(topo < elementos){
    arranjo[topo]=numPush;
    cout<<numPush<<" pushed to the stack"<<endl;
    return 1;
  }else{
    cout<<"Full stack"<<endl;
    return 0;
  }
}

int stack::pop(){
  if(topo<0){
    cout<<"Empty stack"<<endl;
    return 0;
  }else{
    cout<<arranjo[topo]<<" popped to the stack"<<endl;
    topo = topo - 1;
    return 1;
  }
}


int main()
{
  //apagar depois
  //int teste;
  // Initialize random seed to generate random numbers
  srand (time(NULL));

  // Create a stack with 10 elements
  stack s(10);

  // Result for push and pop
  int result = 1;

  // While the stack is not full or empty
  while(result)
  {
    //apagar depois
    //cout<<"Deseja continuar?"<<endl;
    //cin>> teste;
    if ((rand() % 100) < 50)
    {
        // Push to the stack a random number between 1 and 100
        result = s.push(rand() % 100 + 1);
    }
    else
    {
        // Pop the last entry
        result = s.pop();
    }
  }

}
