#include<ctime>
#include<cmath>
#include<iostream>
#include<vector>
#include"poly.hpp"
#include "../util/FFT.hpp"


C_List randComplexVector(int len){
    srand(time(NULL));
    C_List list = C_List();
    for(int i = 0 ; i < len ; ++ i){
        int r = rand() % 10;
        list.push_back(Complex(r));
    }
    return list;
}

//系数表达的多项式乘法，卷积计算
C_List coefProduct( C_List c1 , C_List c2 ){
   
    int m = c1.size();
    int n = c2.size();

    //计算结果的最高次项为 m + n

    C_List res = C_List(m + n);

    //计算每一项，并将结果加入到相应的系数中
    for(int i = 0 ; i < m ; ++ i){
        for(int j = 0 ; j < n ; ++j){
            res[i + j] += c1[i] * c2[j];
        }
    }

    return res;
}


//点值表达的多项式乘法，FFT方法
C_List valueProduct( C_List c1 , C_List c2 ){
    //延拓c1与c2到与结果相等的长度
    int m = c1.size();
    int n = c2.size();

    FFT::Extention(c1,n);
    FFT::Extention(c2,m);
    
    //计算c1与c2的点值表达形式
    C_List freq1 = FFT::FT(c1);
    C_List freq2 = FFT::FT(c2);

    //计算点值相乘
    C_List res = C_List();
    int size = m + n;
    for(int i = 0 ; i < size ; ++ i){
        Complex c = freq1[i] * freq2[i];
        res.push_back(c);
    }

    //将点值转换为系数
    C_List coef = FFT::IFT(res);

    return coef;
}


//比较两个复数序列的每一项是否对应相等
float testRes(C_List cl1 , C_List cl2){
    float error = 0;
    int size = cl1.size();
    for(int i = 0 ; i< size - 1 ; ++ i){
        float r1 = cl1[i].r;
        float r2 = cl2[i].r;
        error += std::abs(r1 - r2);
    }
    return error;
}

//查看计算时间
float testTime(C_List (*fn)(C_List , C_List) , C_List a, C_List b){
    std::clock_t startTime = clock();

    fn(a,b);

    std::clock_t endTime = clock();

    return ((float)(endTime - startTime)) / CLOCKS_PER_SEC;
}

void printCList(C_List list){
    for(Complex c : list){
        std::cout << c << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}