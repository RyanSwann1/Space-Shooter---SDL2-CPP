#include "Game.h"
#include "Vector2D.h"

#include <iostream>
#include <string>
#include <SDL.h>
#include <memory>

int numb(int *numb)
{
	numb = 6;
}

/*
Work out pointer as an argument to afuncton - does it alter the original element and does it make copy
*/

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

	//
	//int totalSum = 0;

	//int numb = 0;

	////std::cin >> userInput;
	//while (std::cin >> numb)
	//{
	//	if (numb == 0) {
	//		break;
	//	}
	//	totalSum += numb;
	//}
	
	//std::string userInput;
	//std::string password = "polo";
	//const unsigned int maxPasswordAttempts = 3;
	//int passwordAttempts = 0;

	//while (passwordAttempts < maxPasswordAttempts)
	//{
	//	std::cout << "Enter password: ";
	//	std::cin >> userInput;
	//	if (userInput == password) {
	//		std::cout << "Access granted.";
	//		break;
	//	}
	//	else {
	//		passwordAttempts++;
	//	}
	//}

	//std::cout << "\nAccess denied.";

	
	//for (int i = 1; i <= 20; i++)
	//{
	//	std::cout << i * i << "\n";
	//}




	//for (int i = 99; i >= 0;)
	//{
	//	std::cout << i << " bottles of beer on the wall," << i << " bottles of beer.\n";
	//	i--;
	//	std::cout << "Take one down and pass it around, " << i << "bottles of beer on the wall.\n\n";
	//}

	//std::cout << "\n\nEnd\n";
	char c;
	std::cin >> c;
	return 0;
}

