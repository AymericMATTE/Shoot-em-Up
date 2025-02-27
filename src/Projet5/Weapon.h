#pragma once

#include "Entity.h"
#include <vector>

class Player;
class Bullet;

class Weapon : public Entity
{

protected :

	int mDamageAmount;
	float mReloadTime;
	float mCooldown;

public : 
	Weapon(sf::Texture texture, int damageAmount, float reloadTime);

	Weapon(std::string filepath, int damageAmount, float reloadTime);

	virtual void Attack(Player* pPlayer) = 0;

	virtual void UpdateWeapon(float DeltaTime, Player* pPlayer, bool IsUsed) = 0;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	virtual std::vector<Bullet*>& GetBullet() = 0;

};