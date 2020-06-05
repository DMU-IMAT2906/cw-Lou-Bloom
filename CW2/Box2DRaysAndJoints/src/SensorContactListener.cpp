#include "SensorContactListener.h"
#include <iostream>
using namespace std;

void SensorContactListener::BeginOpen(b2Contact * contact)
{
	//!< Gets the body attatched to the fixtures
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	//!< Checks whether the fixtures are sensors
	bool isSensorE = contact->GetFixtureA()->IsSensor();
	bool isSensorF = contact->GetFixtureB()->IsSensor();
	//!< gets the user data of the staticSensorDoor if iSensorE and isSensorF is a sensor then points to function in sensor
	if (isSensorE)
	{ 
		StaticSensorDoor * sensorO = static_cast<StaticSensorDoor *>(bodyA->GetUserData());
		sensorO->onActionButton(bodyB);
	}
	if (isSensorF)
	{
		StaticSensorDoor * sensorO = static_cast<StaticSensorDoor *>(bodyB->GetUserData());
		sensorO->onActionButton(bodyA);
	}
}
void SensorContactListener::EndOpen(b2Contact * contact)
{
	//!< Gets the body attatched to the fixtures
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	//!< Checks whether the fixtures are sensors
	bool isSensorE = contact->GetFixtureA()->IsSensor();
	bool isSensorF = contact->GetFixtureB()->IsSensor();
	//!< gets the user data of the staticSensorDoor if iSensorE and isSensorF is a sensor then points to function in sensor
	if (isSensorE)
	{
		StaticSensorDoor * sensorO = static_cast<StaticSensorDoor *>(bodyA->GetUserData());
		sensorO->offActionButton(bodyB);
	}
	if (isSensorF)
	{
		StaticSensorDoor * sensorO = static_cast<StaticSensorDoor *>(bodyB->GetUserData());
		sensorO->offActionButton(bodyA);
	}
}
void SensorContactListener::BeginHit(b2Contact * contact)
{
	//!< Gets the body attatched to the fixtures
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();

	//!< Checks whether the fixtures are sensors
    bool isSensorC = contact->GetFixtureA()->IsSensor();
    bool isSensorD = contact->GetFixtureB()->IsSensor();
	//!< gets the user data of the staticSensorDoor if iSensorC and isSensorD is a sensor then points to function in sensor
    if (isSensorC)
	{
	    StaticSensorDamage * sensorD = static_cast<StaticSensorDamage *>(bodyA->GetUserData());
	    sensorD->onActionDeath(bodyB);
	}
	if (isSensorD)
	{
		StaticSensorDamage * sensorD = static_cast<StaticSensorDamage *>(bodyB->GetUserData());
	    sensorD->onActionDeath(bodyA);
	}
}
void SensorContactListener::EndHit(b2Contact * contact)
{
	//!< Gets the body attatched to the fixtures
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	//!< Checks whether the fixtures are sensors
	bool isSensorC = contact->GetFixtureA()->IsSensor();
	bool isSensorD = contact->GetFixtureB()->IsSensor();
	
	//!< gets the user data of the staticSensorDoor if iSensorC and isSensorD is a sensor then points to function in sensor
	if (isSensorC)
	{
	    StaticSensorDamage * sensorD = static_cast<StaticSensorDamage *>(bodyA->GetUserData());
	    sensorD->offActionDeath(bodyB);
	}
	if (isSensorD)
	{
		StaticSensorDamage * sensorD = static_cast<StaticSensorDamage *>(bodyB->GetUserData());
	    sensorD->offActionDeath(bodyA);
	}
}
void SensorContactListener::BeginContact(b2Contact * contact)
{
	//!< Gets the body attatched to the fixtures
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	//!< Checks whether the fixtures are sensors
	bool isSensorA = contact->GetFixtureA()->IsSensor();
	bool isSensorB = contact->GetFixtureB()->IsSensor();
	//!< gets the user data of the staticSensorDoor if iSensorA and isSensorB is a sensor then points to function in sensor
	if (isSensorA)
	{
		StaticSensor * sensor = static_cast<StaticSensor *>(bodyA->GetUserData());
		sensor->onAction(bodyB);
	}
	if (isSensorB)
	{
		StaticSensor * sensor = static_cast<StaticSensor *>(bodyB->GetUserData());
		sensor->onAction(bodyA);
	}
}

void SensorContactListener::EndContact(b2Contact * contact)
{
	//!< Gets the body attatched to the fixtures
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	//!< Checks whether the fixtures are sensors
	bool isSensorA = contact->GetFixtureA()->IsSensor();
	bool isSensorB = contact->GetFixtureB()->IsSensor();

	//!< gets the user data of the staticSensorDoor if iSensorA and isSensorB is a sensor then points to function in sensor
	if (isSensorA)
	{
		StaticSensor * sensor = static_cast<StaticSensor *>(bodyA->GetUserData());
		sensor->offAction(bodyB);
	}
	if (isSensorB)
	{
		StaticSensor * sensor = static_cast<StaticSensor *>(bodyB->GetUserData());
		sensor->offAction(bodyA);
	}
}