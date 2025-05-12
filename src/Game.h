#pragma once

#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "Character/Player.h"
#include "Enemies/EnemyBase.h"
#include "iostream"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	bool endGame;

	Player* player;

	std::vector<EnemyBase*> enemies;
	int maxEnemies;

	//Image variables
	sf::Image spriteSheet_Tilemap;
	sf::Image spriteSheet_Backgrounds;

	bool PlayerDead;
	int currentScore;
	int livesScore;
	sf::Text* scoreText;

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
	void UpdateCollisions();

	void SpawnEnemies();
};