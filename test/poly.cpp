#include<ctime>
#include<cmath>
#include<iostream>
#include<vector>
#include<fstream>
#include"poly.hpp"
#include "../include/FFT.hpp"

#define USE_FLOAT


C_List randComplexVector(int len){
    static int i = 0;
    i += 1;
    srand(time(NULL) + i);
    C_List list = C_List();
    for(int i = 0 ; i < len ; ++ i){
        //整数
#ifdef USE_FLOAT
        int r = rand() % 10;
        list.push_back(Complex(r));
#else
    float r = ((float)(rand() % 10)) / 1.1f;
    list.push_back(Complex(r));
#endif
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
//dft方式计算的多项式系数是有误差的，而且当量特别大的时候，误差也会特别大，初步判断是三角函数的计算误差
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


//比较两个复数序列的每一项的误差
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


void compareTime(int a_count , int b_count)
{   
    float coef_time = 0;
    float value_time = 0;

    C_List v1 = randComplexVector(a_count);
    C_List v2 = randComplexVector(b_count);


    float t1 = testTime(coefProduct , v1 , v2);
    float t2 = testTime(valueProduct , v1 , v2);

    coef_time += t1;
    value_time += t2;

    std::cout << "coef product : " << t1 << " s" << std::endl;
    std::cout << "value product : " << t2 << " s" << std::endl;
    

}

void writeFile(C_List list , std::string fileName){
    std::fstream outFile(fileName , std::ios::app);

    if(!outFile.is_open()){
        std::cout << "create file failed" << std::endl;
        outFile.close();
        return ;
    }


    for (Complex c : list){
        std::string chr = std::to_string(c.r) + "\n";
        outFile.write(chr.c_str() , chr.size());
    }

    outFile.close();
}

void compareError(int count ){
    C_List A = randComplexVector(count);
    C_List B = randComplexVector(count);
    
    C_List C1 = coefProduct(A,B);
    C_List C2 = valueProduct(A,B);

    float error = testRes(C1,C2);
    
    std::cout << "total error : { " << error << " } avg error : { " << (error / C1.size()) << " }" << std::endl;

    // writeFile(C1,"a.txt");
    // writeFile(C2,"b.txt");
}






