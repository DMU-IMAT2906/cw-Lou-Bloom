#pragma once

/*!
\file staticBlock.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"

/*! \class StaticBlock
\brief A simple block which can not move or rotate but can collide with stuff
*/

class StaticBlock : public sf::RectangleShape, public PhysicalThing
{
public:
	StaticBlock() {}; //!< Default Contructor;
	StaticBlock(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation); //!< Complete contructor
};