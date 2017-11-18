/*
 * Missile.h
 *
 *  Created on: Nov 16, 2017
 *      Author: root
 */

#ifndef MISSILE_H_
#define MISSILE_H_

#include "WorldObject.h"

class Missile: public WorldObject {
public:
    Missile(double x, double y);
    ~Missile();
    void handleCollision(WorldObject &b);
    void draw(sf::RenderTarget &target);
    void step(float dt);
    void setVelocity(double x, double y);
    void setAcceleration(double x, double y);
    inline void reset(){    selfDestruct = true;    }
private:
    void explode(void);
    sf::CircleShape projectile;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
};

bool intersects(sf::CircleShape circle, sf::RectangleShape rect);
sf::Vector2f RotatePoint(sf::Vector2f Point, sf::Vector2f Origin, double phi);

#endif /* MISSILE_H_ */
