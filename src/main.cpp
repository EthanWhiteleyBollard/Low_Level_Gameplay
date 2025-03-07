#pragma once

#include "SFML/Graphics.hpp"
#include "main.h"

int main() 
{
    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "SFML works!", sf::Style::Close);
    sf::RectangleShape player({100.f, 100.f});
    player.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        // Event polling section of code - this must be done in the thread which created the window
        // we will talk about threading later, but essentially this must be done here
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) 
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }

        window.clear();
        window.draw(player);
        window.display();
    }
	return 0;
}