#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "Character/Player.h"

class EnemyBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();
	void Render(sf::RenderTarget* target);
	void Update(Player player);

	
protected:

private:
	sf::RectangleShape Shape;
	float Movespeed;

	void InitVariables();

};