//FlockAnimPhase.h


#ifndef _FLOCK_ANIM_PHASE_H
#define _FLOCK_ANIM_PHASE_H

#include "Phase.h"



class FlockAnimPhase : public YGEEngine::SThrPhase 
{

public:

	bool load();																						// Load assets needed by this phase

	bool unload();																						// Unload assets needed by this phase

	// Rendering operations
	void prerender(YGEGraphics::RenderDevice *device);	  //Pre render operation
	void render(YGEGraphics::RenderDevice *device);

	bool finished();

};


#endif