#ifndef GAME_H
#define GAME_H

#include "SDLDeleter.h"
#include "SDLGameObject.h"
#include "GameStateMachine.h"
#include <SDL.h>
#include <vector>
#include <string>
#include <memory>
#include <random>
class Game
{
public:
	static Game * instance();

	void handleEvents();
	void endGame() { m_running = false; }
	void update();
	void addGameObjects();
	void render();
	void clearGameObjects() { m_gameObjects.clear(); }
	bool init(const char* title, int w, int h);
	bool isRunning() const { return m_running; }


	//Getters
	SDL_Window* getWindow() const { return m_window.get(); }
	SDL_Surface* getWindowSurface() const { return m_windowSurface.get(); }
	SDL_Renderer* getRenderer() const { return m_renderer.get(); }
	std::vector<std::unique_ptr<SDLGameObject>>& getGameObjects() { return m_gameObjects; }
	int getPlayingFieldWidth() const { return m_playingFieldWidth; }
	int getPlayingFieldHeight() const { return m_playingFieldHeight; }
	float getRandomNumb(const float min, const float max);
	
	std::string getMessage() const { return "Hello World."; }

private:
	Game();
	~Game();
	bool m_running;
	int m_playingFieldWidth;
	int m_playingFieldHeight;

	std::unique_ptr<SDL_Window, SDLDeleter> m_window;
	std::unique_ptr<SDL_Renderer, SDLDeleter> m_renderer;
	std::unique_ptr<SDL_Surface, SDLDeleter> m_windowSurface;

	std::vector<std::unique_ptr<SDLGameObject>> m_gameObjects;
	GameStateMachine m_gameStateMachine;

	static Game * sm_instance;
};
#endif // !GAME_H

