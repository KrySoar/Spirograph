#pragma once
#include <SFML/Graphics.hpp>
#include "params.hpp"

class Arm {
    friend class Tip;

    float mThickness;
    float mLength;
    float mSpeed;

    sf::RectangleShape mLine;

    public:
    Arm();
    Arm(float length, float speed);
    Arm(sf::Vector2f position, float length, float speed);

    void rotate(float angle);
    void attachTo(Arm &);
    void setPosition(sf::Vector2f);
    void draw(sf::RenderWindow &) const;

    float getRotation() const;
    sf::Vector2f getPosition() const;
    float getSpeed() const;
};