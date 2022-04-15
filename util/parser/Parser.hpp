#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <vector>

class Parser{
public:
    static std::vector<sf::Vector2f> ParserPathFile(std::string);
};

#endif