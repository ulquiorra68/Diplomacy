#ifndef OFFER_H
#define OFFER_H

#include "code/include/player.h"
#include "code/include/Territory.h"

class Offer
{
private:
    Player* p;
    int p_cost;
public:
    Offer(Player* p1, Player* p2);
    ~Offer();

    bool makeAnOffer(Player* p1, Player* p2, Territory t, int gold);
};

#endif // OFFER_H
