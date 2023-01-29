#pragma once
#include <SFML/Graphics.hpp>
#include "params.h"
#include "arm.hpp"

class Tip {
    float mRadius;
    sf::CircleShape mPoint;

    static int mCount;

    public:
    Tip();
    Tip(float radius);

    void attachTo(Arm &lastArm);
    void setPosition(sf::Vector2f);
    void setSize(float tipSize);
    void draw(sf::RenderWindow &) const;
    sf::Vector2f getPosition() const;
    float getSize() const;
    static int getCount();
};