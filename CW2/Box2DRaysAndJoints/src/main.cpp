/*!
\file main.cpp
\brief Contains the entry point for the application
*/

#include <Box2D/Box2D.h>

#include <SFML/Graphics.hpp>
#include <iostream>
//#include "collectibleSensor.h"
#include "game.h"

using namespace std;

void main() /** Entry point for the application */
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Box2D Demo"); // Open main window
	Game game;

	float fFrameTime = 1.f / 60.f;

	// Start a clock to provide time for the physics
	sf::Clock clock;

	// Run a game loop
	while (window.isOpen())
	{
		window.clear(sf::Color::White);

		sf::Event event;
		while (window.pollEvent(event))
		{
			// window closed button pressed
			if (event.type == sf::Event::Closed)
				window.close();
			//!< Calls the functions based on the users input 
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Right)
				{
					game.processKeyPress(event.key.code);
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					game.processKeyPress(event.key.code);
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					game.processKeyPress(event.key.code);
				}
				if (event.key.code == sf::Keyboard::Add)
				{
					game.processKeyPress(event.key.code);
				}
				if (event.key.code == sf::Keyboard::Subtract)
				{
					game.processKeyPress(event.key.code);
				}
				if (event.key.code == sf::Keyboard::A)
				{
					game.processKeyPress(event.key.code);
					game.moveBlockLeft();
				}
				if (event.key.code == sf::Keyboard::D)
				{
					game.processKeyPress(event.key.code);
					game.moveBlockRight();
				}
				if (event.key.code == sf::Keyboard::W)
				{
					game.launchBlock();
				}
				if (event.key.code == sf::Keyboard::Tab)
				{
					game.toggleDebug();
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					cout << "GAME OVER" << endl;
					window.clear();
					window.close();
				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
				game.processKeyPress(event.key.code);
				sf::Vector2i mousePosi(event.mouseMove.x, event.mouseMove.y);
				sf::Vector2f mousePosf = window.mapPixelToCoords(mousePosi);
			}
		}
		// Find out how much time has elapsed

		float fElapsedTime = clock.getElapsedTime().asSeconds();
		// If a frame has past then update the physics
		if (fElapsedTime > fFrameTime)
		{
			game.update(fElapsedTime);
			clock.restart();
		}
		window.draw(game);
		window.display();
	}
}