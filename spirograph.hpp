#pragma once

#include <vector>
#include <deque>
#include "arm.hpp"
#include "tip.hpp"

class Spirograph {
    std::vector<Arm> mArms;
    
    Tip mTip;
    std::deque<Tip> mDrawing;

public:
    Spirograph();
    Spirograph(sf::Vector2f position, float length, float speed);

    void add_arm(Arm);
    void update();
    void draw(sf::RenderWindow &);
    void write();
};
