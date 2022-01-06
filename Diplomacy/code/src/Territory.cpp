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
	m_pushButton->setText(QString::fromStdString(std::to_string(numOfTanks())));
	m_pushButton->setObjectName(QString::fromStdString(GetName()));
	int xpos = getXpos() - 10;
	int ypos = getYpos() - 10;
	xpos = xpos * 1.18534;
	ypos = ypos * 1.18534;
	m_pushButton->setGeometry(xpos, ypos, 10, 10);
	m_pushButton->setStyleSheet("background-color: rgba(180, 180, 180, 1);\
                                color: white;\
                                border-style: solid;\
                                border-width:1px;\
                                border-radius:12px;\
                                max-width:25px;\
                                max-height:25px;\
                                min-width:25px;\
                                min-height:25px; ");

}

void Territory::setButtonColor(Color color)
{
	string rgbaColor = GetStringColor(color);
	QString qstr = QString::fromStdString(rgbaColor);
	QString textColor = "white";
	if (color == White || color == Yellow || color == Cyan)
		textColor = "black";
	if(color == Gray)
		m_pushButton->setText(QString::fromStdString(" - "));
	else
		m_pushButton->setText(QString::fromStdString(std::to_string(numOfTanks())));
	m_pushButton->setStyleSheet("background-color: " + qstr + ";\
                                color: " + textColor + "; \
                                border-style: solid;\
                                border-width:1px;\
                                border-radius:12px;\
                                max-width:25px;\
                                max-height:25px;\
                                min-width:25px;\
                                min-height:25px; ");

}

string Territory::GetStringColor(Color color)
{
	string colorStr;
	if (color == Red)
		colorStr = "rgba(255, 0, 0, 1)";
	else
		if (color == Blue)
			colorStr = "rgba(0, 0, 255, 1)";
		else
			if (color == Green)
				colorStr = "rgba(0, 255, 0, 1)";
			else
				if (color == Yellow)
					colorStr = "rgba(255, 255, 0, 1)";
				else
					if (color == Cyan)
						colorStr = "rgba(0, 255, 255, 1)";
					else
						if (color == White)
							colorStr = "rgba(255, 255, 255, 1)";
						else
							if (color == Black)
								colorStr = "rgba(0, 0, 0, 1)";
							else
								colorStr = "rgba(180, 180, 180,1)";

	return colorStr;
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
	if (nation == "germany")
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

void Territory::reDrawButtonText()
{
	if(!m_TerritoryPlayerBelonging)
		m_pushButton->setText(QString::fromStdString(" - "));
	else
		m_pushButton->setText(QString::fromStdString(std::to_string(numOfTanks())));
}

bool Territory::isBoarder(Territory* terr)
{
if (!terr->GetBorders().empty())
	{
		for (Territory* territory : terr->GetBorders())
		{
			if (territory->GetName() == GetName())
				return true;
		}
	}
	return false;
}



