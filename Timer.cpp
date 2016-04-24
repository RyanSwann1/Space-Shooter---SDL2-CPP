#include "Timer.h"

Timer * Timer::sm_instance = new Timer();

Timer::Timer()
{
	m_currentTime = SDL_GetTicks();
}


Timer::~Timer()
{
}

Timer * Timer::instance()
{
	return sm_instance;
}

void Timer::resetInstance()
{
	delete sm_instance;
	sm_instance = nullptr;
}

void Timer::update()
{
	m_currentTime = SDL_GetTicks();
}

bool Timer::compareToTimePassed(const int i)
{
	if (SDL_TICKS_PASSED(m_currentTime, i))
	{
		return true;
	}
	return false;
}
