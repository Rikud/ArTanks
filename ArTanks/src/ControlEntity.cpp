/*
 * ControlEntity.cpp
 *
 *  Created on: Dec 8, 2017
 *      Author: ivan
 */

#include "ControlEntity.h"
#include "Missile.h"
#include "Game.h"
#include "Tank.h"

ControlEntity::ControlEntity() : myTank(nullptr), life(maxlife), power(0.4) {}
ControlEntity::ControlEntity(Tank *val) : myTank(val), life(maxlife), power(0.4) {
	this->myTank->setOwner(this);
}

void ControlEntity::fire()
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

ControlEntity::~ControlEntity() {
	// TODO Auto-generated destructor stub
}

