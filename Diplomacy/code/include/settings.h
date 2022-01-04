#ifndef SETTINGS_H
#define SETTINGS_H

#include<QVector>

class Settings
{
private:
    int p_numOfPlayers;
    int p_numOfStartingTanks;

public:
    Settings();
    Settings(int numOfPlayers, int numOfStartingTanks);
    ~Settings();

    int numOfPlayers() const;
    int numOfStartingTanks() const;
};

#endif // SETTINGS_H
