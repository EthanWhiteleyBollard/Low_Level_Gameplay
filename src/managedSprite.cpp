#include "managedSprite.h"

// default constructor
LLGP::managedSprite::managedSprite() {}

// standard constructor taking a texture with defaults for position, scale, and origin
LLGP::managedSprite::managedSprite(sf::Image textureSrc, sf::Vector2i textureLocation, sf::Vector2i textureSize, sf::Vector2f location , sf::Vector2f scale, LLGP::e_objectOrigin origin) : texture(texture), position(location), scale(scale)
{
	this->textureSrc = textureSrc;
	this->size = textureSize;
	bool result = texture.loadFromImage(this->textureSrc, false, sf::IntRect(textureLocation, textureSize));

	sprite = std::make_unique<sf::Sprite>(texture, sf::IntRect({ 0,0 }, { textureSize }));
}

// move constructor
LLGP::managedSprite::managedSprite(managedSprite&& other) :
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

// destructor - should be virtual if we are utilising inheritance to allow for proper destruction process.
LLGP::managedSprite::~managedSprite()
{

}


sf::Vector2f LLGP::managedSprite::getScale() 
{
	return scale;
}
sf::Vector2f LLGP::managedSprite::setScale(int scale) 
{
	this->scale = sf::Vector2f{ this->scale.x * scale, this->scale.y * scale };
	sprite->setScale(this->scale);

	return this->scale;
}
sf::Vector2f LLGP::managedSprite::setScale(sf::Vector2f scale) 
{
	this->scale = scale;
	sprite->setScale(this->scale);

	return this->scale;
}

sf::Vector2f LLGP::managedSprite::getPosition() 
{
	return position;
}

sf::Vector2f LLGP::managedSprite::setPosition(sf::Vector2f position) 
{
	this->position = position;
	sprite->setPosition(this->position);

	return this->position;
}

sf::Vector2f LLGP::managedSprite::moveRelative(sf::Vector2f offset) 
{
	position = position + offset;
	sprite->setPosition(position);

	return this->position;
}

sf::Vector2f LLGP::managedSprite::moveAbsolute(sf::Vector2f position) 
{
	this->position = position;
	sprite->setPosition(this->position);

	return this->position;
}

sf::Vector2f LLGP::managedSprite::getVelocity() 
{
	return velocity;
}

sf::Vector2f LLGP::managedSprite::setVelocity(sf::Vector2f velocity) 
{
	this->velocity = velocity;

	return this->velocity;
}

sf::Vector2f LLGP::managedSprite::addVelocity(sf::Vector2f velocity)
{
	this->velocity += velocity;

	return this->velocity;
}

sf::Vector2f LLGP::managedSprite::getAcceleration() 
{
	return acceleration;
}

sf::Vector2f LLGP::managedSprite::setAcceleration(sf::Vector2f acceleration) 
{
	this->acceleration = acceleration;

	return this->acceleration;
}

sf::Vector2f LLGP::managedSprite::addAcceleration(sf::Vector2f acceleration) 
{
	this->acceleration += acceleration;

	return this->acceleration;
}

LLGP::e_objectError LLGP::managedSprite::update() 
{

	return errorState;
}
LLGP::e_objectError LLGP::managedSprite::fixedUpdate() 
{
	// update velocity of object
	velocity = velocity + acceleration;
	
	// update position using velocity
	position = position + velocity;

	// update sprite position
	sprite->setPosition(position);

	return errorState;
}

bool LLGP::managedSprite::render(sf::RenderWindow& window)
{
	window.draw(*sprite);

	return true;
}