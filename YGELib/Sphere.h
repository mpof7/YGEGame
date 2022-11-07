//Sphere.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_SPHERE_H
#define _YGE_SPHERE_H

#include "RenderDevice.h"
#include "DSVector.h"
#include "Object.h"



//#ifndef CALLBACK
//#define CALLBACK
//#endif




namespace YGEGraphics
{

	//!  Sphere class
    /*!
        A sphere primitive class
     */

	class Sphere : public YGECore::Object, public Drawable
	{
	

		public:
		
		Sphere(const float radious, const int slices, const int stacks);

		void draw(RenderDevice *device);

		void init();

		//void CALLBACK errorCallback(GLenum errorCode);



	private:

		float radious;
		int slices;
		int stacks;

		GLuint displaylist;
	
	
	};




}
#endif