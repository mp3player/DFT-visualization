#ifndef _TEST_H_
#define _TEST_H_

#include<ctime>
#include "Complex.hpp"
#include "_typedef.hpp"

namespace poly{

//系数表达的多项式乘法，卷积计算
C_List coefProduct( C_List , C_List );

//点值表达的多项式乘法，FFT方法
C_List valueProduct( C_List , C_List );

//比较序列的实部绝对差
float testRes(C_List , C_List );

//查看计算时间
float recordTime(C_List (*)(C_List , C_List) , C_List , C_List);

//测试多项式计算
void compareTime(int , int );


}

#endif