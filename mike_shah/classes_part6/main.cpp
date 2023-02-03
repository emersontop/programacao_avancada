//cd C:\Users\eggui '.\Documents\02estudo\programacao_avancada\mike_shah\classes_part6'
//g++ main.cpp -o main
//./main

#include <iostream>

#include "Vector.h"

using namespace std;

ostream& operator<<(ostream& os,const Vector3f& obj){
    os <<obj.x <<"," <<obj.y<< "," << obj.z;
    return os;
}

int main(){

    Vector3f myVector1;

    cout<<myVector1<<endl;

    return 0;
}