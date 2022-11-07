//SoundPhase.cpp

#include "SoundPhase.h"
#include "DrawNode.h"
#include "Debug.h"
#include "AudioDevice.h"


SoundPhase::SoundPhase() 
{
	soundic = 0LL;
	ssource = 0;
	sbuffer = 0;
		
}


SoundPhase::~SoundPhase() 
{
			
}


bool SoundPhase::load() 
{

	//Initialize sound engine and play a sound
	 soundic = new YGESound::OpenALAudioDevice();

	if(soundic->init())
	{
	
		ssource = soundic->createSource(DS3DVectorMake(-2.0f, 0.0f, 0.0f), DS3DVectorMake(0.0f, 0.0f, 0.0f), true);
	
		sbuffer = soundic->loadWav("../Data/laugh1.wav");
		
		soundic->setListenerAttribs(DS3DVectorMake(0.0f, 0.0f, 0.0f), DS3DVectorMake(0.0f, 0.0f, 0.0f), DS3DVectorMake(0.0f, 0.0f, -1.0f), DS3DVectorMake(0.0f, 1.0f, 0.0f));
	
	}



	//sound rendering
	soundic->play(ssource, sbuffer);

	

	return Phase::load();
}


bool SoundPhase::unload() 
{
	soundic->~AudioDevice();

	return Phase::unload();
}


bool SoundPhase::finished() 
{

	return (phaseTime > 7000);
}


void SoundPhase::prerender(YGEGraphics::RenderDevice *device) 
{
	
	Phase::prerender(device);

	DS4DVector clearCol;

	clearCol.x = 1.0f;
	clearCol.y = 0.0f;
	clearCol.z = 0.0f;
	clearCol.w = 1.0f;

	device->clearColourBuffer(clearCol);
}
