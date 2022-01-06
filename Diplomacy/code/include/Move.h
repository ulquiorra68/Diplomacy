#ifndef MOVE_H
#define MOVE_H

#include "code/include/player.h"
#include "code/include/Territory.h"

class Player;
class Territory;

class Move
{
private:

    Player* p_PlayerMadeMove;

    Territory* p_StartTerritory;
    Territory* p_EndTerritory;

    int p_moveType; // 1 attack 2 help 3 repositioning army
   

public:
    Move(Player* player, Territory* t1, Territory* t2, int type) { p_PlayerMadeMove = player; p_StartTerritory = t1;  p_EndTerritory = t2, p_moveType = type; };
    ~Move() {};

    int getType() { return p_moveType; };
    Territory* getStartTerritory() { return p_StartTerritory; };
    Territory* getEndTerritory() { return p_EndTerritory; };
    Player* getPlayer() { return p_PlayerMadeMove; };

 
};

#endif // MOVE_H
