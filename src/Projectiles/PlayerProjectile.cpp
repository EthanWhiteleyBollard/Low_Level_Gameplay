#include "PlayerProjectile.h"

//--------------------------------------------------------------------------------------------------------------------------
//Construct & Destruct
PlayerProjectile::PlayerProjectile()
{
	shape.setPosition(sf::Vector2f(0,0));
	InitVariables();
}

//--------------------------------------------------------------------------------------------------------------------------

PlayerProjectile::~PlayerProjectile()
{
}

//--------------------------------------------------------------------------------------------------------------------------
//Initialization
void PlayerProjectile::InitVariables()
{
	MoveSpeed = 3.f;

	shape.setFillColor(sf::Color::Blue);
	shape.setSize(sf::Vector2f(10.f, 5.f));

	shape.setPosition(sf::Vector2f(250.f, 250.f));
}

//--------------------------------------------------------------------------------------------------------------------------
//Functions
void PlayerProjectile::UpdateBounds(const sf::RenderTarget* target)
{
	if (shape.getGlobalBounds().position.x + shape.getGlobalBounds().size.x > target->getSize().x || shape.getGlobalBounds().position.x < 0.f) { std::cout << "Destroy Side"; }

	if (shape.getGlobalBounds().position.y < 0.f || shape.getGlobalBounds().position.y + shape.getGlobalBounds().size.y > target->getSize().y) { std::cout << "Destroy Top"; }
}

//--------------------------------------------------------------------------------------------------------------------------

void PlayerProjectile::Update()
{
	shape.move(sf::Vector2f(-MoveSpeed, 0.f));
}

//--------------------------------------------------------------------------------------------------------------------------