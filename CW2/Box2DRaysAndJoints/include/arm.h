#pragma once

#include <SFML/Graphics.hpp>

#include "physicalThing.h"

class Arm : public PhysicalThing, public sf::Drawable
{
private:
	sf::RectangleShape m_rectangle;
	b2Body * m_anchor;
	b2RevoluteJoint * m_hinge;
	b2MotorJoint * m_motorJointArm; //!< Joint for constraining the paddles movement
	bool m_stopped = false;
public:
	Arm() {}; //!< Default constructor
	Arm(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, b2Body * anchorToBody, float orientation); // Full constructor
	Arm(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, b2Body * anchorToBody, float orientation, sf::Texture * tex); // Full constructor
	void draw(sf::RenderTarget& render, sf::RenderStates states) const; //!< Draw door
	void update();
	void setJointLinearDistance(b2Vec2 dist); //!< Set the joints linear distance
	b2Vec2 getJointLinearDistance(); //!< Get the joints linear distance
	void applyImpulse(b2Vec2 impulse); //!< Apply impulse to the body
	void applyForce(const sf::Vector2f& force);
	void accel(b2Vec2 acc);//!< Apply force to the body
	bool isStopped() const; //!< Has the circle stopped moving
};
