/*!
\file dynamicBlock.cpp
*/

#include "dynamicBlock.h"

DynamicBlock::DynamicBlock(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size/*, const float orientation*/)
{
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = 0 * DEG2RAD;
	l_bodyDef.type = b2_dynamicBody;

	m_body = world->CreateBody(&l_bodyDef);
	m_body->SetUserData(this); // used by our contact listener

	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;

	l_fixtureDef.density = mk_fDensity;
	//l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.friction = mk_fFrictionPlayer;
	//l_fixtureDef.restitution = mk_fRestitution;
	l_fixtureDef.shape = &l_shape;
	//l_fixtureDef.userData = &l_fixtureDef;

	m_body->CreateFixture(&l_fixtureDef);

	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setOutlineThickness(0.f);
}
void DynamicBlock::update()
{
	// Check whether the circle has stopped (simualated ground friction)
	m_stopped = m_body->GetLinearVelocity().Length() < 0.1f;
	//If stopped trim any remaining velocity
	if (m_stopped)
	{
		m_body->SetLinearVelocity(b2Vec2(0.f, 0.f));
		m_body->SetAngularVelocity(0.0f);
	}
	b2Vec2 pos = m_body->GetPosition();
	setPosition(pos.x, pos.y);
	//float angle = m_body->GetAngle()* RAD2DEG;
	//setRotation(angle);
}
void DynamicBlock::applyImpulse(b2Vec2 impulse) { m_body->ApplyLinearImpulseToCenter(impulse, true); }
bool DynamicBlock::isStopped() const { return m_stopped; }
void DynamicBlock::applyForce(const sf::Vector2f & force) 
{
	m_body->ApplyLinearImpulseToCenter(b2Vec2(force.x, force.y), true);
	m_body->ApplyForceToCenter(b2Vec2(force.x, force.y), true);
}
void DynamicBlock::accel(b2Vec2 accel)
{}