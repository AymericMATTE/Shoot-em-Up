#include "RessourceManager.h"

RessourceManager::RessourceManager()
{
}

sf::Texture* RessourceManager::GetTexture(std::string TextureName)
{
    return mListTexture[TextureName];
}

void RessourceManager::AddTexture(std::string name)
{
    sf::Texture* Texture = new sf::Texture;

    std::string filepath = std::string("../../../res/" + name + ".png");

    if (!Texture->loadFromFile(filepath))
        exit(0);

    mListTexture.insert({ name, Texture });
}

RessourceManager::~RessourceManager()
{
    for (auto it = mListTexture.begin(); it != mListTexture.end(); ++it)
    {
        delete it->second;
        mListTexture.erase(it);
    }
}
