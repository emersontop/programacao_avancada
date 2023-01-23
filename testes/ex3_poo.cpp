//cd '.\desktop\arquivos temporarios\02_faculdade\programacao_av'
//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\testes'
//g++ ex.cpp myfunctions.cpp -o prog
//./prog 
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
    public:
    Rectangle();
    Rectangle(int, int);
    int area() {return width*height;}
};

Rectangle::Rectangle(){
    width = 5;
    height =5;
}

Rectangle::Rectangle(int x, int y){
    width = x;
    height = y;
}

int main(){
    Rectangle rect(2,2);
    cout << "Area e: " << rect.area() << endl;
    Rectangle rectb;
    cout << "Area e: " << rectb.area() << endl;
    return 0;
}