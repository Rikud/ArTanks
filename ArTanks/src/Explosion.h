/*
 * Explosion.h
 *
 *  Created on: Nov 16, 2017
 *      Author: root
 */

#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "WorldObject.h"
#include "Animation.h"

class Tank;

class Explosion: public WorldObject {
public:
	Explosion(sf::Vector2f pos,int r = 25);
	~Explosion();
	inline void setRadius(int r){ expCircle.setRadius(r); }
	inline int getRadius(){ return expCircle.getRadius(); }
	void handleCollision(WorldObject &b);
	void draw(sf::RenderTarget &target);
	void step(float dt);
	void reset();
private:
	std::map<Tank*,bool> tanksActedOn;
	sf::CircleShape expCircle;
	std::unique_ptr<Animation> anim;
};

#endif /* EXPLOSION_H_ */
