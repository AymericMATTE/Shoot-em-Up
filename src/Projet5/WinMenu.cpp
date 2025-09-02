#include "WinMenu.h"
#include "GameManager.h"
#include "Macro.h"

WinMenu::WinMenu() : Menu()
{
	if (!mTexture.loadFromFile(RES_PATH + "VictoryScreen.png"))
		exit(0);
}

void WinMenu::Init()
{
	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	sf::RectangleShape* Wallpaper = new sf::RectangleShape((sf::Vector2f)GameManager::GetInstance()->GetWindow()->getSize());

	Wallpaper->setTexture(&mTexture);

	sf::RectangleShape* QuitButton = new sf::RectangleShape(sf::Vector2f(WindowSize.x / 9, WindowSize.y / 9));

	QuitButton->setTexture(&mButtonTexture);

	QuitButton->setOrigin(QuitButton->getSize().x / 2.f, QuitButton->getSize().y / 2.f);

	sf::Text* QuitText = new sf::Text("QUIT", mFont);

	QuitText->setFillColor(sf::Color(207, 115, 39));

	QuitText->setOrigin(QuitText->getGlobalBounds().getSize().x / 2, QuitText->getGlobalBounds().getSize().y / 2);

	QuitText->setPosition(WindowSize.x / 2, 17 * WindowSize.y / 18);

	QuitButton->setPosition(QuitText->getPosition().x, QuitText->getPosition().y + QuitText->getGlobalBounds().getSize().y / 2);

	mQuitButton = QuitButton;

	mQuitText = QuitText;

	mWallpaper = Wallpaper;
}

void WinMenu::Update()
{
	sf::Vector2i MousePosition = sf::Mouse::getPosition();

	sf::Vector2u WindowSize = GameManager::GetInstance()->GetWindow()->getSize();

	if (MousePosition.y >= (WindowSize.y * (16.f / 18.f)) && MousePosition.y <= WindowSize.y && MousePosition.x >= (4 * WindowSize.x / 9.f) && MousePosition.x <= (WindowSize.x * (5.f / 9.f)))
	{
		mQuitButton->setTexture(&mPressedButtonTexture);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			GameManager::GetInstance()->GetWindow()->close();
	}
	else
	{
		mQuitButton->setTexture(&mButtonTexture);
	}
}

void WinMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*mWallpaper);

	target.draw(*mQuitButton);

	target.draw(*mQuitText);
}