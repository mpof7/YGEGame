//PointEntity.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _POINT_ENTITY_H
#define _POINT_ENTITY_H

#include "Actor.h"
#include "DSVector.h"


namespace YGEEngine 
{

	class Phase;


	//!  PointEntity class
    /*!
        Point entities' base class
     */

	class PointEntity : public DynamicActor, public YGESimulator::Simultable 
    {

	public:

		PointEntity();
		~PointEntity();

	
		void sync();

		void step();


		void addToPhase(YGEEngine::Phase * const phase);
	
		void removeFromPhase(YGEEngine::Phase * const phase);

	
		void moveTowards(DS3DVector destination);
	
		void faceTowards(DS3DVector destination);


		//Accessor Methods

		inline void setInitialPosition(const DS3DVector pos)
		{
			initialPosition = pos;
		
		};


		inline void setNewPosition(const DS3DVector npos)
		{
			newPosition = npos;
		
		};


		inline void setInitialVelocity(const DS3DVector vel)
		{
			initialVelocity = vel;
		
		};


		inline void setNewVelocity(const DS3DVector nvel)
		{
			newVelocity = nvel;
		
		};


		inline void applyForce(const DS3DVector f)
		{
			appliedForce = f;

		};


		inline DS3DVector getInitialPosition()
		{
			return initialPosition;
		
		};


		inline DS3DVector getNewPosition()
		{
			return newPosition;
		
		};


		inline DS3DVector getInitialVelocity()
		{
			return initialVelocity;
		
		};


		inline DS3DVector getNewVelocity()
		{
			return newVelocity;
		
		};


		inline DS3DVector getAppliedForce()
		{
			return appliedForce;
		
		};



		YGEGraphics::InterpolatedTransform3D	*transform3d;


	private:
	
	
		YGEGraphics::Transform					*frameTransform;
      
    



		DS3DVector   initialPosition;
		DS3DVector   initialVelocity;
		DS3DVector   appliedForce;

		DS3DVector   newPosition;
		DS3DVector   newVelocity;
		


	};


}

#endif 