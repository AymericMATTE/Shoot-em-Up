#include "Bullet.h"
#include "GameManager.h"
#include "Character.h"

Bullet::Bullet(std::string filepath, double angle, float speed,int damage, Character* pCharacter) : Entity(filepath)
{
	mSpeed = speed;
	mDamage = damage;

	double anglenew = 90.f - angle;

	CheckAngle(anglenew);
	mDirection = getVectorFromDegreesAngle(anglenew);
	setRotation(anglenew);

	setPosition(pCharacter->getPosition());
}

Bullet::Bullet(sf::Texture texture, double angle, float speed,int damage, Character* pCharacter) : Entity(texture)
{
	mSpeed = speed;
	mDamage = damage;

	double anglenew = 90.f - angle;

	CheckAngle(anglenew);
	mDirection = getVectorFromDegreesAngle(anglenew);
	setRotation(anglenew);

	setPosition(pCharacter ->getPosition());
}

void Bullet::UpdateBullet(float ElapsedTime)
{
	move(mDirection.x * mSpeed * ElapsedTime, mDirection.y * mSpeed * ElapsedTime);
}

int Bullet::GetDamage()
{
	return mDamage;
}

