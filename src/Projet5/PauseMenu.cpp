#include "PauseMenu.h"
#include "GameManager.h"

PauseMenu::PauseMenu() : Menu()
{
}

void PauseMenu::Init()
{
	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	sf::RectangleShape* DarkEffect = new sf::RectangleShape(sf::Vector2f(GameManager::GetInstance()->GetWindow()->getSize().x, GameManager::GetInstance()->GetWindow()->getSize().y));
	DarkEffect->setFillColor(sf::Color(0U, 0U, 0U, 125U));

	sf::RectangleShape* PlayButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 5, WindowSize.y / 7));
	sf::RectangleShape* ParamButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 5, WindowSize.y / 7));
	sf::RectangleShape* QuitButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 5, WindowSize.y / 7));

	PlayButton->setTexture(&mButtonTexture);
	ParamButton->setTexture(&mButtonTexture);
	QuitButton->setTexture(&mButtonTexture);

	PlayButton->setOrigin(PlayButton->getSize().x / 2.f, PlayButton->getSize().y / 2.f);
	QuitButton->setOrigin(QuitButton->getSize().x / 2.f, QuitButton->getSize().y / 2.f);
	ParamButton->setOrigin(ParamButton->getSize().x / 2.f, ParamButton->getSize().y / 2.f);

	sf::Text* PlayText = new sf::Text("CONTINUE", mFont);
	sf::Text* ParamText = new sf::Text("OPTIONS", mFont);
	sf::Text* QuitText = new sf::Text("QUIT", mFont);

	PlayText->setFillColor(sf::Color(207, 115, 39));
	ParamText->setFillColor(sf::Color(207, 115, 39));
	QuitText->setFillColor(sf::Color(207, 115, 39));

	PlayText->setOrigin(PlayText->getGlobalBounds().getSize().x / 2, PlayText->getGlobalBounds().getSize().y / 2);
	ParamText->setOrigin(ParamText->getGlobalBounds().getSize().x / 2, ParamText->getGlobalBounds().getSize().y / 2);
	QuitText->setOrigin(QuitText->getGlobalBounds().getSize().x / 2, QuitText->getGlobalBounds().getSize().y / 2);

	PlayText->setPosition(WindowSize.x / 2, 4 * WindowSize.y / 14);
	ParamText->setPosition(WindowSize.x / 2, WindowSize.y / 2);
	QuitText->setPosition(WindowSize.x / 2, 10 * WindowSize.y / 14);

	PlayButton->setPosition(PlayText->getPosition().x, PlayText->getPosition().y + PlayText->getGlobalBounds().getSize().y / 2);
	ParamButton->setPosition(ParamText->getPosition().x, ParamText->getPosition().y + ParamText->getGlobalBounds().getSize().y / 2);
	QuitButton->setPosition(QuitText->getPosition().x, QuitText->getPosition().y + QuitText->getGlobalBounds().getSize().y / 2);

	mListButton.insert({ "DarkEffect", DarkEffect });
	mListButton.insert({ "PlayButton",PlayButton });
	mListButton.insert({ "ParamButton",ParamButton });
	mListButton.insert({ "QuitButton", QuitButton });

	mListText.insert({ "PlayText",PlayText });
	mListText.insert({ "ParamText",ParamText});
	mListText.insert({ "QuitText", QuitText });
}

void PauseMenu::Update()
{
	sf::Vector2i MousePosition = sf::Mouse::getPosition();

	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	if (MousePosition.y >= (3 * WindowSize.y / 14) && MousePosition.y <= (WindowSize.y * (5.f / 14.f)) && MousePosition.x >= (2 * WindowSize.x / 5.f) && MousePosition.x <= (WindowSize.x * (3.f / 5.f)))
	{
		mListButton["PlayButton"]->setTexture(&mPressedButtonTexture);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			GameManager::GetInstance()->ChangeGameStates(RunLevel);
	}
	else
	{
		mListButton["PlayButton"]->setTexture(&mButtonTexture);
	}

	if (MousePosition.y >= (WindowSize.y * (6.f / 14.f)) && MousePosition.y <= (WindowSize.y * (8.f / 14.f)) && MousePosition.x >= (2 * WindowSize.x / 5.f) && MousePosition.x <= (WindowSize.x * (3.f / 5.f)))
	{
		mListButton["ParamButton"]->setTexture(&mPressedButtonTexture);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			GameManager::GetInstance()->ChangeGameStates(RunParamMenu);
	}
	else
	{
		mListButton["ParamButton"]->setTexture(&mButtonTexture);
	}

	if (MousePosition.y >= (WindowSize.y * (9.f / 14.f)) && MousePosition.y <= (WindowSize.y * (11.f / 14.f)) && MousePosition.x >= (2 * WindowSize.x / 5.f) && MousePosition.x <= (WindowSize.x * (3.f / 5.f)))
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

void PauseMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto it = mListButton.begin(); it != mListButton.end(); ++it)
		target.draw(*it->second);

	for (auto it = mListText.begin(); it != mListText.end(); ++it)
		target.draw(*it->second);
}