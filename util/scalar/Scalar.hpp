#ifndef _SCALAR_H_
#define _SCALAR_H_

#include"../_typedef.hpp"

class Scalar{

public:
    float min ;
    float max;
public :
    Scalar(float , float );
    C_List apply(C_List);
    void setScale(float ,float );
    Complex getMax(C_List);
    Complex getMin(C_List);
};

#endif