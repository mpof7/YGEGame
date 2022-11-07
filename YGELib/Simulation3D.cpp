//Simulation3D.cpp

#include "Simulation3D.h"
#include "Debug.h"

namespace YGESimulator
{

	BPSimulator::BPSimulator()
	{

		broadphase = new btDbvtBroadphase();
		collisionConfiguration = new btDefaultCollisionConfiguration();
		dispatcher = new btCollisionDispatcher(collisionConfiguration);
		solver = new btSequentialImpulseConstraintSolver;

		dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
		assert(dynamicsWorld);


		dynamicsWorld->setGravity(btVector3(0,-10,0));
	
	}



	BPSimulator::~BPSimulator()
	{
	
		// Clean up behind ourselves like good little programmers
		//delete dynamicsWorld;
		//delete solver;
		//delete dispatcher;
		//delete collisionConfiguration;
		//delete broadphase;
	
	}





	void BPSimulator::step()
	{
	
	
		dynamicsWorld->stepSimulation(1/60.f,10);
	
	
	}




}