#include "Level1.h"
#include "Map.h"
#include "Weapon.h"
#include "GameManager.h"

#include "Shotgun.h"
#include "BaseballBat.h"
#include "AssaultRifle.h"

#include "Gadget.h"

#include "Thrower.h"
#include "Walker.h"
#include "Mastodon.h"

Level1::Level1() : Scene()
{
	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	std::vector<std::vector<Enemy*>> Level1Enemies =
	{
		{new Thrower(WindowSize.x / 2, 0), new Thrower(WindowSize.x / 2, WindowSize.y),new Thrower(0,WindowSize.y),new Thrower(WindowSize.x,WindowSize.y), new Walker(WindowSize.x, WindowSize.y / 2), new Walker(0, WindowSize.y / 2),  new Walker(WindowSize.x,0), new Walker(0,0),},
		{new Thrower(0,0), new Thrower(WindowSize.x / 9,0), new Thrower(2 * WindowSize.x / 9,0) , new Thrower(3 * WindowSize.x / 9,0), new Thrower(4 * WindowSize.x / 9,0), new Thrower(5 * WindowSize.x / 9,0), new Thrower(6 * WindowSize.x / 9,0), new Thrower(7 * WindowSize.x / 9,0), new Thrower(8 * WindowSize.x / 9,0), new Thrower(WindowSize.x,0)},
		{new Thrower(0,WindowSize.y), new Thrower(WindowSize.x / 9,WindowSize.y), new Thrower(2 * WindowSize.x / 9,WindowSize.y) , new Thrower(3 * WindowSize.x / 9,WindowSize.y), new Thrower(4 * WindowSize.x / 9,WindowSize.y), new Thrower(5 * WindowSize.x / 9,WindowSize.y), new Thrower(6 * WindowSize.x / 9,WindowSize.y), new Thrower(7 * WindowSize.x / 9,WindowSize.y), new Thrower(8 * WindowSize.x / 9,WindowSize.y), new Thrower(WindowSize.x,WindowSize.y)},
		{new Walker(0,WindowSize.y), new Walker(WindowSize.x / 9,WindowSize.y), new Walker(2 * WindowSize.x / 9,WindowSize.y) , new Walker(3 * WindowSize.x / 9,WindowSize.y), new Walker(4 * WindowSize.x / 9,WindowSize.y), new Walker(5 * WindowSize.x / 9,WindowSize.y), new Walker(6 * WindowSize.x / 9,WindowSize.y), new Walker(7 * WindowSize.x / 9,WindowSize.y), new Walker(8 * WindowSize.x / 9,WindowSize.y), new Walker(WindowSize.x,WindowSize.y), new Walker(0,0), new Walker(WindowSize.x / 9,0), new Walker(2 * WindowSize.x / 9,0) , new Walker(3 * WindowSize.x / 9,0), new Walker(4 * WindowSize.x / 9,0), new Walker(5 * WindowSize.x / 9,0), new Walker(6 * WindowSize.x / 9,0), new Walker(7 * WindowSize.x / 9,0), new Walker(8 * WindowSize.x / 9,0), new Walker(WindowSize.x,0)},
		{new Mastodon(WindowSize.x / 2, WindowSize.y / 2), new Walker(WindowSize.x, WindowSize.y / 2), new Walker(0, WindowSize.y / 2), new Thrower(WindowSize.x / 2, WindowSize.y), new Thrower(WindowSize.x / 2, 0)}
	};

	mEnemyWave = Level1Enemies;

	Map* map = new Map((float)WindowSize.x, (float)WindowSize.y);
	map->loadTextures();

	std::vector<std::vector<int>> mapData = {
		{0, 1, 0, 0, 6, 1, 0, 1, 0, 1, 2, 0, 1, 1, 17},
		{17, 0, 1, 0, 8, 3, 14, 18, 1, 1,6, 0, 1, 0, 0},
		{1, 1, 1, 17, 2, 1, 16, 3, 3, 5, 12, 7, 3,3,3},
		{1, 17, 0, 0, 2, 1, 1,  0, 17, 0,  4,  0,1,18,0},
		{18, 0, 1, 1, 6, 0, 18,  1, 0, 18,  2,  1,0,1,1},
		{3, 3, 3, 5, 11,7, 3, 3, 14, 1,  6,  1,13,3,3},
		{0, 1, 1, 0, 1, 18, 0, 1, 16, 5, 12,  7,15,1,17},
		{0, 17, 0, 1, 0, 0, 1, 1,  0, 0, 4,    1,18,0,1},
	};
	map->loadMap(mapData);

	mMap = map;

	std::vector<Weapon*> mWeaponUsed;

	mPlayer = new Player(mWeaponUsed);
	mElapsedTime = 0;

	for (int i = 0; i < mEnemyWave[0].size(); ++i)
	{
		mCurrentEnemies.push_back(mEnemyWave[0][i]);
	}
}
