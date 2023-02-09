#include <iostream>
//RAII >> assunto da aula 
using namespace std;

class Collection{
    public:
        //constructor
        Collection(){
            data = new int[10];
            try{
                throw 20;
            }catch(int e){
                //algum error aqui
            }
        }
        //destrucutor
        ~Collection(){
            cout<<"Destructor foi chamado"<<endl;
            delete[] data;
        }
        //operator
        int& operator[](size_t idx){
            return data[idx];
        }

        const int& operator[](size_t idx)const{
            return data[idx];
        }

    private:
        int* data;
};


int main(){

    Collection myCollection;
    myCollection[0]=7;
    myCollection[1]=7;
    myCollection[2]=7;

    cout<<myCollection[0]<<endl;

    return 0;
}