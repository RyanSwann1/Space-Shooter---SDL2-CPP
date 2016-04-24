#ifndef SDLGameObject_H
#define SDLGameObject_H

#include "Vector2D.h"
class SDLGameObject
{
public:
	SDLGameObject();
	~SDLGameObject();

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual Vector2D getPos() const = 0;
	virtual int getHeight() const = 0;
	virtual int getWidth() const = 0;
private:

};
#endif // !SDLGameObject_H
