#include "code/include/offer.h"

void Offer::setCost(int amount)
{
    p_cost = amount;
}

int Offer::getCost()
{
    return p_cost;
}

void Offer::setAcceped(bool flag)
{
    p_accepted = flag;
}

bool Offer::getAccepted()
{
    return p_accepted;
}

Offer::Offer(Player* offering, Territory* territory, int gold) : p_offering(offering),
    p_territory(territory),
    p_cost(gold)
{
    p_accepted = false;
    p_players = vector<Player *>();
}

Player* Offer::makeAnOffer(Player *p, Territory *t, int gold)
{
    if (p_players.size() == 0)
    {
        p_accepted = false;
        return nullptr;
    }
    else if (p_players.size() == 1)
    {
        p_accepted = true;
        return p_players[0];
    }
    else
    {
        int maxTanks = 0;
        Player* helper = nullptr;

        for (auto it = p_players.begin(); it != p_players.end(); it++)
        {
            if ((*it)->getNumOfAllTanks() > maxTanks)
            {
                helper = (*it);
                maxTanks = (*it)->getNumOfAllTanks();
            }
        }

        p_accepted = true;
        return helper;
    }
}
