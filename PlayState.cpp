#include "PlayState.h"
#include "SDLGameObject.h"
#include "Game.h"
#include "LaserHandler.h"
#include "AsteroidManagement.h"
#include "EnemyManager.h"
#include "Timer.h"

const std::string PlayState::m_ID = "PlayState";

PlayState::PlayState()
{
}


PlayState::~PlayState()
{
}

void PlayState::draw()
{
	//Draw all game objects
	for (auto &gameObject : Game::instance()->getGameObjects())
	{

		gameObject->draw();
	}
	//Draw all other game objects
	LaserHandler::instance()->draw();
	EnemyManager::instance()->draw();
	AsteroidManagement::instance()->draw();

}

void PlayState::update()
{
	//Update all game objects
	for (auto &gameObject : Game::instance()->getGameObjects())
	{
		gameObject->update();
	}
	LaserHandler::instance()->update();
	AsteroidManagement::instance()->update();
	EnemyManager::instance()->update();
	Timer::instance()->update();
}

void PlayState::onEnter()
{
	Game::instance()->addGameObjects(); //Add neccessary game objects
	Timer::instance();//Initialize timer
}

void PlayState::onExit()
{
	Timer::instance()->stop();
	LaserHandler::resetInstance();
	AsteroidManagement::resetInstance();
	EnemyManager::resetInstance();
	Game::instance()->clearGameObjects();
}