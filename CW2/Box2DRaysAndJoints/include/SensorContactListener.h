#pragma once

/*!
\file SensorContactListener.h
*/

#include <Box2D\Box2D.h>

#include "staticSensor.h"
#include "staticSensorDamage.h"
#include "staticSensorDoor.h"

/*! \class SensorContactListener
\brief A listener which listens for contacts between games objects and sensors
*/

class SensorContactListener : public b2ContactListener
{
public:
	//!< Collectible sensor contact functions
	void BeginContact(b2Contact* contact); //!< Called when two fixtures begin to touch
	void EndContact(b2Contact* contact); //!< Called when two fixtures cease to touch for 
	
	//!<Death sensor contact functions
	void BeginHit(b2Contact* contact); //!< Called when two fixtures begin to touch
	void EndHit(b2Contact* contact); //!< Called when two fixtures cease to touch

	//!< Open door contact functions
	void BeginOpen(b2Contact* contact); //!< Called when two fixtures begin to touch
	void EndOpen(b2Contact* contact); //!< Called when two fixtures cease to touch
};