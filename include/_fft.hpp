#ifndef _ITERATIVE_FFT_H_
#define _ITERATIVE_FFT_H_

#include "Complex.hpp"

#include<fstream>
#include<iostream>
#include <bitset>
#include <cmath>
#include <regex>
#include "bit_map_65536.hpp"

#include "util.hpp"

template <unsigned int bit_length>
unsigned long reverse(int num){
    std::bitset<bit_length> bit(num);
    std::bitset<bit_length> rev(0);
    for(int i = 0 ; i < bit_length ; ++ i){
        rev[i] = bit[bit_length - i - 1];
    }
    return rev.to_ulong();
}

template <int BIT_LENGTH>
void generateMap(){

    std::vector<unsigned int> index = std::vector<unsigned int>();
    std::vector<unsigned int> val = std::vector<unsigned int>();
    const int LENGTH = std::pow(2 , BIT_LENGTH);
    for(int i = 0 ; i < LENGTH ; ++ i){
        index.push_back(i);
        unsigned long rev = reverse<BIT_LENGTH>(i);
        val.push_back(rev);
    }
    //重排顺序
    //将数组放入文件中
    std::ofstream outFile("bit_map_" + std::to_string(LENGTH) + ".h" , std::ios::app);

    if(!outFile.is_open()){
        std::cout << "create file failed" << std::endl;
    }

    std::string header = "#include<vector>\nstd::vector<int> bit_map = {";
    std::string footer = "};";
    outFile.write( header.c_str() , header.size() );

    for(int i = 0 ; i < LENGTH ; ++ i){
        if(i == LENGTH - 1){
            std::string content = std::to_string(val[i]) + " ";
            outFile.write( content.c_str() , content.size() );
        }else{
            std::string content = std::to_string(val[i]) + ", ";
            outFile.write( content.c_str() , content.size() );
        }
        
    }
    outFile.write( footer.c_str() , footer.size() );

    outFile.close();
}


//非递归的fft 
C_List fft(C_List signal){
    int N = bit_map.size();
    //逆序二进制位
    C_List list = C_List( N );
    
    for(int i = 0 ; i < N ; ++i){
        list[bit_map[i]] = signal[i];
    }
    
    //执行迭代的fft算法
    int lgn = std::log2( N );
    //分组处理信号
    for(int s = 1 ; s <= lgn ; ++s){
        int m = std::pow(2,s);
        Complex Wm = Complex::Eulor(-2.0f * M_PI / m);  //x
        //处理所有的信号，步长为m
        for(int k = 0 ; k < N ; k += m){
            Complex w(1.0f);
            //处理m个信号
            for(int j = 0 ; j < m / 2 ; ++ j){
                    
                Complex t = w * list[k + j + m / 2];
                Complex u = list[k + j];
                list[k + j] = u + t;
                list[k + j + m / 2] = u - t;
                w = w * Wm;
            }
        }
    }
    return list;
}

//非递归的ifft
C_List ifft(C_List signal){
    int N = bit_map.size();
    //逆序二进制位
    C_List list = C_List( N );
    
    for(int i = 0 ; i < N ; ++i){
        list[bit_map[i]] = signal[i];
    }
    
    //执行迭代的fft算法
    int lgn = std::log2( N );
    //分组处理信号
    for(int s = 1 ; s <= lgn ; ++s){
        int m = std::pow(2,s);
        Complex Wm = Complex::Eulor(2.0f * M_PI / m);  //x
        //处理所有的信号，步长为m
        for(int k = 0 ; k < N ; k += m){
            Complex w(1.0f);
            //处理m个信号
            for(int j = 0 ; j < m / 2 ; ++ j){
                    
                Complex t = w * list[k + j + m / 2];
                Complex u = list[k + j];
                list[k + j] = u + t;
                list[k + j + m / 2] = u - t;
                w = w * Wm;
            }
        }
    }
    for(int i = 0 ; i < list.size() ; ++ i){
        list[i] *= (1.0f / N);
    }
    return list;
}

void testTimeWithFFT(){

    C_List list = util::randComplexVector(65535);

    //测试非递归调用的时间
    std::clock_t startTime = clock();
    C_List freq1 = fft(list);
    std::clock_t endTime = clock();
    float iteCost = ((float)(endTime - startTime)) / CLOCKS_PER_SEC;

    //----------------------------------------------------------------
    //测试递归调用的时间
    startTime = clock();
    C_List freq2 = FFT::FT(list);
    endTime = clock();
    float recCost = ((float)(endTime - startTime)) / CLOCKS_PER_SEC;

    std::cout << "ite cost " << iteCost << std::endl;
    std::cout << "rec cost " << recCost << std::endl;

    float error = 0;


    for(int i = 0 ; i < 1024 ; ++ i){
        error = ( freq1[i] - freq2[i] ).length();
    }
    std::cout << "ifft error " << error << std::endl;

}



void testfft(){
    for(int i = 0 ; i < 4 ; ++ i){
        testTimeWithFFT();
        std::cout << "------------------------------------" << std::endl;
    }

    generateMap<24>();
}

#endif