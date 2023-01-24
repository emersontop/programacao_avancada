//cd '.\desktop\arquivos temporarios\02_faculdade\programacao_av'
//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\testes'
//g++ ex.cpp myfunctions.cpp -o prog
//./prog 
#include <iostream>
using namespace std;

template <class T>
    class mypair {
        T values[2];
    public:
        mypair(T first, T second)
        {values[0]=first; values[1]=second;}
};

int main(){
    mypair<int> myobject (115, 36);
    mypair<double> myfloats (3.0, 2.18);
    return 0;
}