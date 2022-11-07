//Engine.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_ENGINE_H
#define _YGE_ENGINE_H

#include <GLee.h>
#include <SDL.h>
#include <SDL_opengl.h>



namespace YGEGraphics{class RenderDevice;}

namespace YGEEngine
{


	class Phase;    //Phase class definition instead of using Phase.h header file



	//!  Engine class
    /*!
        The YGEGame engine's base class
     */

	class Engine
	{
	
	public:

		 Engine(Phase *phase);       //class constructor
		~Engine();                   //class destructor
		


		static inline bool pause(const bool pause)              //pauses the engine
		{
		
		   IsPaused = pause;
		
		
		  return pause;
		}                  
		                 
		
		void tick(YGEGraphics::RenderDevice *device);      //this function is the actual engine tick


		static bool  IsPaused;                                  //is the engine paused?


	protected:
		
		Phase          *currentPhase;                     //engine's currently processed phase
		unsigned long  engineTickRate;                    //how much ticks to be passed before an engine tick occurs
		unsigned long  engineTickAccumulator;             //engine's tick accumulator
		unsigned long  previousTick;                      //the previous time stamp
	
	
	};




}
#endif