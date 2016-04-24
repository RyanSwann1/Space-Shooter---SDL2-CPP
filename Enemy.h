#ifndef ENEMY_H
#define ENEMY_H

#include "SDLGameObject.h"
#include <SDL.h>
#include <string>
class Enemy :
	public SDLGameObject
{
public:
	Enemy();
	Enemy(const float x);
	~Enemy();

	void draw() override;
	void update() override;
	Vector2D getPos() const override { return m_position; }
	int getHeight() const override { return m_sizeHeight; }
	int getWidth() const override { return m_sizeWidth; }
private:
	Vector2D m_position;
	Vector2D m_velocity;
	int m_movementSpeed;
	unsigned int m_sizeWidth;
	unsigned int m_sizeHeight;
	static const std::string m_textureID;

	bool m_fireLaser;
	const int m_timeBetweenShots = 3000;
	int m_nextFireTime;
	void shoot();

};
#endif // !ENEMY_H
