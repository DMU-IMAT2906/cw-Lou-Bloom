#pragma once

/*!
\file paddle.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"

/*! \class Paddle
\brief A simple block which is moved by a motor joint
*/

class Paddle : public sf::RectangleShape, public PhysicalThing
{
private:
	b2MotorJoint * m_motorJoint; //!< Joint for constraining the paddles movement
public:
	Paddle() {}; //!< Default Constructor
	Paddle(b2World * world, sf::Vector2f position, sf::Vector2f size, const float orientation, b2Body * anchor); //!< Complete contructor
	void update(); //!< Update rendering infomation
	void setJointLinearDistance(b2Vec2 dist); //!< Set the joints linear distance
	b2Vec2 getJointLinearDistance(); //!< Get the joints linear distance
};