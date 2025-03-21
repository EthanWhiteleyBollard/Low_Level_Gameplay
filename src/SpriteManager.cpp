#include "SpriteManager.h"

SpriteManager::SpriteManager()
{
}

SpriteManager::SpriteManager(const sf::Image textureSrc, sf::Vector2i textureLocation, sf::Vector2i textureSize, sf::Vector2f location, sf::Vector2f scale, e_objectOrigin origin)
{
	this->textureSrc = textureSrc;
	this->size = textureSize;
	bool result = texture.loadFromImage(this->textureSrc, false, sf::IntRect({ textureLocation }, { textureSize }));

	sprite = std::make_unique<sf::Sprite>(texture, sf::IntRect({ textureLocation }, { textureSize }));
}

SpriteManager::SpriteManager(SpriteManager&& other) :
	scale(other.scale),
	position(other.position),
	velocity(other.velocity),
	acceleration(other.acceleration),
	originLocation(other.originLocation),
	texture(other.texture),
	sprite(std::move(other.sprite)),
	errorState(other.errorState)
{

}

SpriteManager::~SpriteManager()
{
}

//sf::Vector2f SpriteManager::getScale()
//{
//	return scale;
//}
//
//sf::Vector2f SpriteManager::setScale(int scale)
//{
//	return sf::Vector2f();
//}
//
//sf::Vector2f SpriteManager::setScale(sf::Vector2f scale)
//{
//	return sf::Vector2f();
//}
//
sf::Vector2f SpriteManager::getPosition()
{
	return position;
}

sf::Vector2f SpriteManager::setPosition(sf::Vector2f position)
{
	this->position = position;
	return position;
}

//sf::Vector2f SpriteManager::moveRelative(sf::Vector2f offset)
//{
//	return sf::Vector2f();
//}
//
//sf::Vector2f SpriteManager::moveAbsolute(sf::Vector2f position)
//{
//	return sf::Vector2f();
//}
//
//sf::Vector2f SpriteManager::getVelocity()
//{
//	return velocity;
//}
//
//sf::Vector2f SpriteManager::setVelocity(sf::Vector2f velocity)
//{
//	return sf::Vector2f();
//}
//
//sf::Vector2f SpriteManager::addVelocity(sf::Vector2f velocity)
//{
//	return sf::Vector2f();
//}
//
//sf::Vector2f SpriteManager::getAcceleration()
//{
//	return acceleration;
//}
//
//sf::Vector2f SpriteManager::setAcceleration(sf::Vector2f acceleration)
//{
//	return sf::Vector2f();
//}
//
//sf::Vector2f SpriteManager::addAcceleration(sf::Vector2f acceleration)
//{
//	this->acceleration += acceleration;
//	return this->acceleration;
//}

e_objectError SpriteManager::update()
{
	return errorState;
}

e_objectError SpriteManager::fixedUpdate()
{
	//velocity = velocity + acceleration;

	//position = position + velocity;

	sprite->setPosition(position);

	return errorState;
}

bool SpriteManager::render(sf::RenderTarget& window)
{
	window.draw(*sprite);

	return true;
}
