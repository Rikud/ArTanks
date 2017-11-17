#include "Player.h"
#include "Application.h"
//#include "utilities.h"

Player::Player(Tank *val) :
    myTank(val),
    life(maxlife),
    power(0.4)
{}
