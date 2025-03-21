#pragma once

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SpriteManager.h"

class Player
{
public:
	//Construct & Destruct
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();
	
	//Functions
	void Update(sf::RenderTarget* target);
	void Render(sf::RenderTarget& target);

private:
	//Variables
	sf::RectangleShape shape;

	float MovementSpeed;
	sf::Image spriteSheet_Characters;

	//Initialization
	void initVariables();
	void initShape();

};