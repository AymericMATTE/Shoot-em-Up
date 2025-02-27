#pragma once

#include <SFML/Graphics.hpp>
#include "unordered_map"
#include "Menu.h"

class Weapon;

class PrePlayMenu : public Menu
{
	std::unordered_map<std::string, sf::RectangleShape*> mListButton;
	std::unordered_map<std::string, sf::Texture> mListTexture;

	sf::Text* mExplanation;

	bool AssaultRifleUsed;
	bool ShotgunUsed;
	bool BaseballBatUsed;

	int nbrOfWeapon;

public:
	PrePlayMenu();

	virtual void Init();
	virtual void Update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

