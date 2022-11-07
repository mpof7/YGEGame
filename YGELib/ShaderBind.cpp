//ShaderBind.cpp

#include "ShaderBind.h"



namespace YGEGraphics
{


	ShaderBind::ShaderBind()
	{
	
		shader = 0LL;
	
	}



   void ShaderBind::draw(RenderDevice *device) 
   {

		if (child) 
		{

			GLuint obj = shader->getObject();

		    glUseProgram(obj);

			child->draw(device);

			glUseProgram(0);

		}

		if (group) 
		{
			group->draw(device);
		}

	}









}


