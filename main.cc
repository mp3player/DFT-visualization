#include <iostream>
#include<fstream>
#include "include/FFT.hpp"
#include "./test/poly.hpp"
#include "include/AnimateIDFT.hpp"
#include "include/Parser.hpp"
#include "include/Scalar.hpp"
// #include "./audio/Player.hpp"
#include<regex>

#include "include/fft.h"


//A多项式的阶次               
#define A_COEF_COUNT 1024
//B多项式的阶次
#define B_COEF_COUNT 1024
//多项式的大小，用于测试计算误差
#define TEST_ERROR_COUNT 1024 * 4
//窗口大小
#define WIDTH 1920
#define  HEIGHT 1080
//限制帧率
#define MAX_FRAME_RATE 180

//坐标变换
sf::Transform transform(
    1.0f,0.0f,WIDTH / 2,
    0.0f,-1.0f,HEIGHT / 2,
    0.0f,0.0f,1.0f
);


void animate();

int main()
{
    testfft();
    // 比较计算时间
    // for(int i = 0 ; i < 10 ; ++ i)
        // compareTime(A_COEF_COUNT , B_COEF_COUNT);
    // 比较计算误差
    // compareError(TEST_ERROR_COUNT);
    // DFT的逆过程动画演示，正弦和余弦合成动画的演示，绘制一个心形图案
    // animate();
    return 0;
}

void animate(){
    std::vector<AnimateIDFT *> animateGroup = std::vector<AnimateIDFT *>();

    for(int i = 0 ; i <= 34 ; ++ i){
        // V_list vertexList = Parser::ParserPathFile("assets/path/map/" + std::to_string(i) + ".json");
        V_list vertexList = Parser::ParserPathFile("js/map/" + std::to_string(i) + ".json");
        AnimateIDFT * animate = new AnimateIDFT(vertexList,Complex(-103,-30),60.0f);
        animateGroup.push_back(animate);
    }

    std::string heart = "assets/path/heart.json";
    V_list heartPath = Parser::ParserPathFile(heart);
    AnimateIDFT heartAnimation = AnimateIDFT(heartPath);

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
                case sf::Event::MouseWheelScrolled : {
                    sf::Vector2f zoom = event.mouseWheelScroll.delta > 0 ? sf::Vector2f(1.1f,1.1f) : sf::Vector2f(.9f,.9f);
                    transform.scale(zoom);
                    
                }break;
            }
            
        }


        window->clear( sf::Color::Black );
        // heartAnimation.run(window,transform);
        for(AnimateIDFT * animate : animateGroup){
            if(!animate->finished){
                animate->run(window,transform);
                break;
            }else{
                window->draw( &(animate->outline[0]) , animate->outline.size() , sf::LinesStrip , transform);
            }
        }
        window->display();
    }

}