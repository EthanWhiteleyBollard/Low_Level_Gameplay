#pragma once
#include "iostream"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SpriteManager.h"
#include "Projectiles/PlayerProjectile.h"

class Player
{
public:
	//Construct & Destruct
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();
	
	//Functions
	void Update(const sf::RenderTarget* target);
	void Render(sf::RenderTarget& target);

	const sf::RectangleShape& GetShape() const;

	sf::Vector2f GetPostion();

	PlayerProjectile GetProjectile() { return projectile; }

private:
	//Variables
	sf::RectangleShape shape;

	float MovementSpeed;
	sf::Image spriteSheet_Characters;

	PlayerProjectile projectile;

	//Initialization
	void initVariables();
	void initShape();

	//Private Functions
	void UpdateMovement();
	void Shooting();
	void UpdateWindowBounds(const sf::RenderTarget* target);
};