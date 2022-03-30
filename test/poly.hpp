#ifndef _TEST_H_
#define _TEST_H_

#include<ctime>
#include"../util/Complex.hpp"
#include "../util/_typedef.hpp"

//生成随机多项式系数
C_List randComplexVector(int len = 256);

//系数表达的多项式乘法，卷积计算
C_List coefProduct( C_List , C_List );

//点值表达的多项式乘法，FFT方法
C_List valueProduct( C_List , C_List );

//比较序列的实部绝对差
float testRes(C_List , C_List );

//查看计算时间
float testTime(C_List (*)(C_List , C_List) , C_List , C_List);

void printCList(C_List list);


#endif