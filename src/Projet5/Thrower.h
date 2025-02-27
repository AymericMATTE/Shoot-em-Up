#pragma once
#include "Enemy.h"

class Thrower : public Enemy
{
	float mCoolDown;
	int ReloadTime;

public:

	Thrower(sf::Vector2f position, Gadget* Itemdrop = nullptr);

	Thrower(float x, float y, Gadget* Itemdrop = nullptr);

	virtual void Collide(Bullet* collider);

	virtual void UpdateEnemy(float ElapsedTime, Player* pPlayer);

	virtual void LifeChange(int amount);

	void Attack(double angle, float ElapsedTime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

