#include "Laser.h"
#include "TextureManager.h"
#include "Game.h"

const std::string Laser::m_textureID = "PlayerLaser";
const std::string Laser::m_enemyTextureID = "EnemyLaser";

Laser::Laser()
{
}

Laser::Laser(const float x, const float y, const std::string& ID) :
	m_position(x, y),
	m_ID(ID)
{
	m_movementSpeed = 7;
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_sizeHeight = 70;
	m_sizeWidth = 20;
	m_withinGameBounds = true;
}


Laser::~Laser()
{
}

void Laser::draw()
{
	if (m_ID == "PlayerLaser") {
		TextureManager::instance()->draw(m_position.getX(), m_position.getY(), m_sizeWidth, m_sizeHeight, m_textureID);
	}
	else if (m_ID == "EnemyLaser") {
		TextureManager::instance()->draw(m_position.getX(), m_position.getY(), m_sizeWidth, m_sizeHeight, m_enemyTextureID);
	}
	
}

void Laser::update()
{
	m_velocity = handleDirection();

	m_position += m_velocity;
}


Vector2D & Laser::handleDirection()
{
	Vector2D newVelocity;
	newVelocity.setX(0);
	newVelocity.setY(0);
	
	if(m_ID == "EnemyLaser"){
		newVelocity.setY(m_movementSpeed);
	}
	else if (m_ID == "PlayerLaser") {
		newVelocity.setY(-m_movementSpeed);
	}

	return newVelocity;
}