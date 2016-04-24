#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "SDLGameObject.h"
#include <vector>
#include <memory>
class EnemyManager
{
public:

	static EnemyManager *instance();
	static void resetInstance();
	void draw();
	void update();
	void spawnEnemy();
	std::vector<std::unique_ptr<SDLGameObject>>& getEnemies() { return m_enemies; }

private:
	EnemyManager();
	~EnemyManager();

	const int m_timeBetweenSpawn = 6000;
	int m_nextSpawnTime;
	bool m_spawn;

	std::vector<std::unique_ptr<SDLGameObject>> m_enemies;
	//std::vector<SDLGameObject*> m_enemies;
	void checkWithinGameBounds();
	static EnemyManager *sm_instance;
};

#endif // !ENEMY_MANAGER_H