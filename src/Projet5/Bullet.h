#pragma once

#include "Entity.h"

class Character;


class Bullet : public Entity
{
	sf::Vector2f mDirection;

	float mSpeed;

	int mDamage;

public :
	Bullet(std::string filepath, double angle, float speed,int damage, Character* pCharacter);

	Bullet(sf::Texture texture, double angle, float speed,int damage, Character* pCharacter);

	void UpdateBullet(float ElapsedTime);

	int GetDamage();
};

