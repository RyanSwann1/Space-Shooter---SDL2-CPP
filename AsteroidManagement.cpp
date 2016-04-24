#include "AsteroidManagement.h"
#include "Asteroid.h"
#include "Game.h"
#include "CollisionHandler.h"
#include "Timer.h"
#include <SDL.h>
#include <iostream>
AsteroidManagement * AsteroidManagement::sm_instance = new AsteroidManagement();

AsteroidManagement::AsteroidManagement()
{
	m_nextSpawnTime = 0;
	m_spawnAsteroid = true;
}


AsteroidManagement::~AsteroidManagement()
{
}


void AsteroidManagement::update()
{
	spawnAsteroids();
	checkAsteroidBounds();
	//std::cout << m_asteroids.size() << "\n";

	if (m_spawnAsteroid)
	{	
		m_asteroids.push_back(std::unique_ptr<SDLGameObject>(new Asteroid(Game::instance()->getRandomNumb(0, Game::instance()->getPlayingFieldWidth()))));
		m_spawnAsteroid = false;
	}

	//Controls movement of all asteroids
	for (auto &asteroid : m_asteroids)
	{
		asteroid->update();
	}
}

void AsteroidManagement::draw()
{
	for (auto &asteroid : m_asteroids)
	{
		asteroid->draw();
	}
}

void AsteroidManagement::checkAsteroidBounds()
{
	std::vector<std::unique_ptr<SDLGameObject>>::const_iterator iter;
	for (iter = m_asteroids.cbegin(); iter != m_asteroids.cend();)
	{
		if (CollisionHandler::gameBoundsHeight(iter->get()))
		{
			iter = m_asteroids.erase(iter);
		}
		else {
			iter++;
		}
	}
}

void AsteroidManagement::spawnAsteroids()
{
	if (Timer::instance()->compareToTimePassed(m_nextSpawnTime))
	{
		m_nextSpawnTime += m_timeBetweenSpawn;
		m_spawnAsteroid = true;
	}
}


AsteroidManagement * AsteroidManagement::instance()
{
	return sm_instance;
}

void AsteroidManagement::resetInstance()
{
	delete sm_instance;
	sm_instance = nullptr;
}

