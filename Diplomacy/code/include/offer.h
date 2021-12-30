#ifndef OFFER_H
#define OFFER_H

#include "code/include/player.h"
#include "code/include/Territory.h"

class Offer
{
private:
    Player* p_offering;

    vector<Player*> p_players;

    Territory* p_territory;

    int p_cost;
    bool p_accepted;

public:
    Offer(Player* p1, Territory* t, int gold);
    ~Offer();

    void setCost(int amount);
    int getCost();
    void setAcceped(bool flag);
    bool getAccepted();

    Player* makeAnOffer(Player* p, Territory* t, int gold);
};

#endif // OFFER_H
