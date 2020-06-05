/*!
\file deathSensor.cpp
*/
#include "deathSensor.h"
using namespace std;

DeathSensor::DeathSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, RectangleShape dead)//, Score * coinScore)//, StaticCircle * coin)//, sf::CircleShape * coin)
{
	m_texDeadScreen.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/GameOverScreen.png");
	initRectangleHit(world, position, size, orientation);
	dead = deadScreen;
	iDamage = 0;
	iLife = 0;
}
//!< When the player touches the sensor the int iDamage increase each contact until it reaches 10 then it displays the gameOverScreen rectangle shape
void DeathSensor::onActionDeath(b2Body * other) 
{
	iDamage = iDamage + 1;
	iLife = iDamage;

	cout << "You've taken " << iDamage << " damage" << endl;

	if (iLife >= 10) 
	{
		setSize(sf::Vector2f(10.0f, 8.0f));
		setTexture(&m_texDeadScreen);
		deadScreen.move(sf::Vector2f(-20.0f, -20.0f));
	}
}