#ifndef LASER_HANDLER_H
#define LASER_HANDLER_H

#include "SDLGameObject.h"
#include <vector>
#include <memory>
class LaserHandler
{
public:

	static LaserHandler *instance();
	static void resetInstance();
	void addLaser(const SDLGameObject& gameObject, const std::string& ID);
	void draw();
	void update();

	std::vector<std::unique_ptr<SDLGameObject>>& getPlayerLasers() { return m_playerLasers; }
	std::vector<std::unique_ptr<SDLGameObject>>& getEnemyLasers() { return m_enemyLasers; }

private:
	LaserHandler();
	~LaserHandler();
	
	std::vector<std::unique_ptr<SDLGameObject>> m_enemyLasers;
	std::vector<std::unique_ptr<SDLGameObject>> m_playerLasers;
	
	void checkwithinGameBounds();
	void handleCollisions();
	void handleGameObjectCollision(std::vector<std::unique_ptr<SDLGameObject>>& gameObjects);
	static LaserHandler * sm_instance;
};
#endif // !LASER_HANDLER_H
