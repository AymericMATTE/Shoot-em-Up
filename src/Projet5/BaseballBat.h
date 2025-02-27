#pragma once
#include "Weapon.h"

class Bullet;

class BaseballBat : public Weapon
{
	std::vector<Bullet*> mBullet;

public:
	BaseballBat();

	virtual void Attack(Player* pPlayer);

	virtual void UpdateWeapon(float DeltaTime, Player* pPlayer, bool IsUsed);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual std::vector<Bullet*>& GetBullet();

	~BaseballBat();
};
