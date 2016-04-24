#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.h"
class PlayState :
	public GameState
{
public:
	PlayState();
	~PlayState();

	void update() override;
	void draw() override;
	void onEnter() override;
	void onExit() override;
	std::string getID() const override { return m_ID; }

private:
	static const std::string m_ID;
};
#endif // !PLAY_STATE_H
