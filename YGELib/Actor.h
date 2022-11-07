//Actor.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_ACTOR_H
#define _YGE_ACTOR_H

#include "Phase.h"
#include "DSVector.h"
#include "Simulation.h"


namespace YGEEngine {

	class YGEGraphics::Transform;
	

	//!  Actor class
    /*!
        Actor base class
     */


	class Actor : public PhaseObject 
	{

	public:

		Actor() 
		{ 
			active = true; 
		};


	};
	


	//!  PositionActor class
    /*!
        Position actor base class
     */

	class PositionActor : public Actor 
	{

	public:

		PositionActor();

		inline YGEGraphics::Transform *getTransform() { return transform; }

		void addToPhase(Phase * const phase);

		void removeFromPhase(Phase * const phase);


	protected:

		YGEGraphics::Transform		*transform;

	};
	


	//!  DynamicActor class
    /*!
        Dynamic actor base class
     */

	class DynamicActor : public PositionActor, public YGESimulator::Syncroable 
	{

	public:

		DynamicActor(){};

		void addToPhase(Phase * const phase);

		void removeFromPhase(Phase * const phase);

		virtual void moveTowards(DS3DVector destination) = 0;

		virtual void faceTowards(DS3DVector destination) = 0;

	};


}

#endif
