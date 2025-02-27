#ifndef GAMETILE_H
#define GAMETILE_H

#include <SFML/Graphics.hpp>

class GameTile : public sf::Drawable {
private:
    sf::Sprite sprite;

public:

    GameTile(sf::Texture& texture, int x,int y, float, float);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
