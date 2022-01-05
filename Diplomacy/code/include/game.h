#ifndef GAME_H
#define GAME_H

#include<vector>
#include<unordered_set>

//#include "code/include/Territory.h"
#include "code/include/player.h"
#include "code/include/offer.h"

class Game
{
private:
    std::vector<Player*> p_players;
    std::unordered_set<Territory*> p_territories;
    Player* p_currPlayer;

public:
    Game() {};
    Game(const std::vector<Player*> &players, const std::vector<Territory*> &territories);
    ~Game();

    void start(std::vector<QPushButton*> buttons);
    void end(Player* p);

    void playMove(Player* p);
    void attack(Territory* att, Territory* def);
    void help(Player* helper, Player* seeker, Offer* offer);
    void moveTanks(Territory* fstTerritory, Territory* sndTerritory);
    void initTerritories();
    void initBordersAndCapitals();
    void setInitialTanks();
    bool playerSetTanks(Player* player);

    std::vector<Player*> players();
   // unordered_set<Territory*> territories;

    Player* currPlayer();
    void setCurrPlayer(Player* newCurrPlayer);
};

#endif // GAME_H
