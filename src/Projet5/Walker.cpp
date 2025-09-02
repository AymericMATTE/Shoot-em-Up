#include "Walker.h"
#include "Bullet.h"
#include "Gadget.h"
#include "Player.h"
#include "Macro.h"

Walker::Walker(sf::Vector2f position,Gadget* Itemdrop) : Enemy(RES_PATH + "Walker.png", 150, 200.f, Itemdrop)
{
	setPosition(position);
}

Walker::Walker(float x, float y, Gadget* Itemdrop) : Enemy(RES_PATH + "Walker.png", 150, 200.f, Itemdrop)
{
	setPosition(x,y);
}

void Walker::Collide(Bullet* collider)
{
	LifeChange((collider->GetDamage()));
}

void Walker::UpdateEnemy(float ElapsedTime, Player* pPlayer)
{
	sf::Vector2f playerPosition = pPlayer->getPosition();

	sf::Vector2f vector = playerPosition - getPosition();

	double angle = 90 - VectorToDegreesAngle(vector);

	sf::Vector2f direction = getVectorFromDegreesAngle(angle);

	move(direction.x * mSpeed * ElapsedTime, direction.y * mSpeed * ElapsedTime);
}


void Walker::LifeChange(int amount)
{
	mHP -= amount;
}
