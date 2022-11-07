//DemoPhase.h

#ifndef _DEMO_PHASE_H
#define _DEMO_PHASE_H

#include "Phase.h"
#include "Time.h"


class DemoPhase : public YGEEngine::SThrPhase 
{

public:

	DemoPhase();
	~DemoPhase();
		
	bool load();																						// Load assets needed by this phase

	bool unload();																						// Unload assets needed by this phase
	
	// Rendering operations
	void prerender(YGEGraphics::RenderDevice *device);										// Do pre-render stage

	void render(YGEGraphics::RenderDevice *device);											// Do render stage

	bool finished();

private:

	unsigned long				phaseStartTime;

};


#endif