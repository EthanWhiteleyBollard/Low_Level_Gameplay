#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"

class Bullet 
{
private:
	sf::CircleShape shape;

	sf::Vector2f Direction;
	float movementSpeed;

	void InitVariables();

public:
	Bullet();
	Bullet(float dirX, float dirY, float moveSpeed, sf::Vector2f spawnPos);
	virtual ~Bullet();

	void Update();
	void Render(sf::RenderTarget& target);
};