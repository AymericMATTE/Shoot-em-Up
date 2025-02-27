#include "PrePlayMenu.h"
#include "GameManager.h"
#include "Shotgun.h"
#include "AssaultRifle.h"
#include "BaseballBat.h"
#include "Scene.h"

PrePlayMenu::PrePlayMenu()
{
	nbrOfWeapon = 0;
	ShotgunUsed = false;
	AssaultRifleUsed = false;
	BaseballBatUsed = false;

	sf::Texture Shotgun;
	sf::Texture AssaultRifle;
	sf::Texture BaseballBat;

	if (!Shotgun.loadFromFile("../../../res/Shotgun.png"))
		exit(0);
	if (!AssaultRifle.loadFromFile("../../../res/AssaultRifle.png"))
		exit(0);
	if (!BaseballBat.loadFromFile("../../../res/BaseballBat.png"))
		exit(0);

	mListTexture.insert({ "Shotgun",Shotgun });
	mListTexture.insert({ "AssaultRifle",AssaultRifle });
	mListTexture.insert({ "BaseballBat",BaseballBat});
}

void PrePlayMenu::Init()
{
	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	sf::RectangleShape* DarkEffect = new sf::RectangleShape(sf::Vector2f(GameManager::GetInstance()->GetWindow()->getSize().x, GameManager::GetInstance()->GetWindow()->getSize().y));
	DarkEffect->setFillColor(sf::Color(0U, 0U, 0U, 125U));

	sf::RectangleShape* ShotgunButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 7, WindowSize.y / 7));
	sf::RectangleShape* AssaultRifleButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 7, WindowSize.y / 7));
	sf::RectangleShape* BaseballBatButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 7, WindowSize.y / 7));

	ShotgunButton->setTexture(&mListTexture["Shotgun"]);
	AssaultRifleButton->setTexture(&mListTexture["AssaultRifle"]);
	BaseballBatButton->setTexture(&mListTexture["BaseballBat"]);

	ShotgunButton->setOrigin(ShotgunButton->getSize().x / 2.f, ShotgunButton->getSize().y / 2.f);
	AssaultRifleButton->setOrigin(AssaultRifleButton->getSize().x / 2.f, AssaultRifleButton->getSize().y / 2.f);
	BaseballBatButton->setOrigin(BaseballBatButton->getSize().x / 2.f, BaseballBatButton->getSize().y / 2.f);

	ShotgunButton->setPosition(2 * WindowSize.x / 7, 2 * WindowSize.y / 3);
	AssaultRifleButton->setPosition(WindowSize.x / 2, 2 * WindowSize.y / 3);
	BaseballBatButton->setPosition(5 * WindowSize.x / 7, 2 * WindowSize.y / 3);

	mListButton.insert({ "DarkEffect", DarkEffect });
	mListButton.insert({ "ShotgunButton", ShotgunButton });
	mListButton.insert({ "AssaultRifleButton", AssaultRifleButton });
	mListButton.insert({ "BaseballBatButton", BaseballBatButton });

	mExplanation = new sf::Text("PICK 2 WEAPONS",mFont);

	mExplanation->setOrigin(mExplanation->getGlobalBounds().getSize().x / 2, mExplanation->getGlobalBounds().getSize().y / 2);

	mExplanation->setPosition(sf::Vector2f(WindowSize.x / 2, WindowSize.y / 3));

	mExplanation->setFillColor(sf::Color(207, 115, 39));
}

void PrePlayMenu::Update()
{
	sf::Vector2i MousePosition = sf::Mouse::getPosition();

	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	if (MousePosition.y >= (11 * WindowSize.y / 21) && MousePosition.y <= (WindowSize.y * (17.f / 21.f)) && MousePosition.x >= (3 * WindowSize.x / 14.f) && MousePosition.x <= (WindowSize.x * (5.f / 14.f)))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !ShotgunUsed)
		{
			mListButton["ShotgunButton"]->setOutlineThickness(5.f);
			mListButton["ShotgunButton"]->setOutlineColor(sf::Color::Red);
			ShotgunUsed = true;
			nbrOfWeapon++;
		}
	}

	if (MousePosition.y >= (WindowSize.y * (11.f / 21.f)) && MousePosition.y <= (WindowSize.y * (17.f / 21.f)) && MousePosition.x >= (3 * WindowSize.x / 7.f) && MousePosition.x <= (WindowSize.x * (4.f / 7.f)))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !AssaultRifleUsed)
		{
			mListButton["AssaultRifleButton"]->setOutlineThickness(5.f);
			mListButton["AssaultRifleButton"]->setOutlineColor(sf::Color::Red);
			AssaultRifleUsed = true;
			nbrOfWeapon++;
		}
	}

	if (MousePosition.y >= (WindowSize.y * (11.f / 21.f)) && MousePosition.y <= (WindowSize.y * (17.f / 21.f)) && MousePosition.x >= (9 * WindowSize.x / 14.f) && MousePosition.x <= (WindowSize.x * (11.f / 14.f)))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !BaseballBatUsed)
		{
			mListButton["BaseballBatButton"]->setOutlineThickness(5.f);
			mListButton["BaseballBatButton"]->setOutlineColor(sf::Color::Red);
			BaseballBatUsed = true;
			nbrOfWeapon++;
		}
	}

	if (nbrOfWeapon == 2)
	{
		std::vector<Weapon*> WeaponUsed;

		if (ShotgunUsed)
		{
			mListButton["ShotgunButton"]->setOutlineThickness(0.f);
			WeaponUsed.push_back(new Shotgun());
			ShotgunUsed = false;
		}

		if (AssaultRifleUsed)
		{
			mListButton["AssaultRifleButton"]->setOutlineThickness(0.f);
			WeaponUsed.push_back(new AssaultRifle());
			AssaultRifleUsed = false;
		}

		if (BaseballBatUsed)
		{
			mListButton["BaseballBatButton"]->setOutlineThickness(0.f);
			WeaponUsed.push_back(new BaseballBat());
			BaseballBatUsed = false;
		}

		GameManager::GetInstance()->GetScene()->ChangePlayerWeapon(WeaponUsed);
		GameManager::GetInstance()->ChangeGameStates(States::RunLevel);
	
		nbrOfWeapon = 0;
	}
}

void PrePlayMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto it = mListButton.begin(); it != mListButton.end(); ++it)
		target.draw(*it->second);

	target.draw(*mExplanation);
}