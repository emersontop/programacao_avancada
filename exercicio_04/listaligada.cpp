#include <iostream>

using namespace std;

class No{
  public:
    float x;
    float y;
    No* p_noNext;

    //construtor
    No(float a, float b){
      x=a;
      y=b;
      cout<<"Valor de x: "<<x<<" Valor de Y: "<<y<<endl;
    };
};

class Lista{
  public:
    //atributo
    //no* lista;
    No* head;

    //construtor
    Lista(){
      head = 0;
    }
    //medtodo
};

int main(){

  No primeiroNo(10.0,12.5);
  No segundoNo(11.0,13.5);
  No terceiroNo(12.0,14.5);
  No quartoNo(13.0,15.5);


  return 0;
};
