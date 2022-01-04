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
    vector<Player*> p_players;
    unordered_set<Territory*> p_territories;
    Player* p_currPlayer;

public:
    Game();
    Game(const vector<Player*> &players, const vector<Territory*> &territories);
    ~Game();

    void start();
    void end(Player* p);

    void playMove(Player* p);
    void attack(Territory* att, Territory* def);
    void help(Player* helper, Player* seeker, Offer* offer);
    void moveTanks(Territory* fstTerritory, Territory* sndTerritory);

    const vector<Player*> &players() const;
    const unordered_set<Territory*> &territories() const;

    Player* currPlayer() const;
    void setCurrPlayer(Player* newCurrPlayer);
};

#endif // GAME_H
