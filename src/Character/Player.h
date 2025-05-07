#pragma once
#include "iostream"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SpriteManager.h"
#include "Projectiles/Bullet.h"

class Player
{
public:
	//Construct & Destruct
	Player(float x = 120.f, float y = 120.f);
	virtual ~Player();

	//Functions
	void Update(const sf::RenderTarget* target);
	void Render(sf::RenderTarget& target);

	const bool canAttack();

	const sf::RectangleShape& GetShape() const;

	sf::Vector2f GetPostion();

private:
	//Variables
	sf::RectangleShape shape;

	float MovementSpeed;
	sf::Image spriteSheet_Characters;

	//Shooting
	std::vector<Bullet> Bullets;
	float attackCooldown;
	float attackCooldownMax;

	//Initialization
	void initVariables();
	void initShape();

	//Private Functions
	void UpdateMovement();
	void Shooting();
	void UpdateWindowBounds(const sf::RenderTarget* target);
	void SpawnBullet(sf::Vector2f direction, sf::Vector2f spawnPoint);
};