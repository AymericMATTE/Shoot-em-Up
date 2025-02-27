#pragma once

#include "Entity.h"

class Player;

class Gadget : public Entity
{

public :
	Gadget(std::string filepath);

	Gadget(sf::Texture texture);

	virtual void Use(Player* pPlayer);
};

class HealGadget : public Gadget
{
	int mAmount;

public :
	HealGadget(int amount);

	virtual void Use(Player* pPlayer);
};

class ShieldGadget : public Gadget
{
	int mAmount;

public:
	ShieldGadget(int amount);

	virtual void Use(Player* pPlayer);
};