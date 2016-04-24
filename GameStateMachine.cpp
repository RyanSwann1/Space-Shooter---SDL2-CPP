#include "GameStateMachine.h"



GameStateMachine::GameStateMachine()
{
}


GameStateMachine::~GameStateMachine()
{
}

void GameStateMachine::startState(GameState * gameState)
{
	if (m_gameStates.empty())
	{
		m_gameStates.push_back(gameState);
		m_gameStates.back()->onEnter();
	}
}

void GameStateMachine::changeState(GameState *gameState)
{
	//If there are already existing game states
	if (!m_gameStates.empty())
	{
		//If new state isn't the same as current state
		if (m_gameStates.back()->getID() != gameState->getID())
		{
			//Remove current state
			m_gameStates.back()->onExit();
			m_gameStates.erase(m_gameStates.end() - 1);
			//Add new state
			m_gameStates.push_back(gameState);
			m_gameStates.back()->onEnter();
		}
	}
}

void GameStateMachine::update()
{
	m_gameStates.back()->update();
}

void GameStateMachine::draw()
{
	m_gameStates.back()->draw();
}
