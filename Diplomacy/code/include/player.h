#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<vector>
#include<unordered_set>

enum class Color{
    BLUE,
    RED,
    GREEN,
    YELLOW
};

class Player
{
private:
    std::string p_name;
    Color p_color;
    bool p_ownerInd;

//    std::unordered_set<Territory*> p_territories;

public:
    Player();
    Player(const std::string &name, Color color, bool ownerInd);
    ~Player();

    const std::string &name() const;

//    void addTerritory(Territory*);
//    void removeTerritory(Territory*);



    void setName(const std::string &newName);
    Color color() const;
    void setColor(Color newColor);
    Color getColor() { return p_color; };
//    std::int32_t numOfTerritories() const;
    bool ownerInd() const;
    void setOwnerInd(bool newOwnerInd);

//    const std::unordered_set<Territory *> &territories() const;
//    void setTerritories(const std::unordered_set<Territory *> &newTerritories);
};

#endif // PLAYER_H
