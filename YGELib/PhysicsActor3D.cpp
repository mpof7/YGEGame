//PhysicsActor3D.cpp


#include "PhysicsActor3D.h"
#include "Debug.h"


namespace YGEEngine
{


	PhysicsActor3D::PhysicsActor3D()
	{

		transform = modelTransform = new YGEGraphics::InterpolatedTransform3D;
		frameTransform = new YGEGraphics::InterpolatedTransform2D;
		assert(modelTransform && frameTransform);

	}




	PhysicsActor3D::~PhysicsActor3D()
	{

		delete fallRigidBody->getMotionState();
		delete fallRigidBody;
		delete groundRigidBody->getMotionState();
		delete groundRigidBody;
		delete fallShape;
		delete groundShape;

	}




	void PhysicsActor3D::sync()
	{
	
		btTransform trans;

		fallRigidBody->getMotionState()->getWorldTransform(trans);

		btVector3		pos = trans.getOrigin();
	
		btQuaternion    rot = trans.getRotation();

		modelTransform->setPos(DS3DVectorMake(pos.x(), pos.y(), pos.z()));

		DSQuat rotation;
		rotation.x = rot.x();
		rotation.y = rot.y();
		rotation.z = rot.z();
		rotation.w = rot.w();

		modelTransform->setRot(rotation);


	}





	void PhysicsActor3D::addToPhase(YGEEngine::Phase * const phase)
	{

		DynamicActor::addToPhase(phase);

		phase->addInterpable(modelTransform);

		phase->addDeleteable(frameTransform);

	}






	void PhysicsActor3D::removeFromPhase(YGEEngine::Phase * const phase)
	{

		DynamicActor::removeFromPhase(phase);

		phase->remInterpable(modelTransform);

		phase->remDeleteable(frameTransform);

	}






	void PhysicsActor3D::addBPSimulation(YGESimulator::BPSimulator * const sim)
	{


		btDiscreteDynamicsWorld  *dynamicsWorld = sim->getSimSpace();   //create thr current simulation's world
		assert(dynamicsWorld);


	
		groundShape = new btStaticPlaneShape(btVector3(0,1,0),1);    //a plane shape for the ground to use for collision detection
		fallShape = new btSphereShape(1);                            //a sphere shape for the falling object to use for collisiopn detection


	
		groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-1,0)));   //place the ground at y=-1 with the identity rotation
		fallMotionState =  new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,50,0)));    //place the falling object at y=50m above the ground with the identity rotation



		//Set up some attributes for the falling object
		btScalar mass = 1;
		btVector3 fallInertia(0,0,0);
		fallShape->calculateLocalInertia(mass,fallInertia);


	

		//Structs containing info about the construction of the rigid bodies
		btRigidBody::btRigidBodyConstructionInfo  groundRigidBodyCI(0,groundMotionState,groundShape,btVector3(0,0,0));
		btRigidBody::btRigidBodyConstructionInfo  fallRigidBodyCI(mass,fallMotionState,fallShape,fallInertia);

	
		//define the ground and falling object's rigid bodies using the above info provided
		groundRigidBody = new btRigidBody(groundRigidBodyCI);
		fallRigidBody = new btRigidBody(fallRigidBodyCI);

	
		//fallRigidBody->applyCentralImpulse(btVector3(0,0,-0.5));
		//fallRigidBody->applyTorque(btVector3(30, 0, 0));
		//fallRigidBody->applyImpulse(btVector3(0, -30, 0), btVector3(0, 0, 0));
		//fallRigidBody->applyTorqueImpulse(btVector3(1, 0, 0));
		//fallRigidBody->setFriction(100);

	

		//And finally add the rigid bodies into our simulation world
		dynamicsWorld->addRigidBody(groundRigidBody);
		dynamicsWorld->addRigidBody(fallRigidBody);


	}





	void PhysicsActor3D::remBPSimulation(YGESimulator::BPSimulator * const sim)
	{

		btDiscreteDynamicsWorld  *dynamicsWorld = sim->getSimSpace();
		assert(dynamicsWorld);

		dynamicsWorld->removeRigidBody(fallRigidBody);
		dynamicsWorld->removeRigidBody(groundRigidBody);

	
	}




	void PhysicsActor3D::moveTowards(DS3DVector destination) {};

	void PhysicsActor3D::faceTowards(DS3DVector destination) {};




}