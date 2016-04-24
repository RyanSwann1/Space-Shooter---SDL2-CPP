#ifndef COLLISION_HANDLER_H
#define COLLISION_HANDLER_H

#include "SDLGameObject.h"
#include <SDL.h>
#include "Game.h"
class CollisionHandler
{
public:
	CollisionHandler();
	~CollisionHandler();

	static bool gameObjectCollision(const SDLGameObject * const & gameObject1, const SDLGameObject * const & gameObject2);
	static bool gameBoundsCollision(const SDLGameObject * const & gameObject);

	static bool gameBoundsWidth(const SDLGameObject * const & gameObject) { return gameObject->getPos().getX() + gameObject->getWidth() >= Game::instance()->getPlayingFieldWidth(); }
	static bool gameBoundsHeight(const SDLGameObject * const & gameObject) { return gameObject->getPos().getY() >= Game::instance()->getPlayingFieldHeight(); }

private:

};
#endif // !COLLISION_HANDLER_H


