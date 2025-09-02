#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Macro.h"

Map::Map(float width, float height) {
    mMap.setPosition(sf::Vector2f(0,0));
    screenWidth = width;
    screenHeight = height;
    mMap.setSize(sf::Vector2f(width, height));
}

void Map::loadTextures() {
    if (!Ground.loadFromFile(RES_PATH + "Map/Ground.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture Ground.png");
    }
    if (!Ground2.loadFromFile(RES_PATH + "Map/Ground2.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture Ground2.png");
    }
    if (!Road.loadFromFile(RES_PATH + "Map/Road.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture Road.png");
    }
    if (!Road2.loadFromFile(RES_PATH + "Map/Road2.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture Road2.png");
    }
    if (!PathIntersection.loadFromFile(RES_PATH + "Map/PathIntersection.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture PathIntersection.png");
    }
    if (!PathIntersection2.loadFromFile(RES_PATH + "Map/PathIntersection2.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture PathIntersection2.png");
    } 
    if (!PathIntersection3.loadFromFile(RES_PATH + "Map/PathIntersection3.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture PathIntersection3.png");
    }
    if (!PathIntersection4.loadFromFile(RES_PATH + "Map/PathIntersection4.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture PathIntersection4.png");
    }
    if (!Intersection.loadFromFile(RES_PATH + "Map/Intersection.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture Intersection.png");
    }
    if (!Intersection2.loadFromFile(RES_PATH + "Map/Intersection2.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture Intersection2.png");
    }
    if (!Intersection3.loadFromFile(RES_PATH + "Map/Intersection3.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture Intersection3.png");
    }
    if (!Intersection4.loadFromFile(RES_PATH + "Map/Intersection4.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture Intersection4.png");
    }
    if (!AllWays.loadFromFile(RES_PATH + "Map/AllWays.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture AllWays.png");
    }
    if (!RoadTurn.loadFromFile(RES_PATH + "Map/RoadTurn.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture RoadTurn.png");
    }
    if (!RoadTurn2.loadFromFile(RES_PATH + "Map/RoadTurn2.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture RoadTurn2.png");
    }
    if (!RoadTurn3.loadFromFile(RES_PATH + "Map/RoadTurn3.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture RoadTurn3.png");
    }
    if (!RoadTurn4.loadFromFile(RES_PATH + "Map/RoadTurn4.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture RoadTurn4.png");
    }
    if (!CrackedGround.loadFromFile(RES_PATH + "Map/CrackedGround.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture CrackedGround.png");
    }
    if (!CrackedGround2.loadFromFile(RES_PATH + "Map/CrackedGround2.png")) {
        throw std::runtime_error("Erreur : impossible de charger la texture CrackedGround2.png");
    }
}

void Map::loadMap(const std::vector<std::vector<int>>& mapData) {
    float tileWidth = screenWidth / 15;
    float tileHeight = screenHeight / 8;
    int posY = 0;
    for (int j = 0; j < 8; ++j) { 
        int posX = 0; 
        for (int i = 0; i < 15; ++i) {  
            sf::Texture* texture = nullptr;
            if (mapData[j][i] == 0) { 
                texture = &Ground;
            }
            else if (mapData[j][i] == 1) {
                texture = &Ground2;
            }   
            else if (mapData[j][i] == 2) {
                texture = &Road;
            }
            else if (mapData[j][i] == 3) {
                texture = &Road2;
            }
            else if (mapData[j][i] == 4) {
                texture = &PathIntersection;
            }
            else if (mapData[j][i] == 5) {
                texture = &PathIntersection2;
            }
            else if (mapData[j][i] == 6) {
                texture = &PathIntersection3;
            }
            else if (mapData[j][i] == 7) {
                texture = &PathIntersection4;
            }
            else if (mapData[j][i] == 8) {
                texture = &Intersection;
            }
            else if (mapData[j][i] == 9) {
                texture = &Intersection2;
            }
            else if (mapData[j][i] == 10) {
                texture = &Intersection3;
            }
            else if (mapData[j][i] == 11) {
                texture = &Intersection4;
            }
            else if (mapData[j][i] == 12) {
                texture = &AllWays;
            }
            else if (mapData[j][i] == 13) {
                texture = &RoadTurn;
            }
            else if (mapData[j][i] == 14) {
                texture = &RoadTurn2;
            }
            else if (mapData[j][i] == 15) {
                texture = &RoadTurn3;
            }
            else if (mapData[j][i] == 16) {
                texture = &RoadTurn4;
            }
            else if (mapData[j][i] == 17) {
                texture = &CrackedGround;
            }
            else if (mapData[j][i] == 18) {
                texture = &CrackedGround2;
            }
            GameTile tile(*texture, posX, posY,tileWidth,tileHeight);
            tiles.push_back(tile);
            posX += tileWidth;
        }
        posY += tileHeight;
    }
}



void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& tile : tiles) {
        target.draw(tile);
    }
    //target.draw(mMap, states);
}
