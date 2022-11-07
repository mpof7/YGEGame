//InputDevice.cpp

#include "InputDevice.h"
#include "Engine.h"



namespace YGEInput
{
	
	bool InputDevice::myKeyArray[255];

	bool InputDevice::Xhit;

	KeyboardState  InputDevice::keyboardEvent;

	GeneralState  InputDevice::generalEvent;




	InputDevice::InputDevice()
	{
		
		for(int i = 0; i < 255; i++) myKeyArray[i] = false;
		quit = false;
		Xhit = false;
		previousTick = YGECore::Time::getMilliTime();
		inputTickRate = 60;
		inputTickAccumulator = 0;

	}


	InputDevice::~InputDevice()
	{
	
	}



	SDLInputDevice::SDLInputDevice()
	{
	
		
	
	}


	SDLInputDevice::~SDLInputDevice()
	{
	

	
	}



	bool KeyboardState::IsKeyDown(const int keyenum)
	{
		 
		return SDLInputDevice::IsKeyDown(keyenum);
	}


	bool KeyboardState::IsKeyUp(const int keyenum)
	{
	 
		return SDLInputDevice::IsKeyUp(keyenum);
	}


	

	bool GeneralState::XcloseWindow()
	{
	 
		return SDLInputDevice::XcloseWindow();
	}








	bool SDLInputDevice::IsKeyUp(const int keyenum)
	{

		//event.key.keysym.sym = (SDLKey) keyenum;
	
		// Poll for events
		//while (SDL_PollEvent(&event)) 
		//{
		
		
			//if((event.type == SDL_KEYUP) && (event.key.keysym.sym == (SDLKey) keyenum))
			//{
				

			// return true;
			//}
		
		
		//}
	
	
	
		return myKeyArray[keyenum];
	}



	bool SDLInputDevice::IsKeyDown(const int keyenum)
	{

		/*

		event.key.keysym.sym = (SDLKey) keyenum;
	
		// Poll for events
		while (SDL_PollEvent(&event)) 
		{
			
		
			if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == (SDLKey) keyenum))
			{
				
			 return true;
			}
		
		 
		}
		
	
		return false;*/


		return myKeyArray[keyenum];
	}





	bool SDLInputDevice::XcloseWindow()
	{

		
	
		// Poll for events
		//while (SDL_PollEvent(&event)) 
		//{
			
		
		//	if(event.type == SDL_QUIT)
			//{
				
			// return true;
			//}
		
		 
		//}

	
	  return Xhit;
	}





	void SDLInputDevice::CheckInput()
	{

	   


		if (keyboardEvent.IsKeyDown(keys_Escape) || generalEvent.XcloseWindow()) quit = true; 


		
		
		
		if(keyboardEvent.IsKeyDown(keys_P))
		{
			
			if(YGEEngine::Engine::IsPaused == false)
			{
			
				YGEEngine::Engine::pause(true);
			 
			}
			else
			if(YGEEngine::Engine::IsPaused == true)
			{

				YGEEngine::Engine::pause(false);
			 
			}
			
			//Meta ton elegxo...edw prepei na 8esw to P = false
			myKeyArray[keys_P] = false; 
		
		} 
		
		

		
	}

      
	

	void SDLInputDevice::UpdateInput()
	{


		unsigned long currentTick = YGECore::Time::getMilliTime();
		unsigned long delta = currentTick - previousTick;


		inputTickAccumulator += delta;



		if(inputTickAccumulator >= inputTickRate)
		{

	
		// Poll for events
		while(SDL_PollEvent(&event)) 
		{
		
		
			if(event.type == SDL_KEYDOWN) 
			{
			
				myKeyArray[event.key.keysym.sym] = true;
		
			} 
		    else if (event.type == SDL_KEYUP) 
			{
			
				myKeyArray[event.key.keysym.sym] = false;
		
			}
			else if (event.type == SDL_QUIT)
			{
			
				Xhit =true;
			
			}

		
		
		}

	
	
	   inputTickAccumulator -= inputTickRate;
	}


		CheckInput();


      previousTick = currentTick;
	}


}