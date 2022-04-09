#include <iostream>
#include<fstream>
#include "util/FFT.hpp"
#include "./test/poly.hpp"
#include "test/draw.hpp"
#include "./audio/Player.hpp"
#include<regex>


//A多项式的阶次               
#define A_COEF_COUNT 1024 * 16 + 1
//B多项式的阶次
#define B_COEF_COUNT 1024 * 16
//多项式的大小，用于测试计算误差
#define TEST_ERROR_COUNT 1024 * 4


int main()
{   
    

    // 比较计算时间
    // compareTime(A_COEF_COUNT , B_COEF_COUNT);
    // 比较计算误差
    // compareError(TEST_ERROR_COUNT);
    // DFT的逆过程动画演示，正弦和余弦合成动画的演示，绘制一个心形图案
    // drawHeart();
    // 绘制一个地图轮廓
    // drawMap();
    return 0;
}