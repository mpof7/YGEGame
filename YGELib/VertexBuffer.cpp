//VertexBuffer.cpp

#include "VertexBuffer.h"
#include "Debug.h"



namespace YGEGraphics
{


	VBO::VBO(VertexSource *vs) 
	{
		
		vertexSource = vs;

	}

	VBO::~VBO()
	{
		//free up buffer resources
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ibo);
	}


	void VBO::insertIntoGraphicsContext(RenderDevice *device) 
	{
		
		if (vertexSource) 
		{
			
			//Generate buffer objects
			glGenBuffers(1, &vbo);
			glGenBuffers(1, &ibo);
			assert(vbo && ibo);
			
			//Fill the buffers with data
			if (vertexSource->vertexBufferSize()) 
			{
				fillBuffers();
			}
			
			//Unbind buffers
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}


	}


	void VBO::draw(RenderDevice *device) 
	{
		
		if (vertexSource && vertexSource->vertexBufferSize()) 
		{
			
			//Bind the VBO and IBO
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			
			//For dynamic vertex buffers, refill the buffers
			if (GL_STATIC_DRAW != vertexSource->getMode()) fillBuffers();
			
			//Call draw on the vertexSource
			vertexSource->draw(device);
			
			//Unbind the VBO and IBO
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}


	}


	void VBO::fillBuffers() 
	{
		
		GLenum mode = vertexSource->getMode();
		
		//Bind the new VBO and allocate enough space for its storage
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertexSource->vertexBufferSize(), NULL, mode);
		
		//Map the vertex buffer
		GLvoid *vboBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		assert(vboBuffer);
		
		//Fill the vertex buffer with interleaved data
		vertexSource->fillVertexBuffer(vboBuffer);
		
		//Unmap and unbind the vertex buffer
		glUnmapBuffer(GL_ARRAY_BUFFER);
		
		GLsizeiptr iboSize = vertexSource->indexBufferSize();
		
		if (iboSize) 
		{
			
			//Bind the new IBO and allocate enough space for its storage
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, iboSize, NULL, mode);
			
			//Map the index buffer
			GLvoid *iboBuffer = glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);
			assert(iboBuffer);
			
			//Fill index buffer
			vertexSource->fillIndexBuffer(iboBuffer);
			
			//Unmap and unbind the index buffer
			glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
		}




	}




}