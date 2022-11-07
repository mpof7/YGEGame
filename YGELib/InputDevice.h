//InputDevice.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_INPUTDEVICE_H
#define _YGE_INPUTDEVICE_H

#include <SDL.h>
#include "Time.h"
#include "KeyEnums.h"


namespace YGEInput
{


	typedef struct KeyboardState
	{
    
     
		bool IsKeyUp(const int keyenum);
	    bool IsKeyDown(const int keyenum);

	};




	typedef struct GeneralState
	{
    
         bool XcloseWindow();

	};




	//!  InputDevice class
    /*!
        Input interface class
     */

	class InputDevice
	{
	
	public:

		InputDevice();
	   virtual ~InputDevice();

	   virtual void CheckInput() = 0;

	   virtual void UpdateInput() = 0;

	   static KeyboardState  keyboardEvent;

	   static GeneralState  generalEvent;
	
	
	   bool                quit;
		

	   static bool         myKeyArray[255];


	protected:

		YGECore::YGETime   previousTick;
		YGECore::YGETime   inputTickRate;
		YGECore::YGETime   inputTickAccumulator;

		static bool        Xhit;
        
	};



	//!  SDLInputDevice class
    /*!
        SDL input device class
     */

	class SDLInputDevice : public InputDevice
	{
	
	public:

		SDLInputDevice();
	   ~SDLInputDevice();


	   void CheckInput();

	   void UpdateInput();

	   static bool IsKeyUp(const int keyenum);

	   static bool IsKeyDown(const int keyenum);

	   static bool XcloseWindow();
	  
	   
	  
	protected:

		 SDL_Event    event;

 		
	
	};


	

}
#endif