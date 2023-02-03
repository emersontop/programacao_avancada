#include "Array.h" 

#include <iostream>

#include<vector>

using namespace std;

Array::Array(){
    cout<< "Contructor" <<endl;
    for(int i=0;i<1;i++){
        data.push_back(i);
    }
}

Array::~Array(){
    cout<< "Destructor" <<endl;
    //delete[] data;
}

Array::Array(const Array& rhs){
    cout<< "Copy Contructor" <<endl;
    for(int i=0;i<rhs.data.size();i++){
        data.push_back(rhs.data[i]);
    }
}

Array& Array::operator=(const Array& rhs){
    cout<< "Copy assignment operator" <<endl;
    if (&rhs == this){
        return *this;
    }
    data.clear();
    for(int i=0;i<rhs.data.size();i++){
        data.push_back(rhs.data[i]);
    }

    return *this; 
}

void Array::Printingdata(){
    for(int i=0;i<data.size();i++){
        cout << data[i] << endl;
    }
}

void Array::SetData(int index, int value){
    data[index] = value;
}