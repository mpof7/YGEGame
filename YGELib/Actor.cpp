//Actor.cpp

#include "Actor.h"
#include "Transform.h"



namespace YGEEngine
{

	PositionActor::PositionActor()
	{
	
		transform = 0LL;
	
	}


	void PositionActor::addToPhase(Phase * const phase) 
	{

		PhaseObject::addToPhase(phase);

		phase->addDeleteable(transform);

	}


	void PositionActor::removeFromPhase(Phase * const phase) 
	{

		PhaseObject::removeFromPhase(phase);

		phase->remDeleteable(transform);

	}



	void DynamicActor::addToPhase(Phase * const phase) 
	{

		PositionActor::addToPhase(phase);

		phase->addSyncroable(this);

	}




	void DynamicActor::removeFromPhase(Phase * const phase) 
	{

		PositionActor::removeFromPhase(phase);

		phase->remSyncroable(this);

	}



}