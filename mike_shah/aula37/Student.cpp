#include "Student.h"

#include<string>
#include<iostream>
using namespace std;

Student::Student(){
    m_name ="No name";
    cout<<"Contructor: "<<endl;
    cout<<"m_name is: "<< m_name <<endl;
}

Student::Student(string name){
    m_name =name;
    cout<<"Contructor: "<<endl;
    cout<<"m_name is: "<< m_name <<endl;
}

Student::~Student(){
    cout<<"Destructor: "<< m_name  <<endl;
}

void Student::printname(){
    cout<<"Name is "<< m_name <<endl;
}