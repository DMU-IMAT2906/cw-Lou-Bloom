#include "movingArm.h"

MovingArm::MovingArm(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f localPositionOnAnchor/*, b2Body * anchorBody*/, float orientation, sf::Color colour)
{
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;

	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = mk_fRestitution;
	l_fixtureDef.shape = &l_shape;

	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;
	l_bodyDef.type = b2_dynamicBody;

	m_body = world->CreateBody(&l_bodyDef);
	m_body->CreateFixture(&l_fixtureDef);
	m_body->SetAngularDamping(0.1f);

	//l_bodyDef.type = b2_staticBody;

	b2CircleShape l_circ;
	l_circ.m_radius = fminf(size.x / 2.0f, size.y / 2.0f);
	l_fixtureDef.shape = &l_circ;

	m_anchor = world->CreateBody(&l_bodyDef);
	m_anchor->CreateFixture(&l_fixtureDef);

	b2RevoluteJointDef jointDef;
	jointDef.bodyA = m_anchor;
	jointDef.bodyB = m_body;
	jointDef.collideConnected = false;
	jointDef.localAnchorA.Set(0.0f, -0.0f);// Centre of the box
	jointDef.localAnchorB.Set(localPositionOnAnchor.x, localPositionOnAnchor.y); // from constructor
	m_hinge = (b2RevoluteJoint*)world->CreateJoint(&jointDef);

	m_rectangle.setPosition(position);
	m_rectangle.setSize(size);
	m_rectangle.setOrigin(size * 0.5f);
	m_rectangle.setRotation(orientation);
	m_rectangle.setFillColor(sf::Color::Red);
	m_rectangle.setOutlineThickness(0.f);
	
	b2MotorJointDef mjd;
	//mjd.bodyA = anchorBody;
	mjd.bodyA = m_anchor;
	mjd.bodyB = m_body;
	mjd.linearOffset = b2Vec2(m_body->GetPosition().x - /*anchorBody*/m_anchor->GetPosition().x, 0.f);
	mjd.angularOffset = 0.0f;
	mjd.maxForce = 1000.f;
	mjd.maxTorque = 1000.f;

	m_motorJointArm = (b2MotorJoint*)world->CreateJoint(&mjd);
	
}

bool MovingArm::isStopped() const
{
	return m_stopped;
}
/*
void MovingArm::setJointLinearDistance(b2Vec2 angle)
{
	m_motorJointArm->SetLinearOffset(angle);
}
*/
void MovingArm::setJointLinearDistance(b2Vec2 dist)
{
	m_motorJointArm->SetLinearOffset(dist);
}

b2Vec2 MovingArm::getJointLinearDistance()
{
	return m_motorJointArm->GetLinearOffset();
}

MovingArm::MovingArm(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, float orientation, sf::Texture * tex)
{
}

void MovingArm::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_rectangle);
}

void MovingArm::update()
{
	b2Vec2 pos = m_body->GetPosition();
	m_rectangle.setPosition(pos.x, pos.y);

	// Check whether the circle has stopped (simualated ground friction)
	m_stopped = m_body->GetLinearVelocity().Length() < 0.1f;
	//If stopped trim any remaining velocity
	if (m_stopped)
	{
		m_body->SetLinearVelocity(b2Vec2(0.f, 0.f));
		m_body->SetAngularVelocity(0.0f);
	}

	float angle = m_body->GetAngle()* RAD2DEG;
	m_rectangle.setRotation(angle);
}
