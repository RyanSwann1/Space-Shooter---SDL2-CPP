#ifndef ASTEROID_H
#define ASTEROID_H

#include "SDLGameObject.h"
#include "Vector2D.h"
#include <string>
class Asteroid :
	public SDLGameObject
{
public:
	Asteroid();
	Asteroid(const float x);
	~Asteroid();


	void draw() override;
	void update() override;
	Vector2D getPos() const override { return m_position; }
	int getHeight() const override { return m_sizeHeight; }
	int getWidth() const override { return m_sizeWidth; }

private:
	Vector2D m_position;
	Vector2D m_velocity;
	float m_movementSpeed;
	float m_startXPos;
	float m_startYPos;
	int m_sizeWidth;
	int m_sizeHeight;

	static const std::string m_textureID;

};
#endif // !ASTEROID_H
