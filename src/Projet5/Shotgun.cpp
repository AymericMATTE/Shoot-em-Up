#include "Shotgun.h"
#include "Player.h"
#include "Bullet.h"
#include "Macro.h"

Shotgun::Shotgun() : Weapon(RES_PATH + "Shotgun.png", 15, 1.f)
{
}

void Shotgun::Attack(Player* pPlayer)
{
	double angle = pPlayer->GetAngle(); 

	mBullet.push_back(new Bullet(RES_PATH + "Laser Sprites/02.png", angle, 200.f, mDamageAmount, pPlayer));

	mBullet.push_back(new Bullet(RES_PATH + "Laser Sprites/02.png", angle - 15, 200.f, mDamageAmount, pPlayer));

	mBullet.push_back(new Bullet(RES_PATH + "Laser Sprites/02.png", angle + 15, 200.f, mDamageAmount, pPlayer));
}

void Shotgun::UpdateWeapon(float DeltaTime, Player* pPlayer, bool IsUsed)
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
	{
		mBullet[i]->UpdateBullet(DeltaTime);
	}
}

void Shotgun::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < mBullet.size(); i++)
		target.draw(*mBullet[i]);
}

std::vector<Bullet*>& Shotgun::GetBullet()
{
	return mBullet;
}

Shotgun::~Shotgun()
{
	for (int i = 0; i < mBullet.size(); ++i)
		delete mBullet[i];
}
