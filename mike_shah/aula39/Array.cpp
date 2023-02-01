#include "Array.h"

#include <iostream>

using namespace std;

Array::Array(){
    cout<< "Contructor" <<endl;
    data = new int[10];
    for(int i=0;i<10;i++){
        data[i]=i*i;
    }
}

Array::~Array(){
    cout<< "Destructor" <<endl;
    delete[] data;
}

Array::Array(const Array& rhs){
    cout<< "Copy Contructor" <<endl;
    delete[] data;
    data = new int[10];
    for(int i=0;i<10;i++){
        data[i]=rhs.data[i];
    }
}

void Array::Printingdata(){
    for(int i=0;i<10;i++){
        cout << data[i] << endl;
    }
}

void Array::SetData(int index, int value){
    data[index] = value;
}