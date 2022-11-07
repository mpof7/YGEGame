//SDLRenderDevice.h

#ifndef _YGE_SDLRENDERDEVICE_H
#define _YGE_SDLRENDERDEVICE_H

#include "RenderDevice.h"



namespace YGEGraphics
{

	class SDLRenderDevice : public RenderDevice
	{
	
	public:

		SDLRenderDevice(const int width, const int height, const int bpp);
		 ~SDLRenderDevice();

	

		void flush();


	private:

		SDL_Surface *screen;
	
	
	};


}
#endif