#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"

class Enemy;
class Bullet;
class Gadget;

class Scene : public sf::Drawable
{

protected :
	Map* mMap;

	std::vector<std::vector<Enemy*>> mEnemyWave;

	std::vector<Enemy*> mCurrentEnemies;

	std::vector<Gadget*> mGadgetList;

	Player* mPlayer;

	sf::Clock mDeltaTime;

	float mElapsedTime;

	int mCurrentWave;

	float mCountDown;

public :
	Scene();

	void InitScene();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void UpdateClock();

	void UpdateColision();

	void Update();

	bool CheckColision(Entity* hitbox1, Entity* hitbox2);

	void ChangePlayerWeapon(std::vector<Weapon*> NewWeapon);

	void CheckDeadCharacter();

	void UpdateWave();

	void RestartClock();

	~Scene();
}; 