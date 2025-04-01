#include "EnemyBase.h"

//--------------------------------------------------------------------------------------------------------------------------
//Construct & Destruct
EnemyBase::EnemyBase()
{
	Shape.setPosition({ 50.f,50.f });

	InitVariables();
}

//--------------------------------------------------------------------------------------------------------------------------

EnemyBase::~EnemyBase()
{
}

//--------------------------------------------------------------------------------------------------------------------------
//Initialization
void EnemyBase::InitVariables()
{
	Shape.setFillColor(sf::Color::Yellow);
	Shape.setSize(sf::Vector2f(45.f, 45.f));

	Movespeed = 2.f;
}

//--------------------------------------------------------------------------------------------------------------------------
//Functions
void EnemyBase::Update(Player player)
{
	//Chase Player
	sf::Vector2f Direction = player.GetPostion() - Shape.getPosition();
	Shape.move(Movespeed * Direction.normalized());

}

//--------------------------------------------------------------------------------------------------------------------------

const sf::RectangleShape& EnemyBase::GetShape() const
{
	return Shape;
}

//--------------------------------------------------------------------------------------------------------------------------

void EnemyBase::Render(sf::RenderTarget* target)
{
	target->draw(Shape);
}

//--------------------------------------------------------------------------------------------------------------------------