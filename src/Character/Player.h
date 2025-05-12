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
	void Render(sf::RenderWindow& target);
	void DeleteBullet(int i);

	const bool canAttack();

	std::vector<Bullet*>& GetBullets();
	Bullet* GetSetBullet(int i);

	sf::Sprite* GetSprite();
	sf::Vector2f GetPostion();
	sf::Vector2f SetPosition(sf::Vector2f pos);
	int GetLives();
	int SetLives(int i);

private:
	//Variables
	float MovementSpeed;

	int lives;

	sf::Vector2f playerPos;
	sf::Sprite* sprite = nullptr;
	sf::Texture texture;
	
	//Shooting
	std::vector<Bullet*> Bullets;
	float attackCooldown;
	float attackCooldownMax;

	//Initialization
	void initVariables();

	//Private Functions
	void UpdateMovement();
	void Shooting();
	void UpdateWindowBounds(const sf::RenderTarget* target);
	void SpawnBullet(sf::Vector2f direction, sf::Vector2f spawnPoint);
};