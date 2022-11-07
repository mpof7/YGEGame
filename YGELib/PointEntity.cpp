//PointEntity.cpp

#include "PointEntity.h"
#include "Debug.h"


namespace YGEEngine
{

	PointEntity::PointEntity()
	{
	
		transform = transform3d = new YGEGraphics::InterpolatedTransform3D;

		frameTransform = new YGEGraphics::InterpolatedTransform3D;

		assert(transform && frameTransform);


		initialPosition = DS3DVector(DS3DVectorMake(0.0f, 0.0f, 0.0f));
		initialVelocity = DS3DVector(DS3DVectorMake(0.0f, 0.0f, 0.0f));
		appliedForce = DS3DVector(DS3DVectorMake(0.1f, 0.0f, 0.0f));
		newPosition = DS3DVector(DS3DVectorMake(0.0f, 0.0f, 0.0f));
		newVelocity = DS3DVector(DS3DVectorMake(0.0f, 0.0f, 0.0f));
	
	 
	
	}




	PointEntity::~PointEntity()
	{
	
	}



	void PointEntity::sync()
	{
	
		transform3d->setPos(DS3DVectorMake(newPosition.x, newPosition.y, newPosition.z));

		//transform3d->setRot(actorRot);
	
	}


	void PointEntity::step()
	{
	
		//newPosition.x += 0.01f;
		
		newVelocity = DS3DVectorAdd(initialVelocity, appliedForce); //initialVelocity + dt*appliedForce;

		newPosition = DS3DVectorAdd(initialPosition, newVelocity); //initialPosition + dt*newVetlociy;

		
		if(newPosition.x >= 5.0 || newPosition.x <= -5.0 )
		{

			//df = -df;

			//myPoint->setVelocity(df);

			appliedForce = DS3DVectorNegate(appliedForce);


		}

		

		initialPosition = newPosition;
		
	
	}



	void PointEntity::addToPhase(Phase * const phase) 
	{

		DynamicActor::addToPhase(phase);

		phase->addInterpable(transform3d);

		phase->addSimultable(this);

		phase->addDeleteable(frameTransform);

	}





	void PointEntity::removeFromPhase(Phase * const phase) 
	{

		DynamicActor::removeFromPhase(phase);

		phase->remInterpable(transform3d);

		phase->remSimultable(this);

		phase->remDeleteable(frameTransform);

	}





	void PointEntity::moveTowards(DS3DVector destination) 
	{

	}




	void PointEntity::faceTowards(DS3DVector destination) 
	{

	}






}