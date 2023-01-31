//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\testes'
//g++ ex1_poo.cpp -o ex1_poo
//./ex1_poo 
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
    //atributos provados, nao podem ser acessados
    public:
    void set_values(int,int);
    int area() {return width*height;}
    //funcao da class rectangle que foi declarada e escrita aqui mesmo
};

void Rectangle::set_values(int x, int y){
    //funcao da class rectangle
    width = x;
    height = y;
}

int main(){
    Rectangle rect; //instanciando a class
    rect.set_values(2,2); //chamdno uma funcao da classe
    cout << "Area e: " << rect.area() << endl;
    return 0;
}