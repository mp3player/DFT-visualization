#include <iostream>
#include<fstream>
#include <SFML/Graphics.hpp>

#include "./shape/M_Circle.hpp"
#include "./util/Complex.hpp"
#include "./util/FFT.hpp"
#include "./util/Parser.hpp"
#include "path.h"

#define WIDTH 800                   //窗口大小
#define HEIGHT 800
#define MAX_FRAME_RATE 60           //限制帧率

//转换坐标系到笛卡尔坐标系
sf::Transform trans(
    1.0f,0.0f,WIDTH / 2,
    0.0f,-1.0f,HEIGHT / 2,
    0.0f,0.0f,1.0f
);

std::vector< sf::Vertex > axis = std::vector< sf::Vertex >();
std::vector<sf::Vertex> shape = std::vector<sf::Vertex>();
std::vector<Complex> com = std::vector<Complex>();

void animate(std::vector<Complex> coef){
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");

    sf::Texture* tex = new sf::Texture();
    tex->setSmooth(true);
    tex->loadFromFile("./assets/chrome.jpeg");

    window.setFramerateLimit(MAX_FRAME_RATE);

    int k = 0;
    int N = coef.size();
    //生成圆圈
    std::vector<M_Circle *> circles = std::vector<M_Circle *>();

    for(int i = 0 ; i < N ; ++ i){
        M_Circle * circle = new M_Circle(10);
        // circle->setTexture(tex);
        circle->setOutlineThickness(2.0f);
        circle->setOutlineColor(sf::Color::Red);
        circle->setFillColor(sf::Color(1,0,0,0));
        circles.push_back(circle);
    }



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear( sf::Color::Black );
        axis.clear();
        Complex X(0.0f);
        for(int i = 0 ; i < N ; ++ i){
            
            Complex c = coef[i] * Complex::Eulor( 2.0f * PI * k * i / N );


            Complex next = X + c;


            axis.push_back((next / N).toVector());

            M_Circle * circle = circles[i];
            circle->setPosition( (X / N).toVector() );
            circle->setRadius( (c / N).length() );
            window.draw( *circle , trans );

            X = next;
        }
        shape.push_back(
            sf::Vertex( (X / N).toVector() )
        );

        k = (k + 1) % N;

        window.draw( &(axis[0]) , axis.size() , sf::LinesStrip , trans );
        window.draw( &(shape[0]) , shape.size() , sf::LinesStrip , trans );

        

        window.display();
    }

    //释放内存
    for(M_Circle * circle : circles){
        delete circle;
    }
}

int main()
{
    // Parser::ParserPathFile("path.json");

    std::vector<Complex> signal = std::vector<Complex>();

    for(int i = 0 ; i < path.size() ; i += 2){
        Complex c(path[i] , path[ i + 1 ]) ;
        signal.push_back(c);
    }

    // dft 629个频率
    std::vector<Complex> coef = FFT::DFT(signal);
    std::vector<Complex> part = std::vector<Complex>();
    int max_length = 40;
    //只取低频部分，高频部分用0填充
    for(int i = 0 ; i < coef.size() ; ++ i){
        if(i < max_length)
            part.push_back(coef[i]);
        else
            part.push_back(Complex(0,0));
    }

    std::cout << part.size() << std::endl;

    
    animate(part);

 
    return 0;
}