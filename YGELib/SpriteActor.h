//SpriteActor.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _SPRITE_ACTOR_H
#define _SPRITE_ACTOR_H

#include "Actor.h"
#include "DSVector.h"


namespace YGEEngine 
{

	class Phase;


	//!  SpriteActor class
    /*!
        A 2D actor class
     */

	class SpriteActor : public DynamicActor 
    {

	public:

		SpriteActor();

	
		void sync();

	
		void addToPhase(YGEEngine::Phase * const phase);
	
		void removeFromPhase(YGEEngine::Phase * const phase);

	
		void moveTowards(DS3DVector destination);
	
		void faceTowards(DS3DVector destination);


	private:
	
		YGEGraphics::InterpolatedTransform2D	*transform2d;
	
		YGEGraphics::Transform					*frameTransform;

		DS2DVector   initialPos;
		DS2DVector   velocity;


	};


}

#endif 