#include "code/include/player.h"

const std::string &Player::name() const
{
    return p_name;
}

void Player::setName(const std::string &newName)
{
    p_name = newName;
}

Color Player::color() const
{
    return p_color;
}

void Player::setColor(Color newColor)
{
    p_color = newColor;
}

bool Player::ownerInd() const
{
    return p_ownerInd;
}

void Player::setOwnerInd(bool newOwnerInd)
{
    p_ownerInd = newOwnerInd;
}


//void Player::addTerritory(Territory *t)
//{
//    p_territories.insert(t);
//}

//void Player::removeTerritory(Territory *t)
//{
//    auto wanted = p_territories.find(t);
//    p_territories.erase(wanted);
//}

//std::int32_t Player::numOfTerritories() const
//{
//    return p_territories.size();
//}

//const std::unordered_set<Territory *> &Player::territories() const
//{
//    return p_territories;
//}

//void Player::setTerritories(const std::unordered_set<Territory *> &newTerritories)
//{
//    p_territories = newTerritories;
//}
