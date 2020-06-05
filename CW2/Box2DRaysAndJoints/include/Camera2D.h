#pragma once

/**
@file camera2D.h
*/
/** \Class Camera2D
* \brief A 2D Camera based on sf::view, includes pan, tilt, zoom and boundaries
*/

#include <SFML/Graphics.hpp>


class Camera2D
{
private:
	sf::View m_view; //!< View used to implement the camera
	sf::FloatRect m_boundaries; //!< Boundary area the camera is allowed to operate in
public:
	sf::View getView() const; //!< Returns the view of the camera
	void setCentre(sf::Vector2f centre); //!< Set the centre of the camera's view
	void setSize(sf::Vector2f size); //!< Set the size of the camera's view
	void setBoundaries(sf::FloatRect boundaries); //!< Set the camera's boundaries
	void pan(sf::Vector2f distance); //!< Move the camera by a given amount
	void tilt(float angle); //!< Rotate the camera by a set amount
	void zoom(float factor); //!< Zoom the camera in by a set amount
};