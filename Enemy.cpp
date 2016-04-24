#include "Enemy.h"
#include "TextureManager.h"
#include "LaserHandler.h"
#include "Timer.h"
#include <iostream>
const std::string Enemy::m_textureID = "EnemyShip"; //Texture ID

Enemy::Enemy()
{
}

Enemy::Enemy(const float x) : m_position(x, -50)
{
	m_sizeHeight = 50;
	m_sizeWidth = 50;
	m_movementSpeed = 2;
	m_velocity.setX(0);
	m_velocity.setY(m_movementSpeed);
	m_nextFireTime = 0;
}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	TextureManager::instance()->draw(m_position.getX(), m_position.getY(), m_sizeWidth, m_sizeHeight, m_textureID);
}

void Enemy::update()
{
	//Fire laser
	shoot();

	m_position += m_velocity;
}

void Enemy::shoot()
{
	if (Timer::instance()->compareToTimePassed(m_nextFireTime))
	{
		m_nextFireTime += m_timeBetweenShots;
		LaserHandler::instance()->addLaser(*this, "EnemyLaser");
	}
}
