#include "Player.h"

Player::Player(Tank *val) :
    myTank(val),
    life(maxlife)
    //power(0.4)
{}

Player::Player(Tank *val, Sight *sight) :
	myTank(val),
	mySight(sight),
	life(maxlife)
		{}
