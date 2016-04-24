#include "Game.h"
#include "Vector2D.h"

#include <iostream>
#include <string>
#include <SDL.h>
#include <memory>


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


	//std::cout << "\n\nEnd\n";
	char c;
	std::cin >> c;
	return 0;
}

