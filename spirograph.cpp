
#include "spirograph.hpp"

Spirograph::Spirograph() {

}

Spirograph::Spirograph(sf::Vector2f position, float length, float speed) {
    add_arm(Arm{position, length, speed});
}


void Spirograph::add_arm(Arm arm) {
    mArms.push_back(arm);

    if(mArms.size() > 1)
    {
        mArms.back().attachTo(mArms.at(mArms.size() - 2));
    } else {
        //Center the first arm
        mArms.front().setPosition(sf::Vector2f(WIN_WIDTH/2.0f,WIN_HEIGHT/2.0f));
    }

    mTip.attachTo(mArms.back());
}

void Spirograph::update() {
    int i = 0;
    for(Arm &arm : mArms) {
        arm.rotate(arm.getSpeed());
        if(i > 0) {
            arm.attachTo(mArms.at(i-1));
        }

        i++;
    }
    
    mTip.attachTo(mArms.back());
}

void Spirograph::draw(sf::RenderWindow &window) {

    for(Arm &arm : mArms) {
        //arm.draw(window);
    }
    mTip.draw(window);
}

