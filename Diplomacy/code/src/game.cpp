#include "code/include/game.h"

void Game::start()
{

}

void Game::end(Player *p)
{

}

bool Game::playMove(Player *p)
{

}

void Game::addTanksToTerritory(Territory* t, int num)
{

}

const vector<Player*> &Game::players() const
{
    return p_players;
}

const unordered_set<Territory*> &Game::territories() const
{
    return p_territories;
}

Player* Game::currPlayer() const
{
    return p_currPlayer;
}

void Game::setCurrPlayer(Player* newCurrPlayer)
{
    p_currPlayer = newCurrPlayer;
}
