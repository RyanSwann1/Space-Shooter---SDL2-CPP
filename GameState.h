#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
class GameState
{
public:
	GameState();
	~GameState();

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	virtual std::string getID() const = 0;

private:

};
#endif // !GAME_STATE_H