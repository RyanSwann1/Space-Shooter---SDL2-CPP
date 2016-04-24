#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H

#include "GameState.h"
#include <vector>
#include <memory>
class GameStateMachine
{
public:
	GameStateMachine();
	~GameStateMachine();

	void startState(GameState * gameState);
	void changeState(GameState *gameState);
	void update();
	void draw();
private:
	std::vector<GameState*> m_gameStates;

};
#endif // !GAME_STATE_MACHINE_H
