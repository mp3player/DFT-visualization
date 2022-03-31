#ifndef _DRAW_H_
#define _DRAW_H_

#include<ctime>
#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>
#include "draw.hpp"

#include"../util/_typedef.hpp"
#include "../shape/M_Circle.hpp"
#include "../util/Complex.hpp"
#include "../util/FFT.hpp"
#include "../util/Parser.hpp"
#include "../path.h"


#define WIDTH 800                   //窗口大小
#define HEIGHT 800
#define MAX_FRAME_RATE 1024           //限制帧率
#define ZOOM_RATIO 1.1              //缩放的比率

//转换坐标系到笛卡尔坐标系
sf::Transform trans(
    1.0f,0.0f,WIDTH / 2,
    0.0f,-1.0f,HEIGHT / 2,
    0.0f,0.0f,1.0f
);

Vex_list axis = Vex_list();
Vex_list shape1 = Vex_list();
Vex_list shape2 = Vex_list();

void animateIDFT( sf::RenderWindow * window , Cir_list circles, C_List coef , Vex_list & shape , float factor = 1.0f){

    static int k = 0;
    int N = coef.size();
    
    axis.clear();
    Complex X(0.0f);
    for(int i = 0 ; i < N ; ++ i){
        
        Complex c = coef[i] * Complex::Eulor( 2.0f * PI * k * i / N );

        Complex next = X + c;

        axis.push_back((next / N).toVector());

        M_Circle * circle = circles[i];
        circle->setPosition( ( X / N ).toVector() );
        circle->setRadius( ( c / N ).length() );
        window->draw( *circle , trans );

        X = next;
    }
    shape.push_back(
        sf::Vertex( (X / N).toVector() )
    );

    k = (k + 1) % N;

    window->draw( &(axis[0]) , axis.size() , sf::LinesStrip , trans );
    window->draw( &(shape[0]) , shape.size() , sf::LinesStrip , trans );

}

void draw(){

    // V_list vs = Parser::ParserPathFile("./assets/path/heart.json");
    V_list vs = Parser::ParserPathFile("cd.json");

    std::cout << vs.size() << std::endl;

    C_List signal = C_List();

    for(sf::Vector2f v : vs){
        signal.push_back( (Complex(v) - Complex(104,30.5)) * 400);
    }

    C_List freq = FFT::DFT(signal);
    //生成圆圈
    Cir_list circles = Cir_list();

    for(int i = 0 ; i < freq.size() ; ++ i){
        M_Circle * circle = new M_Circle(10);
        circle->setOutlineThickness(2.0f);
        circle->setOutlineColor(sf::Color::Red);
        circle->setFillColor(sf::Color(1,0,0,0));
        circles.push_back(circle);
    }

    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "My window");
    window->setFramerateLimit(MAX_FRAME_RATE);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:{
                    window->close();
                }break;
                case sf::Event::MouseWheelScrolled:{
                    sf::Vector2f zoom = event.mouseWheelScroll.delta > 0 ? sf::Vector2f(1.1f,1.1f) : sf::Vector2f(.9f,.9f);
                    trans.scale( zoom );
                }
            }
            
        }


        window->clear( sf::Color::Black );
        
        animateIDFT(window,circles,freq,shape2);
        
        window->display();
    }



     //释放内存
    for(M_Circle * circle : circles){
        delete circle;
    }
}


#endif