//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\testes'
//g++ ex8_poo.cpp -o ex8_poo
//./ex8_poo

#include <iostream>
using namespace std;

class Mother {
    public :
        Mother ()
            { cout << " Mother : no  parameters \n"; }
        Mother ( int a)
            { cout << " Mother :  int   parameter \n"; }
};

class Daughter : public Mother {
    public :
        Daughter ( int a)
            { cout << " Daughter :  int   parameter \n\n"; }
};

class Son : public Mother {
    public :
        Son (int a) : Mother (a)
            { cout << " Son :  int   parameter \n\n"; }
};

int main(){
    Daughter kelly (0);
    Son bud (0);
    return 0;
}