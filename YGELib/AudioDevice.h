//AudioDevice.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_AUDIODEVICE_H
#define _YGE_AUDIODEVICE_H

#include "al.h"
#include "alc.h"
#include <AL\alut.h>
#include "DSVector.h"


namespace YGESound
{

	//!  AudioDevice class
    /*!
        Sound interface class
     */

	class AudioDevice
	{

	public:

		AudioDevice();
		virtual ~AudioDevice();


		virtual bool init() = 0;

		virtual int loadWav(const char *filename) = 0;

		virtual int createSource(DS3DVector position, DS3DVector velocity, bool islooping) = 0;

		virtual void setListenerAttribs(DS3DVector position, DS3DVector velocity, DS3DVector orientdir, DS3DVector upVector) = 0;

		virtual void play(const int source, const int buffer) = 0;

		virtual void stop(const int source) = 0;

		virtual void pause(const int source) = 0;

	
	};



	//!  OpenALAudioDevice class
    /*!
        OpenAL sound device class
     */

	class OpenALAudioDevice : public AudioDevice
	{
	
	public:

		OpenALAudioDevice();
	   ~OpenALAudioDevice();

	   bool init();

	   int loadWav(const char *filename);

	   int createSource(DS3DVector position, DS3DVector velocity, bool islooping);

	   void setListenerAttribs(DS3DVector position, DS3DVector velocity, DS3DVector orientdir, DS3DVector upVector);

	   void play(const int source, const int buffer);

	   void stop(const int source);

	   void pause(const int source);


	protected:

		ALCdevice    *dev;
        ALCcontext   *soundcontx;

        ALuint        sbo;                     //Buffers hold sound data
		ALuint        soundSource;             //Sources are points emitting sound
	
	};


}
#endif