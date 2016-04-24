#include "EnemyManager.h"
#include "Enemy.h"
#include "Game.h"
#include "CollisionHandler.h"
#include "Timer.h"
#include <iostream>


EnemyManager *EnemyManager::sm_instance = new EnemyManager();

EnemyManager::EnemyManager()
{
	m_nextSpawnTime = 0;
}


EnemyManager::~EnemyManager()
{

}


EnemyManager * EnemyManager::instance()
{
	return sm_instance;
}

void EnemyManager::resetInstance()
{
	delete sm_instance;
	sm_instance = nullptr;
}

void EnemyManager::draw()
{
	for (auto &enemy : m_enemies)
	{
		enemy->draw();
	}
}

void EnemyManager::update()
{
	checkWithinGameBounds();
	spawnEnemy();
	if (m_spawn)
	{
		/*
		afronym: whaterver comes after 'new'
		afronym: you get a pointer to it
		afronym: so new Enemy() -> Enemyj*
		*/
		m_enemies.push_back(std::unique_ptr<SDLGameObject>(new Enemy(Game::instance()->getRandomNumb(0, Game::instance()->getPlayingFieldWidth()))));
		m_spawn = false;
	}

	for (auto &enemy : m_enemies)
	{
		enemy->update();
	}
}

void EnemyManager::spawnEnemy()
{
	if (Timer::instance()->compareToTimePassed(m_nextSpawnTime))
	{
		m_nextSpawnTime += m_timeBetweenSpawn;
		m_spawn = true;
	}
}

void EnemyManager::checkWithinGameBounds()
{
	std::vector<std::unique_ptr<SDLGameObject>>::const_iterator iter;
	//std::vector<SDLGameObject*>::iterator iter;
	for (iter = m_enemies.cbegin(); iter != m_enemies.cend();)
	{
		if (CollisionHandler::gameBoundsHeight(iter->get()))
		{
			//delete iter;
			iter = m_enemies.erase(iter);
		}
		else {
			iter++;
		}
	}
}


