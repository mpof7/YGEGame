//ExplosionSystem.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _EXPLOSION_SYSTEM_H
#define _EXPLOSION_SYSTEM_H

#include "PointEntity.h"




namespace YGEEngine
{

	class Phase;


	//!  ExposionSystem class
    /*!
        Explosion like simulation base class
     */

	class ExplosionSystem : public DynamicActor, public YGESimulator::Simultable 
	{
	
	public:
		ExplosionSystem(int n);
		~ExplosionSystem();


		void initializeFlock();


		void sync();

		void step();


		void addToPhase(YGEEngine::Phase * const phase);
	
		void removeFromPhase(YGEEngine::Phase * const phase);

	
		void moveTowards(DS3DVector destination);
	
		void faceTowards(DS3DVector destination);



	

		PointEntity   *elementArray;

		PointEntity  *particleSysElements;




		PointEntity   *flockLeader;


		inline void setFlockLeader(PointEntity *leader)
		{
		
			flockLeader = leader;
		
		};

		inline int getNumOfElements()
		{
		
			return numOfElements;
		};


		inline PointEntity* getFlock()
		{
		
			return flockLeader;
		};


	   

	private:

		YGEGraphics::InterpolatedTransform3D	*transform3d;
	
		YGEGraphics::Transform					*frameTransform;




		int  numOfElements;

	
	};


}

#endif