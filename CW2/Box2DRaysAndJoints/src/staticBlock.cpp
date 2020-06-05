/*!
\file staticBlock.cpp
*/

#include "staticBlock.h"

StaticBlock::StaticBlock(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation)
{
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	m_body = world->CreateBody(&l_bodyDef);
	m_body->SetUserData(this); // used by our contact listener

	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;

	l_fixtureDef.density = mk_fDensity;//!< Sets the density for the block
	l_fixtureDef.friction = mk_fFrictionPlatform;//!< Sets the friction for the block
	l_fixtureDef.restitution = mk_fRestitution;//!< Sets the restitution for the block
	l_fixtureDef.shape = &l_shape;

	m_body->CreateFixture(&l_fixtureDef);

	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);
	setOutlineThickness(0.f);
}