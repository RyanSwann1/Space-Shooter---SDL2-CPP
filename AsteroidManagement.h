#ifndef ASTEROID_MANAGEMENT_H
#define ASTEROID_MANAGEMENT_H


#include "SDLGameObject.h"
#include <vector>
#include <memory>
class AsteroidManagement
{
public:

	static AsteroidManagement *instance();
	static void resetInstance();
	void update();
	void draw();
	void checkAsteroidBounds();
	void onExit() { sm_instance = nullptr; }
	std::vector<std::unique_ptr<SDLGameObject>>& getAsteroids() { return m_asteroids; }
	

private:
	AsteroidManagement();
	~AsteroidManagement();
	std::vector<std::unique_ptr<SDLGameObject>> m_asteroids;
	int m_timeBetweenSpawn = 2000;
	int m_nextSpawnTime;
	bool m_spawnAsteroid;

	void spawnAsteroids();
	static AsteroidManagement *sm_instance;
};
#endif // !ASTEROID_MANAGEMENT_H


