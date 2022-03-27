#include "Complex.hpp"
#include <cmath>


Complex::Complex( float r ) : Complex(r,0.0f) {};

Complex::Complex( float r , float i ){
    this->r = r;
    this->i = i;
}

Complex::Complex( sf::Vector2f vec ){
    this->r = vec.x;
    this->i = vec.y;
}

 //+
Complex Complex::operator +  (Complex num){
    return Complex(this->r + num.r , this->i + num.i);
}
Complex Complex::operator += (Complex num){
    this->r += num.r;
    this->i += num.i;
    return *this;
}

//-
Complex Complex::operator -  (){
    return Complex(this->r , -this->i);
}
Complex Complex::operator -  (Complex num){
    return Complex(this->r - num.r , this->i - num.i); 
}
Complex Complex::operator -= (Complex num){
    this->r -= num.r;
    this->i -= num.i;
    return *this;
}

//x
Complex Complex::operator *  (Complex num){
    float r = this->r * num.r - this->i * num.i;
    float i = this->r * num.i + this->i * num.r;
    return Complex(r,i);
}
Complex Complex::operator *= (Complex num){
    float r = this->r * num.r - this->i * num.i;
    float i = this->r * num.i + this->i * num.r;
    this->r = r;
    this->i = i;
    return *this;
}

//div
Complex Complex::operator /  (Complex num){
    // conj
    Complex conj = -num;
    // mod
    float mod = conj.length();

    if(mod == 0)
        return Complex();


    Complex com = *this * conj;

    return com * (1.0f / (mod * mod));
}
Complex Complex::operator /= (Complex num){
    Complex conj = -num;

    float mod = conj.length();

    if(mod == 0){
        this->r = 0;
        this->i = 0;
    }

    *this *= conj;
    *this *= (1.0f / (mod * mod) );
    return *this;
}


float Complex::length(){
    return std::sqrt( std::pow( this->r , 2.0f ) + std::pow( this->i , 2.0f ) );
}

sf::Vector2f Complex::toVector(){
    return sf::Vector2f(this->r , this->i);
}


std::ostream & operator << (std::ostream & cout , Complex num){
    cout << num.r << (num.i >= 0 ? "+" : "-") << abs(num.i) << "i" ;
    return cout;
}

Complex Complex::Eulor(float ang){
    float r = std::cos(ang);
    float i = std::sin(ang);
    return Complex(r,i);
}
    