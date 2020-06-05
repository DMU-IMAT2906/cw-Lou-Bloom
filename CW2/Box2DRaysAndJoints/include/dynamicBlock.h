#pragma once
/*!
\file dynamicSquare.h
*/
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"

class DynamicBlock : public sf::RectangleShape, public PhysicalThing
{
private:
	bool m_stopped = false;
public:
	DynamicBlock() {};//!< Default constructor
	DynamicBlock(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size/*, const float orientation*/); //!< Complete contructor
	void update(); //!< Update rendering infomation 
	void applyImpulse(b2Vec2 impulse); //!< Apply impulse to the body
	void applyForce(const sf::Vector2f& force);
	void accel(b2Vec2 acc);//!< Apply force to the body
	bool isStopped() const; //!< Checks whether the block stopped moving
};