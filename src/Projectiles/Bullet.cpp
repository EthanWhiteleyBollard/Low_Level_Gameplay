#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(float dirX, float dirY, float moveSpeed, sf::Vector2f spawnPos)
{
	this->Direction.x = dirX;
	this->Direction.y = dirY;
	this->movementSpeed = moveSpeed;
	InitVariables();
	shape.setPosition(spawnPos);
}

void Bullet::InitVariables()
{
	shape.setRadius(10);
	shape.setFillColor(sf::Color::Blue);
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	shape.move(movementSpeed * Direction);
}

void Bullet::Render(sf::RenderTarget& target)
{
	target.draw(shape);
}

const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}
