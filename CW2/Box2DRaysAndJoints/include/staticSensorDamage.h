#pragma once

/*!
\file staticSensor.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "physicalThing.h"

/*! \class StaticSensor
\brief A simple block which can not move or rotate and does not coliide with circles
*/

class StaticSensorDamage : public sf::RectangleShape, public PhysicalThing
{
public:
	void initRectangleHit(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation);
	void initCircleHit(b2World * world, sf::Vector2f position, float radius);
	virtual void onActionDeath(b2Body * other) = 0;//!< Thing the sensor does when hit
	virtual void offActionDeath(b2Body * other) = 0; //!< Thing the sensor does when hit stops
};