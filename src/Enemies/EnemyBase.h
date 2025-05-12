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

	const int GetScore() const;
	sf::Sprite* GetSprite();

private:

	//Variables
	float Movespeed;
	sf::Vector2f position;
	int score;

	sf::Sprite* sprite = nullptr;
	sf::Texture texture;

	//Initialization
	void InitVariables(sf::RenderTarget& target, Player player);

};