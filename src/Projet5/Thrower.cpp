#include "Thrower.h"

#include "Bullet.h"
#include "Gadget.h"
#include "Player.h"

Thrower::Thrower(sf::Vector2f position, Gadget* Itemdrop) : Enemy("../../../res/Walker.png", 150, 100.f, Itemdrop)
{
	setPosition(position);
	ReloadTime = 2.f;
	mCoolDown = ReloadTime;
}

Thrower::Thrower(float x, float y, Gadget* Itemdrop) : Enemy("../../../res/Walker.png", 150, 100.f, Itemdrop)
{
	setPosition(x, y);
	ReloadTime = 2.f;
	mCoolDown = ReloadTime;
}

void Thrower::Collide(Bullet* collider)
{
	LifeChange((collider->GetDamage()));
}

void Thrower::UpdateEnemy(float ElapsedTime, Player* pPlayer)
{
	sf::Vector2f playerPosition = pPlayer->getPosition();

	sf::Vector2f vector = playerPosition - getPosition();

	double angle = 90 - VectorToDegreesAngle(vector);

	sf::Vector2f direction = getVectorFromDegreesAngle(angle);

	move(direction.x * mSpeed * ElapsedTime, direction.y * mSpeed * ElapsedTime);

	Attack(VectorToDegreesAngle(vector), ElapsedTime);
}

void Thrower::LifeChange(int amount)
{
	mHP -= amount;
}

void Thrower::Attack(double angle, float ElapsedTime)
{
	mCoolDown -= ElapsedTime;

	if (mCoolDown <= 0)
	{
		mCoolDown = ReloadTime;
		mEnemyBullet.push_back(new Bullet("../../../res/Stone.png", angle, 200.f, 20, this));
	}

	for (int i =0; i < mEnemyBullet.size(); ++i)
		mEnemyBullet[i]->UpdateBullet(ElapsedTime);
}

void Thrower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Entity::draw(target, states);

	for (int i = 0; i < mEnemyBullet.size(); ++i)
		target.draw(*mEnemyBullet[i]);
}
