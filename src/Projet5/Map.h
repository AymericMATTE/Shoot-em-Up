#pragma once

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTile.h"

class Map : public sf::Drawable{
private:
    sf::RectangleShape mMap;
    sf::Texture Ground;
    sf::Texture Ground2;
    sf::Texture CrackedGround;
    sf::Texture CrackedGround2;
    sf::Texture Road;
    sf::Texture Road2;
    sf::Texture AllWays;
    sf::Texture Intersection;
    sf::Texture Intersection2;
    sf::Texture Intersection3;
    sf::Texture Intersection4;
    sf::Texture PathIntersection;
    sf::Texture PathIntersection2;
    sf::Texture PathIntersection3;
    sf::Texture PathIntersection4;
    sf::Texture RoadTurn;
    sf::Texture RoadTurn2;
    sf::Texture RoadTurn3;
    sf::Texture RoadTurn4;
    float screenWidth, screenHeight;
    std::vector<GameTile> tiles;

public:
    Map(float, float);

    void loadTextures();
    void loadMap(const std::vector<std::vector<int>>& mapData); 
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif