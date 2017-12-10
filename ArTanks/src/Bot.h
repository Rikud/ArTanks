/*
 * Bot.h
 *
 *  Created on: Dec 8, 2017
 *      Author: ivan
 */

#ifndef SRC_BOT_H_
#define SRC_BOT_H_

#include "ControlEntity.h"

class Bot: public ControlEntity {
public:
	Bot() = default;
	Bot(Tank *val);
	virtual ~Bot();
	void CalculateTurretPosition();
};

#endif /* SRC_BOT_H_ */
