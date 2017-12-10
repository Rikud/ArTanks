/*
 * BotII.cpp
 *
 *  Created on: Dec 8, 2017
 *      Author: ivan
 */

#include "BotII.h"

BotII::BotII() : WorldObject(IIType)
{
	// TODO Auto-generated constructor stub

}

void BotII::draw(sf::RenderTarget& target) {

}

void BotII::step(float dt) {

	for (unsigned int i = 0; i < this->botsArray.size(); ++i) {
		Bot* currentBot = this->botsArray[i];
		if (currentBot->readyTofire()) {
			//currentBot->CalculateTurretPosition();
			currentBot->fire();
		}
	}
}

void BotII::reset() {

}

void BotII::handleCollision(WorldObject &b) {

}

BotII::~BotII() {
	// TODO Auto-generated destructor stub
}

