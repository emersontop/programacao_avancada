#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student{ //Student - Our new user defined type
    public:
        // Action - Constructor
        Student();
        // Action - Constructor
        Student(string name);
        // Action - Destructor
        ~Student();
        // Action - Print the Student name
        void printname();
    public:
        string m_name;
};

#endif