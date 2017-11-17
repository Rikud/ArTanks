/*
 * Sight.h
 *
 *  Created on: Nov 16, 2017
 *      Author: ivan
 */

#ifndef SIGHT_H_
#define SIGHT_H_
#include "WorldObject.h"
class Player;
class Sight: public WorldObject {
public:
	Sight();
	~Sight();
	void draw(sf::RenderTarget &target);
	void reset();
	void step(float dt);
	void setPosition(const sf::Vector2f& pos);
	void setPosition(int x,int y) { setPosition(sf::Vector2f(x,y)); }
	void move();
	void setPlayer(Player *p);
	void handleCollision(WorldObject &b);
private:
	Player* myOwner;
	sf::Texture texture;
	sf::Sprite	sprite;
};

#endif /* SIGHT_H_ */
