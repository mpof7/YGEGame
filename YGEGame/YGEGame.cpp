//YGEGame.cpp


#include "Engine.h"
#include "RenderDevice.h"
#include "ParticlePhase.h"
#include "ExplosionAnimPhase.h"
#include "FlockAnimPhase.h"
#include "Debug.h"
#include "InputDevice.h"







static void MainGameLoopRun(YGEEngine::Engine &engine);






int SDL_main(int argc, char* argv[]) {


	


	// Setup phase chain
	//YGEEngine::Phase *particlePhase =  new ParticlePhase();
	//YGEEngine::Phase *explosionAnimationPhase =  new ExplosionAnimPhase();
	YGEEngine::Phase *flockAnimationPhase =  new FlockAnimPhase();
	
	
	
	flockAnimationPhase->next = NULL;
	//particlePhase->next = explosionAnimationPhase;
	//explosionAnimationPhase->next = flockAnimationPhase;
	

	// Create engine
	YGEEngine::Engine engine(flockAnimationPhase);

	// Run game loop
	MainGameLoopRun(engine);

	return 0;
}






void MainGameLoopRun(YGEEngine::Engine &engine) 
{
		
	// Initialise SDL. Subsystems will be initialised elsewhere
	int error = SDL_Init(SDL_INIT_TIMER);
	assert(!error);


	//Create graphics context
	#ifdef _DEBUG
	YGEGraphics::SDLRenderDevice device(800, 600, 32);
    #else
	YGEGraphics::SDLRenderDevice device(1024, 768, 32);
    #endif
	


	//Create the input engine
	YGEInput::InputDevice   *inputEngine = new YGEInput::SDLInputDevice();

	// Main SDL game loop
	//SDL_Event event;


	//This is the actual main game loop
	for (inputEngine->quit;!inputEngine->quit;)
	{
		
		   //Tick game engine
		   engine.tick(&device);
		  
		   //Update the input and check for input events
		   inputEngine->UpdateInput();

/*
		// Poll for events
		while (SDL_PollEvent(&event)) 
		{

			switch(event.type) 
			{

				case SDL_KEYDOWN:

					switch (event.key.keysym.sym) 
					{

						case SDLK_ESCAPE:
					
							quit = true;
							break;
					}
					break;

				case SDL_QUIT:

					quit = true;
					break;
			}

		}

		*/

		
	}
	
	SDL_Quit();
}
