#include <iostream>
#include <SFML/Graphics.hpp>
#include "params.h"
#include <cmath>
#include "arm.hpp"
#include "spirograph.hpp"

// Pour calculer la position d'un point sur un cercle à partir de l'angle du rayon, on peut utiliser les relations trigonométriques suivantes :

// x = cx + r * cos(angle)
// y = cy + r * sin(angle)

// où (cx, cy) est le centre du cercle, r est le rayon du cercle,
//et angle est l'angle en radians formé par le rayon et l'horizontale.
//Les coordonnées (x, y) du point sur le cercle sont obtenues en remplaçant les valeurs appropriées dans ces équations.

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Spirograph");

    Spirograph spiro(sf::Vector2f(WIN_WIDTH/2.0f,WIN_HEIGHT/2.0f), 100.0f , 0.5f);
    spiro.add_arm(Arm{200.0f, 0.1f});
    spiro.add_arm(Arm{150.0f, 0.2f});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        spiro.update();
        spiro.draw(window);

        window.display();
    }

    return 0;
}