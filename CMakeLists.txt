cmake_minimum_required(VERSION 3.10)

project(fft)

set(CMAKE_CXX_STANDARD 14)

link_directories(/home/coder/lib/SFML-2.5.1/lib)

include_directories(/home/coder/lib/SFML-2.5.1/include/)


add_executable(
    fft main.cc 
    ./src/M_Circle.cpp 
    ./src/Complex.cpp 
    ./src/FFT.cpp 
    ./src/Parser.cpp 
    ./src/AnimateIDFT.cpp
    
    ./src/Scalar.cpp

    ./src/poly.cpp
    ./src/util.cpp

    ./include/_typedef.hpp
    ./include/_fft.hpp
    ./include/bit_map_65536.hpp
    

)

target_link_libraries(fft sfml-graphics sfml-window sfml-system sfml-network sfml-audio)