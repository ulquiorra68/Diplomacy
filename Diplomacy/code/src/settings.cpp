#include "code/include/settings.h"

int Settings::numOfPlayers() const
{
    return p_numOfPlayers;
}

int Settings::numOfStartingTanks() const
{
    return p_numOfStartingTanks;
}

Settings::Settings()
{

}

Settings::~Settings()
{

}
