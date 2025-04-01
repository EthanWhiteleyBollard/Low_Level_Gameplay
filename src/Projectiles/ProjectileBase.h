#pragma once
#include "iostream"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Projectile 
{
public:
	//Variables
	float MoveSpeed = 0.f;
	sf::RectangleShape shape;

	//Functions
	const sf::RectangleShape& GetShape() const { return shape; };
};