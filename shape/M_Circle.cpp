#include "M_Circle.hpp"

M_Circle::M_Circle(float radius, std::size_t pointCount) : sf::CircleShape(radius,pointCount){
    offset = sf::Vector2f(radius,radius);
    this->setOrigin(radius,radius);
    this->setPointCount(2 * 3 * radius);
}

void M_Circle::setRadius(float radius){
    sf::CircleShape::setRadius(radius);
    this->setOrigin(radius,radius);
}