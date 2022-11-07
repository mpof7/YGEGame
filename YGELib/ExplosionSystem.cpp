//ExplosionSystem.cpp


#include "ExplosionSystem.h"
#include "Debug.h"


namespace YGEEngine
{


	ExplosionSystem::ExplosionSystem(int n)
	{


		transform = transform3d = new YGEGraphics::InterpolatedTransform3D;

		

		frameTransform = new YGEGraphics::InterpolatedTransform3D;

		assert(transform && frameTransform);

		//transform3d = NULL;

		numOfElements = n;

		
		
		elementArray = new PointEntity[n];
		//elementArray = (PointEntity *) malloc(n * sizeof(PointEntity));
		
		
		particleSysElements = elementArray;
		
	

		//flockLeader = &flockElements[0]; //or flockLeader = NULL;
		flockLeader = NULL;
	
	
	
	}



	void ExplosionSystem::initializeFlock()
	{
	
				DS3DVector randomVelvec;

		for( int i =0; i < numOfElements; i++)
		{

			// generate random hemispherical velocity (like an explosion)

			float PI = 3.14159f;

			float theta = ((float)rand()/RAND_MAX) *2 * PI;

			float phi = ((float)rand()/RAND_MAX) * PI;

			float mag = ((float)rand()/RAND_MAX);

			//random.set( (cos(theta)*sin(phi)/2.0), (sin(theta)*sin(phi)), cos(phi)/2.0 );

			//random *= mag;

			//this->flockElements[i].setVelocity(random);

			randomVelvec = DS3DVector(DS3DVectorMake((cos(theta)*sin(phi)/2.0), (sin(theta)*sin(phi)), cos(phi)/2.0));

			randomVelvec = DS3DVectorMultiply(randomVelvec, mag);




		
	
	
			particleSysElements[i].setNewVelocity(randomVelvec);
		    //(flockElements + i)->setNewVelocity(randomVelvec);
			
			//elementArray[i].setNewVelocity(randomVelvec);
			
		}
	

	
	
	}




	ExplosionSystem::~ExplosionSystem()
	{
	
		//flockLeader = NULL;
	
	}



	void ExplosionSystem::sync()
	{
	
		//transform3d->setPos(DS3DVectorMake(flockLeader->getNewPosition().x, flockLeader->getNewPosition().y, flockLeader->getNewPosition().z));
		//transform3d->setPos(DS3DVectorMake(flockElements[5].getNewPosition().x, flockElements[5].getNewPosition().y, flockElements[5].getNewPosition().z));
		//transform3d->setRot(actorRot);

		transform3d->setPos(DS3DVectorMake(0.0f, 0.0f, 0.0f));

		
	
	
	}



	void ExplosionSystem::step()
	{

		DS3DVector gravity = DS3DVector(DS3DVectorMake(0.0, -0.05, 0.0));
        DS3DVector bounce = DS3DVector(DS3DVectorMake(0.0, 0.8, 0.0));
        DS3DVector newVel;
        DS3DVector newPos;
        DS3DVector zero = DS3DVector(DS3DVectorMake(0.0, 0.0, 0.0));



		// implement flocking algorithm here
		for( int i = 0 ; i < numOfElements; i++)
		{
		
			//newVel = flockElements[i].getVelocity()+ gravity*dt;
            //newPos = flockElements[i].getPosition() + flockElements[i].getVelocity()*dt;

			newVel = DS3DVectorAdd(particleSysElements[i].getNewVelocity(), gravity);

			newPos = DS3DVectorAdd(particleSysElements[i].getInitialPosition(), particleSysElements[i].getNewVelocity());



			if(DS3DVectorLength(particleSysElements[i].getNewVelocity()) > 0.05 || abs(particleSysElements[i].getNewPosition().y -9.5) > 0.05)
			{
			
				float drag = 0.98f;

				// newPos = flockElement[i].getPosition() + flockElement[i].getVelocity();

				//newVel = flockElements[i].getVelocity()*drag + gravity;

				//newPos = flockElements[i].getPosition() + flockElements[i].getVelocity();

				newVel = DS3DVectorAdd(DS3DVectorMultiply(particleSysElements[i].getNewVelocity(), drag), gravity);

				newPos = DS3DVectorAdd(particleSysElements[i].getInitialPosition(), particleSysElements[i].getNewVelocity());



				if( newPos.y < -9.5 ) newVel.y *=-bounce.y;
			
			
			}
		
		

			particleSysElements[i].setNewPosition(DS3DVectorMake(newPos.x, newPos.y, newPos.z));

            particleSysElements[i].setNewVelocity(newVel);

            particleSysElements[i].setInitialPosition(newPos);



		
		    particleSysElements[i].sync();
		
		}
	

		
	
	
	}




	void ExplosionSystem::addToPhase(Phase * const phase) 
	{

		DynamicActor::addToPhase(phase);

		for( int i = 0 ; i < numOfElements; i++)
		{
		
			phase->addInterpable(this->particleSysElements[i].transform3d);

		}

		phase->addSimultable(this);

		phase->addDeleteable(frameTransform);

	

	}



	void ExplosionSystem::removeFromPhase(Phase * const phase) 
	{

		DynamicActor::removeFromPhase(phase);

		for( int i = 0 ; i < numOfElements; i++)
		{
		
			phase->remInterpable(this->particleSysElements[i].transform3d);

		}

		phase->remSimultable(this);

		phase->remDeleteable(frameTransform);

	}




	void ExplosionSystem::moveTowards(DS3DVector destination) 
	{

	}



	void ExplosionSystem::faceTowards(DS3DVector destination) 
	{

	}





}

