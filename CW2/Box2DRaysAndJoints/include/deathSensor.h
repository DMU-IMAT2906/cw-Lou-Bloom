#pragma once

/**
@file deathSensor.h
*/

#include "staticSensorDamage.h"

class DeathSensor : public StaticSensorDamage
{
public:
	DeathSensor() {}; //!< Default constructor
	DeathSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, RectangleShape dead);
	void onActionDeath(b2Body * other);
	void offActionDeath(b2Body * other) {};

	int iDamage;//!< Int for each point of contact that occurs between the player and the sensor
	int iLife;//!< Int for adding up all the contact instances

	sf::RectangleShape deadScreen;//!<Rectangle shape that displays upon iLife reaching a set value
	sf::Texture m_texDeadScreen;//!<Texture used for deadScreen
};