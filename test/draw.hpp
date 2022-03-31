#ifndef _DRAW_H_
#define _DRAW_H_

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



void animateDFT( sf::RenderWindow * window , std::vector<M_Circle*> circles, std::vector<Complex> coef , std::vector<sf::Vertex> & shape , float factor = 1.0f);

void animateIDFT( sf::RenderWindow * window , std::vector<M_Circle*> circles, std::vector<Complex> coef , std::vector<sf::Vertex> & shape , float factor = 1.0f);

void drawLine();

void draw();

#endif