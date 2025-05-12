#include "Player.h"
#pragma once

//--------------------------------------------------------------------------------------------------------------------------
//Construct & Destruct
Player::Player(float x, float y)
{
	playerPos = { x,y };

	initVariables();

	sf::Image image("Assets/Character.png");

	bool result = texture.loadFromImage(image, true, sf::IntRect({ 0,0 }, { 40, 49 }));

	if (result) {
		sprite = new sf::Sprite(texture);
	}
}

//--------------------------------------------------------------------------------------------------------------------------

Player::~Player()
{
}

//--------------------------------------------------------------------------------------------------------------------------
//Initialization
void Player::initVariables()
{
	MovementSpeed = 6.f;
	attackCooldownMax = 8.f;
	attackCooldown = attackCooldownMax;
	lives = 2;
}

//--------------------------------------------------------------------------------------------------------------------------
//Functions
void Player::Update(const sf::RenderTarget* target)
{
	UpdateMovement();


	if (attackCooldown < attackCooldownMax) { attackCooldown += .4f; }
	Shooting();

	UpdateWindowBounds(target);

	for (auto *bullet : Bullets) 
	{
		bullet->Update();
	}

}

//--------------------------------------------------------------------------------------------------------------------------

void Player::UpdateMovement()
{
	sf::Vector2f movementVector = { 0,0 };

	//Left Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
	{
		movementVector += { -MovementSpeed, 0.f };
	}

	//Right Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
	{
		movementVector += { MovementSpeed, 0.f};
	}

	//Up Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
	{
		movementVector += { 0.f, -MovementSpeed };
	}

	//Down Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
	{
		movementVector += { 0.f, MovementSpeed };
	}

	if (movementVector.x != 0.0f || movementVector.y != 0.0f) 
	{
		playerPos += movementVector;
	}
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::Shooting()
{	
	if (!canAttack()) { return; }

	sf::Vector2f movementVector = { 0,0 };

	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
	{
		movementVector += { 0.f, -1 };
	}
	//Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) 
	{ 
		movementVector += { 0.f, 1 };
	}
	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) 
	{
		movementVector += { 1, 0 };
	}
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) 
	{ 
		movementVector += { -1, 0 };
	}

	if (movementVector.x != 0.0f || movementVector.y != 0.0f)
	{
		SpawnBullet(movementVector.normalized(), playerPos);
	}

}

//--------------------------------------------------------------------------------------------------------------------------

void Player::SpawnBullet(sf::Vector2f direction, sf::Vector2f spawnPoint)
{
	Bullets.push_back(new Bullet(direction.x, direction.y, 10, spawnPoint));
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::UpdateWindowBounds(const sf::RenderTarget* target)
{
	//Left Check
	if (playerPos.x < 0.f)
		playerPos = { 0, playerPos.y};
	//Right Check
	if (playerPos.x + sprite->getGlobalBounds().size.x > target->getSize().x)
		playerPos = { target->getSize().x - sprite->getGlobalBounds().size.x, playerPos.y};
	//Top Check
	if (playerPos.y < 0.f)
		playerPos = { playerPos.x, 0.f };
	//Bottom Check
	if (playerPos.y + sprite->getGlobalBounds().size.y > target->getSize().y)
		playerPos = { playerPos.x , target->getSize().y - sprite->getGlobalBounds().size.y };

	//Bullets
	unsigned counter = 0;
	for (auto *bullet : Bullets)
	{
		if (bullet->getBounds().position.y + bullet->getBounds().size.y < 0.f || bullet->getBounds().position.y + bullet->getBounds().size.y > target->getSize().y || bullet->getBounds().position.x + bullet->getBounds().size.x > target->getSize().x || bullet->getBounds().position.x < 0.f) 
		{
			delete bullet;
			DeleteBullet(counter);
			--counter;
		}

		++counter;
	}
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::Render(sf::RenderWindow& target)
{
	sprite->setPosition(playerPos);
	target.draw(*sprite);
	for (auto* i : Bullets) 
	{
		i->Render(target);
	}
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::DeleteBullet(int i)
{
	Bullets.erase(Bullets.begin() + i);
}

//--------------------------------------------------------------------------------------------------------------------------

const bool Player::canAttack()
{
	if (attackCooldown >= attackCooldownMax) 
	{
		attackCooldown = 0.f;
		return true; 
	}
	return false;
}

//--------------------------------------------------------------------------------------------------------------------------
//Getter Functions

std::vector<Bullet*>& Player::GetBullets()
{
	return Bullets;
}

//--------------------------------------------------------------------------------------------------------------------------

Bullet* Player::GetSetBullet(int i)
{
	return Bullets[i];
}

//--------------------------------------------------------------------------------------------------------------------------

sf::Sprite* Player::GetSprite()
{
	return sprite;
}

sf::Vector2f Player::GetPostion()
{
	return playerPos;
}

//--------------------------------------------------------------------------------------------------------------------------

sf::Vector2f Player::SetPosition(sf::Vector2f pos)
{
	playerPos = pos;
	return playerPos;
}

//--------------------------------------------------------------------------------------------------------------------------

int Player::GetLives()
{
	return lives;
}

//--------------------------------------------------------------------------------------------------------------------------

int Player::SetLives(int i)
{
	lives = i;
	return lives;
}

//--------------------------------------------------------------------------------------------------------------------------