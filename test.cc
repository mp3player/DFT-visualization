#include<ctime>
#include<iostream>

template <typename FN , typename PAR>
void testTime1(  FN(*p)(PAR) , PAR x){

    // 获取当前时间
    std::clock_t s_time = clock();


    p(x);


    //获取执行完毕后的时间
    std::clock_t e_time = clock();


    //计算过程的时间
    // std::cout << s_time << std::endl;
    // std::cout << e_time << std::endl;
    // std::cout << CLOCKS_PER_SEC << std::endl;
    // std::cout << (e_time - s_time) << std::endl;
    std::cout << ((float)(e_time - s_time) / CLOCKS_PER_SEC) << std::endl;
}