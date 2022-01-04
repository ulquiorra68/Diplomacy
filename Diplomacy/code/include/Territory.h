#ifndef TERRITORY_H
#define TERRITORY_H

#include <iostream>
#include "code/include/player.h"
#include "code/include/Color.h"
#include "code/include/Nation.h"
#include<string>
#include<vector>

using namespace std;
class Player;

class Territory {

public:
	Territory() {};
	Territory(string name, Nation nation, double x = 1, double y = 1, bool isCapital = false);
	~Territory();

	//getters & setters
	string GetName() { return m_TerritoryName; }
	Player* GetPlayerBelonging() { return m_TerritoryPlayerBelonging; }
	void SetPlayerBelonging(Player* player) { m_TerritoryPlayerBelonging = player; }
	Nation GetNationalBelonging() { return m_TerritoryNationalBelonging; }
	bool IsCapital() { return m_CapitalFlag; }
	int numOfTanks() { return numOfTanksOn; }
	void decreaseNumOfTanks() { numOfTanksOn--; }
	void increaseNumOfTanks() { numOfTanksOn++; }

	void DrawCircle();

	void AddBorders(vector<Territory*> territorries);
	string GetNationalBelongingText();
	//void PrintTerritoryInfos();  // NOTE: test method

private:
	//non changeable initial territory attributes
	string m_TerritoryName;
	Nation m_TerritoryNationalBelonging;
	bool m_CapitalFlag = false;
	double m_PositionX = 0;
	double m_PositionY = 0;
	vector<Territory*> m_Borders;
	int numOfTanksOn = 0;

	//changeable ingame territory attributes
	Player* m_TerritoryPlayerBelonging = nullptr;


};

#endif