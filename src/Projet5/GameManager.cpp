#include "GameManager.h"
#include "Scene.h"
#include "Map.h"

#include "Menu.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "GameOverMenu.h"
#include "ParamMenu.h"
#include "PrePlayMenu.h"
#include "WinMenu.h"

#include "Level1.h"
#include "Level2.h"

GameManager* GameManager::mInstance = nullptr;

GameManager::GameManager()
{
	ActualLevel = 0;
	sf::VideoMode mode = sf::VideoMode::getDesktopMode();
	mWindow.create(mode, "enêtre", sf::Style::Fullscreen);

	GameStates = RunMainMenu;

	mListMenu.insert({ "MainMenu", new MainMenu()});
	mListMenu.insert({ "PauseMenu", new PauseMenu()});
	mListMenu.insert({ "GameOverMenu", new GameOverMenu()});
	mListMenu.insert({ "ParamMenu", new ParamMenu()});
	mListMenu.insert({ "PrePlayMenu", new PrePlayMenu() });
	mListMenu.insert({ "WinMenu", new WinMenu() });
}

GameManager* GameManager::GetInstance()
{
	if (mInstance == nullptr)
		mInstance = new GameManager();

	return mInstance;
}

void GameManager::Init()
{
	for (auto it = mListMenu.begin(); it != mListMenu.end(); ++it)
		it->second->Init();

	AddScene(new Level1());
	AddScene(new Level2());

	mListLevel[ActualLevel]->InitScene();
}

void GameManager::Update(sf::Event event)
{
	if (event.type == sf::Event::Closed)
		mWindow.close();

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && (GameStates == RunLevel))
		ChangeGameStates(RunPauseMenu);
}

void GameManager::Display()
{
	mWindow.clear(sf::Color::Black);

	switch(GameStates)
	{
	case RunLevel :
		mWindow.draw(*mListLevel[ActualLevel]);
		break;

	case RunMainMenu :
		mWindow.draw(*mListMenu["MainMenu"]);
		break;

	case RunPauseMenu :
		mWindow.draw(*mListLevel[ActualLevel]);
		mWindow.draw(*mListMenu["PauseMenu"]);
		break;

	case RunGameOverMenu :
		mWindow.draw(*mListLevel[ActualLevel]);
		mWindow.draw(*mListMenu["GameOverMenu"]);
		break;

	case RunParamMenu :
		mWindow.draw(*mListMenu["ParamMenu"]);
		break;

	case RunPrePlayMenu :
		mWindow.draw(*mListMenu["PrePlayMenu"]);
		break;
	case RunWinMenu :
		mWindow.draw(*mListMenu["WinMenu"]);
		break;
	}

	mWindow.display();
}

void GameManager::ChangeScene()
{
	if (ActualLevel + 1 < mListLevel.size())
	{
		ActualLevel++;
		GameStates = RunPrePlayMenu;
	}

	else
		GameStates = RunWinMenu;
}

sf::RenderWindow* GameManager::GetWindow()
{
	return &mWindow;
}

void GameManager::Run()
{
	Init();

	sf::RenderWindow* pWindow = GetWindow();

	while (pWindow->isOpen())
	{
		sf::Event event;

		while (pWindow->pollEvent(event))
		{
			Update(event);
		}

		switch(GameStates)
		{
		case RunLevel :
			mListLevel[ActualLevel]->Update();
			break;

		case RunPauseMenu: 
			mListMenu["PauseMenu"]->Update();
			mListLevel[ActualLevel]->RestartClock();
			break;

		case RunParamMenu :
			mListMenu["ParamMenu"]->Update();
			break;

		case RunGameOverMenu :
			mListMenu["GameOverMenu"]->Update();
			mListLevel[ActualLevel]->RestartClock();
			break;

		case RunMainMenu :
			mListMenu["MainMenu"]->Update();
			mListLevel[ActualLevel]->RestartClock();
			break;

		case RunPrePlayMenu :
			mListMenu["PrePlayMenu"]->Update();
			mListLevel[ActualLevel]->RestartClock();
			break;
		case RunWinMenu :
			mListMenu["WinMenu"]->Update();
			break;
		}

		Display();
	}
}

void GameManager::AddScene(Scene* Level)
{
	mListLevel.push_back(Level);
}

void GameManager::ChangeGameStates(States NewGameState)
{
	PreviousGameStates = GameStates;
	GameStates = NewGameState;
}

States GameManager::GetPreviousGameState()
{
	return PreviousGameStates;
}

void GameManager::RestartScene()
{
	delete mListLevel[ActualLevel];

	switch (ActualLevel)
	{
	case 0 :
		mListLevel[ActualLevel] = new Level1();
		break;
	case 1 :
		mListLevel[ActualLevel] = new Level2();
		break;
	}

	GameStates = RunPrePlayMenu;
}

Scene* GameManager::GetScene()
{
	return mListLevel[ActualLevel];
}
