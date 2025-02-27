#pragma once

#include <SFML/Graphics.hpp>

class Menu : public sf::Drawable
{
protected : 

	sf::Font mFont;
	sf::Texture mButtonTexture;
	sf::Texture mPressedButtonTexture;

public :
	Menu();

	virtual void Init() = 0 ;
	virtual void Update() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};