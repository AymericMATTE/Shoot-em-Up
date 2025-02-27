#pragma once

#include <SFML/Graphics.hpp>
#include "unordered_map"

class RessourceManager
{
	std::unordered_map<std::string, sf::Texture*> mListTexture;

public :
	RessourceManager();

	sf::Texture* GetTexture(std::string TextureName);

	void AddTexture(std::string);

	~RessourceManager();
};

