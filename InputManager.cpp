#include "InputManager.h"
#include "Game.h"

InputManager * InputManager::sm_instance = nullptr;



InputManager::InputManager()
{
}


InputManager::~InputManager()
{

}

InputManager * InputManager::instance()
{
	if (sm_instance == nullptr) {
		sm_instance = new InputManager();
	}
	return sm_instance;
}

void InputManager::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			Game::instance()->endGame();
			break;

		case SDL_KEYDOWN:
			onKeyDown();
			break;
			
		case SDL_KEYUP:
			onKeyUp();
			break;

		default:
			break;
		}
		//break;
	}
}

void InputManager::onKeyDown()
{
	keyState = SDL_GetKeyboardState(nullptr);
}

void InputManager::onKeyUp()
{
	keyState = SDL_GetKeyboardState(nullptr);
}

bool InputManager::isKeyDown(const SDL_Scancode & key)
{
	//If key has been pressed
	if (keyState != 0)
	{
		//If matchibng key has been pressed
		if (keyState[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;

}


