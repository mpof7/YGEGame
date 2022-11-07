//Cube.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_CUBE_H
#define _YGE_CUBE_H

#include "VertexBuffer.h"


namespace YGEGraphics
{

	//!  Cube class
    /*!
        A 3D cube primitive class
     */

	class Cube : public VertexSource
	{

	public:

		Cube(const float cubeSize);
	   ~Cube();


		void draw(RenderDevice *device);
		
		void fillVertexBuffer(void *vboBuffer);
		void fillIndexBuffer(void *iboBuffer);
		
		GLsizeiptr vertexBufferSize();
		GLsizeiptr indexBufferSize();


	private:

		float	cubeSize;
		unsigned short	vertexSize;
		
	
	};


}
#endif