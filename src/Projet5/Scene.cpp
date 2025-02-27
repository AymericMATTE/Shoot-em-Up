#include "Scene.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Gadget.h"
#include "Weapon.h"
#include "GameManager.h"

Scene::Scene()
{
	mCurrentWave = 0;
	mCountDown = 20.f;
}

void Scene::InitScene()
{

	mDeltaTime.restart();
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	mMap->draw(target, states);

	for (int i = 0; i < mCurrentEnemies.size(); i++)
		mCurrentEnemies[i]->draw(target, states);

	mPlayer->draw(target, states);
}

void Scene::UpdateClock()
{
	mElapsedTime += mDeltaTime.getElapsedTime().asSeconds();
	mCountDown -= mDeltaTime.getElapsedTime().asSeconds();

	mDeltaTime.restart();
}

void Scene::UpdateColision()
{

	for (int i = 0; i < mCurrentEnemies.size(); i++)
	{
		for (auto it = mCurrentEnemies[i]->GetEnemyBullet().begin(); it != mCurrentEnemies[i]->GetEnemyBullet().end();)
		{
			Bullet* actualBullet = *it;

			if (CheckColision(mPlayer, actualBullet))
			{
				mPlayer->Collide(actualBullet);
				it = mCurrentEnemies[i]->GetEnemyBullet().erase(it);
				delete actualBullet;
			}
			else
				++it;
		}

		for (auto it = mPlayer->GetPlayerActualWeapon()->GetBullet().begin(); it != mPlayer->GetPlayerActualWeapon()->GetBullet().end();)
		{
			Bullet* actualBullet = *it;

			if (CheckColision(mCurrentEnemies[i], actualBullet))
			{
				mCurrentEnemies[i]->Collide(actualBullet);
				it = mPlayer->GetPlayerActualWeapon()->GetBullet().erase(it);
				delete actualBullet;
			}
			else
				++it;
		}

		for (auto it = mPlayer->GetPlayerWeapon()->GetBullet().begin(); it != mPlayer->GetPlayerWeapon()->GetBullet().end();)
		{
			Bullet* actualBullet = *it;

			if (CheckColision(mCurrentEnemies[i], actualBullet))
			{
				mCurrentEnemies[i]->Collide(actualBullet);
				it = mPlayer->GetPlayerWeapon()->GetBullet().erase(it);
				delete actualBullet;
			}
			else
				++it;
		}

		if (CheckColision(mPlayer, mCurrentEnemies[i]))
		{
			mPlayer->Collide(mCurrentEnemies[i]);
		}
	}

	for (auto it = mPlayer->GetPlayerActualWeapon()->GetBullet().begin(); it != mPlayer->GetPlayerActualWeapon()->GetBullet().end();)
	{
		Bullet* actualBullet = *it;

		if (actualBullet->getPosition().x > GameManager::GetInstance()->GetWindow()->getSize().x || actualBullet->getPosition().x < 0 || actualBullet->getPosition().y > GameManager::GetInstance()->GetWindow()->getSize().y || actualBullet->getPosition().y < 0)
		{
			it = mPlayer->GetPlayerActualWeapon()->GetBullet().erase(it);
			delete actualBullet;
		}
		else
			++it;
	}

	for (auto it = mPlayer->GetPlayerWeapon()->GetBullet().begin(); it != mPlayer->GetPlayerWeapon()->GetBullet().end();)
	{
		Bullet* actualBullet = *it;

		if (actualBullet->getPosition().x > GameManager::GetInstance()->GetWindow()->getSize().x || actualBullet->getPosition().x < 0 || actualBullet->getPosition().y > GameManager::GetInstance()->GetWindow()->getSize().y || actualBullet->getPosition().y < 0)
		{
			it = mPlayer->GetPlayerWeapon()->GetBullet().erase(it);
			delete actualBullet;
		}
		else
			++it;
	}

	for (auto it = mGadgetList.begin(); it != mGadgetList.end();)
	{
		Gadget* actualGadget = *it;

		if (CheckColision(mPlayer, actualGadget))
		{
			mPlayer->Collide(actualGadget);
			it = mGadgetList.erase(it);
			delete actualGadget;
		}
		else
			++it;
	}
}

void Scene::Update()
{
	float DeltaTime = mDeltaTime.getElapsedTime().asSeconds();

	sf::Vector2f movement = sf::Vector2f(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		movement.y -= 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		movement.x -= 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		mPlayer->ChangeWeapon();

	mPlayer->CheckMovement(movement, DeltaTime);

	mPlayer->UpdatePlayer(movement, DeltaTime);

	for (int i = 0; i < mCurrentEnemies.size(); i++)
		mCurrentEnemies[i]->UpdateEnemy(DeltaTime,mPlayer);

	UpdateColision();

	CheckDeadCharacter();

	UpdateClock();

	UpdateWave();
}

bool Scene::CheckColision(Entity* hitbox1, Entity* hitbox2)
{
	sf::Vector2f position1 = hitbox1->getPosition() + hitbox1->GetHitbox()->getPosition();
	sf::Vector2f position2 = hitbox2->getPosition() + hitbox2->GetHitbox()->getPosition();

	int norm = GetNorm(position1, position2);

	int totalRadius = hitbox1->GetHitbox()->getRadius() + hitbox2->GetHitbox()->getRadius();

	return norm <= totalRadius;
}

void Scene::ChangePlayerWeapon(std::vector<Weapon*> NewWeapon)
{
	mPlayer->ChangeWeaponsUsed(NewWeapon);
}

void Scene::CheckDeadCharacter()
{
	for (auto it = mCurrentEnemies.begin(); it != mCurrentEnemies.end();)
	{
		Enemy* currentEnemy = *it;

		if (!currentEnemy->IsAlive())
		{
			it = mCurrentEnemies.erase(it);
		}
		else
			++it;
	}

	if (mCurrentEnemies.empty() && mCurrentWave == (mEnemyWave.size() - 1))
	{
		GameManager::GetInstance()->ChangeScene();
	}

	if (!mPlayer->IsAlive())
	{
		GameManager::GetInstance()->ChangeGameStates(RunGameOverMenu);
	}
}

void Scene::UpdateWave()
{
	if (mCountDown <= 0 && mEnemyWave.size() > mCurrentWave + 1)
	{
		mCurrentWave++;
		mCountDown = 20.f;

		for (int i = 0; i < mEnemyWave[mCurrentWave].size(); ++i)
		{
			mCurrentEnemies.push_back(mEnemyWave[mCurrentWave][i]);
		}
	}
}

void Scene::RestartClock()
{
	mDeltaTime.restart();
}

Scene::~Scene()
{
	for (int i = 0; i < mEnemyWave.size(); i++)
	{
		for (int j = 0; j < mEnemyWave[i].size(); j++)
		{
			if (mEnemyWave[i][j] != nullptr)
			{
				delete mEnemyWave[i][j];
			}
		}
	}

	delete mMap;
	delete mPlayer;
}