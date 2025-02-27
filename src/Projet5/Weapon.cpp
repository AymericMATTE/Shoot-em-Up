#include "Weapon.h"
#include "Player.h"
#include "Bullet.h"

Weapon::Weapon(sf::Texture texture, int damageAmount, float reloadTime) : Entity(texture)
{
	mDamageAmount = damageAmount;
	mReloadTime = reloadTime;
	mCooldown = reloadTime;
}

Weapon::Weapon(std::string filepath, int damageAmount, float reloadTime) : Entity(filepath)
{
	mDamageAmount = damageAmount;
	mReloadTime = reloadTime;
	mCooldown = reloadTime;
}