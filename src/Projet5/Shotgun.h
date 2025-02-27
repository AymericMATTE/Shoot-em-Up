#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Weapon.h"

class Bullet;


class Shotgun : public Weapon
{
	std::vector<Bullet*> mBullet;

public:
	Shotgun();

	virtual void Attack(Player* pPlayer);

	virtual void UpdateWeapon(float DeltaTime, Player* pPlayer, bool IsUsed);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual std::vector<Bullet*>& GetBullet();

	~Shotgun();
};
