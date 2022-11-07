//threeDActor.cpp


#include "threeDActor.h"
#include "Debug.h"
#include "InputDevice.h"


namespace YGEEngine
{

	DS3DVector                             threeDActor::actorPosition;
	DSQuat                                 threeDActor::actorRot;
	YGEGraphics::InterpolatedTransform3D   *threeDActor::transform3d;
	float                                  threeDActor::yaw;



	threeDActor::threeDActor() 
	{

		transform = transform3d = new YGEGraphics::InterpolatedTransform3D;

		frameTransform = new YGEGraphics::InterpolatedTransform3D;

		assert(transform && frameTransform);


		actorPosition = DS3DVector(DS3DVectorMake(0.0f, 0.0f, 0.0f));

		actorRot = DSQuatIdentity;

		yaw = 0;
	
    }



	void threeDActor::sync() 
	{
	
		transform3d->setPos(DS3DVectorMake(actorPosition.x, actorPosition.y, actorPosition.z));

		transform3d->setRot(actorRot);

	}


	void threeDActor::update()
	{

		//Move forward
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_W))
		{
		
			YGEEngine::threeDActor::moveForward(DS3DVectorMake(0.0f, 0.0f, 1.0f));
		
		}



		//Move backward
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_S))
		{
		
			YGEEngine::threeDActor::moveForward(DS3DVectorMake(0.0f, 0.0f, -1.0f));
		
		}



		//Orient right
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_D))
		{

			YGEEngine::threeDActor::yaw -= 0.001f;
			YGEEngine::threeDActor::orientTowards(YGEEngine::threeDActor::yaw);
		
		}



		//Orient left
		if (YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_A))
		{

			YGEEngine::threeDActor::yaw += 0.001f;
			YGEEngine::threeDActor::orientTowards(YGEEngine::threeDActor::yaw);
		
		}
	
	
	}


	void threeDActor::addToPhase(Phase * const phase) 
	{

		DynamicActor::addToPhase(phase);

		phase->addUpdateable(this);
	
		phase->addInterpable(transform3d);

		phase->addDeleteable(frameTransform);

	}



	void threeDActor::removeFromPhase(Phase * const phase) 
	{

		DynamicActor::removeFromPhase(phase);

		phase->remUpdateable(this);

		phase->remInterpable(transform3d);

		phase->remDeleteable(frameTransform);

	}



	void threeDActor::moveTowards(DS3DVector destination) 
	{

	}




	void threeDActor::faceTowards(DS3DVector destination) 
	{

	}






	void threeDActor::orientTowards(DSFloat angle)
	{
	
	
		actorRot = DSQuatRotate(&DSQuatIdentity, &DSVector3DYAxis, angle);
	
		
	
	}


	void threeDActor::moveForward(DS3DVector destination)
	{

		//DS3DVector rotatedVector;

		//DS3DVector actorRotation;

		float moveSpeed = 0.001f;


		//actorRotation = DS3DVectorFromDSQuat(&transform3d->getRot());

		//rotatedVector = DS3DVectorMake(destination.x * actorRotation.x, destination.y * actorRotation.y, destination.z * actorRotation.z);


		//actorPosition.x += moveSpeed * rotatedVector.x;
		//actorPosition.y += moveSpeed * rotatedVector.y;
		//actorPosition.z += moveSpeed * rotatedVector.z;
	

		actorPosition.x += moveSpeed * destination.x;
		actorPosition.y += moveSpeed * destination.y;
		actorPosition.z += moveSpeed * destination.z;

		
	
	}


}