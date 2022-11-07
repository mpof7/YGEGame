//Time.cpp

#include "Time.h"



namespace YGECore
{

	const unsigned long Time::getMilliTime()
	{
	
		return SDL_GetTicks();   //returns the time in milliseconds using SDL's: SDL_GetTicks() function
	
	}



}