/*!
\file game.cpp
*/
#include "game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	//!< Output some text when the game begins
	cout << "Welcome to the game \n" 
		    "Your goal is to collect all 4 alarm clocks\n"
		    "Use the coffee mug to open the doors\n"
		    "You have 4 health\n"
		    "Watch out for cigarettes and Janice\n"
		    "<----Controls---->\n"
		    "Player:      MoveLeft      = A\n"
		    "             MoveRight     = D\n"
		    "             Jump          = W\n"
		    "Coffee mug:  Aim ray left  = <-\n"
		    "             Aim ray right = ->\n"
		    "             Launch        = spaceBar\n"
		    "Enjoy"
		 << endl;

	//!< Setting the textures used in the game
	m_texBackground.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/dreamWorld.jpg");

	m_texPlayer.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/chandler.png");
	m_texBall.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/coffeeCup.png");
	m_texEnemy.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/janice.png");

	m_texFloor.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/conrete.jpg");
	m_texRoof.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/conrete.jpg");
	m_texWalls.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/bricks.jpg");

	m_texHUD.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/HUD.png");
	m_texCollect.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/tVirus.png");
	m_texCollectible.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/alarmClock.png");
	m_texButton.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/button.png");

	m_texCigarettes.loadFromFile("C:/Users/steft/OneDrive/Documents/My Pictures/CW.pics/cigarettes.jpg");

	m_view.setCenter(0.0f, 0.0f);

	m_pWorld = new b2World(mk_gravity);

	m_debugDraw.setWorld(m_pWorld);
	//!< Setting the rectangle shape used for the the background image behind everything
	m_background.setSize(sf::Vector2f(640.f, 360.f));
	m_background.setPosition(sf::Vector2f(-320.0f, -180.0f));
	m_background.setTexture(&m_texBackground);
	//!<Setting the camera used to view the scene
	m_camera.setCentre(sf::Vector2f(0.0f, 0.0f));
	m_camera.setSize(sf::Vector2f(10.0f, 8.0f));
	m_camera.setBoundaries(sf::FloatRect(0.f, 600.f, 0.f, 600.f));
	//!<Setting the death sensors in the game
	m_dSensorScreen = DeathSensor(m_pWorld, sf::Vector2f(-14.0f, -14.0f), sf::Vector2f(1.5f * 0.5f, 1.0f * 0.5f), 0.f, m_endScreen);
	m_dSensorScreen.setOrigin(sf::Vector2f(5.0f, 4.0f));
	m_dSensorScreen.setUserData(&m_dSensorScreen);
	//!<Player level 1 death sensors
	m_dSensor = DeathSensor(m_pWorld, sf::Vector2f(-7.0f, -0.5f), sf::Vector2f(1.2f * 1.0f, 1.0f * 1.0f), 0.f, m_endScreen);
	m_dSensor.setUserData(&m_dSensorScreen);
	m_dSensor.setTexture(&m_texCigarettes);
	m_dSensor2 = DeathSensor(m_pWorld, sf::Vector2f(-3.0f, -0.5f), sf::Vector2f(1.2f * 1.0f, 1.0f * 1.0f), 0.f, m_endScreen);
	m_dSensor2.setUserData(&m_dSensorScreen);
	m_dSensor2.setTexture(&m_texCigarettes);
	m_dSensor3 = DeathSensor(m_pWorld, sf::Vector2f(1.0f, -0.5f), sf::Vector2f(1.2f * 1.0f, 1.0f * 1.0f), 0.f, m_endScreen);
	m_dSensor3.setUserData(&m_dSensorScreen);
	m_dSensor3.setTexture(&m_texCigarettes);
	//!<Player level 2 death sensors
	m_dSensor4 = DeathSensor(m_pWorld, sf::Vector2f(2.25f, 4.0f), sf::Vector2f(1.5f * 1.5f, 1.0f* 1.0f), 0.f, m_endScreen);
	m_dSensor4.setUserData(&m_dSensorScreen);
	m_dSensor4.setTexture(&m_texCigarettes);
	//!<Ball level 2 death sensors
	m_dSensor5 = DeathSensor(m_pWorld, sf::Vector2f(13.75f, 7.5f), sf::Vector2f(1.1f * 1.1f, 1.0f * 1.0f), 0.f, m_endScreen);
	m_dSensor5.setUserData(&m_dSensorScreen);
	m_dSensor5.setTexture(&m_texCigarettes);
	m_dSensor6 = DeathSensor(m_pWorld, sf::Vector2f(16.2f, 7.9f), sf::Vector2f(1.0f * 1.0f, 1.0f * 0.5f), 0.f, m_endScreen);
	m_dSensor6.setUserData(&m_dSensorScreen);
	m_dSensor6.setTexture(&m_texCigarettes);
	m_dSensor7 = DeathSensor(m_pWorld, sf::Vector2f(20.5f, 4.9f), sf::Vector2f(1.35f * 1.35f, 1.0f * 0.5f), 0.f, m_endScreen);
	m_dSensor7.setUserData(&m_dSensorScreen);
	m_dSensor7.setTexture(&m_texCigarettes);
	//!<Player level 3 death sensors
	m_dSensor8 = DeathSensor(m_pWorld, sf::Vector2f(-4.5f, 13.95f), sf::Vector2f(10.0f * 1.0f, 1.0f * 1.0f), 0.f, m_endScreen);
	m_dSensor8.setUserData(&m_dSensorScreen);
	m_dSensor8.setTexture(&m_texCigarettes);
	m_dSensor9 = DeathSensor(m_pWorld, sf::Vector2f(3.5f, 13.95f), sf::Vector2f(2.0f * 1.0f, 1.0f * 1.0f), 0.f, m_endScreen);
	m_dSensor9.setUserData(&m_dSensorScreen);
	m_dSensor9.setTexture(&m_texCigarettes);
	//!<Ball level 3 death sensors
	m_dSensor10 = DeathSensor(m_pWorld, sf::Vector2f(16.75f, 11.75f), sf::Vector2f(2.0f * 1.0f, 0.5f * 1.0f), 0.f, m_endScreen);
	m_dSensor10.setUserData(&m_dSensorScreen);
	m_dSensor10.setTexture(&m_texCigarettes);
	m_dSensor11 = DeathSensor(m_pWorld, sf::Vector2f(14.5f, 14.2f), sf::Vector2f(3.0f * 1.0f, 0.5f * 1.0f), 0.f, m_endScreen);
	m_dSensor11.setUserData(&m_dSensorScreen);
	m_dSensor11.setTexture(&m_texCigarettes);
	//!<Player level 4 death sensors
	m_dSensor13 = DeathSensor(m_pWorld, sf::Vector2f(-6.0f, 21.7f), sf::Vector2f(3.5f * 1.0f, 1.0f * 0.5f), 0.f, m_endScreen);
	m_dSensor13.setUserData(&m_dSensorScreen);
	m_dSensor13.setTexture(&m_texCigarettes);
	//!<Ball level 4 death sensors
	m_dSensor14 = DeathSensor(m_pWorld, sf::Vector2f(22.5f, 21.5f), sf::Vector2f(4.0f * 1.0f, 1.0f * 0.5f), 0.f, m_endScreen);
	m_dSensor14.setUserData(&m_dSensorScreen);
	m_dSensor14.setTexture(&m_texCigarettes);
	m_dSensor15 = DeathSensor(m_pWorld, sf::Vector2f(13.0f, 21.75f), sf::Vector2f(2.0f * 1.0f, 1.0f * 0.5f), 0.f, m_endScreen);
	m_dSensor15.setUserData(&m_dSensorScreen);
	m_dSensor15.setTexture(&m_texCigarettes);
	//!< Setting the dynamicBlock for the player into the game
	m_player = DynamicBlock(m_pWorld, sf::Vector2f(-9.0f, -2.0f), sf::Vector2f(1.2f, 1.2f));
	m_player.setTexture(&m_texPlayer);
	m_player.setUserData(&m_player);
	//!< Setting the dynamic ball for the playable ball into the game
	m_ballDirection = 0.0f;
	m_ball = DynamicCircle(m_pWorld, sf::Vector2f(11.0f, -2.0f), 0.3f, m_ballDirection);
	m_ball.setTexture(&m_texBall);
	m_ball.setUserData(&m_ball);
	//!< Setting the ray attatched to the ball into the game
	m_ray = Ray(m_pWorld, 20.f, sf::Color::Red);
	m_ray.cast(sf::Vector2f(0.0f, 1.0f), 120, 10);
	//!<Setting the staticBlocks used for the players levels
	m_playerPlatforms.resize(25);
	//!< Level 1 player
	m_playerPlatforms[0] = StaticBlock(m_pWorld, sf::Vector2f(-2.05f, 0.0f), sf::Vector2f(15.7f, 0.1f), 0.f);  
	m_playerPlatforms[0].setTexture(&m_texFloor);
	m_playerPlatforms[1] = StaticBlock(m_pWorld, sf::Vector2f(-9.0f, -1.0f), sf::Vector2f(2.0f, 2.0f), 0.f);
	m_playerPlatforms[1].setTexture(&m_texWalls);
	m_playerPlatforms[2] = StaticBlock(m_pWorld, sf::Vector2f(-5.0f, -2.0f), sf::Vector2f(2.0f, 4.0f), 0.f);
	m_playerPlatforms[2].setTexture(&m_texWalls);
	m_playerPlatforms[3] = StaticBlock(m_pWorld, sf::Vector2f(-1.0f, -2.5f), sf::Vector2f(2.0f, 5.0f), 0.f);
	m_playerPlatforms[3].setTexture(&m_texWalls);
	m_playerPlatforms[4] = StaticBlock(m_pWorld, sf::Vector2f(3.0f, -1.0f), sf::Vector2f(2.0f, 2.0f), 0.f);
	m_playerPlatforms[4].setTexture(&m_texWalls);
	m_playerPlatforms[5] = StaticBlock(m_pWorld, sf::Vector2f(8.4f, -3.5f), sf::Vector2f(3.0f, 0.1f), 0.f);
	m_playerPlatforms[5].setTexture(&m_texWalls);
	//!< Level 2 player
	m_playerPlatforms[6] = StaticBlock(m_pWorld, sf::Vector2f(6.5f, 4.0f), sf::Vector2f(7.0f, 1.0f), 0.f);
	m_playerPlatforms[6].setTexture(&m_texWalls);
	m_playerPlatforms[7] = StaticBlock(m_pWorld, sf::Vector2f(0.0f, 4.0f), sf::Vector2f(3.0f, 1.0f), 0.f);
	m_playerPlatforms[7].setTexture(&m_texWalls);
	m_playerPlatforms[8] = StaticBlock(m_pWorld, sf::Vector2f(-3.0f, 4.25f), sf::Vector2f(3.0f, 0.5f), 0.f);
	m_playerPlatforms[8].setTexture(&m_texWalls);
	m_playerPlatforms[9] = StaticBlock(m_pWorld, sf::Vector2f(-2.05f, 8.0f), sf::Vector2f(15.7f, 0.1f), 0.f);
	m_playerPlatforms[9].setTexture(&m_texFloor);
	//!< Level 3 player
	m_playerPlatforms[10] = StaticBlock(m_pWorld, sf::Vector2f(8.0f, 11.0f), sf::Vector2f(4.0f, 0.5f), 0.f);
	m_playerPlatforms[10].setTexture(&m_texWalls);
	m_playerPlatforms[11] = StaticBlock(m_pWorld, sf::Vector2f(1.5f, 13.5f), sf::Vector2f(2.0f, 2.0f), 0.f);
	m_playerPlatforms[11].setTexture(&m_texWalls);
	m_playerPlatforms[12] = StaticBlock(m_pWorld, sf::Vector2f(-8.5f, 11.0f), sf::Vector2f(3.0f, 0.5f), 0.f);
	m_playerPlatforms[12].setTexture(&m_texWalls);
	m_playerPlatforms[13] = StaticBlock(m_pWorld, sf::Vector2f(-2.05f, 14.5f), sf::Vector2f(15.7f, 0.1f), 0.f);
	m_playerPlatforms[13].setTexture(&m_texFloor);
	//!< Level 4 player
	m_playerPlatforms[14] = StaticBlock(m_pWorld, sf::Vector2f(5.0f, 19.5f), sf::Vector2f(2.0f, 0.2f), 0.f);
	m_playerPlatforms[14].setTexture(&m_texWalls);
	m_playerPlatforms[15] = StaticBlock(m_pWorld, sf::Vector2f(-0.5f, 18.5f), sf::Vector2f(3.0f, 3.0f), 0.f);
	m_playerPlatforms[15].setTexture(&m_texWalls);
	m_playerPlatforms[16] = StaticBlock(m_pWorld, sf::Vector2f(-5.0f, 19.0f), sf::Vector2f(0.6f, 0.6f), 0.f);
	m_playerPlatforms[16].setTexture(&m_texWalls);
	m_playerPlatforms[17] = StaticBlock(m_pWorld, sf::Vector2f(-9.0f, 21.0f), sf::Vector2f(2.0f, 2.0f), 0.f);
	m_playerPlatforms[17].setTexture(&m_texWalls);
	m_playerPlatforms[18] = StaticBlock(m_pWorld, sf::Vector2f(0.0f, 22.0f), sf::Vector2f(20.0f, 0.1f), 0.f);
	m_playerPlatforms[18].setTexture(&m_texFloor);
	//!< Level boundaries
	m_playerPlatforms[19] = StaticBlock(m_pWorld, sf::Vector2f(0.0f, -7.9f), sf::Vector2f(20.0f, 0.1f), 0.f);
	m_playerPlatforms[19].setTexture(&m_texFloor);
	m_playerPlatforms[20] = StaticBlock(m_pWorld, sf::Vector2f(-10.0f, 7.0f), sf::Vector2f(0.1f, 30.0f), 0.f);
	m_playerPlatforms[20].setTexture(&m_texFloor);
	m_playerPlatforms[21] = StaticBlock(m_pWorld, sf::Vector2f(10.0f, 7.0f), sf::Vector2f(0.1f, 30.0f), 0.f);
	m_playerPlatforms[21].setTexture(&m_texFloor);
	//!< Anchor for moving platforms
	m_playerPlatforms[22] = StaticBlock(m_pWorld, sf::Vector2f(-15.5f, 7.0f), sf::Vector2f(2.0f, 2.0f), 0.f);
	m_playerPlatforms[22].setFillColor(sf::Color::Red);
	m_playerPlatforms[23] = StaticBlock(m_pWorld, sf::Vector2f(-15.5f, 12.0f), sf::Vector2f(2.0f, 2.0f), 0.f);
	m_playerPlatforms[23].setFillColor(sf::Color::Red);
	m_playerPlatforms[24] = StaticBlock(m_pWorld, sf::Vector2f(-15.5f, 21.3f), sf::Vector2f(2.0f, 2.0f), 0.f);
	m_playerPlatforms[24].setFillColor(sf::Color::Red);
	//!< Player level 2 moving platform
	m_movingPlatform1 = Paddle(m_pWorld, sf::Vector2f(-2.0f, 7.0f), sf::Vector2f(1.0f, 1.0f), 0.0f, m_playerPlatforms[22].getBody());
	m_movingPlatform1.setUserData(&m_movingPlatform1);
	m_movingPlatform1.setTexture(&m_texEnemy);
	m_movingPlatform2 = Paddle(m_pWorld, sf::Vector2f(-6.0f, 11.0f), sf::Vector2f(2.0f, 0.5f), 0.0f, m_playerPlatforms[23].getBody());
	m_movingPlatform2.setUserData(&m_movingPlatform2);
	m_movingPlatform2.setTexture(&m_texFloor);
	m_movingPlatform3 = Paddle(m_pWorld, sf::Vector2f(-0.5f, 21.3f), sf::Vector2f(1.0f, 1.0f), 0.0f, m_playerPlatforms[24].getBody());
	m_movingPlatform3.setUserData(&m_movingPlatform3);
	m_movingPlatform3.setTexture(&m_texEnemy);

	//!<Setting the staticBlocks for the ball levels
	m_ballPlatforms.resize(31);
	//!< Ball level 1
	m_ballPlatforms[0] = StaticBlock(m_pWorld, sf::Vector2f(13.5f, 0.0f), sf::Vector2f(7.0f, 0.1f), 0.f);
	m_ballPlatforms[0].setTexture(&m_texFloor);
	m_ballPlatforms[1] = StaticBlock(m_pWorld, sf::Vector2f(11.0f, -1.5f), sf::Vector2f(2.0f, 3.0f), 0.f);
	m_ballPlatforms[1].setTexture(&m_texWalls);
	m_ballPlatforms[2] = StaticBlock(m_pWorld, sf::Vector2f(13.0f, -1.0f), sf::Vector2f(3.0f, 2.0f), 0.f);
	m_ballPlatforms[2].setTexture(&m_texWalls);
	m_ballPlatforms[3] = StaticBlock(m_pWorld, sf::Vector2f(16.5f, -4.5f), sf::Vector2f(4.0f, 0.1f), 0.f);
	m_ballPlatforms[3].setTexture(&m_texWalls);
	m_ballPlatforms[4] = StaticBlock(m_pWorld, sf::Vector2f(14.55f, -5.05f), sf::Vector2f(0.1f, 1.0f), 0.f);
	m_ballPlatforms[4].setTexture(&m_texWalls);
	m_ballPlatforms[5] = StaticBlock(m_pWorld, sf::Vector2f(17.0f, -6.75f), sf::Vector2f(0.1f, 2.5f), 0.f);
	m_ballPlatforms[5].setTexture(&m_texWalls);
	m_ballPlatforms[6] = StaticBlock(m_pWorld, sf::Vector2f(14.0f, -2.95f), sf::Vector2f(4.0f, 0.1f), 0.f);
	m_ballPlatforms[6].setTexture(&m_texWalls);
	m_ballPlatforms[7] = StaticBlock(m_pWorld, sf::Vector2f(23.0f, -4.0f), sf::Vector2f(3.0f, 8.0f), 0.f);
	m_ballPlatforms[7].setTexture(&m_texWalls);
	m_ballPlatforms[8] = StaticBlock(m_pWorld, sf::Vector2f(20.0f, -6.25f), sf::Vector2f(3.0f, 3.5f), 0.f);
	m_ballPlatforms[8].setTexture(&m_texWalls);
	m_ballPlatforms[9] = StaticBlock(m_pWorld, sf::Vector2f(18.0f, 0.0f), sf::Vector2f(2.0f, 0.1f), 0.f);
	m_ballPlatforms[9].setTexture(&m_texWalls);
	//!<Ball level 2
	m_ballPlatforms[10] = StaticBlock(m_pWorld, sf::Vector2f(23.0f, 6.0f), sf::Vector2f(3.0f, 4.0f), 0.f);
	m_ballPlatforms[10].setTexture(&m_texWalls);
	m_ballPlatforms[11] = StaticBlock(m_pWorld, sf::Vector2f(20.5f, 6.5f), sf::Vector2f(2.0f, 3.0f), 0.f);
	m_ballPlatforms[11].setTexture(&m_texWalls);
	m_ballPlatforms[12] = StaticBlock(m_pWorld, sf::Vector2f(17.3f, 2.5f), sf::Vector2f(0.3f, 5.0f), 0.f);
	m_ballPlatforms[12].setTexture(&m_texWalls);
	m_ballPlatforms[13] = StaticBlock(m_pWorld, sf::Vector2f(18.25f, 8.0f), sf::Vector2f(12.5f, 0.1f), 0.f);
	m_ballPlatforms[13].setTexture(&m_texFloor);
	m_ballPlatforms[14] = StaticBlock(m_pWorld, sf::Vector2f(15.0f, 7.0f), sf::Vector2f(1.0f, 2.0f), 0.f);
	m_ballPlatforms[14].setTexture(&m_texWalls);
	m_ballPlatforms[15] = StaticBlock(m_pWorld, sf::Vector2f(12.5f, 6.5f), sf::Vector2f(1.0f, 3.0f), 0.f);
	m_ballPlatforms[15].setTexture(&m_texWalls);
	//!< Ball level 3
	m_ballPlatforms[16] = StaticBlock(m_pWorld, sf::Vector2f(11.5f, 14.2f), sf::Vector2f(3.0f, 0.6f), 0.f);
	m_ballPlatforms[16].setTexture(&m_texWalls);
	m_ballPlatforms[17] = StaticBlock(m_pWorld, sf::Vector2f(19.0f, 14.2f), sf::Vector2f(6.0f, 0.6f), 0.f);
	m_ballPlatforms[17].setTexture(&m_texWalls);
	m_ballPlatforms[18] = StaticBlock(m_pWorld, sf::Vector2f(19.3f, 12.0f), sf::Vector2f(10.25f, 0.1f), 0.f);
	m_ballPlatforms[18].setTexture(&m_texWalls);
	m_ballPlatforms[19] = StaticBlock(m_pWorld, sf::Vector2f(16.0f, 14.5f), sf::Vector2f(12.0f, 0.1f), 0.f);
	m_ballPlatforms[19].setTexture(&m_texFloor);
	m_ballPlatforms[20] = StaticBlock(m_pWorld, sf::Vector2f(19.0f, 9.25f), sf::Vector2f(0.5f, 2.5f), 0.f);
	m_ballPlatforms[20].setTexture(&m_texWalls);
	m_ballPlatforms[21] = StaticBlock(m_pWorld, sf::Vector2f(14.5f, 9.25f), sf::Vector2f(0.5f, 2.5f), 0.f);
	m_ballPlatforms[21].setTexture(&m_texWalls);
	//!< Ball level 4
	m_ballPlatforms[22] = StaticBlock(m_pWorld, sf::Vector2f(23.25f, 19.0f), sf::Vector2f(2.5f, 1.0f), 0.f);
	m_ballPlatforms[22].setTexture(&m_texWalls);
	m_ballPlatforms[23] = StaticBlock(m_pWorld, sf::Vector2f(18.5f, 19.0f), sf::Vector2f(5.0f, 0.5f), 0.f);
	m_ballPlatforms[23].setTexture(&m_texWalls);
	m_ballPlatforms[24] = StaticBlock(m_pWorld, sf::Vector2f(16.0f, 21.75f), sf::Vector2f(4.0f, 0.5f), 0.f);
	m_ballPlatforms[24].setTexture(&m_texWalls);
	m_ballPlatforms[25] = StaticBlock(m_pWorld, sf::Vector2f(11.0f, 21.0f), sf::Vector2f(2.0f, 2.0f), 0.f);
	m_ballPlatforms[25].setTexture(&m_texWalls);
	m_ballPlatforms[26] = StaticBlock(m_pWorld, sf::Vector2f(17.25f, 22.0f), sf::Vector2f(14.5f, 0.1f), 0.f);
	m_ballPlatforms[26].setTexture(&m_texWalls);
	m_ballPlatforms[27] = StaticBlock(m_pWorld, sf::Vector2f(22.5f, 21.75f), sf::Vector2f(4.0f, 0.5f), 0.f);
	m_ballPlatforms[27].setTexture(&m_texWalls);
	m_ballPlatforms[28] = StaticBlock(m_pWorld, sf::Vector2f(17.95f, 21.15f), sf::Vector2f(0.1f, 0.7f), 0.f);
	m_ballPlatforms[28].setTexture(&m_texWalls);
	//!< Level walls
	m_ballPlatforms[29] = StaticBlock(m_pWorld, sf::Vector2f(24.5f, 7.0f), sf::Vector2f(0.1f, 30.0f), 0.f);
	m_ballPlatforms[29].setTexture(&m_texFloor);
	m_ballPlatforms[30] = StaticBlock(m_pWorld, sf::Vector2f(17.25f, -7.9f), sf::Vector2f(14.5f, 0.1f), 0.f);
	m_ballPlatforms[30].setTexture(&m_texFloor);
	//!<Setting the sliding doors in game and the open sensors for the doors
	m_door = SlidingDoor(m_pWorld, sf::Vector2f(6.895, 0.0), 0.0f);
	m_open = OpenDoorSensor(m_pWorld, sf::Vector2f(18.0f, -6.0f), sf::Vector2f(1.0f * 0.5f, 1.0f * 0.5f), 0.f, &m_door);
	m_open.setUserData(&m_open);                  
	m_open.setTexture(&m_texButton);
	m_door2 = SlidingDoor(m_pWorld, sf::Vector2f(6.895, 8.0), 0.0f);
	m_open2 = OpenDoorSensor(m_pWorld, sf::Vector2f(12.5f, 2.5f), sf::Vector2f(1.0f * 0.5f, 1.0f * 0.5f), 0.f, &m_door2);
	m_open2.setUserData(&m_open2);                
	m_open2.setTexture(&m_texButton);
	m_door3 = SlidingDoor(m_pWorld, sf::Vector2f(6.895, 14.5), 0.0f);
	m_open3 = OpenDoorSensor(m_pWorld, sf::Vector2f(21.0f, 11.5f), sf::Vector2f(1.0f * 0.5f, 1.0f * 0.5f), 0.f, &m_door3);
	m_open3.setUserData(&m_open3);                
	m_open3.setTexture(&m_texButton);
	//!<Setting the rectangle shape in the top left corner
	m_HUD.setOrigin(sf::Vector2f(5.0f, 4.0f));
	m_HUD.setSize(sf::Vector2f(3.5f, 0.5f));
	m_HUD.setTexture(&m_texHUD);
	//!<Setting the rectangle shape used for the game over screen by the death sensors
	m_endScreen.setOrigin(sf::Vector2f(0.0f, 0.0f));
	//!<Setting the rectangle shape used for the won screen by the collectible sensors
	m_wonScreen.setOrigin(sf::Vector2f(0.0f, 0.0f));
	//!<Setting the collectible sensors into the game
	m_cSensorScreen = CollectibleSensor(m_pWorld, sf::Vector2f(-13.0f, -13.0f), sf::Vector2f(0.6f * 0.5f, 0.6f * 0.6f), 0.f, m_wonScreen);
	m_cSensorScreen.setOrigin(sf::Vector2f(5.0f, 4.0f));
	m_cSensorScreen.setUserData(&m_cSensorScreen);
	//!< Player level 1 collectible sensor
	m_cSensor = CollectibleSensor(m_pWorld, sf::Vector2f(9.0f, -4.0f), sf::Vector2f(0.5f * 1.0f, 0.5f * 1.0f), 0.f, m_wonScreen);
	m_cSensor.setUserData(&m_cSensorScreen);
	m_cSensor.setTexture(&m_texCollectible);
	//!< Player level 2 collectible sensor
	m_cSensor2 = CollectibleSensor(m_pWorld, sf::Vector2f(2.25f, 5.0f), sf::Vector2f(0.5f * 1.0f, 0.5f * 1.0f), 0.f, m_wonScreen);
	m_cSensor2.setUserData(&m_cSensorScreen);
	m_cSensor2.setTexture(&m_texCollectible);
	//!< Player level 3 collectible sensor
	m_cSensor3 = CollectibleSensor(m_pWorld, sf::Vector2f(-8.5f, 10.0f), sf::Vector2f(0.5f * 1.0f, 0.5f * 1.0f), 0.f, m_wonScreen);
	m_cSensor3.setUserData(&m_cSensorScreen);
	m_cSensor3.setTexture(&m_texCollectible);
	//!< Player level 4 collectible sensor
	m_cSensor4 = CollectibleSensor(m_pWorld, sf::Vector2f(-9.0f, 19.0f), sf::Vector2f(0.5f * 1.0f, 0.5f * 1.0f), 0.f, m_endScreen);
	m_cSensor4.setUserData(&m_cSensorScreen);
	m_cSensor4.setTexture(&m_texCollectible);
	//!< Ball level 4 collectible sensor
	m_cSensor5 = CollectibleSensor(m_pWorld, sf::Vector2f(19.5f, 21.5f), sf::Vector2f(0.5f * 1.0f, 0.5f * 1.0f), 0.f, m_endScreen);
	m_cSensor5.setUserData(&m_cSensorScreen);
	m_cSensor5.setTexture(&m_texCollectible);
	//!< Setting the worlds contact listener as m_listener
	m_pWorld->SetContactListener(&m_listener);
}

Game::~Game()
{
	delete m_pWorld;
	m_pWorld = nullptr;
}

void Game::update(float timestep)
{
	//!< This sets the direction position and distance for the platforms to move the jointLinearDistances for each
	float distY = m_movingPlatform1.getJointLinearDistance().y;
	float distX = 0.0f;
	if (m_paddleRight) {
		float deltaPos = -paddleSpeed * timestep;
		distX = m_movingPlatform1.getJointLinearDistance().x + deltaPos;
		if (distX < 10.0f) {
			distX = 10.0;
			m_paddleRight = !m_paddleRight; } }
	else {
		float deltaPos = paddleSpeed * timestep;
		distX = m_movingPlatform1.getJointLinearDistance().x + deltaPos;
		if (distX > 13.0f) {
			distX = 13.0;
			m_paddleRight = !m_paddleRight; } }
	m_movingPlatform1.setJointLinearDistance(b2Vec2(distX, distY));

	float distY2 = m_movingPlatform2.getJointLinearDistance().y;
	float distX2 = 0.0f;
	if (m_paddleRight2) 
	{
		float deltaPos = -paddleSpeed * timestep;
		distX2 = m_movingPlatform2.getJointLinearDistance().x + deltaPos;
		if (distX2 < 11.0f) 
		{
			distX2 = 11.0;
			m_paddleRight2 = !m_paddleRight2; 
		} 
	}
	else {
		float deltaPos = paddleSpeed * timestep;
		distX2 = m_movingPlatform2.getJointLinearDistance().x + deltaPos;

		if (distX2 > 15.0f) {
			distX2 = 15.0;
			m_paddleRight2 = !m_paddleRight2; } }
	m_movingPlatform2.setJointLinearDistance(b2Vec2(distX2, distY2));

	float distY3 = m_movingPlatform3.getJointLinearDistance().y;
	float distX3 = 0.0f;
	if (m_paddleRight3) 
	{
		float deltaPos = -paddleSpeed * timestep;
		distX3 = m_movingPlatform3.getJointLinearDistance().x + deltaPos;
		if (distX3 < 13.0f) 
		{
			distX3 = 13.0;
			m_paddleRight3 = !m_paddleRight3; 
		} 
	}
	else 
	{
		float deltaPos = paddleSpeed * timestep;
		distX3 = m_movingPlatform3.getJointLinearDistance().x + deltaPos;
		if (distX3 > 16.0f) 
		{
			distX3 = 16.0;
			m_paddleRight3 = !m_paddleRight3; 
		} 
	}
	m_movingPlatform3.setJointLinearDistance(b2Vec2(distX3, distY3));
	
	// Update the world
	m_pWorld->Step(timestep, mk_iVelIterations, mk_iVelIterations);

	// Update all game objects - updates rendering positions
	//!< This sets the positions to the players position so that they move with the player
	m_camera.setCentre(m_player.getPosition());
	m_dSensorScreen.setPosition(m_player.getPosition());
	m_cSensorScreen.setPosition(m_player.getPosition());
	m_HUD.setPosition(m_player.getPosition());

	m_player.update();
	m_ball.update();

	m_movingPlatform1.update();
	m_movingPlatform2.update();
	m_movingPlatform3.update();

	m_door.update(timestep);
	m_door2.update(timestep);
	m_door3.update(timestep);

	if (m_ball.isStopped())
	{
		m_ray.setDirection(m_ballDirection);
		m_ray.cast(sf::Vector2f(m_ball.getPosition()), 120, 6);
	}

	// Delete debug shapes
	if (m_debug) m_debugDraw.clear();
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Set the view
	target.setView(m_camera.getView());

	target.draw(m_background);
	// Draw all game objects

	for (auto block : m_playerPlatforms) target.draw(block);
	for (auto block : m_ballPlatforms) target.draw(block);

	target.draw(m_player);

	target.draw(m_ray);
	target.draw(m_ball);

	target.draw(m_movingPlatform1);
	target.draw(m_movingPlatform2);
	target.draw(m_movingPlatform3);

	target.draw(m_dSensor);
	target.draw(m_dSensor2);
	target.draw(m_dSensor3);
	target.draw(m_dSensor4);
	target.draw(m_dSensor5);
	target.draw(m_dSensor6);
	target.draw(m_dSensor7);
	target.draw(m_dSensor8);
	target.draw(m_dSensor9);
	target.draw(m_dSensor10);
	target.draw(m_dSensor11);
	target.draw(m_dSensor13);
	target.draw(m_dSensor14);
	target.draw(m_dSensor15);
	target.draw(m_dSensorScreen);

	target.draw(m_cSensor2);
	target.draw(m_cSensor3);
	target.draw(m_cSensor4);
	target.draw(m_cSensor5);
	target.draw(m_cSensor);
	target.draw(m_cSensorScreen);

	target.draw(m_HUD);

	target.draw(m_open);
	target.draw(m_open2);
	target.draw(m_open3);

	if (!m_debug) target.draw(m_door);
	if (!m_debug) target.draw(m_door2);
	if (!m_debug) target.draw(m_door3);

	if (m_ball.isStopped()) target.draw(m_ray);
	// Debug Draw
	if (m_debug) target.draw(m_debugDraw);
}

void Game::toggleDebug()
{
	m_debug = !m_debug;
}

void Game::processKeyPress(sf::Keyboard::Key code)
{
	switch (code)
	{
	case sf::Keyboard::Tab:
		toggleDebug();
		break;
		//!<Applying force to the ball based on the balls direction and whether its stopped
	case sf::Keyboard::Space:
		if (m_ball.isStopped()) m_ball.applyImpulse(b2Vec2(3.0f * cosf(m_ballDirection), 3.0f * sinf(m_ballDirection)));
		break;
		//!< Applies force to the ball based on its direction
	case sf::Keyboard::Right:
		m_ballDirection += 0.05f;
		if (m_ballDirection > 2.0f * M_PI) m_ballDirection -= 2.0f * M_PI;
		break;
		//!< Applies force to the ball based on its direction
	case sf::Keyboard::Left:
		m_ballDirection -= 0.05f;
		if (m_ballDirection < 0.0f) m_ballDirection += 2.0f * M_PI;
		break;
	case sf::Keyboard::A:
		m_camera.pan(sf::Vector2f(-10.0f, 0.0f));
		break;
	case sf::Keyboard::D:
		m_camera.pan(sf::Vector2f(-10.0f, 0.0f));
		break;
		//!< Zooms the camera out and back in
	case sf::Keyboard::Subtract:
		m_camera.zoom(1.1f);
		break;
	case sf::Keyboard::Add:
		m_camera.zoom(0.9f);
		break;
	}
}
//!< Applies force to the player based on the functions in the dynamic block class
void Game::launchBlock() { m_player.applyForce(sf::Vector2f(0.0f, -10.0f)); }
void Game::moveBlockLeft() { m_player.applyForce(sf::Vector2f(-0.9f, 0.0f)); }
void Game::moveBlockRight() { m_player.applyForce(sf::Vector2f(0.9f, 0.0f)); }