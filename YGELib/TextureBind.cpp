//TextureBind.cpp

#include "TextureBind.h"


namespace YGEGraphics
{


	TextureBind::TextureBind()
	{
	
		texture = 0LL;

	}


	void TextureBind::draw(RenderDevice *device)
	{
	
		if (child) 
		{
			
			glEnable(GL_TEXTURE_2D);


			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


			glBindTexture(GL_TEXTURE_2D, texture->texId);


			child->draw(device);


			glBindTexture(GL_TEXTURE_2D, 0);


			glDisable(GL_TEXTURE_2D);
			
		}


		if (group)
		{ 
			group->draw(device);
		}

	
	}


}