#include "Player.h"
#pragma once

//--------------------------------------------------------------------------------------------------------------------------
//Construct & Destruct
Player::Player(float x, float y)
{
	shape.setPosition({x,y});

	initVariables();
	initShape();
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
	spriteSheet_Characters = sf::Image("Assets/tilemap-characters_packed.png");
	attackCooldownMax = 8.f;
	attackCooldown = attackCooldownMax;
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::initShape()
{
	shape.setFillColor(sf::Color::Red);
	shape.setSize(sf::Vector2f(35.f, 35.f));
	//shape.setOrigin({shape.getLocalBounds().size.x / 2.0f, shape.getLocalBounds().size.y / 2.0f});
}


//--------------------------------------------------------------------------------------------------------------------------
//Functions
void Player::Update(const sf::RenderTarget* target)
{
	UpdateMovement();

	if (attackCooldown < attackCooldownMax) { attackCooldown += .4f; }

	Shooting();

	UpdateWindowBounds(target);

	//std::cout << std::boolalpha << clock.isRunning() << std::endl;

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

	if(movementVector.x != 0.0f || movementVector.y != 0.0f)
		shape.move(movementVector.normalized() * MovementSpeed);
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
		SpawnBullet(movementVector.normalized(), shape.getPosition());

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
	if (shape.getGlobalBounds().position.x < 0.f)
		this->shape.setPosition({ 0, shape.getGlobalBounds().position.y});
	//Right Check
	if (shape.getGlobalBounds().position.x + shape.getGlobalBounds().size.x > target->getSize().x)
		this->shape.setPosition({ target->getSize().x - shape.getGlobalBounds().size.x, shape.getGlobalBounds().position.y });
	//Top Check
	if (shape.getGlobalBounds().position.y < 0.f)
		this->shape.setPosition({ shape.getGlobalBounds().position.x, 0.f });
	//Bottom Check
	if (shape.getGlobalBounds().position.y + shape.getGlobalBounds().size.y > target->getSize().y)
		this->shape.setPosition({ shape.getGlobalBounds().position.x, target->getSize().y - shape.getGlobalBounds().size.y });
	//Left Top Check
	if (shape.getGlobalBounds().position.x < 0.f && shape.getGlobalBounds().position.y < 0.f)
		this->shape.setPosition({ 0.f, 0.f });
	//Left Down Check
	if (shape.getGlobalBounds().position.x < 0.f && shape.getGlobalBounds().position.y + shape.getGlobalBounds().size.y > target->getSize().y)
		this->shape.setPosition({ 0.f, target->getSize().y - shape.getGlobalBounds().size.y });
	//Right Top Check
	if (shape.getGlobalBounds().position.x + shape.getGlobalBounds().size.x > target->getSize().x && shape.getGlobalBounds().position.y < 0.f)
		this->shape.setPosition({ target->getSize().x - shape.getGlobalBounds().size.x, 0.f });
	//Right Down Check
	if (shape.getGlobalBounds().position.x + shape.getGlobalBounds().size.x > target->getSize().x && shape.getGlobalBounds().position.y + shape.getGlobalBounds().size.y > target->getSize().y)
		this->shape.setPosition({ target->getSize().x - shape.getGlobalBounds().size.x, target->getSize().y - shape.getGlobalBounds().size.y });

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

void Player::Render(sf::RenderTarget& target)
{
	SpriteManager sprite = SpriteManager::SpriteManager(spriteSheet_Characters, sf::Vector2i{ 0,0 }, sf::Vector2i{ 24, 24 });
	target.draw(shape);
	//sprite.render(target);
	for (auto *i : Bullets) {
		i->Render(target);
	}
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::DeleteBullet(int i)
{
	Bullets.erase(Bullets.begin() + i);
	std::cout << "Delete Bullet" << std::endl;
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

const sf::RectangleShape& Player::GetShape() const
{
	return shape;
}

//--------------------------------------------------------------------------------------------------------------------------

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

sf::Vector2f Player::GetPostion()
{
	return shape.getPosition();
}

//--------------------------------------------------------------------------------------------------------------------------