#pragma once

/*!
\file collectibleSensor.h
*/

#include "staticSensor.h"

class CollectibleSensor : public StaticSensor
{
public:
	CollectibleSensor() {}; //!< Default constructor
	CollectibleSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, RectangleShape won);//, StaticCircle * coin);// , sf::CircleShape * coin);
	void onAction(b2Body * other);//!< Function used for the collectible sensor to add to score etc
	void offAction(b2Body * other) {};//!< Function used for the collectible sensor to add to score etc

	int iScore;//!< int for each contact between the sensor and another body
	int iTotal;//!< int for adding all the contact instances

	sf::RectangleShape WonScreen;//!< The rectangle shape that appears when the iTotal reaches a certain value
	sf::Texture m_texWonScreen;//!<The texture used by WonScreen
};