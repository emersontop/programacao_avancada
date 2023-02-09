#ifndef INTARRAY_H
#define INTARRAY_H

#include<vector>
#include<string>

using namespace std;

//definicaoda class
class IntArray {
    public:
        //contrutor
        IntArray(string name);
        //destructor
        ~IntArray();
        //copy constructor
        IntArray(const IntArray& rhs);
        //copy Assignmet operator.
        IntArray& operator=(const IntArray& rhs);
        //move constructor policy
        IntArray(IntArray&& source);
        //Movve assignment operator policy
        IntArray& operator=(IntArray&& source);

    private:
        string m_name;
        int* m_data;
};

#endif