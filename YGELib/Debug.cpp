//Debug.cpp

#include "Debug.h"
#include "RenderDevice.h"


namespace YGEGraphics
{


	DebugDrawNode::DebugDrawNode() 
	{

		baseTime = YGECore::Time::getMilliTime();
		fpsAccum = childAccum = groupAccum = 0;
		frames = 0;

	}



	void DebugDrawNode::draw(RenderDevice *device) 
	{

		YGECore::YGETime  timeNow = YGECore::Time::getMilliTime();
		fpsAccum += timeNow - baseTime;
		frames++;

		if (fpsAccum >= 1000) 
		{

			printf("%d fps child = %d group = %d\n", frames, childAccum, groupAccum);
			frames = 0;
			fpsAccum -= 1000;
			childAccum = groupAccum = 0;
		}

		if (child) 
		{
			
			YGECore::YGETime  start = YGECore::Time::getMilliTime();
			child->draw(device);
			childAccum += (YGECore::Time::getMilliTime() - start);
		}

		if (group) 
		{
			
			YGECore::YGETime start = YGECore::Time::getMilliTime();
			group->draw(device);
			childAccum += (YGECore::Time::getMilliTime() - start);
		}


		baseTime = timeNow;
	}





}