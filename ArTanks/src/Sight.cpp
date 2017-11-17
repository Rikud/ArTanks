/*
 * Sight.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ivan
 */
#include "Player.h"
#include "Sight.h"

Sight::Sight(): myOwner(nullptr) {
	if (this->texture.loadFromFile("texture/sight.png"))
	{
		this->sprite.setTexture(this->texture, true);
	}
	this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
}

void Sight::draw(sf::RenderTarget &target) {
	target.draw(sprite);
}

void Sight::setPosition(const sf::Vector2f& pos) {
	this->sprite.setPosition(pos);
}

void Sight::reset() {

}

void Sight::setPlayer(Player *p) {
	this->myOwner = p;
	this->sprite.setPosition(this->myOwner->getTankPos() - sf::Vector2f (0, this->sprite.getLocalBounds().width));
}

float findThePolarAngleOfTheVector(float x, float y) {
	if (x >= 0)
		if (y >= 0)
			return atan(y / x);
		else
			return atan(y / x) + 2 * M_PI;
	else
		return atan(y / x) + M_PI;
}

void Sight::step(float dt) {

}

void Sight::move() {
	sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(Application::getWindow()).x, sf::Mouse::getPosition(Application::getWindow()).y);
	this->setPosition(mousePosition);
	sf::Vector2f turretPosition = this->myOwner->getTurretPos();
	sf::Vector2f vectorTurretCursor = mousePosition - turretPosition;
	//float cosAngle = vectorTurretCursor.x / sqrt(powf(vectorTurretCursor.x, 2.0) + powf(vectorTurretCursor.y, 2.0));
	this->myOwner->setTurretAngle(findThePolarAngleOfTheVector(vectorTurretCursor.x, vectorTurretCursor.y) * 180 / M_PI);
}

void Sight::handleCollision(WorldObject &b) {

}

Sight::~Sight() {
	// TODO Auto-generated destructor stub
}

