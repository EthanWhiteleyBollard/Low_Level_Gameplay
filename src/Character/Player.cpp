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
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::initShape()
{
	shape.setFillColor(sf::Color::Red);
	shape.setSize(sf::Vector2f(35.f, 35.f));
	shape.setOrigin({shape.getLocalBounds().size.x / 2.0f, shape.getLocalBounds().size.y / 2.0f});
}


//--------------------------------------------------------------------------------------------------------------------------
//Functions
void Player::Update(const sf::RenderTarget* target)
{
	UpdateMovement();
	Shooting();
	UpdateWindowBounds(target);

	for (Bullet& bullet : Bullets) 
	{
		bullet.Update();
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
	sf::Vector2f movementVector = { 0,0 };
	sf::Vector2f spawnPoint = { 0,0 };

	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
	{
		movementVector += { 0.f, -1 };
		spawnPoint += { 0, -shape.getGlobalBounds().position.y };
	}
	//Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) 
	{ 
		movementVector += { 0.f, 1 };
		spawnPoint += { 0, shape.getLocalBounds().position.y };
	}
	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) 
	{
		movementVector += { 1, 0 };
		spawnPoint += { shape.getGlobalBounds().position.x, 0 };
	}
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) 
	{ 
		movementVector += { -1, 0 };
		spawnPoint += { -shape.getGlobalBounds().position.x, 0 };
	}

	if (movementVector.x != 0.0f || movementVector.y != 0.0f)
		SpawnBullet(movementVector.normalized(), spawnPoint);
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::SpawnBullet(sf::Vector2f direction, sf::Vector2f spawnPoint)
{
	Bullets.push_back(Bullet(direction.x, direction.y, 10, spawnPoint));
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::UpdateWindowBounds(const sf::RenderTarget* target)
{
	//Left Check
	if (shape.getGlobalBounds().position.x < 0.f)
		shape.setPosition({ 0.f, shape.getGlobalBounds().position.y });
	//Right Check
	if (shape.getGlobalBounds().position.x + shape.getGlobalBounds().size.x > target->getSize().x)
		shape.setPosition({ target->getSize().x - shape.getGlobalBounds().size.x, shape.getGlobalBounds().position.y });
	//Top Check
	if (shape.getGlobalBounds().position.y < 0.f)
		shape.setPosition({ shape.getGlobalBounds().position.x, 0.f });
	//Bottom Check
	if (shape.getGlobalBounds().position.y + shape.getGlobalBounds().size.y > target->getSize().y)
		shape.setPosition({ shape.getGlobalBounds().position.x, target->getSize().y - shape.getGlobalBounds().size.y });
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
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::Render(sf::RenderTarget& target)
{
	SpriteManager sprite = SpriteManager::SpriteManager(spriteSheet_Characters, sf::Vector2i{ 0,0 }, sf::Vector2i{ 24, 24 });
	target.draw(shape);
	//sprite.render(target);
	for (auto i : Bullets) {
		i.Render(target);
	}
}

//--------------------------------------------------------------------------------------------------------------------------

const sf::RectangleShape& Player::GetShape() const
{
	return shape;
}

//--------------------------------------------------------------------------------------------------------------------------

sf::Vector2f Player::GetPostion()
{
	return shape.getPosition();
}

//--------------------------------------------------------------------------------------------------------------------------