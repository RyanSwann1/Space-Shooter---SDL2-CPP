#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <string>
class Vector2D
{
	friend Vector2D& operator +=(Vector2D& v1, const Vector2D& v2);
	friend bool operator ==(const Vector2D& v1, const Vector2D& v2);
public:
	Vector2D();
	Vector2D(const float x, const float y);
	~Vector2D();

	Vector2D& operator()(const std::string& message, Vector2D& v) const;

	//Setters
	void setX(const float x) { m_x = x; }
	void setY(const float y) { m_y = y; }

	float getX() const { return m_x; }
	float getY() const { return m_y; }
private:
	float m_y;
	float m_x;

};
#endif // !VECTOR2D_H
