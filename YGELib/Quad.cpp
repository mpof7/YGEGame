//Quad.cpp

#include "Quad.h"


namespace YGEGraphics
{

	struct QuadVertex 
	{
		
		GLfloat			x, y;			    // Position
		GLubyte			r, g, b, a;			// Colour
		GLshort			s, t;				// Texture coordinates
	};




	Quad::Quad(const float w, const float h)
	{

		width = w;
		height = h;
		vertexSize = sizeof(struct QuadVertex);
		
	}



	Quad::~Quad()
	{
	
	}



	void Quad::draw(RenderDevice *device)
	{
	
		int stride = vertexSize;

		glVertexPointer(2, GL_FLOAT, stride, NULL);
		glEnableClientState(GL_VERTEX_ARRAY);

		glColorPointer(4, GL_UNSIGNED_BYTE, stride, (void *)8);
		glEnableClientState(GL_COLOR_ARRAY);

	    glClientActiveTexture(GL_TEXTURE0);
		//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexCoordPointer(2, GL_SHORT, stride, (void *)12);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glDrawElements(GL_QUADS, 4, GL_UNSIGNED_SHORT, NULL);
		
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	
	}




	GLsizeiptr Quad::vertexBufferSize() 
	{
		
		return (4 * vertexSize);
	}



	void Quad::fillVertexBuffer(void *vboBuffer) 
	{
		
		struct QuadVertex *vertices = static_cast<QuadVertex *>(vboBuffer);
		
				//Quad, defined by 4 vertices
				
				// Vertex 0
				vertices->x = - width;
				vertices->y = - height;
				vertices->s = 0;
				vertices->t = 0;
				vertices->r = 0;
				vertices->g = 255;
				vertices->b = 0;
				vertices->a = 255;
				vertices++;
				
				// Vertex 1
				vertices->x = width;
				vertices->y = - height;
				vertices->s = 1;
				vertices->t = 0;
				vertices->r = 255;
				vertices->g = 0;
				vertices->b = 0;
				vertices->a = 255;
				vertices++;
				
				// Vertex 2
				vertices->x = width;
				vertices->y = height;
				vertices->s = 1;
				vertices->t = 1;
				vertices->r = 0;
				vertices->g = 0;
				vertices->b = 255;
				vertices->a = 255;
				vertices++;
				
				// Vertex 3
				vertices->x = - width;
				vertices->y = height;
				vertices->s = 0;
				vertices->t = 1;
				vertices->r = 255;
				vertices->g = 0;
				vertices->b = 255;
				vertices->a = 255;
				vertices++;


	}




	GLsizeiptr Quad::indexBufferSize() 
	{
		
		return (4 * sizeof(GLushort));
	}




	void Quad::fillIndexBuffer(void *iboBuffer) 
	{
		
		GLushort			*indices = static_cast<GLushort *>(iboBuffer);
		
		// Fill index buffer
	
			unsigned short index = 0;

			
			// Quad
			indices[index++] = 0;
			indices[index++] = 1;
			indices[index++] = 2;
			indices[index++] = 3;
			
			
	}


}