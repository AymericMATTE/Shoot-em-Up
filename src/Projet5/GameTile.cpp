#include "GameTile.h"

GameTile::GameTile(sf::Texture& texture, int x, int y, float width, float height) {
    sprite.setPosition(sf::Vector2f(x, y));
    float ScaleX = (float)width / 64.0f;
    float ScaleY = (float)height / 64.0f;
    sprite.setScale(ScaleX, ScaleY);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}

void GameTile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}