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


void Player::addTerritory(Territory *t)
{
    p_territories.insert(t);
}

void Player::removeTerritory(Territory *t)
{
    auto wanted = p_territories.find(t);
    p_territories.erase(wanted);
}

std::int32_t Player::numOfTerritories() const
{
    return p_territories.size();
}

void Player::setGold(int numOfGold)
{
    p_gold = numOfGold;
}

int Player::getGold()
{
    return p_gold;
}

void Player::increaseGold(int amount)
{
    p_gold += amount;
}

void Player::decreaseGold(int amount)
{
    p_gold -= amount;
}

bool Player::wantsToAttack()
{
    return p_wantsToAttack;
}

void Player::setWantsToAttack(bool flag)
{
    p_wantsToAttack = flag;
}

bool Player::wantsToOffer()
{
    return p_wantsToOffer;
}

void Player::setWantsToOffer(bool flag)
{
    p_wantsToOffer = flag;
}

bool Player::wantsToHelp()
{
    return p_wantsToHelp;
}

void Player::setWantsToHelp(bool flag)
{
    p_wantsToHelp = flag;
}

const std::unordered_set<Territory *> &Player::territories() const
{
    return p_territories;
}

void Player::setTerritories(const std::unordered_set<Territory *> &newTerritories)
{
    p_territories = newTerritories;
}

Player::Player(const string &name, Color color, bool ownerInd) : p_name(name),
    p_color(color),
    p_ownerInd(ownerInd)
{
    p_gold = 30;
    p_wantsToAttack = p_wantsToHelp = p_wantsToOffer = false;
    p_territories = unordered_set<Territory *>();
}
