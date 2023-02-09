#include "IntArray.h" 

#include <iostream>

#include<vector>

using namespace std;

IntArray::IntArray(string name) : m_name(name), m_data(new int[10]){
    cout<<m_name <<": Was contructed" <<endl;
}

IntArray::~IntArray(){
    cout<<m_name <<": Was destructed" <<endl;
    delete[]m_data;
}

IntArray::IntArray(const IntArray& rhs){
    m_name = rhs.m_name+"(Copy)";
    cout<<"Was copy contructed from: "<<rhs.m_name <<endl;
    m_data = new int[10];
    for(int i=0;i<10;i++){
        m_data[i] = rhs.m_data[i];
    }
}

IntArray& IntArray::operator=(const IntArray& rhs){
    if (this!=&rhs){
        delete[]m_data;
        m_name = rhs.m_name+"(Copy)";
        cout<< " Was copy assignment operator"<<rhs.m_name<<endl;
        m_data = new int[10];
        for(int i=0;i<10;i++){
            m_data[i] = rhs.m_data[i];
        }
    }
    return *this; 
}

//move constructor
IntArray::IntArray(IntArray&& source){
    m_name = source.m_name;
    source.m_name="";
    m_data=source.m_data;
    source.m_data=nullptr;
    cout<<m_name << " Used move constructed"<<endl;
}

//move assigment
IntArray& IntArray::operator=(IntArray&& source){
    if(this!=&source){
        m_name = source.m_name;
        source.m_name="";
        m_data=source.m_data;
        source.m_data=nullptr;
        cout<<m_name << " Used move assignment"<<endl;
    }
    return *this;
}