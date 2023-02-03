#include "Vector.h"

Vector3f::Vector3f(): x(1.0f),y(2.0f),z(3.0f){}

/*        // operator +
        Vector3f operator+(const Vector3f& rhs)const {
            Vector3f result;
            result.x=x+rhs.x;
            result.y=y+rhs.y;
            result.z=z+rhs.z;

            return result;
        }

        //operator ++
        Vector3f operator++(){
            x =x+1;
            y =y+1;
            z =z+1;
            return *this;
        }

        bool operator==( const Vector3f& rhs){
            cout << "== da classe" <<endl;
            if(x == rhs.x &&
                y == rhs.y &&
                z == rhs.z){
                return true;
            }   
            return false;
        }*/

/*bool operator==(const Vector3f& lhs, const Vector3f& rhs){
    cout << "== do progrma pricipal" <<endl;
    if(lhs.x == rhs.x &&
        lhs.y == rhs.y &&
        lhs.z == rhs.z){
        return true;
    }   
    return false;
}*/