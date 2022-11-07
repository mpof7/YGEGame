//TextureBind.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_TEXTUREBIND_H
#define _YGE_TEXTUREBIND_H

#include "Texture.h"
#include "RenderDevice.h"
#include "DrawNode.h"



namespace YGEGraphics
{

	//!  TextureBind class
    /*!
        A texture's binding class
     */

	class TextureBind : public DrawNode
	{

	public:

		TextureBind();

		void draw(RenderDevice *device);


		inline const Texture *getTexture() { return texture; }

		inline void setTexture(Texture  *const tex) { texture = tex; }


	protected:

		Texture   *texture;
	
	};


}
#endif