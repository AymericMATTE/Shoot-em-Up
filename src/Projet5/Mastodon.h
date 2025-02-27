#pragma once
#include "Enemy.h"

class Mastodon : public Enemy
{
	float mCooldown;

	bool mEnraged;

	sf::Texture mEnragedTexture;

public :
	Mastodon(sf::Vector2f position);

	Mastodon(float x, float y);

	virtual void Collide(Bullet* collider);

	virtual void UpdateEnemy(float ElapsedTime, Player* pPlayer);

	virtual void LifeChange(int amount);
};

