//RenderDevice.cpp

#include "RenderDevice.h"
#include "Debug.h"





namespace YGEGraphics
{



    RenderDevice::RenderDevice()
	{
	
		colourMatrix = DS4DMatrixIdentity;
		textureMatrix = DS4DMatrixIdentity;
		transformMatrix = DS4DMatrixIdentity;
		projectionMatrix = DS4DMatrixIdentity;

	}





	SDLRenderDevice::SDLRenderDevice(const int width, const int height, const int bpp)
	{
	
		int error = SDL_InitSubSystem(SDL_INIT_VIDEO);
		assert(!error);

		const SDL_VideoInfo *video_caps = SDL_GetVideoInfo();
		assert(video_caps);
		

#ifdef _DEBUG
		bool doubleBuffer = true;
		bool vblSync = false;
		bool showCursor = true;
		unsigned int videoMode = SDL_OPENGL;
#else
		bool doubleBuffer = true;
		bool vblSync = true;
		bool showCursor = false;
		unsigned int videoMode = SDL_OPENGL | SDL_FULLSCREEN;
#endif

	
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, bpp/4);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, bpp/4);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, bpp/4);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, bpp/4);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, doubleBuffer);
		SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, vblSync);

		screen = SDL_SetVideoMode(width, height, bpp, videoMode);
	
		assert(screen);

	
		SDL_ShowCursor(showCursor);
	
	}



	SDLRenderDevice::~SDLRenderDevice()
	{
	
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	
	}



	void SDLRenderDevice::flush()
	{
	
	   SDL_GL_SwapBuffers();
	
	}


	void SDLRenderDevice::clearColourBuffer(const DS4DVector colour) 
	{

		glClearColor(colour.x, colour.y, colour.z, colour.w);
		glClear(GL_COLOR_BUFFER_BIT);
	}


	void SDLRenderDevice::clearColourAndDepthBuffers(const DS4DVector colour) 
	{
		
		
		glClearColor(colour.x, colour.y, colour.z, colour.w);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}


	void SDLRenderDevice::setColourMatrix(const DS4DMatrix m) 
	{

		RenderDevice::setColourMatrix(m);

		glMatrixMode(GL_COLOR);
		glLoadMatrixf(m.raw);
	}


	void SDLRenderDevice::setTextureMatrix(const DS4DMatrix m)
	{

		RenderDevice::setTextureMatrix(m);

		glMatrixMode(GL_TEXTURE);
		glLoadMatrixf(m.raw);
	}


	void SDLRenderDevice::setTransformMatrix(const DS4DMatrix m) 
	{

		RenderDevice::setTransformMatrix(m);
		gluLookAt(0, 3.0, -20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  
		glMatrixMode(GL_MODELVIEW);
		
		glLoadMatrixf(m.raw);
	}


	void SDLRenderDevice::setProjectionMatrix(const DS4DMatrix m)  
	{

		RenderDevice::setProjectionMatrix(m);

	   
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(m.raw);
	   
	
	}



	bool SDLRenderDevice::enableDepthTest()
	{
		glEnable(GL_DEPTH_TEST);

	 return true;
	}
		
	

	bool SDLRenderDevice::disableDepthTest()
	{
		glDisable(GL_DEPTH_TEST);

	 return true;
	}




}