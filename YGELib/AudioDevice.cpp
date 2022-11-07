//SoundDevice.cpp

#include "AudioDevice.h"
#include "Debug.h"



namespace YGESound
{




	AudioDevice::AudioDevice()
	{
	
	}




	AudioDevice::~AudioDevice()
	{
	
	}





	OpenALAudioDevice::OpenALAudioDevice()
	{

		dev = 0LL;
		soundcontx = 0LL;
		sbo = 0;
		soundSource = 0;

	}





	OpenALAudioDevice::~OpenALAudioDevice()
	{

		alcMakeContextCurrent(NULL);
        alcDestroyContext(soundcontx);
        alcCloseDevice(dev);

		alDeleteBuffers(1, &sbo);
        alDeleteSources(1, &soundSource);
        alutExit();

	}





	bool OpenALAudioDevice::init()
	{
	
		dev = alcOpenDevice(NULL);

   
		if(!dev)
		{
        
			DBG(fprintf(stderr, "Error opening sound device\n");)
        
			return 1;
		}
		else
		{
    
			soundcontx = alcCreateContext(dev, NULL);
    
		
    
		
			if(!soundcontx)
			{
        
				DBG(fprintf(stderr, "Error creating sound context\n");)
        
			
				return 1;
			}

    
		
			alcMakeContextCurrent(soundcontx);

		}

      
		return true;
	}




	int OpenALAudioDevice::loadWav(const char *filename)
	{

	    //Clear any error messages
		DBG(alGetError();)

	    //Generate sound buffer object
		alGenBuffers(1, &sbo);

		assert(sbo);


		//Variables to load into.
        ALenum      format;
        ALsizei     size;
        ALvoid      *data;
        ALsizei     freq;
        ALboolean   loop;


		//Load the actual wav audio file
		alutLoadWAVFile((ALbyte *)filename, &format, &data, &size, &freq, &loop);  


		//Check if any errors at loading the audio file
		#ifdef _DEBUG
		if (alGetError() != AL_NO_ERROR)
        {
           printf("Error loading audio file:", filename, alGetError());
           alDeleteBuffers(1, &sbo);
        }
		else
		{
			printf("Loaded audio file: (%s)\nFormat: %d\nSize: %d\nFreq: %d\n", filename, format, size, freq);
		
		}
        #endif

	

		//Fill the sound buffer with sound data
		alBufferData(sbo,format,data,size,freq);
		

		//Unload the audio file's resources as they are not needed now
		alutUnloadWAV(format, data, size, freq);

	

	 return sbo;
	}



	int OpenALAudioDevice::createSource(DS3DVector position, DS3DVector velocity, bool islooping)
	{

		 DBG(alGetError();)
	
		 //Generate a sound source.
		 alGenSources(1, &soundSource);

    
		 //Check if any errors, generating the sound source
        #ifdef _DEBUG
		 if (alGetError() != AL_NO_ERROR)
		 {
			 printf("Error creating sound source:\n", alGetError());
			 alDeleteSources(1, &soundSource);

		 }
        #endif
   



		 //Setting of sound source's attributes
		//alSourcei (Source, AL_BUFFER,   Buffer   );
   
		alSourcef(soundSource, AL_PITCH, 1.0f);
    
		alSourcef(soundSource, AL_GAIN, 1.0f);
    
		alSource3f(soundSource, AL_POSITION, position.x, position.y, position.z);
    
		alSource3f(soundSource, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
    
		alSourcei(soundSource, AL_LOOPING, islooping);

	
	
	
	  return soundSource;
	}



	void OpenALAudioDevice::setListenerAttribs(DS3DVector position, DS3DVector velocity, DS3DVector orientdir, DS3DVector upVector)
	{

		ALfloat listenerOri[]={orientdir.x, orientdir.y, orientdir.z, upVector.x, upVector.y, upVector.z};
	
		//Seting up listener's attributes
		alListener3f(AL_POSITION, position.x, position.y, position.z);
		alListener3f(AL_VELOCITY, velocity.x, velocity.y, velocity.z);
        alListenerfv(AL_ORIENTATION, listenerOri);

	}



	void OpenALAudioDevice::play(const int source, const int buffer)
	{
	
		//Bind buffer (sound data)  with sound source
		alSourcei(source, AL_BUFFER, buffer);


		//Play the source's sound
		alSourcePlay(source);
	
	}



	void OpenALAudioDevice::stop(const int source)
	{
	
		//Stop the source's sound
		alSourceStop(source);
	
	}



	void OpenALAudioDevice::pause(const int source)
	{

		//Pause the source's sound
		alSourcePause(source);
	
	}




}