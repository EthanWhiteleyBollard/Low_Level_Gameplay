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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
	{
		shape.move({ MovementSpeed, 0.f });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
	{
		shape.move({ 0.f, -MovementSpeed });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
	{
		shape.move({ 0.f, MovementSpeed });
	}
}

//--------------------------------------------------------------------------------------------------------------------------

void Player::Render(sf::RenderTarget* target)
{
	target->draw(shape);
}

//--------------------------------------------------------------------------------------------------------------------------