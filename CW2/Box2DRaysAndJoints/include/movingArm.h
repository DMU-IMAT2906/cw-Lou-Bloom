
#pragma once

#include <SFML/Graphics.hpp>

#include "physicalThing.h"

class MovingArm : public PhysicalThing, public sf::Drawable
{
private:
	sf::RectangleShape m_rectangle;
	b2Body * m_anchor;
	b2RevoluteJoint * m_hinge;
	b2MotorJoint * m_motorJointArm; //!< Joint for constraining the paddles movement

	bool m_stopped = false;
public:
	MovingArm() {}; //!< Default constructor
	MovingArm(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor/*, b2Body * anchor2*/, float orientation, sf::Color colour); // Full constructor
	MovingArm(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, float orientation , sf::Texture * tex); // Full constructor
	void draw(sf::RenderTarget& render, sf::RenderStates states) const; //!< Draw door
	void update(); //!< Update rendering infomation 
	void setJointLinearDistance(b2Vec2 dist); //!< Set the joints linear distance
	b2Vec2 getJointLinearDistance(); //!< Get the joints linear distance

	bool isStopped() const; //!< Has the circle stopped moving
};

