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
    QVector<Player*> p_players;
    std::unordered_set<Territory*> p_territories;
    Player* p_currPlayer;
    int p_counter;


public:
    Game() {};
    Game(const std::vector<Player*> &players, const std::vector<Territory*> &territories);
    ~Game();

    void start(std::vector<QPushButton*> buttons);
    void reDrawButtonsText();
    void setTerritoriesColor();
    void end(Player* p);
    std::unordered_set<Territory*> getTerritories() { return p_territories; };

    void playMove(Player* p);
    void attack(Territory* att, Territory* def);
    void help(Player* helper, Player* seeker, Offer* offer);
    void moveTanks(Territory* fstTerritory, Territory* sndTerritory);
    void initTerritories();
    void initBordersAndCapitals();
    void setInitialTanks();
    void countPlayerTanks();
    int getCounter();
    void setCounter(int value);
    void setPlayers(QVector<Player*> players) { p_players = players; };
    void resolveWars();

    bool isUnderAttack(Territory* terr);

    int numOfAttackers(Territory* terr);

    QVector<Player*> players();
   // unordered_set<Territory*> territories;

    Player* currPlayer();
    void setCurrPlayer(Player* newCurrPlayer);
};

#endif // GAME_H
