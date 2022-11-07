//Quad.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_QUAD_H
#define _YGE_QUAD_H

#include "VertexBuffer.h"


namespace YGEGraphics
{

	//!  Quad class
    /*!
        A quad primitive class
     */

	class Quad : public VertexSource
	{

	public:

		Quad(const float width, const float height);
	   ~Quad();


		void draw(RenderDevice *device);
		
		void fillVertexBuffer(void *vboBuffer);
		void fillIndexBuffer(void *iboBuffer);
		
		GLsizeiptr vertexBufferSize();
		GLsizeiptr indexBufferSize();


	private:

		float	width, height;
		unsigned short	vertexSize;
		
	
	};


}
#endif