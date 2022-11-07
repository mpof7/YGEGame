//DrawNode.cpp

#include "DrawNode.h"
#include "RenderDevice.h"
#include "Debug.h"


namespace YGEGraphics
{


	DrawNode::DrawNode()
	{
	
		child = 0LL;
		group = 0LL;
	
	}



	void DrawNode::draw(RenderDevice *device)
	{
	
	
		if (child)
		{
		
			child ->draw(device);
		
		}
	
	
		if (group)
		{
		
			group ->draw(device);
		
		}


	}



	TransformNode::TransformNode()
	{
	
		transform = 0LL;
	}


	void TransformNode::draw(RenderDevice *device) {

		if (child) 
		{
			
			// Get the context's existing transform
			DS4DMatrix oldTransform = device->getTransformMatrix();
			
			// Get this node's transform
			DS4DMatrix newTransform = transform->getTransformMatrix();
			
			// Multiply the transforms together
			device->setTransformMatrix(DS4DMatrixMultiply(&oldTransform, &newTransform));
			
			child->draw(device);
			
			// Restore the previous transform
			device->setTransformMatrix(oldTransform);
		}


		if (group)
		{ 
			group->draw(device);
		}

	}



}