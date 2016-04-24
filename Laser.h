#ifndef LASER_H
#define LASER_H

#include "SDLGameObject.h"
#include "Vector2D.h"
#include <SDL.h>
#include <string>
class Laser :
	public SDLGameObject
{
public:
	Laser();
	Laser(const float x, const float y, const std::string& ID);
	~Laser();
	
	void draw() override;
	void update() override;
	Vector2D getPos() const override { return m_position; }
	int getHeight() const override { return m_sizeHeight; }
	int getWidth() const override { return m_sizeWidth; }

private:
	Vector2D m_position;
	Vector2D m_velocity;
	int m_movementSpeed;
	int m_sizeHeight;
	int m_sizeWidth;
	bool m_withinGameBounds; //Laser within bounds of game
	std::string m_ID;
	static const std::string m_textureID;
	static const std::string m_enemyTextureID;

	Vector2D& handleDirection();
};
#endif // !LASER_H

