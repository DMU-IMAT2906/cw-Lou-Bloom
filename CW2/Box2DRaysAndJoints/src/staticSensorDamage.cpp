/*!
\file staticSensor.cpp
*/

#include "staticSensorDamage.h"

void StaticSensorDamage::initRectangleHit(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation)
{
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	m_body = world->CreateBody(&l_bodyDef);

	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;

	l_fixtureDef.density = mk_fDensity;//!< Sets the density for the sensor
	l_fixtureDef.friction = mk_fFriction;//!< Sets the friction for the sensor
	l_fixtureDef.restitution = mk_fRestitution;//!< Sets the restitution for the sensor
	l_fixtureDef.shape = &l_shape;

	l_fixtureDef.isSensor = true; //Make it a sensor

	m_body->CreateFixture(&l_fixtureDef);

	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);
}
void StaticSensorDamage::initCircleHit(b2World * world, sf::Vector2f position, float radius)
{
	b2BodyDef l_bodyDef;
	b2CircleShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.position.Set(position.x, position.y);

	m_body = world->CreateBody(&l_bodyDef);

	l_shape.m_radius = radius;

	l_fixtureDef.density = mk_fDensity;//!< Sets the density for the sensor
	l_fixtureDef.friction = mk_fFriction;//!< Sets the friction for the sensor
	l_fixtureDef.restitution = mk_fRestitution;//!< Sets the restitution for the sensor
	l_fixtureDef.shape = &l_shape;

	l_fixtureDef.isSensor = true; //Make it a sensor

	m_body->CreateFixture(&l_fixtureDef);

	setPosition(position);
	setSize(sf::Vector2f(radius * 2.0f, radius * 2.0f));
	setOrigin(getSize() * 0.5f);
}