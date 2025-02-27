#include "Entity.h"
#include "GameManager.h"

Entity::Entity(sf::Texture texture)
{
	mTexture = texture;
	mSprite.setTexture(mTexture);
	setOrigin(mTexture.getSize().x / 2, mTexture.getSize().y / 2);
	SetHitbox(mTexture.getSize().x / 2);
}

Entity::Entity(std::string filepath)
{
	if (!mTexture.loadFromFile(filepath))
		exit(0);

	mSprite.setTexture(mTexture);
	setOrigin(mTexture.getSize().x / 2, mTexture.getSize().y / 2);
	SetHitbox(mTexture.getSize().x / 2);
}

void Entity::SetHitbox(float newHitbox)
{
	mHitbox = sf::CircleShape(newHitbox);
	mHitbox.setOrigin(mHitbox.getRadius(), mHitbox.getRadius());
}

sf::CircleShape* Entity::GetHitbox()
{
	return &mHitbox;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(getTransform());

	target.draw(mSprite, states);
}

