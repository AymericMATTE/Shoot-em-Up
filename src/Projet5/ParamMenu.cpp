#include "ParamMenu.h"
#include "GameManager.h"

ParamMenu::ParamMenu() : Menu()
{
}

void ParamMenu::Init()
{
	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	sf::RectangleShape* PlayButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 5, WindowSize.y / 7));
	sf::RectangleShape* QuitButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 5, WindowSize.y / 7));

	PlayButton->setTexture(&mButtonTexture);
	QuitButton->setTexture(&mButtonTexture);

	PlayButton->setOrigin(PlayButton->getSize().x / 2.f, PlayButton->getSize().y / 2.f);
	QuitButton->setOrigin(QuitButton->getSize().x / 2.f, QuitButton->getSize().y / 2.f);

	sf::Text* PlayText = new sf::Text("RETURN", mFont);
	sf::Text* QuitText = new sf::Text("QUIT", mFont);

	PlayText->setFillColor(sf::Color(207, 115, 39));
	QuitText->setFillColor(sf::Color(207, 115, 39));

	PlayText->setOrigin(PlayText->getGlobalBounds().getSize().x / 2, PlayText->getGlobalBounds().getSize().y / 2);
	QuitText->setOrigin(QuitText->getGlobalBounds().getSize().x / 2, QuitText->getGlobalBounds().getSize().y / 2);

	PlayText->setPosition(WindowSize.x / 7, WindowSize.y / 7);
	QuitText->setPosition(WindowSize.x / 7, 6 * WindowSize.y / 7);

	PlayButton->setPosition(PlayText->getPosition().x, PlayText->getPosition().y + PlayText->getGlobalBounds().getSize().y / 2);
	QuitButton->setPosition(QuitText->getPosition().x, QuitText->getPosition().y + QuitText->getGlobalBounds().getSize().y / 2);


	mListButton.insert({ "PlayButton",PlayButton });
	mListButton.insert({ "QuitButton", QuitButton });

	mListText.insert({ "PlayText",PlayText });
	mListText.insert({ "QuitText", QuitText });
}

void ParamMenu::Update()
{
	sf::Vector2i MousePosition = sf::Mouse::getPosition();

	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	if (MousePosition.y >= (WindowSize.y / 14) && MousePosition.y <= (WindowSize.y * (3.f / 14.f)) && MousePosition.x >= (WindowSize.x / 14.f) && MousePosition.x <= (WindowSize.x * (3.f / 14.f)))
	{
		mListButton["PlayButton"]->setTexture(&mPressedButtonTexture);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			GameManager::GetInstance()->ChangeGameStates(GameManager::GetInstance()->GetPreviousGameState());
	}
	else
	{
		mListButton["PlayButton"]->setTexture(&mButtonTexture);
	}

	if (MousePosition.y >= (WindowSize.y * (11.f / 14.f)) && MousePosition.y <= (WindowSize.y * (13.f / 14.f)) && MousePosition.x >= (WindowSize.x / 14.f) && MousePosition.x <= (WindowSize.x * (3.f / 14.f)))
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

void ParamMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto it = mListButton.begin(); it != mListButton.end(); ++it)
		target.draw(*it->second);

	for (auto it = mListText.begin(); it != mListText.end(); ++it)
		target.draw(*it->second);
}