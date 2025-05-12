#include "EnemyBase.h"

//--------------------------------------------------------------------------------------------------------------------------
//Construct & Destruct
EnemyBase::EnemyBase(sf::RenderTarget& target, Player player)
{
	InitVariables(target, player);
}

//--------------------------------------------------------------------------------------------------------------------------

EnemyBase::~EnemyBase()
{
}

//--------------------------------------------------------------------------------------------------------------------------
//Initialization
void EnemyBase::InitVariables(sf::RenderTarget& target, Player player)
{
	Shape.setFillColor(sf::Color::Yellow);
	Shape.setSize(sf::Vector2f(45.f, 45.f));

	//Randomize Spawn
	float shapePosX = static_cast<float>(rand() % target.getSize().x - Shape.getGlobalBounds().size.x);
	float shapePosY = static_cast<float>(rand() % target.getSize().y - Shape.getGlobalBounds().size.y);
	
	//Out of bounds check
	if (shapePosX < 0.f)
		shapePosX = 0.f;

	if (shapePosY < 0.f)
		shapePosY = 0.f;

	//Player range check
	while (shapePosX > player.GetPostion().x - 200 && shapePosX < player.GetPostion().x + 200) { shapePosX = static_cast<float>(rand() % target.getSize().x - Shape.getGlobalBounds().size.x); }
	while (shapePosY > player.GetPostion().y - 200 && shapePosY < player.GetPostion().y + 200) { shapePosY = static_cast<float>(rand() % target.getSize().y - Shape.getGlobalBounds().size.y); }

	position = sf::Vector2f(shapePosX, shapePosY);
	Shape.setPosition(position);

	Movespeed = 2.f;
	score = 150;
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

void EnemyBase::Render(sf::RenderTarget& target)
{
	target.draw(Shape);
}

//--------------------------------------------------------------------------------------------------------------------------
//Getter Functions

const sf::RectangleShape& EnemyBase::GetShape() const
{
	return Shape;
}

//--------------------------------------------------------------------------------------------------------------------------

const int EnemyBase::GetScore() const
{
	return score;
}

//--------------------------------------------------------------------------------------------------------------------------