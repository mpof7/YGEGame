//Time.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_TIME_H
#define _YGE_TIME_H

#include <GLee.h>
#include <SDL.h>
#include <SDL_opengl.h>



namespace YGECore
{


	typedef long long YGETime;

	//!  Time class
    /*!
        Calculates the real time
     */

	class Time
	{
	
	public:


		static const unsigned long getMilliTime();    //gets the time in milliseconds
	
	};


}
#endif