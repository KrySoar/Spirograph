#include <iostream>
#include <SFML/Graphics.hpp>
#include "params.h"
#include <cmath>
#include "arm.hpp"
#include "spirograph.hpp"
#include <vector>
#include <tuple>

// Pour calculer la position d'un point sur un cercle à partir de l'angle du rayon, on peut utiliser les relations trigonométriques suivantes :

// x = cx + r * cos(angle)
// y = cy + r * sin(angle)

// où (cx, cy) est le centre du cercle, r est le rayon du cercle,
//et angle est l'angle en radians formé par le rayon et l'horizontale.
//Les coordonnées (x, y) du point sur le cercle sont obtenues en remplaçant les valeurs appropriées dans ces équations.

void run(std::vector<std::tuple<float,float>> arms);
std::vector<std::tuple<float,float>> user_input();

int main()
{
    auto arms = user_input();    
    run(arms);

    return 0;
}

void run(std::vector<std::tuple<float,float>> arms)
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Spirograph");
    Spirograph spiro;

    for(std::tuple<float,float> arm : arms)
    {
        auto [ length, speed] = arm;
        spiro.add_arm(Arm{length, speed});
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //window.clear();
        spiro.update();
        spiro.draw(window);

        window.display();
    }
}

std::vector<std::tuple<float,float>> user_input()
{
    std::vector<std::tuple<float,float>> arms;
    int nbArms;
    float length;
    float speed;

    std::cout << "How many arms do you want ?" << std::endl;
    std::cin >> nbArms;

    for(int i = 0; i < nbArms; i++)
    {
        std::cout << "Length of arm " << i+1 << " : ";
        std::cin >> length;

        std::cout << "Speed of arm " << i+1 << " : ";
        std::cin >> speed;

        std::cout << std::endl;

        arms.push_back(std::tuple{length,speed});
    }

    return arms;
}