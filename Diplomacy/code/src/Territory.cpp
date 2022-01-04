#include "code/include/Territory.h"

using namespace std;

Territory::Territory(string name, Nation nation, double x, double y, bool isCapital)
{
	m_TerritoryName = name;
	m_TerritoryNationalBelonging = nation;
	m_PositionX = x;
	m_PositionY = y;
	m_CapitalFlag = isCapital;
}

string Territory::GetNationalBelongingText()
{
	string nation_string;
	switch (m_TerritoryNationalBelonging) {
	case Russia:
		nation_string = "Russia";
		break;
	case Turkey:
		nation_string = "Turkey";
		break;
	case Germany:
		nation_string = "Germany";
		break;
	case Austia:
		nation_string = "Austria";
		break;
	case France:
		nation_string = "France";
		break;
	case England:
		nation_string = "England";
		break;
	case Italy:
		nation_string = "Italy";
		break;
	default:
		nation_string = "Unknown National Belonging";
		break;
	}

	return nation_string;
}

void Territory::AddBorders(vector<Territory*> territorries) {

	m_Borders = territorries;
}

void Territory::DrawCircle() {
	
	//Color territory_color = m_TerritoryPlayerBelonging->getColor();

	//draw circle in color territory_color
}



