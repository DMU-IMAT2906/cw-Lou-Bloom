
#include "collectibleSensor.h"
using namespace std;

CollectibleSensor::CollectibleSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, RectangleShape won)//, Score * coinScore)//, StaticCircle * coin)//, sf::CircleShape * coin)
{
	m_texWonScreen.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/wonScreen.png");
	initRectangle(world, position, size, orientation);
	won = WonScreen;

	iScore = 0;
	iTotal = 0;
}
void CollectibleSensor::onAction(b2Body * other)
{
	//!<Increase the iScore variable and iTotal variable upon a contact beginning
	//!<Also when iTotal equals 4 it draws the rectangle shape
	iScore = iScore + 1;
	iTotal = iScore;
	cout << iTotal << endl;
	if (iTotal >= 4) 
	{
		cout << "Done baby " << endl; 
		setSize(sf::Vector2f(10.0f, 8.0f));
		setTexture(&m_texWonScreen);
		WonScreen.move(sf::Vector2f(-20.0f, -20.0f));
	}
}