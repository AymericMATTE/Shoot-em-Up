#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "States.h"

class Scene;
class Menu;

class GameManager
{
	static GameManager* mInstance;

	std::vector<Scene*> mListLevel;

	std::unordered_map<std::string, Menu*> mListMenu;

	sf::RenderWindow mWindow;

	int ActualLevel;

	States GameStates;

	States PreviousGameStates;

public:
	GameManager();

	static GameManager* GetInstance();

	void Init();

	void Update(sf::Event event);

	void Display();

	void ChangeScene();

	sf::RenderWindow* GetWindow();

	void Run();

	void AddScene(Scene* Level);

	void ChangeGameStates(States NewGameState);

	States GetPreviousGameState();

	void RestartScene();

	Scene* GetScene();
};




