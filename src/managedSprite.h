#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

namespace LLGP
{
	enum e_objectOrigin
	{
		TOPLEFT = 0,
		CENTRE,
		MIDDLEBOTTOM
	};

	enum e_objectError
	{
		None = 0,
		Issue1,
		Issue2
	};

	class managedSprite
	{
		// Variables
	public:
	private:
		sf::Vector2f scale;
		sf::Vector2i size;
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
		e_objectOrigin originLocation;
		sf::Image textureSrc;
		sf::Texture texture;
		std::unique_ptr<sf::Sprite> sprite;
		e_objectError errorState;

		// Functions
	public:
		// default constructor
		managedSprite();
		
		// standard constructor taking a texture with defaults for position, scale, and origin
		managedSprite(const sf::Image textureSrc, sf::Vector2i textureLocation, sf::Vector2i textureSize, sf::Vector2f location = { 0.0f, 0.0f }, sf::Vector2f scale = { 1.0f,1.0f }, e_objectOrigin origin = e_objectOrigin::TOPLEFT);
	
		// copy constructor - delete if using uniue_ptr as these cannot be copied
		//managedSprite(const managedSprite& other);
		managedSprite(const managedSprite& other) = delete; 
		
		// move constructor
		managedSprite(managedSprite&& other);

		// destructor - should be virtual if we are utilising inheritance to allow for proper destruction process.
		~managedSprite();
		// virtual ~managedSprite();

		sf::Vector2f getScale();
		sf::Vector2f setScale(int scale);
		sf::Vector2f setScale(sf::Vector2f scale);
		
		sf::Vector2f getPosition();
		sf::Vector2f setPosition(sf::Vector2f position);
		sf::Vector2f moveRelative(sf::Vector2f offset);
		sf::Vector2f moveAbsolute(sf::Vector2f position);

		sf::Vector2f getVelocity();
		sf::Vector2f setVelocity(sf::Vector2f velocity);
		sf::Vector2f addVelocity(sf::Vector2f velocity);

		sf::Vector2f getAcceleration();
		sf::Vector2f setAcceleration(sf::Vector2f acceleration);
		sf::Vector2f addAcceleration(sf::Vector2f acceleration);

		e_objectError update();
		e_objectError fixedUpdate();

		bool render(sf::RenderWindow& window);

	private:

	};
}