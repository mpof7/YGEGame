//Simulation3D.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_SIMULATION_3D_H
#define _YGE_SIMULATION_3D_H

#include "Object.h"
#include "Simulation.h"
#include "Bullet-C-Api.h"
#include "btBulletDynamicsCommon.h"
#include "btBulletCollisionCommon.h"


namespace YGESimulator
{


	//!  BPSimulator class
    /*!
        Bullet physics simulator
     */

	class BPSimulator : public YGECore::Object, public Simultable 
	{

	public:

		BPSimulator();
		virtual ~BPSimulator();

		void step();

		inline btDiscreteDynamicsWorld  *getSimSpace() { return dynamicsWorld; }

	private:

		btBroadphaseInterface                  *broadphase;                         //Object used for defining the broadphase collision detection algorithm
		btDefaultCollisionConfiguration        *collisionConfiguration;             //Object used for defining the collision configuration parameters
		btCollisionDispatcher                  *dispatcher;                         
		btSequentialImpulseConstraintSolver    *solver;                             //The solver object

	
		btDiscreteDynamicsWorld                *dynamicsWorld;                      //The simulation's world


	};
	


	//!  BPActor class
    /*!
        Bullet physics actor
     */

	class BPActor 
	{

		virtual void addBPSimulation(BPSimulator * const sim) = 0;
		virtual void remBPSimulation(BPSimulator * const sim) = 0;

	};







}

#endif