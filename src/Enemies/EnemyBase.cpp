#include "EnemyBase.h"

//--------------------------------------------------------------------------------------------------------------------------
//Construct & Destruct
EnemyBase::EnemyBase(sf::RenderTarget& target)
{
	InitVariables(target);
}

//--------------------------------------------------------------------------------------------------------------------------

EnemyBase::~EnemyBase()
{
}

//--------------------------------------------------------------------------------------------------------------------------
//Initialization
void EnemyBase::InitVariables(sf::RenderTarget& target)
{
	Shape.setFillColor(sf::Color::Yellow);
	Shape.setSize(sf::Vector2f(45.f, 45.f));

	//Randomize Spawn
	float shapePosX = static_cast<float>(rand() % target.getSize().x - Shape.getGlobalBounds().size.x);
	float shapePosY = static_cast<float>(rand() % target.getSize().y - Shape.getGlobalBounds().size.y);
	
	if (shapePosX < 0.f)
		shapePosX = 0.f;

	if (shapePosY < 0.f)
		shapePosY = 0.f;

	position = sf::Vector2f(shapePosX, shapePosY);
	Shape.setPosition(position);

	Movespeed = 2.f;
}

//--------------------------------------------------------------------------------------------------------------------------
//Functions
void EnemyBase::Update(Player* player)
{
	//Chase Player
	sf::Vector2f Direction = player->GetPostion() - Shape.getPosition();
	//position += Movespeed * Direction.normalized();
	//Shape.setPosition(position);
	Shape.move(Movespeed * Direction.normalized());
}

//--------------------------------------------------------------------------------------------------------------------------

const sf::RectangleShape& EnemyBase::GetShape() const
{
	return Shape;
}

//--------------------------------------------------------------------------------------------------------------------------

void EnemyBase::Render(sf::RenderTarget& target)
{
	target.draw(Shape);
}

//--------------------------------------------------------------------------------------------------------------------------