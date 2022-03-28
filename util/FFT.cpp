#include "FFT.hpp"
#include<cmath>

#include<iostream>


void FFT::Expand(std::vector<Complex> & list){
    int size = list.size();
}

std::vector<Complex> FFT::DFT(std::vector<Complex> signal){
    int N = signal.size();
    std::vector<Complex> coef = std::vector<Complex>();
    for(int k = 0 ; k < N ; ++ k){
        Complex X(0.0f);
        for(int n = 0 ; n < N ; ++ n){
            X += signal[n] * Complex::Eulor( -2.0f * PI * k * n / N );
        }
        coef.push_back(X);
    }
    return coef;
}

std::vector<Complex> FFT::IDFT(std::vector<Complex> freq){
    int N = freq.size();
    std::vector<Complex> signal = std::vector<Complex>();
    for(int k = 0 ; k < N ; ++ k){
        Complex X(0.0f);
        for(int n = 0 ; n < N ; ++ n){
            X += freq[n] * Complex::Eulor( 2.0f * PI * k * n / N );
        }
        std::cout << X / N << std::endl;
        signal.push_back(X / N);
    }
    return signal;
}


// recursion
std::vector<Complex> FFT::FT(std::vector<Complex> list){



    return std::vector<Complex>();
};

void process(std::vector<Complex> & signal){
    //取对数
    int size = signal.size();
    std::log2(size);
}