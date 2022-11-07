//Debug.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_DEBUG_H
#define _YGE_DEBUG_H


#ifdef _DEBUG
#include <assert.h>
#include <iostream>
#include <fstream>
#define DBG(x) x
#else
#define assert(x)
#define DBG(x)
#endif


#include "Time.h"
#include "DrawNode.h"

namespace YGEGraphics {
	
	//!  DebugDrawNode class
    /*!
        Calculation of several metrics class
     */

	class DebugDrawNode : public DrawNode 
	{

	public:

		DebugDrawNode();

		void draw(RenderDevice *device);

	private:

		YGECore::YGETime	baseTime;

		YGECore::YGETime	fpsAccum, childAccum, groupAccum;

		unsigned long		frames;

	};


}

#endif