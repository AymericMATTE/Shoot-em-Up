#include "Mastodon.h"
#include "Bullet.h"
#include "Player.h"

Mastodon::Mastodon(sf::Vector2f position) : Enemy("../../../res/BigBoss.png", 1000, 150.f)
{
	mEnraged = false;
	mCooldown = 5.f;
	setPosition(position);

	if (!mEnragedTexture.loadFromFile("../../../res/EnragedBigBoss.png"))
		exit(0);
}

Mastodon::Mastodon(float x, float y) : Enemy("../../../res/BigBoss.png", 1000, 150.f)
{
	mEnraged = false;
	mCooldown = 5.f;
	setPosition(x, y);

	if (!mEnragedTexture.loadFromFile("../../../res/EnragedBigBoss.png"))
		exit(0);
}

void Mastodon::Collide(Bullet* collider)
{
	LifeChange((collider->GetDamage()));
}

void Mastodon::UpdateEnemy(float ElapsedTime, Player* pPlayer)
{
	sf::Vector2f playerPosition = pPlayer->getPosition();

	sf::Vector2f vector = playerPosition - getPosition();

	double angle = 90 - VectorToDegreesAngle(vector);

	sf::Vector2f direction = getVectorFromDegreesAngle(angle);

	mCooldown -= ElapsedTime;

	if (mCooldown <= 0)
	{
		mEnraged = !mEnraged;

		if (mEnraged)
		{
			mCooldown = 3.f;
			mSpeed *= 1.5f;
			mDamage += 10;
			mSprite.setTexture(mEnragedTexture);
		}
		else
		{
			mCooldown = 5.f;
			mSpeed /= 1.5f;
			mDamage -= 10;
			mSprite.setTexture(mTexture);
		}
	}

	move(direction.x * mSpeed * ElapsedTime, direction.y * mSpeed * ElapsedTime);
}


void Mastodon::LifeChange(int amount)
{
	if (mEnraged)
		mHP -= (amount - (amount / 5));
	else
		mHP -= amount;
}
