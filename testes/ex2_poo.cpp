//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\testes'
//g++ ex2_poo.cpp -o ex2_poo
//./ex2_poo 
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
    public:
    Rectangle(int, int); // funcao construtor que nao retorna nada assim quando crio o objeto, tenho que passar essas informacoes
    int area() {return width*height;}
};

Rectangle::Rectangle(int x, int y){
    width = x;
    height = y;
}

int main(){
    Rectangle rect(2,2);
    Rectangle rectb(100,2);
    cout << "Area e: " << rect.area() << endl;
    cout << "Area e: " << rectb.area() << endl;
    return 0;
}