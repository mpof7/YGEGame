//ShaderBind.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_SHADERBIND_H
#define _YGE_SHADERBIND_H


#include "Shader.h"
#include "DrawNode.h"


namespace YGEGraphics 
{

	//!  ShaderBind class
    /*!
        The actual binding of a shader object
     */

  class ShaderBind : public DrawNode 
  {

	public:

		ShaderBind();

		void draw(RenderDevice *device);

		inline const Shader *getShader(){ return shader; }

		inline void setShader(Shader *s) { shader = s; }

	private:

		Shader				*shader;

	};




}
#endif