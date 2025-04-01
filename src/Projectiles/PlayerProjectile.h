#pragma once
#include "ProjectileBase.h"

class PlayerProjectile : public Projectile 
{
public:
	//Construct & Destruct
	PlayerProjectile();
	~PlayerProjectile();

	//Functions
	void Update();
	void UpdateBounds(const sf::RenderTarget* target);

private:
	//Private Functions
	void InitVariables();
};
