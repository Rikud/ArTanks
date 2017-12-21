/*
 * ControlEntity.h
 *
 *  Created on: Dec 8, 2017
 *      Author: ivan
 */

#ifndef SRC_CONTROLENTITY_H_
#define SRC_CONTROLENTITY_H_

#include "Tank.h"

class ControlEntity {
public:
	ControlEntity();
	ControlEntity(Tank* val);
	virtual ~ControlEntity();
	inline void rotateTurret(float f){ myTank->turret.rotate(f);}
	inline void setPower(float pow){ power=pow;}
	inline float getPower(){ return power; }
	inline Tank& getTank() { return *myTank; }
	inline void setTank(Tank *t){myTank = t;}
	inline void setTurretAngle(float f){ myTank->turret.setRotation(f); }
    void fire();
    inline void setTankPos(const sf::Vector2f& pos) { myTank->setPosition(pos); }
    inline float getTurretAngle(){ return myTank->turret.getRotation(); }
    inline const sf::Vector2f& getTankPos() { return myTank->tank.getPosition(); }
    inline const sf::Vector2f& getTurretPos() { return myTank->turret.getPosition(); }
    inline void moveTank(int dir){ myTank->setMovement(dir); } //left: -1, right: 1
    inline void setLife(int l){life = l;}
    inline int getLife() { return life; }
    inline bool isDead(){return !(life);}
    inline bool readyTofire(){return myTank->readyToFire;}
    inline int getTankMove() {return myTank->moving;}

	static const int maxlife = 100;

protected:
	Tank *myTank;
	int life;
	float power; //in range [0,1]
};

#endif /* SRC_CONTROLENTITY_H_ */
