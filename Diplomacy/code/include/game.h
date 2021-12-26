#ifndef GAME_H
#define GAME_H

#include<vector>
#include<unordered_set>

#include "Territory.h"
#include "player.h"

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

    bool playMove(Player* p);
    void addTanksToTerritory(Territory* t, int num);
    void attack(Territory* att, Territory* def);
    void help(Player* helper, Player* seeker);
    void moveTanks(int num, Territory* fstTerritory, Territory* sndTerritory);

    const vector<Player*> &players() const;
    const unordered_set<Territory*> &territories() const;

    Player* currPlayer() const;
    void setCurrPlayer(Player* newCurrPlayer);
};

#endif // GAME_H
