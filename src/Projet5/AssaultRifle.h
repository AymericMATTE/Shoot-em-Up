#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Weapon.h"

class Bullet;


class AssaultRifle : public Weapon
{
	std::vector<Bullet*> mBullet;

public:
	AssaultRifle();

	virtual void Attack(Player* pPlayer);

	virtual void UpdateWeapon(float DeltaTime, Player* pPlayer, bool IsUsed);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual std::vector<Bullet*>& GetBullet();

	~AssaultRifle();
};
