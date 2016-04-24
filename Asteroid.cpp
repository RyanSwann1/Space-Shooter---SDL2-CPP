#include "Asteroid.h"
#include "TextureManager.h"
#include "Game.h"

const std::string Asteroid::m_textureID = "Asteroid";

Asteroid::Asteroid()
{
}

Asteroid::Asteroid(const float x) : m_position(x, -50)
{
	m_movementSpeed = 4;
	m_velocity.setX(0);
	m_velocity.setY(m_movementSpeed);
	m_sizeHeight = 50;
	m_sizeWidth = 50;
}


Asteroid::~Asteroid()
{
}

void Asteroid::draw()
{
	TextureManager::instance()->draw(m_position.getX(), m_position.getY(), m_sizeWidth, m_sizeHeight, m_textureID);
}

void Asteroid::update()
{
	m_position += m_velocity;
}




