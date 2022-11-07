//InterpolationPhase.h

#ifndef _INTERPOLATION_PHASE_H
#define _INTERPOLATION_PHASE_H

#include "Phase.h"
#include "Time.h"



class InterpolationPhase : public YGEEngine::SThrPhase 
{

public:

	InterpolationPhase();
	~InterpolationPhase();
		
	bool load();																						// Load assets needed by this phase

	bool unload();																						// Unload assets needed by this phase
	

	// Rendering operations
	void prerender(YGEGraphics::RenderDevice *device);										// Do pre-render stage

	void render(YGEGraphics::RenderDevice *device);											// Do render stage



	bool finished();


};


#endif