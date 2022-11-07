//Engine.cpp

#include "Engine.h"
#include "Time.h"
#include "Phase.h"
#include "Debug.h"


namespace YGEEngine
{

	bool Engine::IsPaused;


	Engine::Engine(Phase *phase)
	{
	
		engineTickRate = 60;
		currentPhase = NULL;
		engineTickAccumulator = 0;
		previousTick = YGECore::Time::getMilliTime();
		IsPaused = false;

		
		currentPhase = phase;
		
		

		int error = SDL_Init(SDL_INIT_TIMER);
		assert(!error);

		if(currentPhase)
		{
			currentPhase->load();
		}

	
	}


	Engine::~Engine()
	{
	
		SDL_Quit();
	
	}




	void Engine::tick(YGEGraphics::RenderDevice *device)
	{
	
		
		
			unsigned long currentTick = YGECore::Time::getMilliTime();
			unsigned long delta = currentTick - previousTick;

			if(!IsPaused)
			{
			
				engineTickAccumulator += delta;

				if(engineTickAccumulator >= engineTickRate)
				{
				
					if(currentPhase && currentPhase->finished())
					{
					
						currentPhase->unload();
						currentPhase = currentPhase->next;
						if(currentPhase)
						{
							currentPhase->load();
						
						}
					
					}



					engineTickAccumulator -= engineTickRate;
				
				
				}

				currentPhase->tick(delta);

				currentPhase->draw(device);

			}


			previousTick = currentTick;
		
		
		}
	
	}
