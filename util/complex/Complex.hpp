#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <ostream>
#include <SFML/Graphics.hpp>

class Complex {
public :
    float r;
    float i;
public:
    Complex() = default ;
    Complex( float );
    Complex( float , float );
    Complex( sf::Vector2f );


public: 
    //+
    Complex operator +  (Complex);
    Complex operator += (Complex);

    //-
    Complex operator -  ();
    Complex operator -  (Complex);
    Complex operator -= (Complex);

    //x
    Complex operator *  (Complex);
    Complex operator *= (Complex);

    //div
    Complex operator /  (Complex);
    Complex operator /= (Complex);

    //comparison
    bool operator == (Complex);
    bool operator != (Complex);
    

    //|a + bi|

    float length();

    sf::Vector2f toVector();

public:
    friend std::ostream & operator << (std::ostream & , Complex);

public:
    static Complex Eulor(float);
};


#endif