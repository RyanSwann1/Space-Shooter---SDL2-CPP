#include "LaserHandler.h"
#include "Laser.h"
#include "Game.h"
#include "CollisionHandler.h"
#include "EnemyManager.h"
#include "AsteroidManagement.h"
#include <iostream>


LaserHandler * LaserHandler::sm_instance = new LaserHandler();

LaserHandler::LaserHandler()
{
}


LaserHandler::~LaserHandler()
{
	//delete sm_instance;
}

LaserHandler * LaserHandler::instance()
{
	return sm_instance;
}

void LaserHandler::resetInstance()
{
	delete sm_instance;
	sm_instance = nullptr;
}

void LaserHandler::addLaser(const SDLGameObject & gameObject, const std::string& ID)
{
	//Add new PlayerLaser
	if (ID == "PlayerLaser") {
		m_playerLasers.push_back(std::unique_ptr<SDLGameObject>(new Laser(gameObject.getPos().getX() + (gameObject.getWidth() / 3), gameObject.getPos().getY() - 60, ID)));
	}
	
	//Add new EnemyLaser
	else if (ID == "EnemyLaser") {
		m_enemyLasers.push_back(std::unique_ptr<SDLGameObject>(new Laser(gameObject.getPos().getX() + (gameObject.getWidth() / 3), gameObject.getPos().getY() + gameObject.getHeight(), ID)));
	}
}

void LaserHandler::draw()
{
	//Draw enemy lasers
	for (auto &laser : m_enemyLasers)
	{
		laser->draw();
	}

	//Draw player lasers
	for (auto &laser : m_playerLasers)
	{
		laser->draw();
	}
}

void LaserHandler::update()
{

	checkwithinGameBounds();
	for (auto &laser : m_enemyLasers)
	{
		laser->update();
	}

	for (auto &laser : m_playerLasers)
	{
		laser->update();
	}

	handleCollisions();
}

void LaserHandler::checkwithinGameBounds()
{
	//std::cout << m_playerLasers.size() << "\n";
	std::vector<std::unique_ptr<SDLGameObject>>::const_iterator iter;
	for (iter = m_playerLasers.cbegin(); iter != m_playerLasers.cend();)
	{
		if (CollisionHandler::gameBoundsCollision(iter->get()))
		{
			iter = m_playerLasers.erase(iter);
		}	
		else
		{
			iter++;
		}

	}

	for (iter = m_enemyLasers.begin(); iter != m_enemyLasers.end();)
	{
		if (CollisionHandler::gameBoundsHeight(iter->get()))
		{
			iter = m_enemyLasers.erase(iter);
		}
		else {
			iter++;
		}
	}

	//Javawag: and your other line should be iter = m_playerLasers.erase(iter)
	//	Javawag : udderwise, its good
	//	BonBons : will that allow me to scan over the whole vector ok though if i do erase on element ? o.O
	//	Javawag : yeah m8 : D
	//	Javawag : as long as you do iter = m_playerLasers.erase(iter)
	//	Javawag : because erasing makes iter invalid
	//	BonBons : NOICE
	//	Javawag : but it returns you a new iter to use insteadJavawag: the new iteration points to the one after the one you deleted, which is what you want :D
	//Javawag: the old one if you just kept it and tried to do iter++ would crash or break : D because you erased it
}

void LaserHandler::handleCollisions()
{
	handleGameObjectCollision(EnemyManager::instance()->getEnemies());
	handleGameObjectCollision(AsteroidManagement::instance()->getAsteroids());
}

void LaserHandler::handleGameObjectCollision(std::vector<std::unique_ptr<SDLGameObject>>& gameObjects)
{
	bool deletePlayerLaser = false;
	std::vector<std::unique_ptr<SDLGameObject>>::const_iterator gameObjectIter;
	std::vector<std::unique_ptr<SDLGameObject>>::const_iterator playerLaserIter;
	for (playerLaserIter = m_playerLasers.cbegin(); playerLaserIter != m_playerLasers.cend();)
	{
		for (gameObjectIter = gameObjects.cbegin(); gameObjectIter != gameObjects.cend();)
		{
			if (CollisionHandler::gameObjectCollision(playerLaserIter->get(), gameObjectIter->get()))
			{
				gameObjectIter = gameObjects.erase(gameObjectIter);
				deletePlayerLaser = true;
			}
			else {

				gameObjectIter++;
			}
		}
		if (deletePlayerLaser) {
			playerLaserIter = m_playerLasers.erase(playerLaserIter);
			deletePlayerLaser = false;
		}
		else {
			playerLaserIter++;
		}

		
	}

}
