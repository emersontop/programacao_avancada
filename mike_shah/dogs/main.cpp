#include <iostream>

using namespace std;

class Dog{
    public:
        Dog(){}

        void Barck(){
            cout<<"barck! "<<endl;
        }
        void Walk(){
            x+=1;
            y+=1;
        }

        float x,y;
};

class Golden: public Dog{
    public:
        Golden(){
            m_sticksRetrivied=0; 

        }

        void Retrieve(){
            cout<<"Retriveing a stick"<<endl;
            m_sticksRetrivied++;
        }

        float m_sticksRetrivied;
};

class Husky: public Dog{

};

int main(){

    Golden dog1;
    dog1.Barck();
    dog1.Walk();

    Husky dog2;
    dog2.Barck();

    return 0;
}