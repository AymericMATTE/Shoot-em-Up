#include "Level2.h"
#include "Map.h"
#include "GameManager.h"

#include "Weapon.h"
#include "Shotgun.h"
#include "BaseballBat.h"
#include "AssaultRifle.h"

#include "Gadget.h"

#include "Thrower.h"
#include "Walker.h"
#include "Mastodon.h"

Level2::Level2() : Scene()
{
	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	std::vector<std::vector<Enemy*>> Level2Enemies =
	{
		{new Thrower(WindowSize.x / 2, 0), new Walker(WindowSize.x / 2, WindowSize.y),new Walker(0,WindowSize.y),new Thrower(WindowSize.x,WindowSize.y), new Walker(WindowSize.x, WindowSize.y / 2), new Thrower(0, WindowSize.y / 2),  new Walker(WindowSize.x,0), new Walker(0,0),},
		{new Walker(0,0), new Walker(WindowSize.x / 9,0), new Walker(2 * WindowSize.x / 9,0) , new Walker(3 * WindowSize.x / 9,0), new Walker(4 * WindowSize.x / 9,0), new Walker(5 * WindowSize.x / 9,0), new Thrower(6 * WindowSize.x / 9,0), new Thrower(7 * WindowSize.x / 9,0), new Thrower(8 * WindowSize.x / 9,0), new Thrower(WindowSize.x,0)},
		{new Thrower( 0, 0),new Thrower(WindowSize.x,WindowSize.y / 9), new Thrower(WindowSize.x, 2 * WindowSize.y / 9), new Thrower(WindowSize.x, 3 * WindowSize.y / 9) , new Walker(WindowSize.x, 4 * WindowSize.y / 9), new Walker(WindowSize.x, 5 * WindowSize.y / 9), new Walker(WindowSize.x, 6 * WindowSize.y / 9), new Thrower(WindowSize.x, 7 * WindowSize.y / 9), new Thrower(WindowSize.x, 8 * WindowSize.y / 9), new Thrower(WindowSize.x,WindowSize.y)},
		{new Walker(WindowSize.x / 9, WindowSize.y / 2), new Walker( 2 * WindowSize.x / 9, WindowSize.y / 2), new Thrower(3 * WindowSize.x / 9,WindowSize.y / 2) , new Thrower(4 * WindowSize.x / 9,WindowSize.y / 2), new Walker(5 * WindowSize.x / 9,WindowSize.y / 2), new Walker(6 * WindowSize.x / 9,WindowSize.y), new Walker(7 * WindowSize.x / 9,WindowSize.y / 2), new Thrower(8 * WindowSize.x / 9,WindowSize.y / 2), new Walker(WindowSize.x,WindowSize.y / 2), new Walker(WindowSize.x,WindowSize.y), new Thrower(0,0), new Walker(WindowSize.x / 9,0), new Walker(2 * WindowSize.x / 9,0) , new Thrower(3 * WindowSize.x / 9,0), new Walker(4 * WindowSize.x / 9,0), new Walker(5 * WindowSize.x / 9,0), new Walker(6 * WindowSize.x / 9,0), new Thrower(7 * WindowSize.x / 9,0), new Walker(8 * WindowSize.x / 9,0), new Thrower(WindowSize.x,0)},
		{new Mastodon(WindowSize.x, WindowSize.y / 2), new Mastodon(0, WindowSize.y / 2)}
	};

	mEnemyWave = Level2Enemies;

	Map* map = new Map((float)WindowSize.x, (float)WindowSize.y);
	map->loadTextures();

	std::vector<std::vector<int>> mapData = {
		{18, 1, 0,  2, 1, 1, 0, 1, 17, 2, 1, 1, 2, 0, 1},
		{5, 9, 7, 15,18, 0, 0, 1, 0, 2, 0, 1, 6, 0, 17},
		{0, 4, 0,  1, 0, 0, 17, 1, 1, 2, 0, 0, 8, 7, 3},
		{0, 2, 0,  0, 1, 0, 1, 0, 0, 2, 1, 0, 2, 17, 0},
		{0, 2, 0,  0, 1, 0, 1, 0, 0, 16, 3,5, 10,0, 0},
		{0, 6, 0,  18, 17, 1, 0, 1, 0,  1, 1,1, 6, 1, 0},
		{5, 11,7,  3, 3, 3, 3, 3, 3,  3, 3, 5, 11,  14, 1},
		{1,  17, 18,  0, 1, 1, 0, 1, 0,  1, 17, 0, 0,4, 0},
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