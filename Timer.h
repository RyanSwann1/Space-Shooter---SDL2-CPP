#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>
class Timer
{
public:

	static Timer *instance();
	static void resetInstance();
	void update();

	bool compareToTimePassed(const int i);
	Uint32 getTimePassed() const { return m_currentTime; }
	void stop() { m_currentTime = 0; }

private:
	Timer();
	~Timer();
	static Timer *sm_instance;
	Uint32 m_currentTime;

};
#endif // !TIMER_H
