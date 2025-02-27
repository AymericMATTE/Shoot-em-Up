#pragma once

#include "Entity.h"

class Character : public Entity
{
protected :

	int mMaxHP;
	int mHP;
	float mSpeed;

public :
	Character(sf::Texture texture, int HP, float speed);

	Character(std::string filepath, int HP, float speed);

	bool IsAlive();

};

