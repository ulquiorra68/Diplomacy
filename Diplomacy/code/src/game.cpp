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

   // setTestPlayers();
    for (int i = 1; i <= 5; i++)
    {
        string pname = "Player_" + to_string(i);
        Player *p = new Player(pname, Yellow, true, Russia);
        p->initTerritoriesByNation(p_territories);
        p_players.push_back(p);
    }



    if (!p_players.empty())
        setCurrPlayer(p_players[0]);

    setInitialTanks();
    
}

void Game::end(Player *p)
{

}

void Game::playMove(Player *p)
{

}

void Game::setInitialTanks() {
    
    if (!playerSetTanks(currPlayer()))
    {
        string out;
        out = "Set init tanks player: " + currPlayer()->name() + "/n";    
        out += ".";
    } 
}   

bool Game::playerSetTanks(Player* player)
{
    if (player->getNumOfInitTanksLeft() == 0)
        return true;
    
    return false;
}

vector<Player*> Game::players()
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
