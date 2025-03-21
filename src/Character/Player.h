#pragma once

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Player
{
public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();
	
	void Update(sf::RenderTarget* target);
	void Render(sf::RenderTarget* target);

private:
	sf::RectangleShape shape;

	float MovementSpeed;

	void initVariables();
	void initShape();
};