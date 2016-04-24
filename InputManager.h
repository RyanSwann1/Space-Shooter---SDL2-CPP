#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL.h>
#include <memory>

class InputManager
{
public:

	static InputManager *instance();

	void update();
	void onKeyDown();
	void onKeyUp();
	bool isKeyDown(const SDL_Scancode& scanCode);



private:
	InputManager();
	~InputManager();

	static InputManager *sm_instance;

	const Uint8* keyState;
};
#endif // !INPUT_MANAGER_H