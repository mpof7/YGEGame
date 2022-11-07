//SoundPhase.h


#ifndef _SOUND_PHASE_H
#define _SOUND_PHASE_H

#include "Phase.h"
#include "Time.h"

namespace YGESound{class AudioDevice;}

class SoundPhase : public YGEEngine::SThrPhase 
{

public:

	SoundPhase();
	~SoundPhase();
		
	bool load();																						// Load assets needed by this phase

	bool unload();																						// Unload assets needed by this phase

	// Rendering operations
	void prerender(YGEGraphics::RenderDevice *device);										// Do pre-render stage

	bool finished();


	YGESound::AudioDevice                   *soundic;                                      //the sound device
	int                                     ssource;                                       //sound source
	int                                     sbuffer;                                       //sound buffer (data)

};


#endif