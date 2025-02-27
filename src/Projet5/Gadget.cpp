#include "Gadget.h"
#include "Player.h"

Gadget::Gadget(std::string filepath) : Entity(filepath)
{
}

Gadget::Gadget(sf::Texture texture) : Entity(texture)
{
}

void Gadget::Use(Player* pPlayer)
{
	return;
}

HealGadget::HealGadget(int amount) : Gadget("filepath")
{
	mAmount = amount;
}

void HealGadget::Use(Player* pPlayer)
{
	pPlayer->LifeChange(mAmount);
}

ShieldGadget::ShieldGadget(int amount) : Gadget("filepath")
{
	mAmount = amount;
}

void ShieldGadget::Use(Player* pPlayer)
{
	pPlayer->ShieldGain(mAmount);
}
