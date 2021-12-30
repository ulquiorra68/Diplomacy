#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<vector>
#include<unordered_set>

#include "code/include/Color.h"
#include "code/include/Territory.h"

class Player
{
private:
    std::string p_name;
    Color p_color;
    bool p_ownerInd;

    int p_gold;
    int numOfAllTanks;

    bool p_wantsToAttack;
    bool p_wantsToOffer;
    bool p_wantsToHelp;

    std::unordered_set<Territory*> p_territories;

public:
    Player();
    Player(const std::string &name, Color color, bool ownerInd);
    ~Player();

    const std::string &name() const;

    void addTerritory(Territory* t);
    void removeTerritory(Territory* t);

    void setName(const std::string &newName);

    Color color() const;
    void setColor(Color newColor);

    std::int32_t numOfTerritories() const;

    bool ownerInd() const;
    void setOwnerInd(bool newOwnerInd);

    void setGold(int numOfGold);
    int getGold();
    void increaseGold(int amount);
    void decreaseGold(int amount);

    int getNumOfAllTanks();

    bool wantsToAttack();
    void setWantsToAttack(bool flag);

    bool wantsToOffer();
    void setWantsToOffer(bool flag);

    bool wantsToHelp();
    void setWantsToHelp(bool flag);

    const std::unordered_set<Territory *> &territories() const;
    void setTerritories(const std::unordered_set<Territory *> &newTerritories);

    void sumAllTanks(unordered_set<Territory *>);
};

#endif // PLAYER_H
