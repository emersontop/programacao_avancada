//cd '.\desktop\arquivos temporarios\02_faculdade\programacao_av'
//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\testes'
//g++ ex.cpp myfunctions.cpp -o prog
//./prog 
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
    public:
    void set_values(int,int);
    int area() {return width*height;}
};

void Rectangle::set_values(int x, int y){
    width = x;
    height = y;
}

int main(){
    Rectangle rect;
    rect.set_values(2,2);
    cout << "Area e: " << rect.area() << endl;
    return 0;
}