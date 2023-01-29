#include "arm.hpp"
#include <cmath>

Arm::Arm() : Arm(sf::Vector2f(0.0f,0.0f),100.0f , 0.2f) {

}

Arm::Arm(float length, float speed) : Arm(sf::Vector2f(0.0f,0.0f),length , speed) {

}

Arm::Arm(sf::Vector2f position, float length, float speed) {
    mThickness = ARM_WIDTH;
    mLength = length;
    mSpeed = speed;

    mLine.setSize(sf::Vector2f(length,mThickness));
    mLine.setOrigin(0,mThickness/2);
    mLine.setPosition(position);
    mLine.setFillColor(sf::Color::White);

}

void Arm::rotate(float angle) {
    mLine.rotate(angle);
}

void Arm::attachTo(Arm &lastArm){
    const float radian_angle = (lastArm.getRotation()) * (M_PI/180.0f);

    float posX = lastArm.getPosition().x + lastArm.mLength *  std::cos(radian_angle);
    float posY = lastArm.getPosition().y + lastArm.mLength *  std::sin(radian_angle);

    mLine.setPosition(sf::Vector2f(posX, posY));
}

void Arm::setPosition(sf::Vector2f position) {
    mLine.setPosition(position);
}

void Arm::draw(sf::RenderWindow &window) const{
    window.draw(mLine);
}

float Arm::getRotation() const{
    return mLine.getRotation();
}

sf::Vector2f Arm::getPosition() const{
    return mLine.getPosition();
}

float Arm::getSpeed() const{
    return mSpeed;
}