#ifndef PLAYER_H
#define PLAYER_H
#include "Sight.h"
#include "ControlEntity.h"
class Player : public ControlEntity
{
public:
    Player();
    Player(Tank *val);
    Player(Tank *val, Sight* sight);
    inline void moveCursor() {this->mySight->move();}
private:
    Sight* mySight;
};
typedef std::unique_ptr<Player> Playerptr;
#endif // PLAYER_H
