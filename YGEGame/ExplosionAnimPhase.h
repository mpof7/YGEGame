//ExplosionAnimPhase.h


#ifndef _EXPLOSION_ANIM_PHASE_H
#define _EXPLOSION_ANIM_PHASE_H

#include "Phase.h"



class ExplosionAnimPhase : public YGEEngine::SThrPhase 
{

public:

	bool load();																						// Load assets needed by this phase

	bool unload();																						// Unload assets needed by this phase

	// Rendering operations
	void prerender(YGEGraphics::RenderDevice *device);	
	void render(YGEGraphics::RenderDevice *device);

	bool finished();

};


#endif