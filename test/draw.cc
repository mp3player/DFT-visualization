#include<ctime>
#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>

#include "../shape/M_Circle.hpp"
#include "../util/Complex.hpp"
#include "../util/FFT.hpp"
#include "../util/Parser.hpp"


#define WIDTH 800                   //窗口大小
#define HEIGHT 800
#define MAX_FRAME_RATE 24           //限制帧率
#define ZOOM_RATIO 1.1              //缩放的比率

//转换坐标系到笛卡尔坐标系
sf::Transform trans(
    1.0f,0.0f,WIDTH / 2,
    0.0f,-1.0f,HEIGHT / 2,
    0.0f,0.0f,1.0f
);

std::vector< sf::Vertex > axis = std::vector< sf::Vertex >();
std::vector<sf::Vertex> shape1 = std::vector<sf::Vertex>();
std::vector<sf::Vertex> shape2 = std::vector<sf::Vertex>();

void animateDFT( sf::RenderWindow * window , std::vector<M_Circle*> circles, std::vector<Complex> coef , std::vector<sf::Vertex> & shape , float factor = 1.0f){

    static int k = 0;
    int N = coef.size();
    
    axis.clear();
    Complex X(0.0f);
    for(int i = 0 ; i < N ; ++ i){
        
        Complex c = coef[i] * Complex::Eulor( -2.0f * PI * k * i / N );

        Complex next = X + c;

        axis.push_back((next / (N * factor)).toVector());

        M_Circle * circle = circles[i];
        circle->setPosition( (X / (N * factor)).toVector() );
        circle->setRadius( (c / (N * factor)).length() );
        window->draw( *circle , trans );

        X = next;
    }
    shape.push_back(
        sf::Vertex( (X / (N * factor)).toVector() )
    );

    k = (k + 1) % N;

    window->draw( &(axis[0]) , axis.size() , sf::LinesStrip , trans );
    window->draw( &(shape[0]) , shape.size() , sf::LinesStrip , trans );


}

void animateIDFT( sf::RenderWindow * window , std::vector<M_Circle*> circles, std::vector<Complex> coef , std::vector<sf::Vertex> & shape , float factor = 1.0f){

    static int k = 0;
    int N = coef.size();
    
    axis.clear();
    Complex X(0.0f);
    for(int i = 0 ; i < N ; ++ i){
        
        Complex c = coef[i] * Complex::Eulor( 2.0f * PI * k * i / N );

        Complex next = X + c;

        axis.push_back((next / (N * factor)).toVector());

        M_Circle * circle = circles[i];
        circle->setPosition( (X / (N * factor)).toVector() );
        circle->setRadius( (c / (N * factor)).length() );
        window->draw( *circle , trans );

        X = next;
    }
    shape.push_back(
        sf::Vertex( (X / (N * factor)).toVector() )
    );

    k = (k + 1) % N;

    window->draw( &(axis[0]) , axis.size() , sf::LinesStrip , trans );
    window->draw( &(shape[0]) , shape.size() , sf::LinesStrip , trans );


}



void test(){

 std::vector<sf::Vector2f> coords = Parser::ParserPathFile("./assets/path/heart.json");

    std::vector<Complex> signal = std::vector<Complex>();

    

    for(sf::Vector2f vec : coords ){
        signal.push_back(Complex(vec.x,vec.y));
    }

    // dft 629个频率
    std::vector<Complex> coef = signal;
    std::vector<Complex> part = std::vector<Complex>();
    float ratio = 0;
    //只取低频部分，高频部分用0填充
    for(int i = 0 ; i < coef.size() ; ++ i){
        part.push_back(coef[i]);
    }

    //生成圆圈
    std::vector<M_Circle *> circles = std::vector<M_Circle *>();

    for(int i = 0 ; i < part.size() ; ++ i){
        M_Circle * circle = new M_Circle(10);
        // circle->setTexture(tex);
        circle->setOutlineThickness(2.0f);
        circle->setOutlineColor(sf::Color::Red);
        circle->setFillColor(sf::Color(1,0,0,0));
        circles.push_back(circle);
    }

    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "My window");
    

    window->setFramerateLimit(MAX_FRAME_RATE);

    while (!window->isOpen())
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
        
        animateDFT(window,circles,coef,shape2 , .8);
        

        window->display();
    }



     //释放内存
    for(M_Circle * circle : circles){
        delete circle;
    }
}
