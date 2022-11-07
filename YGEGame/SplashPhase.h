//SplashPhase.h

#ifndef _SPLASH_PHASE_H
#define _SPLASH_PHASE_H

#include "Phase.h"
#include "Time.h"


class SplashPhase : public YGEEngine::SThrPhase 
{

public:

	SplashPhase();
	~SplashPhase();
		
	bool load();																						// Load assets needed by this phase

	bool unload();																						// Unload assets needed by this phase
	

	// Rendering operations
	void prerender(YGEGraphics::RenderDevice *device);										// Do pre-render stage

	void render(YGEGraphics::RenderDevice *device);											// Do render stage


	bool finished();


};


#endif