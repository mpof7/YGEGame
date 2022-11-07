//PhysicsActorPhase.h


#ifndef _PHYSICS_ACTOR_PHASE_H
#define _PHYSICS_ACTOR_PHASE_H

#include "Phase.h"


class PhysicsActorPhase : public YGEEngine::SThrPhase 
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