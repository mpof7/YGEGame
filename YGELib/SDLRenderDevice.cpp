//SDLRenderDevice.cpp

#include "SDLRenderDevice.h"
#include <assert.h>


namespace YGEGraphics
{

	#define SDL_VIDEO_MODE SDL_OPENGL


	SDLRenderDevice::SDLRenderDevice(const int width, const int height, const int bpp)
	{
	
	int error = SDL_InitSubSystem(SDL_INIT_VIDEO);

	assert(!error);


	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, bpp/4);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, bpp/4);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, bpp/4);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, bpp/4);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, true);

	screen = SDL_SetVideoMode(width, height, bpp, SDL_VIDEO_MODE);
	
	assert(screen);



	SDL_ShowCursor(0);
	
	
	}



	SDLRenderDevice::~SDLRenderDevice()
	{
	
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	
	}



	void SDLRenderDevice::flush()
	{
	
	SDL_GL_SwapBuffers();
	
	}





}