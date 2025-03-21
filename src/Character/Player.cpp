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
void Player::Update(sf::RenderTarget* target)
{
	//Window Bounds


	//Keyboard Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
	{ 
		shape.move({-MovementSpeed, 0.f });
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

void Player::Render(sf::RenderTarget& target)
{
	SpriteManager sprite = SpriteManager::SpriteManager(spriteSheet_Characters, sf::Vector2i{ 0,0 }, sf::Vector2i{ 24, 24 });
	target.draw(shape);
	sprite.render(target);
}

//--------------------------------------------------------------------------------------------------------------------------