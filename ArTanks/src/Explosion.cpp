/*
 * Explosion.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: root
 */

#include "Explosion.h"
#include "Tank.h"
#include "utilities.h"
#include "Application.h"
#include "Game.h"

Explosion::Explosion(sf::Vector2f pos,int radius) :
    WorldObject(WeaponPostEffectType),
    expCircle(radius),
	anim(AnimationCreator::create(AnimationType::MissileExplosionA,pos))
{
    expCircle.setOrigin(radius,radius);
    expCircle.setPosition(pos);
    Application::getGame().incCounter();
    Land* land = Application::getGame().getLand();
	land->destroyCircle(pos.x, pos.y, radius + 5);
}
Explosion::~Explosion()
{
    Application::getGame().decCounter();
}
void Explosion::handleCollision(WorldObject& anotherObject)
{
    switch(anotherObject.type)
    {
    case WorldObject::TankType:
    {
        Tank &t = static_cast<Tank&>(anotherObject);
        bool &tankActed = tanksActedOn[&t];
        if(tankActed == false && intersects(expCircle,t.getTankRect()))
        {
            sf::Vector2f vec = expCircle.getPosition() - t.getTankRect().getPosition();
            float blowPower = 50*(1-std::hypot(vec.x,vec.y)/(expCircle.getRadius()+t.getTankRect().getLocalBounds().width/2));
            t.weapAct(blowPower);
            tankActed = true;
        }
    }
        break;
    default:
        break;
    }
}
void Explosion::draw(sf::RenderTarget &target)
{
	if(this->anim->selfDestruct == true)
	{
		selfDestruct = true;
	}
	this->anim->draw(target);
}
void Explosion::step(float dt)
{
	this->anim->step(dt);
}

void Explosion::reset()
{
    selfDestruct = true;
}
