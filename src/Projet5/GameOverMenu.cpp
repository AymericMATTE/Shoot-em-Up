#include "GameOverMenu.h"
#include "GameManager.h"
#include "Macro.h"

GameOverMenu::GameOverMenu() : Menu()
{
	if (!mTexture.loadFromFile(RES_PATH + "GameOverScreen.png"));
}

void GameOverMenu::Init()
{
	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	sf::RectangleShape* PlayButton = new sf::RectangleShape(sf::Vector2f(2 * WindowSize.x / 11, WindowSize.y / 14));
	sf::RectangleShape* QuitButton = new sf::RectangleShape(sf::Vector2f(2 * WindowSize.x / 11, WindowSize.y / 14));
	sf::RectangleShape* Wallpaper = new sf::RectangleShape(sf::Vector2f(GameManager::GetInstance()->GetWindow()->getSize().x, GameManager::GetInstance()->GetWindow()->getSize().y));

	Wallpaper->setTexture(&mTexture);

	PlayButton->setTexture(&mButtonTexture);
	QuitButton->setTexture(&mButtonTexture);

	PlayButton->setOrigin(PlayButton->getSize().x / 2.f, PlayButton->getSize().y / 2.f);
	QuitButton->setOrigin(QuitButton->getSize().x / 2.f, QuitButton->getSize().y / 2.f);

	sf::Text* PlayText = new sf::Text("RESTART", mFont);
	sf::Text* QuitText = new sf::Text("QUIT", mFont);
	sf::Text* GameOverText = new sf::Text("GAME OVER", mFont);

	GameOverText->setCharacterSize(200);
	GameOverText->setFillColor(sf::Color::Red);

	PlayText->setFillColor(sf::Color(207, 115, 39));
	QuitText->setFillColor(sf::Color(207, 115, 39));

	PlayText->setOrigin(PlayText->getGlobalBounds().getSize().x / 2, PlayText->getGlobalBounds().getSize().y / 2);
	QuitText->setOrigin(QuitText->getGlobalBounds().getSize().x / 2, QuitText->getGlobalBounds().getSize().y / 2);
	GameOverText->setOrigin(GameOverText->getGlobalBounds().getSize().x / 2, GameOverText->getGlobalBounds().getSize().y / 2);

	PlayText->setPosition(4 * WindowSize.x / 11, 23 * WindowSize.y / 28);
	QuitText->setPosition(7 * WindowSize.x / 11, 23 * WindowSize.y / 28);
	GameOverText->setPosition(WindowSize.x / 2, WindowSize.y / 5);

	PlayButton->setPosition(PlayText->getPosition().x , PlayText->getPosition().y + PlayText->getGlobalBounds().getSize().y / 2);
	QuitButton->setPosition(QuitText->getPosition().x , QuitText->getPosition().y + QuitText->getGlobalBounds().getSize().y / 2);

	mListButton.insert({ "Wallpaper", Wallpaper });
	mListButton.insert({ "PlayButton",PlayButton });
	mListButton.insert({ "QuitButton", QuitButton });

	mListText.insert({ "PlayText", PlayText });
	mListText.insert({ "QuitText", QuitText });
	mListText.insert({ "GameOverText", GameOverText });
}

void GameOverMenu::Update()
{
	sf::Vector2i MousePosition = sf::Mouse::getPosition();

	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	if (MousePosition.y >= ( 11 * WindowSize.y / 14) && MousePosition.y <= (WindowSize.y * (12.f / 14.f)) && MousePosition.x >= (3 * WindowSize.x / 11.f) && MousePosition.x <= (WindowSize.x * (5.f / 11.f)))
	{
		mListButton["PlayButton"]->setTexture(&mPressedButtonTexture);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			GameManager::GetInstance()->RestartScene();
	}
	else
	{
		mListButton["PlayButton"] ->setTexture(&mButtonTexture);
	}

	if (MousePosition.y >= (WindowSize.y * (11.f / 14.f)) && MousePosition.y <= (WindowSize.y * (12.f / 14.f)) && MousePosition.x >= (6 * WindowSize.x / 11.f) && MousePosition.x <= (WindowSize.x * (8.f / 11.f)))
	{
		mListButton["QuitButton"]->setTexture(&mPressedButtonTexture);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			GameManager::GetInstance()->GetWindow()->close();
	}
	else
	{
		mListButton["QuitButton"]->setTexture(&mButtonTexture);
	}
}

void GameOverMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape DarkEffect(sf::Vector2f(GameManager::GetInstance()->GetWindow()->getSize().x, GameManager::GetInstance()->GetWindow()->getSize().y));
	DarkEffect.setFillColor(sf::Color(0U, 0U, 0U, 125U));

	target.draw(DarkEffect);

	for (auto it = mListButton.begin(); it != mListButton.end(); ++it)
		target.draw(*it->second);

	for (auto it = mListText.begin(); it != mListText.end(); ++it)
		target.draw(*it->second);
}

