#pragma once
#include "Enemy.h"

class Walker : public Enemy
{

public:

	Walker(sf::Vector2f position, Gadget* Itemdrop = nullptr);

	Walker(float x, float y, Gadget* Itemdrop = nullptr);

	virtual void Collide(Bullet* collider);

	virtual void UpdateEnemy(float ElapsedTime, Player* pPlayer);

	virtual void LifeChange(int amount);
};

