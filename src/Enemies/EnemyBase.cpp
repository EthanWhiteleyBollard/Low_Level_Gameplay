#include "EnemyBase.h"

//--------------------------------------------------------------------------------------------------------------------------
//Construct & Destruct
EnemyBase::EnemyBase(sf::RenderTarget& target, Player player)
{
	sf::Image image("Assets/Enemy.png");

	bool result = texture.loadFromImage(image, true, sf::IntRect({ 0,0 }, { 40, 53 }));

	if (result) {
		sprite = new sf::Sprite(texture);
	}

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
	//Randomize Spawn
	float shapePosX = static_cast<float>(rand() % target.getSize().x - sprite->getGlobalBounds().size.x);
	float shapePosY = static_cast<float>(rand() % target.getSize().y - sprite->getGlobalBounds().size.y);
	
	//Out of bounds check
	if (shapePosX < 0.f)
		shapePosX = 0.f;

	if (shapePosY < 0.f)
		shapePosY = 0.f;

	//Player range check
	while (shapePosX > player.GetPostion().x - 200 && shapePosX < player.GetPostion().x + 200) { shapePosX = static_cast<float>(rand() % target.getSize().x - sprite->getGlobalBounds().size.x); }
	while (shapePosY > player.GetPostion().y - 200 && shapePosY < player.GetPostion().y + 200) { shapePosY = static_cast<float>(rand() % target.getSize().y - sprite->getGlobalBounds().size.y); }

	position = sf::Vector2f(shapePosX, shapePosY);
	sprite->setPosition(position);

	Movespeed = 2.f;
	score = 150;
}

//--------------------------------------------------------------------------------------------------------------------------
//Functions
void EnemyBase::Update(Player* player)
{
	//Chase Player
	sf::Vector2f Direction = player->GetPostion() - sprite->getPosition();
	//position += Movespeed * Direction.normalized();
	//Shape.setPosition(position);
	sprite->move(Movespeed * Direction.normalized());
}

//--------------------------------------------------------------------------------------------------------------------------

void EnemyBase::Render(sf::RenderTarget& target)
{
	target.draw(*sprite);
}

//--------------------------------------------------------------------------------------------------------------------------
//Getter Functions

sf::Sprite* EnemyBase::GetSprite()
{
	return sprite;
}

//--------------------------------------------------------------------------------------------------------------------------

const int EnemyBase::GetScore() const
{
	return score;
}

//--------------------------------------------------------------------------------------------------------------------------