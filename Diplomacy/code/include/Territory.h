#ifndef TERRITORY_H
#define TERRITORY_H

#include <iostream>
#include "code/include/player.h"
#include "code/include/Color.h"
#include "code/include/Nation.h"
#include<string>
#include<vector>
#include <QPushButton>

//using namespace std;
class Player;

class Territory {

public:
	Territory() {};
	Territory(std::string name, std::string nation, int x = 1, int y = 1, bool isCapital = false);
	Territory(std::string name, int x, int y/*, QPushButton* pushButton*/);
	~Territory();

	//getters & setters
	std::string GetName() { return m_TerritoryName; }
	Player* GetPlayerBelonging() { return m_TerritoryPlayerBelonging; }
	void SetPlayerBelonging(Player* player) { m_TerritoryPlayerBelonging = player; }
	Nation GetNationalBelonging() { return m_TerritoryNationalBelonging; }
	void SetNationalBelonging(std::string nation) { m_TerritoryNationalBelonging = GetNationFromText(nation); }
	bool IsCapital() { return m_CapitalFlag; }
	void SetCapital(bool isCap) { m_CapitalFlag = isCap; }
	void SetBorders(std::vector<Territory*> terr) { m_Borders = terr; }
	std::vector<Territory*> GetBorders() { return m_Borders; };
	void SetButton(QPushButton* pushButton);
	int getXpos() { return m_PositionX; };
	int getYpos() { return m_PositionY; };
	void setButtonColor(Color color);
	std::string GetStringColor(Color color);

	int numOfTanks() { return numOfTanksOn; }
	void setNumOfTanks() { numOfTanksOn = 1; }
	void decreaseNumOfTanks() { numOfTanksOn--; }
	void increaseNumOfTanks() { numOfTanksOn++; }
	QPushButton* pushButton() const;
	void reDrawButtonText();
	bool isBoarder(Territory* terr);


	void DrawCircle();
	void AddBorders(std::vector<Territory*> territorries);
	std::string GetNationalBelongingText();
	Nation GetNationFromText(std::string nation);
	//void PrintTerritoryInfos();  // NOTE: test method

private:
	//non changeable initial territory attributes
	std::string m_TerritoryName;
	Nation m_TerritoryNationalBelonging;
	bool m_CapitalFlag = false;
	int m_PositionX = 0;
	int m_PositionY = 0;
	std::vector<Territory*> m_Borders;
	int numOfTanksOn = 0;
	QPushButton* m_pushButton;

	//changeable ingame territory attributes
	Player* m_TerritoryPlayerBelonging = nullptr;


};

#endif