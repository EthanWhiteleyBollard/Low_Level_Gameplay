#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "Character/Player.h"

class EnemyBase
{
public:
	//Construct & Destruct
	EnemyBase(sf::RenderTarget& target, Player player);
	virtual ~EnemyBase();

	//Public Functions
	void Render(sf::RenderTarget& target);
	void Update(Player* player);

	const sf::RectangleShape& GetShape() const;
	const int GetScore() const;

private:

	//Variables
	sf::RectangleShape Shape;
	float Movespeed;
	sf::Vector2f position;
	int score;

	//Initialization
	void InitVariables(sf::RenderTarget& target, Player player);

};