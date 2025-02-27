#include "Player.h"
#include "Weapon.h"
#include "GameManager.h"
#include "Enemy.h"
#include "Gadget.h"
#include "Bullet.h"


Player::Player(std::vector<Weapon*>& WeaponUsed) : Character("../../../res/PlayerRight.png",150,250.f)
{
	mShield = 0;
	mUsedWeapon = 0;
	mAngle = 0;
	mCoolDownWeapon = 0;
	mInvincibilityTimer = 0;
	mWeapons = WeaponUsed;

	if (!mFont.loadFromFile("../../../res/Font/m04b.ttf"))
		exit(0);

	if (!mInvicibilityTexture.loadFromFile("../../../res/GlowingPlayerRight.png"))
		exit(0);

	mHealth = sf::Text(std::to_string(mHP), mFont);
	mHealth.setCharacterSize(15);

	mHealth.setOrigin(mHealth.getGlobalBounds().getSize().x / 2, mHealth.getGlobalBounds().getSize().y);
	mHealth.setPosition(getPosition().x, getPosition().y - (mTexture.getSize().y / 2));

	sf::Vector2u windowSize = GameManager::GetInstance()->GetWindow()->getSize();

	setPosition(windowSize.x / 2, windowSize.y / 2);
}

void Player::ChangeWeapon()
{
	if (mCoolDownWeapon <= 0)
	{
		mUsedWeapon = !mUsedWeapon;
		mCoolDownWeapon = 5;
	}
}

void Player::LifeChange(int amount)
{
	if (amount < 0)
	{
		mShield += amount;
		if (mShield < 0)
		{
			mHP += mShield;
			mShield = 0;
		}
	}
	else 
	{
		if (mHP += amount > mMaxHP)
			mHP = mMaxHP;

		mHP += amount;
	}

	mHealth.setString(std::to_string(mHP));
}

void Player::ShieldGain(int& amount)
{
	mShield += amount;
}

void Player::ChangeAngle(double& angle)
{
	mAngle = angle;
}

double Player::GetAngle()
{
	return mAngle;
}

Weapon*& Player::GetPlayerActualWeapon()
{
	return mWeapons[mUsedWeapon];
}

Weapon*& Player::GetPlayerWeapon()
{
	return mWeapons[!mUsedWeapon];
}

void Player::Collide(Enemy* collider)
{
	if (mInvincibilityTimer <= 0)
	{
		LifeChange(- (collider->GetDamage()));
		mInvincibilityTimer = 0.3f;
	}
}

void Player::Collide(Bullet* collider)
{
	if (mInvincibilityTimer <= 0)
	{
		LifeChange(-(collider->GetDamage()));
		mInvincibilityTimer = 0.3f;
	}
}

void Player::Collide(Gadget*& collider)
{
	collider->Use(this);
}

void Player::UpdatePlayer(sf::Vector2f& movement,float& DeltaTime)
{

	move(sf::Vector2f(movement.x * mSpeed * DeltaTime, movement.y * mSpeed * DeltaTime));
	UpdateAngle();

	mCoolDownWeapon -= DeltaTime;

	if (mInvincibilityTimer > 0)
		mInvincibilityTimer -= DeltaTime;

	mWeapons[mUsedWeapon]->UpdateWeapon(DeltaTime, this, true);
	mWeapons[!mUsedWeapon]->UpdateWeapon(DeltaTime, this, false);

	if (mInvincibilityTimer > 0.1f)
		mSprite.setTexture(mInvicibilityTexture);
	else
		mSprite.setTexture(mTexture);

	mHealth.setPosition(getPosition().x, getPosition().y - (mTexture.getSize().y / 2));
}

void Player::UpdateAngle()
{
	sf::Vector2i MousePosition = sf::Mouse::getPosition(*GameManager::GetInstance()->GetWindow());

	sf::Vector2f ActualDirection = sf::Vector2f(MousePosition) - getPosition();

	double NewAngle = VectorToDegreesAngle(ActualDirection);

	mAngle = NewAngle;
}

void Player::CheckMovement(sf::Vector2f& movement, float ElapsedTime)
{
	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	sf::Vector2f EntityPosition = getPosition();

	sf::Vector2u EntitySize = mTexture.getSize();

	if (EntityPosition.x + (movement.x * mSpeed * ElapsedTime) + (EntitySize.x / 2) > WindowSize.x)
		movement.x -= 1;

	if (EntityPosition.x - (movement.x * mSpeed * ElapsedTime) - (EntitySize.x / 2) < 0)
		movement.x += 1;

	if (EntityPosition.y + (movement.y * mSpeed * ElapsedTime) + (EntitySize.y / 2) > WindowSize.y)
		movement.y -= 1;

	if (EntityPosition.y - (movement.y * mSpeed * ElapsedTime) - (EntitySize.y / 2) < 0)
		movement.y += 1;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	Entity::draw(target, states);

	states.transform.combine(getTransform());

	target.draw(*mWeapons[mUsedWeapon], states);

	target.draw(*mWeapons[!mUsedWeapon], states);

	target.draw(mHealth);
}

void Player::ChangeWeaponsUsed(std::vector<Weapon*> NewWeaponsUsed)
{
	for (int i = 0; i < mWeapons.size(); i++)
		delete mWeapons[i];

	mWeapons = NewWeaponsUsed;
}

Player::~Player()
{
	for (int i = 0; i < mWeapons.size(); ++i)
		delete mWeapons[i];
}
