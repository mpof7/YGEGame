//FlockingSystem.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _FLOCKING_SYSTEM_H
#define _FLOCKING_SYSTEM_H

#include "PointEntity.h"




namespace YGEEngine
{

	

	class AnimationPath;


	//!  Flocking class
    /*!
        Flocking simulation base class
     */

	class FlockingSystem : public DynamicActor, public YGESimulator::Simultable, public YGESimulator::Updateable 
	{
	
	public:
		FlockingSystem(int n);
		~FlockingSystem();


		void initializeFlock();

		inline int getNumOfElements()
		{
		
			return numOfElements;
		};

		DS3DVector collisionAvoidance(const int elementIndex, const float distanceLength, DS3DVector distanceVector);

		DS3DVector velocityMatching(const int elementIndex, DS3DVector totalVelocity, const int nOfMates);

		DS3DVector flockCentring(const int elementIndex, DS3DVector totalPosition, const int nOfMates);

		void simulateFlockBehaviour(float dt);

		void sync();

		void step();

		void update();

		void addToPhase(YGEEngine::Phase * const phase);
	
		void removeFromPhase(YGEEngine::Phase * const phase);

	
		void moveTowards(DS3DVector destination);
	
		void faceTowards(DS3DVector destination);




		
		PointEntity   *elementArray;

		PointEntity  *flockSysElements;
	   
		float         SummedWeight;

	private:

		YGEGraphics::InterpolatedTransform3D	*transform3d;
	
		YGEGraphics::Transform					*frameTransform;


		int               numOfElements;

		AnimationPath     *splinePath;

		float             delta;

		float             speed;

		float             neighborhoodRange;

		float             minMemberDist;

		float             momentum, Wavoid, Wmatching, Wcentre;

		DS3DVector        Vavoid, Vmatching, Vcentring;

		float             MaxAngleArcLengthChange;

	
	};


}

#endif