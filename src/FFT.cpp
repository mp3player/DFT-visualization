#include "../include/FFT.hpp"


#include<cmath>

#include<iostream>


C_List FFT::DFT(C_List signal){
    int N = signal.size();
    C_List coef = C_List();
    for(int k = 0 ; k < N ; ++ k){
        Complex X(0.0f);
        for(int n = 0 ; n < N ; ++ n){
            X += signal[n] * Complex::Eulor( -2.0f * M_PI * k * n / N );
        }
        coef.push_back(X);
    }
    return coef;
}

C_List FFT::IDFT(C_List freq){
    int N = freq.size();
    C_List signal = C_List();
    for(int k = 0 ; k < N ; ++ k){
        Complex X(0.0f);
        for(int n = 0 ; n < N ; ++ n){
            X += freq[n] * Complex::Eulor( 2.0f * M_PI * k * n / N );
        }
        signal.push_back(X / N);
    }
    return signal;
}

// recursion
C_List FFT::FT(C_List list){
    FFT::Process(list);

    int len = list.size();
    if(len == 1)return list;

    C_List even = C_List();
    C_List odd = C_List();

    for(int i = 0 ; i< len ; ++ i){
        if(i % 2 == 0)  even.push_back(list[i]);
        else            odd.push_back(list[i]);
    }
    C_List a0 = FFT::FT(even);
    C_List a1 = FFT::FT(odd);
    C_List l0 = C_List();
    C_List l1 = C_List();

    Complex w0(1.0f);

    Complex wn = Complex::Eulor(-2.0f * M_PI / len);

    for(int k = 0 ; k < len / 2 ; ++ k){
        Complex t = w0 * a1[k];
        Complex c0 = a0[k] + t;
        Complex c1 = a0[k] - t;
        l0.push_back(c0);
        l1.push_back(c1);
        w0 *= wn;
    }
    l0.insert( l0.end() , l1.begin() , l1.end() );

    return l0;
};

C_List FFT::IFT( C_List list ){
    //预处理
    FFT::Process(list);
    //计算ift
    C_List res = FFT::P_IFT(list);
    int size = res.size();
    C_List r_res = C_List();
    for(int i = 0 ; i < size ; ++ i){
        r_res.push_back(res[i] / size);
    }
    return r_res;
}

C_List FFT::P_IFT( C_List list){
    

    int len = list.size();
    if(len == 1)return list;

    C_List even = C_List();
    C_List odd = C_List();

    for(int i = 0 ; i< len ; ++ i){
        if(i % 2 == 0)  even.push_back(list[i]);
        else            odd.push_back(list[i]);
    }
    C_List a0 = FFT::P_IFT(even);
    C_List a1 = FFT::P_IFT(odd);
    C_List l0 = C_List();
    C_List l1 = C_List();

    Complex w0(1.0f);

    Complex wn = Complex::Eulor(2.0f * M_PI / len);

    for(int k = 0 ; k < len / 2 ; ++ k){
        Complex t = w0 * a1[k];
        Complex c0 = a0[k] + t;
        Complex c1 = a0[k] - t;
        l0.push_back(c0);
        l1.push_back(c1);
        w0 *= wn;
    }
    l0.insert( l0.end() , l1.begin() , l1.end() );

    return l0;
}


void FFT::Process(C_List & signal){
    //取对数
    int size = signal.size();
    //上取整
    float base = std::ceil(std::log2(size));
    int add = (int)std::pow(2 , base);
    for(int i = size;i < add;++i){
        signal.push_back(Complex(0,0));
    }
}


void FFT::Extention(C_List & list , int count){
    //延拓list;
    for(int i = 0 ; i < count ; ++ i){
        list.push_back(0);
    }
}