#include "Character.h"

Character::Character(sf::Texture texture, int HP, float speed) : Entity(texture)
{
    mHP = HP;
    mMaxHP = HP;
    mSpeed = speed;
}

Character::Character(std::string filepath, int HP, float speed) : Entity(filepath)
{
    mHP = HP;
    mMaxHP = HP;
    mSpeed = speed;
}

bool Character::IsAlive()
{
    if (mHP <= 0)
        return false;

    return true;
}
