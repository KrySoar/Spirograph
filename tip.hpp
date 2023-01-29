#pragma once
#include <SFML/Graphics.hpp>
#include "params.h"
#include "arm.hpp"

class Tip {
    float mRadius;
    sf::CircleShape mPoint;

    public:
    Tip();
    Tip(float radius);

    void attachTo(Arm &lastArm);
    void setPosition(sf::Vector2f);
    void setSize(float tipSize);
    void draw(sf::RenderWindow &) const;
};