#include "tip.hpp"
#include <cmath>

int Tip::mCount = 0;

Tip::Tip() : Tip(ARM_WIDTH){
    
}

Tip::Tip(float radius){
    mPoint.setRadius(radius);
    mPoint.setFillColor(sf::Color::Green);
    mPoint.setOrigin(sf::Vector2f(ARM_WIDTH,ARM_WIDTH));

    mCount++;
}


void Tip::attachTo(Arm &lastArm){
    const float radian_angle = (lastArm.getRotation()) * (M_PI/180.0f);

    float posX = lastArm.getPosition().x + lastArm.mLength * std::cos(radian_angle);
    float posY = lastArm.getPosition().y + lastArm.mLength * std::sin(radian_angle);

    mPoint.setPosition(sf::Vector2f(posX, posY));
}

void Tip::setPosition(sf::Vector2f position){
    mPoint.setPosition(position);
}

void Tip::setSize(float tipSize){
    mPoint.setRadius(tipSize);
}

void Tip::draw(sf::RenderWindow &window) const{
    window.draw(mPoint);
}

sf::Vector2f Tip::getPosition() const{
    return mPoint.getPosition();
}

float Tip::getSize() const{
    return mPoint.getRadius();
}

int Tip::getCount() {
    return mCount;
}