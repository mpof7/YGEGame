//Cube.cpp

#include "Cube.h"


namespace YGEGraphics
{


	struct CubeVertex 
	{
		
		GLfloat			x, y, z;			// Position
		GLubyte			r, g, b, a;			// Colour
		GLshort			s, t;				// Texture coordinates
	};
	


	Cube::Cube(const float csize)
	{

		cubeSize = csize;
		vertexSize = sizeof(struct CubeVertex);
		
	}


	Cube::~Cube()
	{
	}


	void Cube::draw(RenderDevice *device)
	{
	
		int stride = vertexSize;

		glVertexPointer(3, GL_FLOAT, stride, NULL);
		glEnableClientState(GL_VERTEX_ARRAY);

		glColorPointer(4, GL_UNSIGNED_BYTE, stride, (void *)12);
		glEnableClientState(GL_COLOR_ARRAY);

	    glClientActiveTexture(GL_TEXTURE0);
		glTexCoordPointer(2, GL_SHORT, stride, (void *)16);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, NULL);
		
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	
	}


	GLsizeiptr Cube::vertexBufferSize() 
	{
		
		return (8 * vertexSize);
	}


	void Cube::fillVertexBuffer(void *vboBuffer) 
	{
		
		struct CubeVertex *vertices = static_cast<CubeVertex *>(vboBuffer);
		
				//Cube's front face
				
				// Vertex 0
				vertices->x = - cubeSize;
				vertices->y = - cubeSize;
				vertices->z = cubeSize;
				vertices->s = 0;
				vertices->t = 0;
				vertices->r = 0;
				vertices->g = 255;
				vertices->b = 0;
				vertices->a = 255;
				vertices++;
				
				// Vertex 1
				vertices->x = cubeSize;
				vertices->y = - cubeSize;
				vertices->z = cubeSize;
				vertices->s = 1;
				vertices->t = 0;
				vertices->r = 255;
				vertices->g = 0;
				vertices->b = 0;
				vertices->a = 255;
				vertices++;
				
				// Vertex 2
				vertices->x = cubeSize;
				vertices->y = cubeSize;
				vertices->z = cubeSize;
				vertices->s = 1;
				vertices->t = 1;
				vertices->r = 0;
				vertices->g = 0;
				vertices->b = 255;
				vertices->a = 255;
				vertices++;
				
				// Vertex 3
				vertices->x = - cubeSize;
				vertices->y = cubeSize;
				vertices->z = cubeSize;
				vertices->s = 0;
				vertices->t = 1;
				vertices->r = 255;
				vertices->g = 0;
				vertices->b = 255;
				vertices->a = 255;
				vertices++;

				//Cube's back face

				// Vertex 4
				vertices->x = - cubeSize;
				vertices->y = - cubeSize;
				vertices->z = - cubeSize;
				vertices->s = 0;
				vertices->t = 0;
				vertices->r = 255;
				vertices->g = 255;
				vertices->b = 0;
				vertices->a = 255;
				vertices++;

				// Vertex 5
				vertices->x = cubeSize;
				vertices->y = - cubeSize;
				vertices->z = - cubeSize;
				vertices->s = 1;
				vertices->t = 0;
				vertices->r = 0;
				vertices->g = 255;
				vertices->b = 255;
				vertices->a = 255;
				vertices++;

				// Vertex 6
				vertices->x = cubeSize;
				vertices->y = cubeSize;
				vertices->z = - cubeSize;
				vertices->s = 1;
				vertices->t = 1;
				vertices->r = 255;
				vertices->g = 0;
				vertices->b = 255;
				vertices->a = 255;
				vertices++;

				// Vertex 7
				vertices->x = - cubeSize;
				vertices->y = cubeSize;
				vertices->z = - cubeSize;
				vertices->s = 0;
				vertices->t = 1;
				vertices->r = 255;
				vertices->g = 0;
				vertices->b = 255;
				vertices->a = 255;
				//vertices++;


	}


	GLsizeiptr Cube::indexBufferSize() 
	{
		
		return (36 * sizeof(GLushort));
	}



	void Cube::fillIndexBuffer(void *iboBuffer) 
	{
		
		GLushort			*indices = static_cast<GLushort *>(iboBuffer);
		
		// Fill index buffer
	
			unsigned short index = 0;

			
			// Triangle 0
			indices[index++] = 0;
			indices[index++] = 1;
			indices[index++] = 2;
			
			// Triangle 1
			indices[index++] = 0;
			indices[index++] = 2;
			indices[index++] = 3;

			// Triangle 2
			indices[index++] = 1;
			indices[index++] = 5;
			indices[index++] = 6;

			// Triangle 3
			indices[index++] = 1;
			indices[index++] = 6;
			indices[index++] = 2;

			// Triangle 4
			indices[index++] = 4;
			indices[index++] = 5;
			indices[index++] = 6;

			// Triangle 5
			indices[index++] = 4;
			indices[index++] = 6;
			indices[index++] = 7;

			// Triangle 6
			indices[index++] = 0;
			indices[index++] = 4;
			indices[index++] = 7;

			// Triangle 7
			indices[index++] = 0;
			indices[index++] = 7;
			indices[index++] = 3;

			// Triangle 8
			indices[index++] = 4;
			indices[index++] = 0;
			indices[index++] = 1;

			// Triangle 9
			indices[index++] = 4;
			indices[index++] = 1;
			indices[index++] = 5;

			// Triangle 10
			indices[index++] = 7;
			indices[index++] = 3;
			indices[index++] = 2;

			// Triangle 11
			indices[index++] = 7;
			indices[index++] = 2;
			indices[index++] = 6;

	}



}