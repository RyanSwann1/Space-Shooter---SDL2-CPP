#include "Game.h"
#include "InputManager.h"
#include "Player.h"
#include "TextureManager.h"
#include "PlayState.h"
#include <SDL_image.h>
#include <SDL_surface.h>
#include <assert.h>

Game * Game::sm_instance = new Game();

Game::Game()
{
	m_playingFieldHeight = 0;
	m_playingFieldWidth = 0;
	m_running = false;
}

Game::~Game()
{

}

Game * Game::instance()
{
	return sm_instance;
}


void Game::handleEvents()
{
	InputManager::instance()->update();
}

bool Game::init(const char* title, int w, int h)
{
	//Init SDL Video
	SDL_Init(SDL_INIT_VIDEO);
	//IMG_Init(IMG_INIT_PNG); //Initialize images
	//int flags = IMG_INIT_PNG;
	//Initialize PNG loading

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());

	}	
	
	//Initialize playing field boundaries
	m_playingFieldWidth = w;
	m_playingFieldHeight = h;

	//Create the window
	m_window = std::unique_ptr<SDL_Window, SDLDeleter>(SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN), SDLDeleter());
	assert(m_window != nullptr);
	//Create the renderer
	m_renderer = std::unique_ptr<SDL_Renderer, SDLDeleter>(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_PRESENTVSYNC), SDLDeleter());
	assert(m_renderer != nullptr);
	//Get the window surface
	m_windowSurface = std::unique_ptr<SDL_Surface, SDLDeleter>(SDL_GetWindowSurface(m_window.get()), SDLDeleter());
	assert(m_windowSurface != nullptr);

	//Set up states
	m_gameStateMachine.startState(new PlayState());

	//Load textures
	TextureManager::instance()->load("Player", "Textures/PlayerShip.PNG");
	TextureManager::instance()->load("PlayerLaser", "Textures/PlayerProjectile.PNG");
	TextureManager::instance()->load("EnemyLaser", "Textures/EnemyProjectile.PNG");
	TextureManager::instance()->load("Asteroid", "Textures/Asteroid.PNG");
	TextureManager::instance()->load("EnemyShip", "Textures/EnemyShip.PNG");

	m_running = true; //Game is running

	return true; 	//If reached, init succesful
}

void Game::update()
{
	m_gameStateMachine.update();
}

void Game::addGameObjects()
{
	m_gameObjects.push_back(std::unique_ptr<SDLGameObject>(new Player()));
}

void Game::render()
{
	SDL_RenderClear(m_renderer.get()); //Clear renderer
	SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 0); //Have background as black
	//Render game objects
	m_gameStateMachine.draw();

	//SDL_Rect srcRect;
	//SDL_Rect destRect;
	//srcRect.h = destRect.h = 50;
	//srcRect.w = destRect.w = 50;
	//srcRect.x = 0;
	//srcRect.y = 0;
	//destRect.x = 100;
	//destRect.y = 100;
	//SDL_RenderCopy(m_renderer.get(), TextureManager::instance()->getPlayerTexture("Player"), &srcRect, &destRect);
	//Apply rendering
	SDL_RenderPresent(m_renderer.get());
}
float Game::getRandomNumb(const float min, const float max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);

	return dis(gen);
}


/*

DELETE CALLS THE DESTRUCTOR FOR A SINGLETON
OBJECTS CANNOT DELETE THEMSELVES

*/