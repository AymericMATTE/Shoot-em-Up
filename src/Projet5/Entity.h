#pragma once

#include "Tools.h"
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{

protected :

	sf::CircleShape mHitbox;

	sf::Sprite mSprite;

	sf::Texture mTexture;
	 
public :
	Entity(std::string filepath);

	Entity(sf::Texture texture);

	void SetHitbox(float newHitbox);

	sf::CircleShape* GetHitbox();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};