/*
 * BotII.h
 *
 *  Created on: Dec 8, 2017
 *      Author: ivan
 */

#ifndef SRC_BOTII_H_
#define SRC_BOTII_H_

#include <vector>

#include "WorldObject.h"
#include "Bot.h"

class BotII: public WorldObject {
public:
	static BotII* II();
	virtual ~BotII();
	inline void addBot(Bot* newBot) {this->botsArray.push_back(newBot);}
	void draw(sf::RenderTarget& target);
	void step(float dt);
	void reset();
	void handleCollision(WorldObject &b);
private:
	BotII();
	BotII(const BotII& root) = delete;
	BotII& operator=(const BotII&) = delete;
	std::vector<Bot*> botsArray;
};

#endif /* SRC_BOTII_H_ */
