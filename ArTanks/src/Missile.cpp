/*
 * Missile.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: root
 */
#include "Missile.h"
#include "Application.h"
#include "Land.h"
#include "Tank.h"
#include "Game.h"
#include "utilities.h"
#include "Explosion.h"

Missile::Missile(double x, double y) : velocity(0, 0) , acceleration(0, gravity)
{
    type = WorldObject::WeaponType;
    selfDestruct = false;
    projectile.setRadius(2.5);
    projectile.setFillColor(sf::Color::Magenta);
    projectile.setPosition(x, y);
    Application::getGame().incCounter();
}
Missile::~Missile()
{
    Application::getGame().decCounter();
}
void Missile::setVelocity(double x, double y)
{
    velocity.x = x;
    velocity.y = y;
}
void Missile::setAcceleration(double x, double y)
{
    acceleration.x = x;
    acceleration.y = y;
}
void Missile::handleCollision(WorldObject &b)
{
    switch(b.type)
    {
    case WorldObject::TankType:
    {
        Tank &t = static_cast<Tank&>(b);
        if(intersects(projectile,t.getTankRect()))
            explode();
    }
    break;
    case WorldObject::LandType:
    {
        Land &l = static_cast<Land&>(b);
        if(projectile.getPosition().y + projectile.getRadius() > (windowHeight - l.getHeight(projectile.getPosition().x))) {
            explode();
        }
    }
    break;
    default:
        break;
    }
}
void Missile::draw(sf::RenderTarget &target)
{
    target.draw(projectile);
}
void Missile::step(float dt)
{
    velocity += acceleration * dt;
    projectile.move( velocity * dt );
    if(projectile.getPosition().x >= windowWidth || projectile.getPosition().x < 0
       || projectile.getPosition().y >= windowHeight)
    {
        selfDestruct = true;
    }
}
void Missile::explode()
{
    Application::getGame().addWorldObj(new Explosion(projectile.getPosition(),30));
    Land* l = Application::getGame().getLand();
    l->destroyCircle(this->projectile.getPosition().x, this->projectile.getPosition().y, 25);
    selfDestruct = true;
}
