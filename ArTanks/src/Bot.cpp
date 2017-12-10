/*
 * Bot.cpp
 *
 *  Created on: Dec 8, 2017
 *      Author: ivan
 */

#include "Bot.h"
#include "Game.h"
#include "Application.h"
#include "utilities.h"

#include <algorithm>

Bot::Bot(Tank *val) :
ControlEntity(val)
{}

void Bot::CalculateTurretPosition() {
	double x2 = Application::getGame().getPlayer()->getTankPos().x;
	double y2 = windowHeight - Application::getGame().getPlayer()->getTankPos().y;
	double x1 = this->getTankPos().x;
	double y1 = windowHeight - this->getTankPos().y;
	double C1 = 0;
	C1 = abs(x2 - x1);
	/*double dx = x2 - x1;
	double dy = y1 - y2;
	double a = gravity * pow(dx, 2) /  pow( (this->power * 500), 2);
	double D = pow(dx, 2) - 4 * a * (dy + a);
	double tgA = 0;
	if (x1 > x2)
		tgA = ( - dx + sqrt(D) ) / ( a * 2 );
	else
		tgA = ( - dx - sqrt(D) ) / ( a * 2 );
	double alpha = atan(tgA);
	this->setTurretAngle(float(alpha));*/
	double C2 = double(gravity) * pow(C1, 2) / pow( double((this->power * 500)), 2);
	double C3 = y1 - y2;
	double a = C2;
	double b = C1;
	double c = C2 + C3;
	double D = pow(b, 2) - 4 * a * c;
	double tgA = 0;
	if (x1 > x2)
		tgA = ( - b + sqrt(D) ) / ( 2 * a );
	else
		tgA = ( - b - sqrt(D) ) / ( 2 * a );
	double alpha = atan(tgA);
	alpha = alpha * 180 / M_PI;
	if (x1 > x2)
		alpha = 180 - alpha;
	this->setTurretAngle(float(alpha));
}

Bot::~Bot() {
	// TODO Auto-generated destructor stub
}

