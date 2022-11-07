//DrawNode.h

// Header file 

//Created by Nick Bofilios 2010



#ifndef _YGE_DRAWNODE_H
#define _YGE_DRAWNODE_H

#include "Object.h"
#include "RenderDevice.h"
#include "Transform.h"


namespace YGEGraphics
{


	//!  DrawNode class
    /*!
        Scene graph's drawing node class
     */

	class DrawNode : public YGECore::Object, public Drawable
	{
	
	public:

		DrawNode();

		void draw(RenderDevice *device);

		Drawable *child, *group;
	
	
	};



	//!  TransformNode class
    /*!
        Scene graph's transformation node class
     */

	class TransformNode : public DrawNode
	{
	
	public:

		TransformNode();

		void draw(RenderDevice *device);

		virtual Transform *getTransform() { return transform; }

		virtual void setTransform(Transform * const t) { transform = t; }



	protected:

		Transform		*transform;
	

	};



}
#endif