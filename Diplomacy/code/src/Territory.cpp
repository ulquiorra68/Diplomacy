#include "code/include/Territory.h"
#include <QString>

using namespace std;

Territory::Territory(string name, string nation, int x, int y, bool isCapital)
{
	m_TerritoryName = name;
	m_TerritoryNationalBelonging = GetNationFromText(nation);
	m_PositionX = x;
	m_PositionY = y;
	m_CapitalFlag = isCapital;

	/*m_pushButton->setText(QString::number(1));
	m_pushButton->setStyleSheet("background-color: rgba(180, 180, 180, 1);\
                                color: brown;\
                                border-style: solid;\
                                border-width:1px;\
                                border-radius:12px;\
                                max-width:25px;\
                                max-height:25px;\
                                min-width:25px;\
                                min-height:25px; ");
*/
}

Territory::Territory(string name, int x, int y/*, QPushButton* pushButton*/) {
	m_TerritoryName = name;
	m_PositionX = x;
	m_PositionY = y;

	/*m_pushButton = pushButton;
	m_pushButton->setText("text");
	m_pushButton->setStyleSheet("background-color: rgba(180, 180, 180, 1);\
                                color: brown;\
                                border-style: solid;\
                                border-width:1px;\
                                border-radius:12px;\
                                max-width:25px;\
                                max-height:25px;\
                                min-width:25px;\
                                min-height:25px; ");
								*/
}

void Territory::SetButton(QPushButton* pushButton) {
	m_pushButton = pushButton;
	m_pushButton->setText(QString::fromStdString(GetName()));
	int xpos = getXpos() - 10;
	int ypos = getYpos() - 10;
	xpos = xpos * 1.18534;
	ypos = ypos * 1.18534;
	m_pushButton->setGeometry(xpos, ypos, 10, 10);
	m_pushButton->setStyleSheet("background-color: rgba(180, 180, 180, 1);\
                                color: brown;\
                                border-style: solid;\
                                border-width:1px;\
                                border-radius:12px;\
                                max-width:25px;\
                                max-height:25px;\
                                min-width:25px;\
                                min-height:25px; ");

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
	case Austria:
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
	case Neutral:
		nation_string = "Neutral";
	default:
		nation_string = "Unknown National Belonging";
		break;
	}

	return nation_string;
}

Nation Territory::GetNationFromText(string nation)
{
	if (nation == "russia")
		return Russia;
	else
	if (nation == "gemrany")
		return Germany;
	else
	if (nation == "france")
		return France;
	else
	if (nation == "austria")
		return Austria;
	else
	if (nation == "england")
		return England;
	else
	if (nation == "italy")
		return Italy;
	if (nation == "turkey")
		return Turkey;
	else
	if (nation == "neutral")
		return Neutral;
		

}

void Territory::AddBorders(vector<Territory*> territorries) {

	m_Borders = territorries;
}

void Territory::DrawCircle() {
	
	//Color territory_color = m_TerritoryPlayerBelonging->getColor();

	//draw circle in color territory_color
}

QPushButton* Territory::pushButton() const
{
	return m_pushButton;
}



