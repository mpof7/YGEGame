//ShaderPhase.h

#ifndef _SHADER_PHASE_H
#define _SHADER_PHASE_H

#include "Phase.h"
#include "Time.h"


class ShaderPhase : public YGEEngine::SThrPhase 
{

public:

	ShaderPhase();
	~ShaderPhase();
		
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