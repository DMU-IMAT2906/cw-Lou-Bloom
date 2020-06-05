#pragma once

#include "staticSensorDoor.h"
#include "slidingDoor.h"

class OpenDoorSensor : public StaticSensorDoor
{
private:

public:
	OpenDoorSensor() {}; //!< Default constructor
	OpenDoorSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, SlidingDoor * door);
	void onActionButton(b2Body * other);//!< Function used to open the door
	void offActionButton(b2Body * other) {};//!< Function used to open the door
	SlidingDoor * m_door;//!< This is the door that the OpenDoorSensor will open 
};