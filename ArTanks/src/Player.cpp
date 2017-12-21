#include "Player.h"
#include "Missile.h"
#include "Game.h"

Player::Player() : sight(nullptr) {}

Player::Player(Tank* playerTank) :
	ControlEntity(playerTank),
	sight(nullptr)
{}

Player::Player(Tank* playerTank, Sight* playerSight) :
	ControlEntity(playerTank),
	sight(playerSight)
{
	this->sight->setPlayer(this);
}
