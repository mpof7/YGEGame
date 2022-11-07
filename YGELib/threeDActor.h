//threeDActor.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _THREED_ACTOR_H
#define _THREED_ACTOR_H

#include "Actor.h"
#include "DSVector.h"



namespace YGEEngine 
{

	class Phase;


	//!  threeDActor class
    /*!
        A 3D actor class
     */
	
	class threeDActor : public DynamicActor , public YGESimulator::Updateable
    {

	public:

		threeDActor();

	
		void sync();
		void update();

	
		void addToPhase(YGEEngine::Phase * const phase);
	
		void removeFromPhase(YGEEngine::Phase * const phase);

	
		void moveTowards(DS3DVector destination);
	
		void faceTowards(DS3DVector destination);


		static void orientTowards(DSFloat angle);
		static void moveForward(DS3DVector destination);
		
		static float    yaw;


	private:
	
		static YGEGraphics::InterpolatedTransform3D	    *transform3d;
	
		YGEGraphics::Transform					        *frameTransform;


		static DS3DVector                               actorPosition;

		static DSQuat                                   actorRot;

		

	};


}

#endif 