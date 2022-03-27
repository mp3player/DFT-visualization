#include"Parser.hpp"


#include<regex>
#include<iostream>

std::vector<sf::Vector2f> Parser::ParserPathFile(std::string path){
    std::ifstream iFile(path.c_str() , std::ios::in);
    if(!iFile.is_open()){
        std::cout << "open {"<< path<< "} failed" << std::endl;
        return std::vector<sf::Vector2f>();
    }
    std::stringstream sstream ;
    sstream << iFile.rdbuf();
    std::string fileData = sstream.str() ;

    std::regex reg ("[-\\d\\.]+");

    std::vector<float> coords = std::vector<float>();
    std::cmatch m;
    while( std::regex_search( fileData.c_str() , m , reg ) ){
        for( std::string s : m ) {
            std::stringstream ss(s);
            float f_val;
            ss >> f_val;
            coords.push_back(f_val);
        }
        fileData = m.suffix().str();
    }
    if(coords.size() % 2 != 0)
        coords.pop_back();


    std::vector<sf::Vector2f> vecs = std::vector<sf::Vector2f>();
    for(int i = 0 ; i < coords.size() ; ++ i){
        float x = coords[i];
        float y = coords[i + 1];
        sf::Vector2f vec(x,y);
        vecs.push_back(vec);
    }


    iFile.close();
    return vecs;
}