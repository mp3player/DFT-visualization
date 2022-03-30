#ifndef _FFT_H_
#define _FFT_H_

#include<vector>
#include"Complex.hpp"


#include"_typedef.hpp"


class FFT{

public:
    //discrete fourier transform
    static C_List DFT( C_List );
    // invert discrete fourier transform
    static C_List IDFT( C_List );


    //fast fourier transform by recursion
    static C_List FT( C_List );
    //fast invert fourier transform by recursion
    static C_List IFT( C_List );
private:
    //预处理序列，补0操作
    static void Process(C_List &);
    //IFFT
    static C_List P_IFT( C_List );
public:
    //内容延拓
    static void Extention( C_List & , int );
};

#endif