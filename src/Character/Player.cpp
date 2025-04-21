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
	////Directional Shooting
	////Up
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)) { std::cout << "Shoot UpRight"; }
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)) { std::cout << "Shoot UpLeft"; }
	////Down
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) { std::cout << "Shoot DownRight"; }
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) { std::cout << "Shoot DownLeft"; }

	//Normal Shooting
	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
	{
		std::cout << "Shoot Up"; 
		SpawnBullet(sf::Vector2f{ 0,-1 });
	}
	//Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) 
	{ 
		std::cout << "Shoot Down"; 
		SpawnBullet(sf::Vector2f{ 0,1 });
	}
	//Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) 
	{
		std::cout << "Shoot Right";
		SpawnBullet(sf::Vector2f{ 1,0 });
	}
	//Left
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) 
	{ 
		std::cout << "Shoot Left";
		SpawnBullet(sf::Vector2f{ -1,0 });
	}
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::SpawnBullet(sf::Vector2f direction)
{
	Bullets.push_back(Bullet(direction.x, direction.y, 10, shape.getPosition()));
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