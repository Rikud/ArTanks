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

Explosion::Explosion(sf::Vector2f pos,int r) :
    WorldObject(WeaponPostEffectType),
    expCircle(r)
{
    expCircle.setOrigin(r,r);
    expCircle.setPosition(pos);
    Application::getGame().incCounter();
}
Explosion::~Explosion()
{
    Application::getGame().decCounter();
}
void Explosion::handleCollision(WorldObject &b)
{
    switch(b.type)
    {
    case WorldObject::TankType:
    {
        Tank &t = static_cast<Tank&>(b);
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
    selfDestruct = true;
}
void Explosion::draw(sf::RenderTarget &target)
{

}
void Explosion::step(float dt)
{
}
void Explosion::reset()
{
    selfDestruct = true;
}
