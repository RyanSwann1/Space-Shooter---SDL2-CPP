#ifndef PLAYER_H
#define PLAYER_H

#include "SDLGameObject.h"
#include "Vector2D.h"
#include <string>
#include <vector>
#include <memory>
class Player :
	public SDLGameObject
{
public:
	Player();
	~Player();

	void draw() override;
	void update() override;
	Vector2D getPos() const override { return m_position; }
	int getHeight() const override { return m_sizeHeight; }
	int getWidth() const override { return m_sizeWidth; }
	static const std::string m_ID;
private:
	//Starting position of player
	float m_startXPos;
	float m_startYPos;
	//Size of player
	int m_sizeWidth;
	int m_sizeHeight;
	//MovementSpeed of player
	float m_movementSpeed;
	int m_laserMovementSpeed;
	Vector2D handleMovement();

	bool m_fireLaser;
	static const int m_timeBetweenFire = 1000;
	int m_nextFire;

	void handleInput();
	void fireLaser();
	void reset();
	void handleCollisions();
	void gameObjectCollision(std::vector<std::unique_ptr<SDLGameObject>>& gameObjects);

	Vector2D m_position;
	Vector2D m_velocity;
	
	
};

#endif // !PLAYER_H