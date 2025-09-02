#include "AssaultRifle.h"
#include "Bullet.h"
#include "Player.h"
#include "Macro.h"

AssaultRifle::AssaultRifle() : Weapon(RES_PATH + "AssaultRifle.png", 25, 0.3f)
{
}

void AssaultRifle::Attack(Player* pPlayer)
{
	double angle = pPlayer->GetAngle();

	mBullet.push_back(new Bullet(RES_PATH + "Laser Sprites/02.png", angle, 400.f, mDamageAmount, pPlayer));
}

void AssaultRifle::UpdateWeapon(float DeltaTime, Player* pPlayer, bool IsUsed)
{

	if (IsUsed)
	{
		mCooldown -= DeltaTime;
		if (mCooldown <= 0)
		{
			Attack(pPlayer);
			mCooldown = mReloadTime;
		}
	}

	for (int i = 0; i < mBullet.size(); i++)
		mBullet[i]->UpdateBullet(DeltaTime);
}

void AssaultRifle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < mBullet.size(); i++)
		target.draw(*mBullet[i]);
}

std::vector<Bullet*>& AssaultRifle::GetBullet()
{
	return mBullet;
}

AssaultRifle::~AssaultRifle()
{
	for (int i = 0; i < mBullet.size(); ++i)
		delete mBullet[i];
}
