#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Menu.h"

class WinMenu : public Menu
{
	sf::Texture mTexture;
	sf::RectangleShape* mQuitButton;
	sf::RectangleShape* mWallpaper;
	sf::Text* mQuitText;

public:
	WinMenu();

	virtual void Init();
	virtual void Update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

