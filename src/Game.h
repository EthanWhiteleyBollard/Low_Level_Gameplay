#pragma once

#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "SpriteManager.h"
#include "Character/Player.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	bool endGame;

	Player player;

	//Image variables
	sf::Image spriteSheet_Tilemap;
	sf::Image spriteSheet_Backgrounds;
	sf::Image spriteSheet_Characters;
	sf::Texture texture_MainCharacter;
	sf::Sprite* sprite_MainCharacter;

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