#ifndef PLAYER_H
#define PLAYER_H
#include "Sight.h"
#include "ControlEntity.h"
class Player : public ControlEntity
{
public:
    Player();
    Player(Tank* playerTank);
    Player(Tank* playerTank, Sight* sight);
    inline void moveCursor() {this->sight->move();}
private:
    Sight* sight;
};
typedef std::unique_ptr<Player> Playerptr;
#endif // PLAYER_H
