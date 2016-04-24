#include "CollisionHandler.h"



CollisionHandler::CollisionHandler()
{
}


CollisionHandler::~CollisionHandler()
{
}

bool CollisionHandler::gameObjectCollision(const SDLGameObject * const & gameObject1, const SDLGameObject * const & gameObject2)
{
	return gameObject1->getPos().getX() + gameObject1->getWidth() >= gameObject2->getPos().getX() &&
		gameObject1->getPos().getX() <= gameObject2->getPos().getX() + gameObject2->getWidth() &&
		gameObject1->getPos().getY() + gameObject1->getHeight() >= gameObject2->getPos().getY() &&
		gameObject1->getPos().getY() <= gameObject2->getPos().getY() + gameObject2->getHeight();
}

bool CollisionHandler::gameBoundsCollision(const SDLGameObject * const & gameObject)
{
	return gameObject->getPos().getX() < 0 || gameObject->getPos().getX() + gameObject->getWidth() > Game::instance()->getPlayingFieldWidth() ||
		gameObject->getPos().getY() < 0 || gameObject->getPos().getY() + gameObject->getHeight() > Game::instance()->getPlayingFieldHeight();
}


