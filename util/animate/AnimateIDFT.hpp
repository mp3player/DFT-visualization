#ifndef _ANIMATE_IDFT_H_
#define _ANIMATE_IDEF_H_

#include"../_typedef.hpp"

//用于执行动画，需要传入N个原始信号值，
class AnimateIDFT{
public:
    Cir_list circles;       //  circle
    Vex_list outline;       // outline of the original shape
    Vex_list axes;           // axes;
    C_List signal;          // original signal
    C_List freq;            // freqent
    int k;
    int N;

public:
    AnimateIDFT( C_List , Complex = Complex(0.0f) , float = 1.0f );

    AnimateIDFT( V_list , Complex = Complex(0.0f) , float = 1.0f );

    ~AnimateIDFT();

    void init( C_List , Complex = Complex(0.0f) , float = 1.0f );

    C_List setup( C_List , Complex = Complex(0.0f) , float = 1.0f );

    void draw(sf::RenderWindow * , sf::Transform );

    void next();

    void run(sf::RenderWindow * , sf::Transform );

};

#endif