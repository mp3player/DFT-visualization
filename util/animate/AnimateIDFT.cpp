#include"AnimateIDFT.hpp"
#include<cmath>
#include<iostream>
#include "../fft/FFT.hpp"


AnimateIDFT::AnimateIDFT(C_List signal , Complex offset , float scale){
    this->init(signal,offset,scale);
}

AnimateIDFT::AnimateIDFT(V_list points , Complex offset , float scale){

    C_List signal = C_List();
    for(sf::Vector2f vec : points)
        signal.push_back(Complex(vec));

    this->init(signal,offset,scale);
}

AnimateIDFT::~AnimateIDFT(){
    // release the memery
    for(M_Circle * circle : this->circles){
        delete circle;
    }
}

void AnimateIDFT::init( C_List signal, Complex offset , float scale ){
    signal = this->setup(signal,offset,scale);
    // DFT
    this->freq = FFT::DFT(signal);
    // reset k and N
    k = 0; 
    N = this->freq.size();
    // generate circles;

    this->circles = Cir_list();

    for(int i = 0 ; i < freq.size() ; ++ i){
        M_Circle * circle = new M_Circle(10);
        circle->setOutlineThickness(1.f);
        circle->setOutlineColor(sf::Color(255,255,255,100));
        circle->setFillColor(sf::Color(1,0,0,0));
        this->circles.push_back(circle);
    }
    axes = Vex_list(N);
}

C_List AnimateIDFT::setup( C_List signal , Complex offset , float scale ){
    C_List transformSignal = C_List();
    for(Complex c : signal){
        c = (c + offset) * scale;
        transformSignal.push_back(c);
    }
    return transformSignal;
}

void AnimateIDFT::draw(sf::RenderWindow * window , sf::Transform transform){
    for(M_Circle * circle : this->circles)
        window->draw( *circle , transform );
    window->draw( &(this->axes[0]) , this->axes.size() , sf::LinesStrip , transform );
    window->draw( &(this->outline[0]) , this->outline.size() , sf::LinesStrip , transform );    
}

void AnimateIDFT::next(){

    // axis.clear();
    Complex X(0.0f);
    for(int i = 0 ; i < N ; ++ i){
        
        Complex c = this->freq[i] * Complex::Eulor( 2.0f * M_PI * k * i / N );

        Complex next = X + c;

        this->axes[i] = ((next / N).toVector());

        M_Circle * circle = circles[i];
        circle->setPosition( ( X / N ).toVector() );

        circle->setRadius( ( c / N ).length() );
        
        X = next;
    }
    if(this->outline.size() < N)
        this->outline.push_back(
            sf::Vertex( (X / N).toVector() )
        );

    k = (k + 1) % N;




    this->k = (this->k + 1 ) % N ;
}

void AnimateIDFT::run(sf::RenderWindow * window, sf::Transform transform){
    this->draw(window,transform);
    this->next();
}