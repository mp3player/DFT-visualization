cmake_minimum_required(VERSION 3.10)

project(fft)

set(CMAKE_CXX_STANDARD 14)

link_directories(/home/coder/lib/SFML-2.5.1/lib)

include_directories(/home/coder/lib/SFML-2.5.1/include/)


add_executable(fft main.cc 
    ./shape/M_Circle.cpp 
    ./util/Complex.cpp 
    ./util/FFT.cpp 
    ./util/Parser.cpp 
    ./util/_typedef.hpp


    path.h
    ./test/draw.cpp 
    ./test/poly.cpp
)

target_link_libraries(fft sfml-graphics sfml-window sfml-system sfml-network sfml-audio)