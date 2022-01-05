#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<vector>
#include<unordered_set>

#include "code/include/Color.h"
#include "code/include/Nation.h"
#include "code/include/Territory.h"

class Territory;

class Player
{
private:
    std::string p_name;
    Color p_color;
    bool p_ownerInd;
    Nation p_playerNationality;

    int p_gold;
    int numOfAllTanks;
    int numOfInitTanks;

    bool p_wantsToAttack;
    bool p_wantsToOffer;
    bool p_wantsToHelp;

    std::unordered_set <Territory*> p_territories;

public:
    Player() {};
    Player(const std::string &name, Color color, bool ownerInd, Nation nation);
    ~Player();

    const std::string &name() const;

    void addTerritory(Territory* t);
    void removeTerritory(Territory* t);

    void setName(const std::string &newName);

    void setNation(Nation nation) { p_playerNationality = nation; };
    Nation getNation() { return p_playerNationality; };

    int getNumOfInitTanksLeft() { return numOfInitTanks; };
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

    std::unordered_set<Territory *> &territories();
    void setTerritories(const std::unordered_set<Territory *> &newTerritories);

    void sumAllTanks(std::unordered_set<Territory*>);
    
    void initTerritoriesByNation(std::unordered_set<Territory*> territories);
};

#endif // PLAYER_H
