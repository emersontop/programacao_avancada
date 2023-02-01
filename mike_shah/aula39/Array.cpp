#include "Array.h"

#include <iostream>

using namespace std;

Array::Array(){
    data = new int[10];
    for(int i=0;i<10;i++){
        data[i]=i*i;
    }
}

Array::~Array(){
    delete[] data;
}

void Array::Printingdata(){
    for(int i=0;i<10;i++){
        cout << data[i] << endl;
    }
}

void Array::SetData(int index, int value){
    data[index] = value;
}