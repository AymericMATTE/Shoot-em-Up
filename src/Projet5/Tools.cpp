#include "Tools.h"

double VectorToDegreesAngle(sf::Vector2f direction)
{
	double radiansAngle = atan2(direction.x, direction.y);

    double degreesAngle = RadianToDegree(radiansAngle);

	return degreesAngle;
}

sf::Vector2f getVectorFromRadiansAngle(double angleRadians) 
{
    sf::Vector2f vector;

    vector.x = std::cos(angleRadians);
    vector.y = std::sin(angleRadians);

    return vector;
}

sf::Vector2f getVectorFromDegreesAngle(double degreesRadians) 
{
    double angleRadians = DegreeToRadian(degreesRadians);

    return getVectorFromRadiansAngle(angleRadians);
}

double DegreeToRadian(double DegreesAngle)
{

    double RadiansAngle = DegreesAngle * (3.14f / 180);

    return RadiansAngle;
}

double RadianToDegree(double RadiansAngle)
{

    double DegreesAngle = RadiansAngle * (180 / 3.14f);
    
    return DegreesAngle;
}

void CheckAngle(double& angle)
{
    if (angle < 0)
        angle += 360;

    if (angle > 360)
        angle -= 360;
}

int GetNorm(sf::Vector2f position1, sf::Vector2f position2)
{
    sf::Vector2f vector = sf::Vector2f (position1.x - position2.x, position1.y - position2.y);

    int norm = sqrt(powf(vector.x, 2.f) + powf(vector.y,2.f));

    return norm;
}

sf::Vector2f GetNormalisedVector(sf::Vector2f vector)
{
    double angle = VectorToDegreesAngle(vector);

    sf::Vector2f normalisedVector = getVectorFromDegreesAngle(angle);

    return normalisedVector;
}