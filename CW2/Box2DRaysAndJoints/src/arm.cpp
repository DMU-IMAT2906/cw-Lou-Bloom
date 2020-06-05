#include "arm.h"

Arm::Arm(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, b2Body * anchorToBody, float orientation)
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

	l_bodyDef.type = b2_staticBody;

	b2CircleShape l_circ;
	l_circ.m_radius = fminf(size.x / 2.0f, size.y / 2.0f);
	l_fixtureDef.shape = &l_circ;

	m_anchor = world->CreateBody(&l_bodyDef);
	m_anchor->CreateFixture(&l_fixtureDef);

	b2RevoluteJointDef jointDef;
	//jointDef.bodyA = m_anchor;
	jointDef.bodyA = anchorToBody;
	jointDef.bodyB = m_body;
	jointDef.collideConnected = false;
	jointDef.localAnchorA.Set(0.f, 0.f);// Centre of the box
	jointDef.localAnchorB.Set(anchor.x, anchor.y); // from constructor
	m_hinge = (b2RevoluteJoint*)world->CreateJoint(&jointDef);

	m_rectangle.setPosition(position);
	m_rectangle.setSize(size);
	m_rectangle.setOrigin(size * 0.5f);
	m_rectangle.setRotation(orientation);
	m_rectangle.setFillColor(sf::Color::Magenta);
	m_rectangle.setOutlineThickness(0.f);

	/*
	b2MotorJointDef mjd;
	//mjd.bodyA = anchorToBody;
	mjd.bodyA = m_anchor;
	mjd.bodyB = m_body;
	mjd.linearOffset = b2Vec2(m_body->GetPosition().x - anchorToBody m_anchor->GetPosition().x, 0.f);
	mjd.angularOffset = 0.0f;
	mjd.maxForce = 1000.f;
	mjd.maxTorque = 1000.f;

	m_motorJointArm = (b2MotorJoint*)world->CreateJoint(&mjd);
	*/
}

Arm::Arm(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, b2Body * anchorToBody, float orientation, sf::Texture * tex)
{
}

bool Arm::isStopped() const
{
	return m_stopped;
}
/*
void Arm::setJointLinearDistance(b2Vec2 dist)
{
	m_motorJointArm->SetLinearOffset(dist);
}

b2Vec2 Arm::getJointLinearDistance()
{
	return m_motorJointArm->GetLinearOffset();
}
*/
void Arm::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_rectangle);
}

void Arm::update()
{
	b2Vec2 pos = m_body->GetPosition();
	m_rectangle.setPosition(pos.x, pos.y);
	float angle = m_body->GetAngle()* RAD2DEG;
	m_rectangle.setRotation(angle);
}

void Arm::applyImpulse(b2Vec2 impulse)
{
	m_body->ApplyLinearImpulseToCenter(impulse, true);
}

void Arm::applyForce(const sf::Vector2f & force)
{
	m_body->ApplyLinearImpulseToCenter(b2Vec2(force.x, force.y), true);
	m_body->ApplyForceToCenter(b2Vec2(force.x, force.y), true);
}

void Arm::accel(b2Vec2 accel)
{

}