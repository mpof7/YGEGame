//Shader.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_SHADER_H
#define _YGE_SHADER_H

#include "RenderDevice.h"
#include "Object.h"


namespace YGEGraphics
{

	//!  Shader class
    /*!
        A shader's program base class
     */

	class Shader : public YGECore::Object, public Insertable
	{
	

	public:

		Shader(const char  *filename);

		void insertIntoGraphicsContext(RenderDevice *device);


		// Loading and compiling the shader
		const char *loadShaderFile(const char *fileName);
		bool compileShader(const char *source);

		inline const GLuint getObject() { return programmeHandle; }
	
	
	private:

		const char         *fileName;
		const char         *source;
		GLuint				object;
		GLhandleARB			programmeHandle, fragShaderHandle, vertShaderHandle;
	
	};


}
#endif