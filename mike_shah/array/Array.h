#ifndef ARRAY_H
#define ARRAY_H

#include<vector>

using namespace std;

//definicaoda class
class Array {
    public:
        //contrutor
        Array();
        //destructor
        ~Array();
        //copy constructor
        Array(const Array& rhs);
        //copy Assignmet operator.
        Array& operator=(const Array& rhs);
        //imprime dados
        void Printingdata();
        //
        void SetData(int index, int value);
    private:
        vector<int>data;
};

#endif