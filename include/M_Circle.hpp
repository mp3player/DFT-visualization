#ifndef _M_CIRCLE_H_
#define _M_CIRCLE_H_

#include <SFML/Graphics.hpp>


class M_Circle : public sf::CircleShape {
private:
    sf::Vector2f offset;
public:
    M_Circle(float radius = 0, std::size_t pointCount = 30);
    void setRadius(float radius);
};

#endif