#pragma once

/*!
\file game.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include <vector>

#include "SFMLDebugDraw.h"

#include "Camera2D.h"
#include "paddle.h"
#include "dynamicCircle.h"
#include "dynamicBlock.h"
#include "staticBlock.h"
#include "slidingDoor.h"
#include "openDoorSensor.h"
#include "SensorContactListener.h"
#include "collectibleSensor.h"
#include "deathSensor.h"
#include "ray.h"

#define _USE_MATH_DEFINES
#include <math.h>

/*! \class Game
\brief Holds all information about the game, blocks, balls etc and allows updating and rendering.
*/

class Game : public sf::Drawable {
private:
	sf::View m_view; //!< The view maps from physical co-ordinates to rendering co-ordinates
	sf::Vector2f m_worldSize = sf::Vector2f(8.f, 6.f); //!< Size of the physical worlds is 8 X 6 metres

	b2World* m_pWorld = nullptr; //!< Pointer to the Box2D world.  Using pointers as BOX2D has it's own memory management
	const int mk_iVelIterations = 7; //!< On each update there will be 7 velocity iterations in the physics engine
	const int mk_iPosIterations = 5; //!< On each update there will be 5 position iterations on each update
	const b2Vec2 mk_gravity = b2Vec2(0.f, 9.81f); //!< Standard earth gravity will be used (negate the value ofcourse!)

	SensorContactListener m_listener;
	bool m_debug = false; //!< Toggle for debug drawing
	SFMLDebugDraw m_debugDraw; //!< Box2D debug drawing

	sf::Texture m_texBackground; //!< Texture to be used by picture as background

	sf::Texture m_texBall; //!< Texture to be used by dynamic circle
	sf::Texture m_texPlayer; //!< Texture to be used by dynamic blocks

	sf::Texture m_texFloor; //!< Texture to be used by static blocks
	sf::Texture m_texRoof; //!< Texture to be used by static blocks
	sf::Texture m_texWalls; //!< Texture to be used by static blocks

	sf::Texture m_texCollectible; //!< Texture for the collectibles in the game
	sf::Texture m_texButton;
	sf::Texture m_texHUD;
	sf::Texture m_texCollect;

	sf::Texture m_texCigarettes;
	sf::Texture m_texEnemy;

	sf::RectangleShape m_background;
	Camera2D m_camera; //!< View used to zoom in to the scene

	DynamicCircle m_ball; //!< Pong puck
	float m_ballDirection;//!< float variable for the direction the ball is facing

	sf::RectangleShape m_HUD;

	std::vector<StaticBlock> m_playerPlatforms; //!< Walls
	std::vector<StaticBlock> m_ballPlatforms;

	Paddle m_movingPlatform3; //!< Moving block
	Paddle m_movingPlatform4; //!< Moving block
	Paddle m_movingPlatform1; //!< Moving block
	Paddle m_movingPlatform2; //!< Moving block

	SlidingDoor m_door; //!< A sliding door with timer
	SlidingDoor m_door2;
	SlidingDoor m_door3;
	SlidingDoor m_door4;
	OpenDoorSensor m_open;
	OpenDoorSensor m_open2;
	OpenDoorSensor m_open3;
	OpenDoorSensor m_open4;

	DeathSensor m_dSensorScreen;
	DeathSensor m_dSensor;
	DeathSensor m_dSensor2;
	DeathSensor m_dSensor3;
	DeathSensor m_dSensor4;
	DeathSensor m_dSensor5;
	DeathSensor m_dSensor6;
	DeathSensor m_dSensor7;
	DeathSensor m_dSensor8;
	DeathSensor m_dSensor9;
	DeathSensor m_dSensor10;
	DeathSensor m_dSensor11;
	DeathSensor m_dSensor13;
	DeathSensor m_dSensor14;
	DeathSensor m_dSensor15;

	CollectibleSensor m_cSensorScreen;
	CollectibleSensor m_cSensor; //!< A sensor for the collectibles throughout the game
	CollectibleSensor m_cSensor2;
	CollectibleSensor m_cSensor3;
	CollectibleSensor m_cSensor4;
	CollectibleSensor m_cSensor5;

	sf::RectangleShape m_wonScreen;
	sf::RectangleShape m_endScreen;

	float paddleSpeed = 2.0f;
	bool m_paddleRight; //!< Moving right
	bool m_paddleRight2; //!< Moving right
	bool m_paddleRight3; //!< Moving right

	Ray m_ray; //!< The ray
	DynamicBlock m_player;//!< The player body

	float m_blockDirection;//!<Variable for the direction the block is facing
public:
	Game(); //!< Constructor which sets up the game
	~Game(); //!< Destructor which cleans all the pointer memory up

	void update(float timestep); //!< Update the game with give timestep
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< Draw the game to the render context
	void toggleDebug(); //!< Toggle for debug drawing

	//void keyPress(sf::Keyboard::Key key); //!< Actions relevant key events
	void processKeyPress(sf::Keyboard::Key code); //!< Process user key press

	void launchBlock(); //!< Give dynamic block some impluse to launch it upwards
	void moveBlockLeft(); //!< Give dynamic block some impluse left
	void moveBlockRight(); //!< Give dynamic block some impluse right

	float topBoundary = (0.0, 0.0);
	float bottomBoundary = (200.0, 320.0);
	float leftBoundary = (0.0, -320.0);
	float rightBoundary = (400.0, -320.0);
};
