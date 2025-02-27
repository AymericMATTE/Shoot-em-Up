#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Menu.h"

class PauseMenu : public Menu
{
	sf::Texture mTexture;
	std::unordered_map<std::string,sf::RectangleShape*> mListButton;
	std::unordered_map<std::string,sf::Text*> mListText;

public:
	PauseMenu();

	virtual void Init();
	virtual void Update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

