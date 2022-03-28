#ifndef _FFT_H_
#define _FFT_H_

#include<vector>
#include"Complex.hpp"


class FFT{
private :
    static void Expand(std::vector<Complex> & list);

public:
    //discrete fourier transform
    static std::vector<Complex> DFT( std::vector<Complex> );
    // invert discrete fourier transform
    static std::vector<Complex> IDFT( std::vector<Complex> );


    //fast fourier transform by recursion
    static std::vector<Complex> FT( std::vector<Complex> );
private:
    static void process(std::vector<Complex> &);
};

#endif