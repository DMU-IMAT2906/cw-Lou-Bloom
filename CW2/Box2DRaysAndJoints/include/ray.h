#pragma once

/*!
\file ray.h
*/

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "physicalThing.h"

class Ray : public sf::Drawable
{
private:
	b2World * m_pWorld; //!< Pointer to the Box2D world
	sf::VertexArray m_line; //!< Line to render the ray
	float m_maxLength; //!< Maximum length of the ray
	float m_direction; //!< Direction of the ray
	b2MotorJoint * m_motorJoint; //!< Joint for constraining the paddles movement
public:
	Ray() {}; //!< Default constructor
	Ray(b2World * world, float maxLength, sf::Color colour); //!< Full constructor
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void cast(sf::Vector2f start, float heading, float maxLength); //!< Cast the ray
	void setDirection(float direction); //!< Set ray direction
};