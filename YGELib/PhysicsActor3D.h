//PhysicsActor3D.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _PHYSICS_ACTOR_3D_H
#define _PHYSICS_ACTOR_3D_H

#include "Actor.h"
#include "DSVector.h"
#include "Simulation3D.h"


namespace YGEEngine 
{


	class Phase;


	//!  PhysicsActor3D class
    /*!
        A 3D physics actor 
     */

   class PhysicsActor3D : public YGEEngine::DynamicActor, public YGESimulator::BPActor 
   {


   public:
	
	   PhysicsActor3D();

	   ~PhysicsActor3D();

	
	   void sync();

	
	   void addToPhase(YGEEngine::Phase * const phase);
	
	   void removeFromPhase(YGEEngine::Phase * const phase);
	
	
	   void addBPSimulation(YGESimulator::BPSimulator * const sim);
	
	   void remBPSimulation(YGESimulator::BPSimulator * const sim);

	
	   void moveTowards(DS3DVector destination);
	
	   void faceTowards(DS3DVector destination);


   private:
	
	   YGEGraphics::InterpolatedTransform3D		*modelTransform;
	   YGEGraphics::Transform2D					*frameTransform;

	
	   //Collidion shapes definition
	    btCollisionShape                        *groundShape;                         
		btCollisionShape                        *fallShape;                            


		//Some motion states
		btDefaultMotionState                    *groundMotionState;                   
		btDefaultMotionState                    *fallMotionState;                     


		//Rigid bodies definition
		btRigidBody                             *groundRigidBody;                    
		btRigidBody                             *fallRigidBody;                      



    };


 }

#endif