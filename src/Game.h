#pragma once

#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Private Functions
	void InitVariables();
	void InitWindow();

public:
	//Constructor & Destructor
	Game();
	virtual ~Game();

	const bool getWindowIsOpen() const;

	//Functions
	void PollEvents();
	void Update();
	void Render();
};