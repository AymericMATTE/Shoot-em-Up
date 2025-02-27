#pragma once

#include "Character.h"

class Gadget;

class Bullet;

class Player;

class Enemy : public Character
{

protected :

	int mDamage;

	bool IsItemDrop;

	Gadget* mItemDrop;

	std::vector<Bullet*> mEnemyBullet;

public :
	Enemy(std::string filepath, int HP, float speed, Gadget* Itemdrop = nullptr);

	virtual void UpdateEnemy(float ElapsedTime, Player* pPlayer) = 0;

	std::vector<Bullet*>& GetEnemyBullet();

	virtual void LifeChange(int amount) = 0;

	virtual void Collide(Bullet* collider) = 0;

	Gadget* GetDrop();

	int GetDamage();

	~Enemy();
};
