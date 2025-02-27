#pragma once

#include "Character.h"

class Weapon;
class Bullet;
class Enemy;
class Gadget;

class Player : public Character
{
	int mShield;

	std::vector<Weapon*> mWeapons;

	bool mUsedWeapon;

	double mAngle;

	float mCoolDownWeapon;

	float mInvincibilityTimer;

	sf::Texture mInvicibilityTexture;

	sf::Text mHealth;

	sf::Font mFont;

public :
	Player(std::vector<Weapon*>& WeaponUsed);

	void ChangeWeapon();

	void LifeChange(int amount);

	void ShieldGain(int& amount);
	
	void ChangeAngle(double& angle);

	double GetAngle();

	Weapon*& GetPlayerActualWeapon();

	Weapon*& GetPlayerWeapon();

	void Collide(Enemy* collider);

	void Collide(Bullet* collider);

	void Collide(Gadget*& collider);

	void UpdatePlayer(sf::Vector2f& movement, float& DeltaTime);

	void UpdateAngle();


	void CheckMovement(sf::Vector2f& movement, float DeltaTime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void ChangeWeaponsUsed(std::vector<Weapon*> NewWeaponsUsed);

	~Player();
};

