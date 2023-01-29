#include <vector>
#include "arm.hpp"
#include "tip.hpp"

class Spirograph {
    std::vector<Arm> mArms;
    Tip mTip;

public:
    Spirograph();
    Spirograph(sf::Vector2f position, float length, float speed);

    void add_arm(Arm);
    void update();
    void draw(sf::RenderWindow &);
};