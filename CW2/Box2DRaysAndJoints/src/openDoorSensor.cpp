/*!
\file openDoorSensor.cpp
*/
#pragma once

#include "openDoorSensor.h"

OpenDoorSensor::OpenDoorSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, SlidingDoor * door)
{
	//!<Sets the rectangle shape used for the sensor
	initRectangleButton(world, position, size, orientation);
	m_door = door;
}
void OpenDoorSensor::onActionButton(b2Body * other)
{
	//!<When the contact begins the colour is set to green and it calls the open function
	setFillColor(sf::Color::Green);
	m_door->open();
}