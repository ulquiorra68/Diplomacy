#include "code/include/player.h"

const std::string &Player::name() const
{
    return p_name;
}

void Player::addMove(Territory* start, Territory* end, int moveType)
{
    Move* m = new Move(this, start, end, moveType);
    p_moves.insert(m);
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
    t->SetPlayerBelonging(this);
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

void Player::sumAllTanks()
{
    int tanks = 0;
    for (Territory* terr : p_territories)
        if (terr->IsCapital())
            tanks++;

    setNumOfAllTanks(tanks);
}

int Player::sumAllUsingTanks()
{
    int sum = 0;
    for (Territory* terr : p_territories)
    {
        if (terr->numOfTanks() > 0)
            sum++;
    }

    return sum;
}

bool Player::isArmyMoveAlreadyMade(Territory* clicked)
{
    for (Move* move : p_moves)
    {
        if ( move->getStartTerritory()->GetName() == clicked->GetName())
            return true;
    }

    return false;
}

std::string Player::GetNationalBelongingText()
{
    std::string nation_string;
    switch (p_playerNationality) {
    case Russia:
        nation_string = "Russia";
        break;
    case Turkey:
        nation_string = "Turkey";
        break;
    case Germany:
        nation_string = "Germany";
        break;
    case Austria:
        nation_string = "Austria";
        break;
    case France:
        nation_string = "France";
        break;
    case England:
        nation_string = "England";
        break;
    case Italy:
        nation_string = "Italy";
        break;
    case Neutral:
        nation_string = "Neutral";
    default:
        nation_string = "Unknown National Belonging";
        break;
    }

    return nation_string;
}

std::string Player::GetColorText()
{
    std::string nation_string;
    switch (p_color) {
    case Blue:
        nation_string = "blue";
        break;
    case Red:
        nation_string = "red";
        break;
    case Green:
        nation_string = "green";
        break;
    case White:
        nation_string = "white";
        break;
    case Black:
        nation_string = "black";
        break;
    case Cyan:
        nation_string = "cyan";
        break;
    case Yellow:
        nation_string = "yellow";
        break;
    default:
        nation_string = " ";
        break;
    }

    return nation_string;
}

void Player::resolveNumOfTanks()
{
    sumAllTanks();

    if (!numOfAllTanks == 0)
    {

        int useTanks = sumAllUsingTanks();
        while (useTanks > numOfAllTanks)
        {
            for (Territory* terr : p_territories)
            {
                if (terr->numOfTanks() == 1)
                {
                    terr->decreaseNumOfTanks();
                    useTanks--;
                    break;
                }
            }
        }
    }
}

void Player::performLosing()
{
    for (Territory* terr : p_territories)
    {
        terr->SetPlayerBelonging(nullptr);
        terr->setNumOfTanks();
        terr->decreaseNumOfTanks();
    }
    p_territories.clear();
}

void Player::setWantsToHelp(bool flag)
{
    p_wantsToHelp = flag;
}

std::unordered_set<Territory *> &Player::territories()
{
    return p_territories;
}

void Player::setTerritories(const std::unordered_set<Territory *> &newTerritories)
{
    p_territories = newTerritories;
}

Player::Player(const std::string &name, Color color, bool ownerInd, Nation nation) : p_name(name),
    p_color(color),
    p_ownerInd(ownerInd),
    p_playerNationality(nation)
{
    p_gold = 30;
    p_wantsToAttack = p_wantsToHelp = p_wantsToOffer = false;
    p_territories = std::unordered_set<Territory *>();
}

void Player::initTerritoriesByNation(std::unordered_set<Territory*> territories) {

    for (Territory* terr : territories)
    {
        if (terr->GetNationalBelonging() == p_playerNationality)
        {
            addTerritory(terr);
        }
    }
}

