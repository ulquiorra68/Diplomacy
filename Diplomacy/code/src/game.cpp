#include "code/include/game.h"

void Game::start()
{

}

void Game::end(Player *p)
{

}

void Game::playMove(Player *p)
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

void attack(Territory* att, Territory* def)
{
    int numOfAttackerTanks = att->numOfTanks();
    int numOfDefenderTanks = def->numOfTanks();

    Player* attacker = att->GetPlayerBelonging();
    Player* defender = def->GetPlayerBelonging();

    if(numOfAttackerTanks > numOfDefenderTanks)
    {
       // att->increaseNumOfTanks(numOfDefenderTanks);
       // def->setNumOfTanks(0);

        def->SetPlayerBelonging(attacker);

        attacker->addTerritory(def);
     //   attacker->increaseGold(defender->getGold());
     //   defender->setGold(0);
    }
    else if (numOfAttackerTanks == numOfDefenderTanks)
    {
      //  int goldPenalty = (int)attacker->getGold()/100*10;
        //int tanksPenalty = (int)attacker->numOfTanks()/100*10;

//        attacker->decreaseGold(goldPenalty);
  //      attacker->decreaseNumOfTanks(tanksPenalty);
    }
    else
    {
        //def->increaseNumOfTanks(numOfAttackerTanks);
      //  att->setNumOfTanks(0);

    //    att->setPlayerBelonging(defender);

     //   defender->addTerritory(att);
     //   defender->increaseGold(attacker->getGold());
     //   attacker->setGold(0);
    }
}

void Game::help(Player* helper, Player* seeker, Offer* offer)
{
   // seeker->increaseNumOfTanks(helper->numOfTanks());
    //seeker->decreaseGold(offer->getCost());
   // helper->increaseGold(offer->getCost());
}

void Game::moveTanks(Territory* from, Territory* to)
{
    from->decreaseNumOfTanks();
    to->increaseNumOfTanks();
}
