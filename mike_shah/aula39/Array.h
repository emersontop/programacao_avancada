#ifndef ARRAY_H
#define ARRAY_H

//definicaoda class
class Array {
    public:
        //contrutor
        Array();
        //destructor
        ~Array();
        //imprime dados
        void Printingdata();
        //
        void SetData(int index, int value);
    private:
        int* data;
};

#endif