#include <iostream>
#include "Player.h"
#include "Nation.h"
#include "Color.h"

using namespace std;

class Territory {

public:
	Territory() {};
	Territory(string name, Nation nation, double x = 1, double y = 1, bool isCapital);
	~Territory();

	//getters & setters
	string GetName() { return m_TerritoryrName; }
	Player* GetPlayerBelonging() { return m_TerritoryPlayerBelonging; }
	Nation GetNationalBelonging() { return m_TerritoryNationalBelonging; }
	bool IsCapital() { return m_CapitalFlag; }

	void DrawCircle();

	void AddBorders(vector<Territory*> territorries);
	string GetNationalBelongingText();
	//void PrintTerritoryInfos();  // NOTE: test method

private:
	//non changeable initial territory attributes
	string m_TerritoryrName;
	Nation m_TerritoryNationalBelonging;
	bool m_CapitalFlag = false;
	double m_PositionX = 0;
	double m_PositionY = 0;
	vector<Territory*> m_Borders;

	//changeable ingame territory attributes
	Player* m_TerritoryPlayerBelonging = nullptr;


};