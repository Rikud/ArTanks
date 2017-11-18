#include "Player.h"
#include "Application.h"
#include "Missile.h"
#include "Game.h"

Player::Player(Tank *val) :
    myTank(val),
	mySight(nullptr),
    life(maxlife),
    power(0.4)
{}

Player::Player(Tank *val, Sight *sight) :
	myTank(val),
	mySight(sight),
	life(maxlife),
	power(0.4)
{}

void Player::fire()
{
	if (this->readyTofire()) {
		double phi = TO_RAD(myTank->turret.getRotation());
		double sin = std::sin(phi) , cos = std::cos(phi);
		double TankVelocity = power*500;
		Missile* m=new Missile(myTank->turret.getPosition().x + myTank->turret.getLocalBounds().width * cos,
								 myTank->turret.getPosition().y + myTank->turret.getLocalBounds().width * sin);
		m->setVelocity(TankVelocity * cos, TankVelocity * sin);
		Application::getGame().addWorldObj(m);
		this->myTank->startReload();
	}
}
