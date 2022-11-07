//RenderDevice.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_RENDERDEVICE_H
#define _YGE_RENDERDEVICE_H


#include "DSMatrix.h"
#include <GLee.h>
#include <SDL.h>
#include <SDL_opengl.h>



namespace YGEGraphics
{

	//!  RenderDevice class
    /*!
        The rendering interface class
     */

	class RenderDevice
	{
	
	public:

		RenderDevice();
		virtual ~RenderDevice() {};


		virtual void flush() = 0;

		// Clearing of frame buffers
		virtual void clearColourBuffer(const DS4DVector colour) = 0;						// Colour buffer only
		virtual void clearColourAndDepthBuffers(const DS4DVector colour) = 0;				// Colour and depth buffer

		// Enabling or disabling several render states
		virtual bool enableDepthTest() = 0;                                                 // Enables depth testing
		virtual bool disableDepthTest() = 0;                                                 // Disables depth testing
		
		// Getting and setting of matrices
		virtual DS4DMatrix getColourMatrix() { return colourMatrix; }						// Colour matrix getter
		virtual void setColourMatrix(const DS4DMatrix m) { colourMatrix = m; }				// Colour matrix setter
		
		virtual DS4DMatrix getTextureMatrix() { return textureMatrix; }					// Texture matrix getter
		virtual void setTextureMatrix(const DS4DMatrix m) { textureMatrix = m; }			// Texture matrix setter
		
		virtual DS4DMatrix getTransformMatrix() { return transformMatrix; }				// Transform matrix getter
		virtual void setTransformMatrix(const DS4DMatrix m) { transformMatrix = m; }		// Transform matrix setter
		
		virtual DS4DMatrix getProjectionMatrix() { return projectionMatrix; }				// Projection matrix getter
		virtual void setProjectionMatrix(const DS4DMatrix m) { projectionMatrix = m; }		// Colour matrix setter



	protected:

		DS4DMatrix						colourMatrix;
		DS4DMatrix						textureMatrix;
		DS4DMatrix						transformMatrix;
		DS4DMatrix						projectionMatrix;

		
	
	};


	//!  Drawable class
    /*!
        Describes a drawable object
	    You should subclass this to make it specific to some rendering system
     */

    class Drawable
	{
	
	public:

		virtual void draw(RenderDevice *device) = 0;
	
	};



	//!  Insertable class
    /*!
        Describes an object that can be inserted into the render device
     */

	class Insertable 
	{
		
	public:

		virtual void insertIntoGraphicsContext(RenderDevice *device) = 0;

	};



	//!  SDLRenderDevice class
    /*!
        The SDL-OpenGL rendering device
     */

	class SDLRenderDevice : public RenderDevice
	{
	
	public:

		SDLRenderDevice(const int width, const int height, const int bpp);
		 ~SDLRenderDevice();

	

		void flush();

		void clearColourBuffer(const DS4DVector colour);
		void clearColourAndDepthBuffers(const DS4DVector colour);

		bool enableDepthTest();
		bool disableDepthTest();
		
	
		
		// Setting of matrices using OpenGL functions
		void setColourMatrix(const DS4DMatrix m);
		void setTextureMatrix(const DS4DMatrix m);
		void setTransformMatrix(const DS4DMatrix m);
		void setProjectionMatrix(const DS4DMatrix m);

	private:

		SDL_Surface *screen;
	
	
	};


}
#endif