#include "BaseballBat.h"
#include "Bullet.h"
#include "Player.h"
#include "Macro.h"

BaseballBat::BaseballBat() : Weapon(RES_PATH + "BaseballBat.png", 50, 0.7f)
{
}

void BaseballBat::Attack(Player* pPlayer)
{

	if (mBullet.size() != 0)
	{
		Bullet* actualbullet = mBullet[0];

		mBullet.erase(mBullet.begin());
		delete actualbullet;
	}

	double angle = pPlayer->GetAngle();

	mBullet.push_back(new Bullet(RES_PATH + "BLANK_ICON.png", angle, 0.f, mDamageAmount, pPlayer));
}

void BaseballBat::UpdateWeapon(float DeltaTime, Player* pPlayer, bool IsUsed)
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

	for (int i = 0; i < mBullet.size(); ++i)
		mBullet[i]->UpdateBullet(DeltaTime);
}

void BaseballBat::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < mBullet.size(); ++i)
		target.draw(*mBullet[i]);
}

std::vector<Bullet*>& BaseballBat::GetBullet()
{
	return mBullet;
}

BaseballBat::~BaseballBat()
{
	for (int i = 0; i < mBullet.size(); ++i)
		delete mBullet[i];
}
