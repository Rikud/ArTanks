#include "Player.h"
#include "Missile.h"
#include "Game.h"

Player::Player() : mySight(nullptr) {}

Player::Player(Tank *val) :
	ControlEntity(val),
	mySight(nullptr)
{}

Player::Player(Tank *val, Sight *sight) :
	ControlEntity(val),
	mySight(sight)
{
	this->mySight->setPlayer(this);
}
