#include "Game.h"
#include "Vector2D.h"

#include <iostream>

int main(int argc, char* args[])
{
	//Init game
	if (Game::instance()->init("Tetris", 650, 650))
	{
		//Game loop
		while (Game::instance()->isRunning()) 
		{
			//Listen for events
			Game::instance()->handleEvents();
			Game::instance()->update();
			Game::instance()->render();
		}
	}
	else
	{
		std::cout << "Game failed to initialize.";
	}

	return 0;
}
