
#include "../include/util.hpp"
#include<ctime>

C_List util::randComplexVector(int len){
    static int i = 0;
    i += 1;
    srand(time(NULL) + i);
    C_List list = C_List();
    for(int i = 0 ; i < len ; ++ i){
        int r = rand() % 10;
        list.push_back(Complex(r));

    }
    return list;
}
