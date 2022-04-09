#ifndef _FT_H_
#define _FT_H_

#include<vector>
#include"Complex.hpp"


#include"_typedef.hpp"


class FT{

public:
    //discrete fourier transform
    static C_List DFT( C_List );
    // invert discrete fourier transform
    static C_List IDFT( C_List );


    //待优化的FFT
    static C_List FT( C_List );
    //待优化的IFFT
    static C_List IFT( C_List );
public:
    //预处理序列，补0操作
    static void Process(C_List &);
    //IFFT
    static C_List P_IFT( C_List );
    //翻转二进制位数
    static int Reverse( int );
public:
    //内容延拓
    static void Extention( C_List & , int );
};

#endif