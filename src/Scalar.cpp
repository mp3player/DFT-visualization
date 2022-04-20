#include "../include/Scalar.hpp"
#include<cmath>
#include<iostream>

Scalar::Scalar(float min, float max){
    this->min = min;
    this->max = max;
}

C_List Scalar::apply(C_List list){
    Complex minC = getMin(list);
    Complex maxC = getMax(list);
    // scale factor
    float rFactor = (maxC.r - minC.r) / (max - min);
    float iFactor = (maxC.i - minC.i) / (max - min);
 
    // std::cout << minC << std::endl;
    // std::cout << maxC << std::endl;


    C_List res = C_List();
    for(Complex c : list){
        float r = ( c.r - minC.r ) / rFactor + min;
        float i = ( c.i - minC.i ) / iFactor + min;
        res.push_back(Complex(r,i));
    }
    return res;
}   


void Scalar::setScale(float min , float max ){
    this->min = min;
    this->max = max;
}

Complex Scalar::getMax(C_List list){
    Complex max(-INFINITY , -INFINITY);
    std::cout << max << std::endl;
    for(Complex c : list){
        if(c.r > max.r ){
            max.r = c.r;
        }
        if(c.i > max.i){
            max.i = c.i;
        }
    }
    return max;
}

Complex Scalar::getMin(C_List list){
    Complex min(-INFINITY , -INFINITY);

    for(Complex c : list){
        if(c.r > min.r ){
            min.r = c.r;
        }
        if(c.i > min.i){
            min.i = c.i;
        }
    }
    return min;
}