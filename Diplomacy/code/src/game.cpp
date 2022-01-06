#include "code/include/game.h"
#include <fstream>
#include <iostream>


using namespace std;

void Game::start(vector<QPushButton*> buttons)
{
    initTerritories();
    initBordersAndCapitals();
    for (Territory* terr : p_territories)
    {
        QPushButton* pb = buttons.back();
        terr->SetButton(pb);
        buttons.pop_back();
    }

    for (Player* player : p_players)
    {
        player->initTerritoriesByNation(p_territories);
    }

    p_counter = 0;

    if (!p_players.empty())
        setCurrPlayer(p_players[0]);

    setInitialTanks();
    setTerritoriesColor();
    reDrawButtonsText();
    
}

void Game::reDrawButtonsText() {
    for (Territory* terr : p_territories)
    {
        terr->reDrawButtonText();
    }

}


void Game::setTerritoriesColor() {

    for (Territory* terr : p_territories)
    {
        Color col = Gray;
        if(terr->GetPlayerBelonging())
         col = terr->GetPlayerBelonging()->color();
  
        terr->setButtonColor(col);
    }


}

void Game::end(Player *p)
{

}

void Game::playMove(Player *p)
{

}

void Game::setInitialTanks() {
    
    for (Territory* terr : p_territories)
    {
        if (terr->IsCapital())
            terr->setNumOfTanks();
    }
}   

void Game::countPlayerTanks() {

    for (Player* player : p_players)
        player->sumAllTanks();
}

QVector<Player*> Game::players()
{
    return p_players;
}
/*
unordered_set<Territory*> Game::territories()
{
    return p_territories;
}*/

Player* Game::currPlayer()
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

void Game::initTerritories()
{
    fstream territoriesFile;
    territoriesFile.open("territories_position.txt", ios::in);
    
    if (!territoriesFile) {
        cout << "No such file";
    }
    else {
        string name;
        int x, y;
        for (int i = 0; i < 57; i++)
        {
            territoriesFile >> name;
            territoriesFile >> x;
            territoriesFile >> y;

            Territory* terr;
            terr = new Territory(name, x, y);
            p_territories.insert(terr);
        }
    }
    
    territoriesFile.close();
}

void Game::initBordersAndCapitals()
{
    fstream territoriesFile;
    territoriesFile.open("territories_list.txt", ios::in);

    if (!territoriesFile) {
        cout << "No such file";
    }
    else {
        string name, nationStr, isCapitalStr, border;
        Nation nation;
        int numOfBorders;
        for (int i = 0; i < 57; i++)
        {
            territoriesFile >> name;
            territoriesFile >> nationStr;
            territoriesFile >> isCapitalStr;
            territoriesFile >> numOfBorders;
            bool isCapit = isCapitalStr == "true" ? true : false;

            vector<Territory*> borders;
            for(int j = 0; j < numOfBorders; j++)
            {
                string borderName;
                territoriesFile >> borderName;
                
                for (Territory* terr : p_territories)
                {
                    if (terr->GetName() == borderName)
                    {
                        borders.push_back(terr);
                        break;
                    }
                }
            }

            for (Territory* terr : p_territories)
            {
                if (terr->GetName() == name)
                {
                    terr->SetNationalBelonging(nationStr);
                    terr->SetCapital(isCapit);
                    terr->SetBorders(borders);
                }
            }
        }
    }

    territoriesFile.close();
}

int Game::getCounter()
{
    return p_counter;
}

void Game::setCounter(int value)
{
    p_counter = value;
}

void Game::resolveWars()
{
    
    for (Player* player : p_players)
    {
        for (Move* move : player->getPlayerMoves())
        {
            //first do all repositioning moves
            if (move->getType() == 3)
            {
                move->getStartTerritory()->decreaseNumOfTanks();
                move->getEndTerritory()->increaseNumOfTanks();
            }
            else
            //second help moves
            if (move->getType() == 2)
            {
                if (!isUnderAttack(move->getStartTerritory()))
                {
                    move->getStartTerritory()->decreaseNumOfTanks();
                    move->getEndTerritory()->increaseNumOfTanks();
                }
            }
            else
            //then attack moves
            if (move->getType() == 1)
            {
                if (!isUnderAttack(move->getStartTerritory()))
                {
                    int numOfAttacks = numOfAttackers(move->getEndTerritory());
                  
                      if (move->getEndTerritory()->numOfTanks() < numOfAttacks)
                      {
                         // move->getStartTerritory()->decreaseNumOfTanks();
                          move->getEndTerritory()->setNumOfTanks();
                          move->getEndTerritory()->SetPlayerBelonging(move->getPlayer());
                      }
                }  
            }
            
            //after attacks, return tanks back from help
            if (move->getType() == 2)
            {
                move->getStartTerritory()->setNumOfTanks();
                move->getEndTerritory()->decreaseNumOfTanks();
            }


        }
    }

    setTerritoriesColor();
    reDrawButtonsText();

    for (Player* p : p_players)
        p->removeAllMoves();
}

bool Game::isUnderAttack(Territory* terr)
{
    for (Player* player : p_players)
    {
        for (Move* move : player->getPlayerMoves())
        {
            if (move->getType() == 1 && move->getEndTerritory() == terr)
                return true;
        }
    }
    return false;
}

int Game::numOfAttackers(Territory* terr)
{
    int count = 0;
    for (Player* player : p_players)
    {
        for (Move* move : player->getPlayerMoves())
        {
            if (move->getType() == 1 && move->getEndTerritory() == terr && !isUnderAttack(move->getStartTerritory()))
                count++;
        }
    }

    return count;
}