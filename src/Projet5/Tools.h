#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

double VectorToDegreesAngle(sf::Vector2f direction);

sf::Vector2f getVectorFromRadiansAngle(double angleRadians);

sf::Vector2f getVectorFromDegreesAngle(double degreesRadians);

double DegreeToRadian(double DegreesAngle);

double RadianToDegree(double RadiansAngle);

void CheckAngle(double& angle);

int GetNorm(sf::Vector2f vector1, sf::Vector2f vector2);

sf::Vector2f GetNormalisedVector(sf::Vector2f);