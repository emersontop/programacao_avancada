#include <iostream>
#include <string>
#include "myfunctions.h"

//cd '.\desktop\arquivos temporarios\02_faculdade\programacao_av'
//g++ ex.cpp myfunctions.cpp -o prog
//./prog 

int main()
{
    string texto;
    int angle;
    int i;

    texto = requestString();
    i = analyseString(texto);
    cout << i << endl;

    stringToAngle(texto, angle);

    cout << angle <<endl;
    cout << "FIM"  <<endl;
    return 0;
}