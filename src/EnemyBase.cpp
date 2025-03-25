#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
	Shape.setPosition({ 50.f,50.f });

	InitVariables();
}

EnemyBase::~EnemyBase()
{
}


void EnemyBase::InitVariables()
{
	Shape.setFillColor(sf::Color::Yellow);
	Shape.setSize(sf::Vector2f(45.f, 45.f));

	Movespeed = 2.f;
}

void EnemyBase::Update(Player player)
{
	sf::Vector2f Direction = player.GetPostion() - Shape.getPosition();
	Shape.move(Movespeed * Direction.normalized());

}

void EnemyBase::Render(sf::RenderTarget* target)
{
	target->draw(Shape);
}