//cd '.\desktop\arquivos temporarios\02_faculdade\programacao_av'
//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\testes'
//g++ ex.cpp myfunctions.cpp -o prog
//./prog 
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
    public:
    Rectangle(int x, int y) : width(x), height(y){}
    int area() {return width*height;}
};

int main(){
    Rectangle obj (3, 4);
    Rectangle * foo , * bar , * baz ;

    foo = & obj ; // recebe o endreco de memoria do objeto "obj"
    //pq usar o new, nao seria apenas para usar Rectangle(5,6)
    bar = new Rectangle (5, 6); // aloca memoria
    baz = new Rectangle [2] { {2 ,5} , {3 ,6} }; //aloca2 memorias
    
    cout << " obj 's  area : " << obj . area () << '\n';
    cout << "*foo 's  area : " << foo -> area () << '\n';
    cout << "*bar 's  area : " << bar -> area () << '\n';
    cout << " baz [0] 's  area :" << baz [0]. area () << '\n';
    cout << " baz [1] 's  area :" << baz [1]. area () << '\n';
    delete bar;
    delete [] baz ;
    return 0;
}