//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\testes'
//g++ ex7_poo.cpp -o ex7_poo
//./ex7_poo

#include <iostream>
using namespace std;

class Polygon {
    //classe poligono
    protected:
        int width, height;
    public:
        void set_values (int a, int b)
            {width=a; height=b;}
};

class Retangle: public Polygon {
    //classe retangle que herda da classe poligon a parte publica
    public:
        int area()
            {return width*height;}
};

class triangle:public Polygon{
    //classe triangle que herda da classe poligon a parte publica
    public:
        int area()
            {return width*height/2;}
};

int main(){
    Retangle rect;
    triangle trgl;
    rect.set_values(4,5);
    trgl.set_values(4,5);
    cout<<rect.area() << endl;
    cout<<trgl.area() << endl;
    return 0;
}