#include "Camera2D.h"

/**
@file camera2D.cpp
*/

sf::View Camera2D::getView() const
{
	return m_view;
}

void Camera2D::setCentre(sf::Vector2f centre)
{
	m_view.setCenter(centre);
}

void Camera2D::setSize(sf::Vector2f size)
{
	m_view.setSize(size);
}

void Camera2D::setBoundaries(sf::FloatRect boundaries)
{
	m_boundaries = boundaries;
}

void Camera2D::pan(sf::Vector2f distance)
{
	bool topLeft = (m_boundaries.contains(m_view.getCenter() + distance + m_view.getSize()*-0.5f));
	bool bottomLeft = (m_boundaries.contains(m_view.getCenter() + distance + m_view.getSize()*0.5f));
	if (topLeft & bottomLeft)
	{
		m_view.move(distance);
	}
}

void Camera2D::tilt(float angle)
{
	m_view.rotate(angle);
}

void Camera2D::zoom(float factor)
{
	m_view.zoom(factor);
}