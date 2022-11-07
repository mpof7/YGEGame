//VertexBuffer.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_VERTEXBUFFER_H
#define _YGE_VERTEXBUFFER_H

#include "RenderDevice.h"
#include "Object.h"


namespace YGEGraphics
{


	//!  VertexSource class
    /*!
        Describes a source of vertices
     */

	class VertexSource : public YGECore::Object
	{
		
	public:

		virtual GLenum getMode() { return GL_STATIC_DRAW; }
		
		virtual void draw(RenderDevice *device) = 0;

		virtual void fillVertexBuffer(void *vboBuffer) = 0;
		virtual void fillIndexBuffer(void *iboBuffer) = 0;
		
		virtual GLsizeiptr vertexBufferSize() = 0;
		virtual GLsizeiptr indexBufferSize() = 0;

	};



	//!  VBO class
    /*!
        Describes a vertex buffer object
     */

	class VBO : public YGECore::Object, public Drawable, public Insertable 
	{

	public:

		VBO(VertexSource *vertexSource);
	   ~VBO();
		
		void draw(RenderDevice *device);
		void insertIntoGraphicsContext(RenderDevice *device);
		
		void fillBuffers();
		
	private:

		VertexSource				*vertexSource;
		
		// Vertex and index buffer objects
		GLuint						vbo;
		GLuint						ibo;


	};

}
#endif