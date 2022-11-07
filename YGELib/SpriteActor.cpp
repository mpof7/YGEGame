//SpriteActor.cpp


#include "SpriteActor.h"
#include "Debug.h"

namespace YGEEngine
{

	SpriteActor::SpriteActor() 
	{

		transform = transform2d = new YGEGraphics::InterpolatedTransform2D;

		frameTransform = new YGEGraphics::InterpolatedTransform2D;

		assert(transform && frameTransform);


		initialPos = DS2DVectorMake(1.0f, 0.0f);
		velocity.x = -0.01f;
		velocity.y = 0.0f;

    }



	void SpriteActor::sync() 
	{


		initialPos.x += velocity.x;
		float x = initialPos.x;
		float y = initialPos.y;

	
		transform2d->setPos(DS2DVectorMake(x, y));
	

	}



	void SpriteActor::addToPhase(Phase * const phase) 
	{

		DynamicActor::addToPhase(phase);

		phase->addInterpable(transform2d);

		phase->addDeleteable(frameTransform);

	}



	void SpriteActor::removeFromPhase(Phase * const phase) 
	{

		DynamicActor::removeFromPhase(phase);

		phase->remInterpable(transform2d);

		phase->remDeleteable(frameTransform);

	}



	void SpriteActor::moveTowards(DS3DVector destination) 
	{

	}

	void SpriteActor::faceTowards(DS3DVector destination) 
	{

	}

}