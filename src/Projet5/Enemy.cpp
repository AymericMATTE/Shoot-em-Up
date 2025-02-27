#include "Enemy.h"
#include "Gadget.h"
#include "Bullet.h"
#include "Player.h"


Enemy::Enemy(std::string filepath, int HP, float speed, Gadget* ItemDrop) : Character(filepath,HP,speed)
{
	if (ItemDrop == nullptr)
		IsItemDrop = false;

	mItemDrop = ItemDrop;
	mDamage = 10;
}

std::vector<Bullet*>& Enemy::GetEnemyBullet()
{
	return mEnemyBullet;
}

Gadget* Enemy::GetDrop()
{
	if (IsItemDrop)
		return mItemDrop;
	return nullptr;
}

int Enemy::GetDamage()
{
	return mDamage;
}

Enemy::~Enemy()
{
	if (mItemDrop != nullptr)
		delete mItemDrop;

	for (int i = 0; i < mEnemyBullet.size(); i++)
		delete mEnemyBullet[i];
}
