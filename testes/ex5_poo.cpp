//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\testes'
//g++ ex5_poo.cpp -o ex5_poo
//./ex5_poo

#include <iostream>
using namespace std;

class CVector {
    public :
        int x,y;
        CVector () {};
        CVector ( int a, int b) : x(a), y(b) {}
        CVector operator + ( const CVector &);
};

CVector CVector :: operator + ( const CVector & param ) {
    CVector temp ;// o objeto de saida
    //preencho o objeto de saida
    temp .x = x + param .x;
    temp .y = y + param .y;
    
    return temp ;
}

int main(){
    CVector foo (3 ,1);
    CVector bar (1 ,2);
    CVector result ;
    result =  bar + foo;
    cout << result .x << ',' << result .y << '\n';
    return 0;
}