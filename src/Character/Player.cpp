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
	MovementSpeed = 10.f;
	spriteSheet_Characters = sf::Image("Assets/tilemap-characters_packed.png");
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::initShape()
{
	shape.setFillColor(sf::Color::Red);
	shape.setSize(sf::Vector2f(100.f, 100.f));
}


//--------------------------------------------------------------------------------------------------------------------------
//Functions

void Player::Update(const sf::RenderTarget* target)
{
	UpdateInputs();
	UpdateWindowBounds(target);
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::UpdateInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
	{
		shape.move({ -MovementSpeed, 0.f });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
	{
		shape.move({ MovementSpeed, 0.f });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
	{
		shape.move({ 0.f, -MovementSpeed });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
	{
		shape.move({ 0.f, MovementSpeed });
	}
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
}

//--------------------------------------------------------------------------------------------------------------------------