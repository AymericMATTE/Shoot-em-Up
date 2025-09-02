#include "MainMenu.h"
#include "GameManager.h"
#include "Macro.h"

MainMenu::MainMenu() : Menu()
{
	if (!mTexture.loadFromFile(RES_PATH + "MainMenuScreen.png"));
}

void MainMenu::Init()
{
	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	sf::RectangleShape* PlayButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 5, WindowSize.y / 7));
	sf::RectangleShape* ParamButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 5, WindowSize.y / 7));
	sf::RectangleShape* QuitButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 5, WindowSize.y / 7));
	sf::RectangleShape* Wallpaper = new sf::RectangleShape(sf::Vector2f(GameManager::GetInstance()->GetWindow()->getSize().x, GameManager::GetInstance()->GetWindow()->getSize().y));

	Wallpaper->setTexture(&mTexture);

	PlayButton->setTexture(&mButtonTexture);
	ParamButton->setTexture(&mButtonTexture);
	QuitButton->setTexture(&mButtonTexture);

	PlayButton->setOrigin(PlayButton->getSize().x / 2.f, PlayButton->getSize().y / 2.f);
	QuitButton->setOrigin(QuitButton->getSize().x / 2.f, QuitButton->getSize().y / 2.f);
	ParamButton->setOrigin(ParamButton->getSize().x / 2.f, ParamButton->getSize().y / 2.f);

	sf::Text* PlayText = new sf::Text("PLAY", mFont);
	sf::Text* ParamText = new sf::Text("OPTIONS", mFont);
	sf::Text* QuitText = new sf::Text("QUIT", mFont);

	PlayText->setFillColor(sf::Color(207, 115, 39));
	ParamText->setFillColor(sf::Color(207, 115, 39));
	QuitText->setFillColor(sf::Color(207, 115, 39));

	PlayText->setOrigin(PlayText->getGlobalBounds().getSize().x / 2, PlayText->getGlobalBounds().getSize().y / 2);
	ParamText->setOrigin( ParamText->getGlobalBounds().getSize().x / 2, ParamText->getGlobalBounds().getSize().y / 2);
	QuitText->setOrigin(QuitText->getGlobalBounds().getSize().x / 2, QuitText->getGlobalBounds().getSize().y / 2);

	PlayText->setPosition(WindowSize.x / 2, 13 * WindowSize.y / 28);
	ParamText->setPosition(WindowSize.x / 2, 18 * WindowSize.y / 28);
	QuitText->setPosition(WindowSize.x / 2, 23 * WindowSize.y / 28);

	PlayButton->setPosition(PlayText->getPosition().x, PlayText->getPosition().y + PlayText->getGlobalBounds().getSize().y / 2);
	ParamButton->setPosition(ParamText->getPosition().x, ParamText->getPosition().y + ParamText->getGlobalBounds().getSize().y / 2);
	QuitButton->setPosition(QuitText->getPosition().x, QuitText->getPosition().y + QuitText->getGlobalBounds().getSize().y / 2);


	mListButton.insert({ "Wallpaper", Wallpaper });
	mListButton.insert({ "PlayButton",PlayButton });
	mListButton.insert({ "ParamButton",ParamButton });
	mListButton.insert({ "QuitButton", QuitButton });

	mListText.insert({ "PlayText",PlayText });
	mListText.insert({ "ParamText",ParamText });
	mListText.insert({ "QuitText", QuitText });
}

void MainMenu::Update()
{
	sf::Vector2i MousePosition = sf::Mouse::getPosition();

	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	if (MousePosition.y >= (11 * WindowSize.y / 28) && MousePosition.y <= (WindowSize.y * (15.f / 28.f)) && MousePosition.x >= (2 * WindowSize.x / 5.f) && MousePosition.x <= (WindowSize.x * (3.f / 5.f)))
	{
		mListButton["PlayButton"]->setTexture(&mPressedButtonTexture);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			GameManager::GetInstance()->ChangeGameStates(States::RunPrePlayMenu);
	}
	else
	{
		mListButton["PlayButton"]->setTexture(&mButtonTexture);
	}

	if (MousePosition.y >= (WindowSize.y * (8.f / 14.f)) && MousePosition.y <= (WindowSize.y * (10.f / 14.f)) && MousePosition.x >= ( 2 * WindowSize.x / 5.f) && MousePosition.x <= (WindowSize.x * (3.f / 5.f)))
	{
		mListButton["ParamButton"]->setTexture(&mPressedButtonTexture);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			GameManager::GetInstance()->ChangeGameStates(States::RunParamMenu);
	}
	else
	{
		mListButton["ParamButton"]->setTexture(&mButtonTexture);
	}

	if (MousePosition.y >= (WindowSize.y * (21.f / 28.f)) && MousePosition.y <= (WindowSize.y * (25.f / 28.f)) && MousePosition.x >= (2 * WindowSize.x / 5.f) && MousePosition.x <= (WindowSize.x * (3.f / 5.f)))
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

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto it = mListButton.begin(); it != mListButton.end(); ++it)
		target.draw(*it->second);

	for (auto it = mListText.begin(); it != mListText.end(); ++it)
		target.draw(*it->second);
}

