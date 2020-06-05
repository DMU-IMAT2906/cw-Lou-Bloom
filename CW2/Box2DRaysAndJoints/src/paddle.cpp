/*!
\file paddle.cpp
*/
#include "paddle.h"

Paddle::Paddle(b2World * world, sf::Vector2f position, sf::Vector2f size, const float orientation, b2Body * anchor)
{
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;
	l_bodyDef.type = b2_dynamicBody;

	m_body = world->CreateBody(&l_bodyDef);
	m_body->SetUserData(this); // used by our contact listener

	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;

	l_fixtureDef.density = mk_fDensityPlatform;
	l_fixtureDef.friction = mk_fFrictionMovingPlatform;
	l_fixtureDef.restitution = mk_fRestitutionPlatform;
	l_fixtureDef.shape = &l_shape;

	m_body->CreateFixture(&l_fixtureDef);

	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);
	setOutlineThickness(0.f);

	//!< This is the motor joint for the paddle so that it moves side to side
	b2MotorJointDef mjd;
	mjd.bodyA = anchor;
	mjd.bodyB = m_body;
	//!<Gets the x position of the body takes away the x position of the anchor
	mjd.linearOffset = b2Vec2(m_body->GetPosition().x - anchor->GetPosition().x, 0.f);
	mjd.angularOffset = 0.0f;
	mjd.maxForce = 1000.f;
	mjd.maxTorque = 1000.f;

	m_motorJoint = (b2MotorJoint*)world->CreateJoint(&mjd);
}

void Paddle::update()
{
	b2Vec2 pos = m_body->GetPosition();
	setPosition(pos.x, pos.y);
	float angle = m_body->GetAngle()* RAD2DEG;
	setRotation(angle);
}

void Paddle::setJointLinearDistance(b2Vec2 dist)
{
	m_motorJoint->SetLinearOffset(dist);
}
b2Vec2 Paddle::getJointLinearDistance()
{
	return m_motorJoint->GetLinearOffset();
}