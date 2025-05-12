#pragma once
#include "iostream"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "Projectiles/Bullet.h"

class Player
{
public:
	//Construct & Destruct
	Player(float x = 120.f, float y = 120.f);
	virtual ~Player();

	//Functions
	void Update(const sf::RenderTarget* target);
	void Render(sf::RenderTarget* target);
	void DeleteBullet(int i);

	const bool canAttack();

	const sf::RectangleShape& GetShape() const;
	std::vector<Bullet*>& GetBullets();
	Bullet* GetSetBullet(int i);

	sf::Vector2f GetPostion();
	sf::Vector2f SetPosition(sf::Vector2f pos);
	int GetLives();
	int SetLives(int i);

private:
	//Variables
	sf::RectangleShape shape;

	float MovementSpeed;

	int lives;
	
	//Shooting
	std::vector<Bullet*> Bullets;
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