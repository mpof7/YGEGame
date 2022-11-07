//FlockingSystem.cpp


#include "FlockingSystem.h"
#include "AnimationPath.h"
#include "InputDevice.h"
#include "Debug.h"


#define CLAMP(val, lo, hi) ((val < lo) ? lo : (hi < val) ? hi : val)


namespace YGEEngine
{


	FlockingSystem::FlockingSystem(int n)
	{


		transform = transform3d = new YGEGraphics::InterpolatedTransform3D;

		frameTransform = new YGEGraphics::InterpolatedTransform3D;

		assert(transform && frameTransform);



		numOfElements = n;

		elementArray = new PointEntity[n];
		//elementArray = (PointEntity *) malloc(n * sizeof(PointEntity));
		flockSysElements = elementArray;
		
	
		splinePath = new AnimationPath();

		delta = 0;
		neighborhoodRange = 5.0f;
		minMemberDist = 1.0f;

		momentum = 0.15f;
		Wavoid = 0.9f;
		Wmatching = 0.05f;
		Wcentre = 0.05f;

		speed = 0.55f;

		MaxAngleArcLengthChange = 270.0f;
	
	}


	
	FlockingSystem::~FlockingSystem()
	{
	

	
	}





	void FlockingSystem::initializeFlock()
	{
	
		DS3DVector randomVelvec;
		const float initRadius = 20.0f;

		flockSysElements[0].setNewVelocity(splinePath->TangentOnCurve(0.f));
		//flockSysElements[0].setNewPosition(DS3DVectorAdd(flockSysElements[i].getInitialPosition(), DS3DVectorMultiply(flockSysElements[i].getNewVelocity(),2.f)));
		flockSysElements[0].setNewPosition(splinePath->PointOnCurve(0.f));
		flockSysElements[0].setInitialPosition(flockSysElements[0].getNewPosition());

		for( int i = 1; i < numOfElements; i++)
		{

			
		/*
			float randVelDotLeader = 0.f;

			do
			{
			//generate random hemispherical velocity (like an explosion)
			float PI = 3.14159f;

			float theta = ((float)rand()/RAND_MAX) *2 * PI;

			float phi = ((float)rand()/RAND_MAX) * PI;

			float mag = ((float)rand()/RAND_MAX);

			randomVelvec = DS3DVector(DS3DVectorMake((cos(theta)*sin(phi)/2.0), (sin(theta)*sin(phi)), cos(phi)/2.0));

			randomVelvec = DS3DVectorMultiply(randomVelvec, mag);

			randVelDotLeader = DS3DVectorDot(randomVelvec, flockSysElements[0].getNewVelocity());
			}
			while(randVelDotLeader<0.7f);
			*/

	
			randomVelvec = DS3DVectorMake(((float(rand())/RAND_MAX)-0.5f)*2.f, ((float(rand())/RAND_MAX)-0.5f)*2.f, ((float(rand())/RAND_MAX)-0.5f)*2.f);

	
			flockSysElements[i].setInitialPosition(DS3DVectorAdd(flockSysElements[0].getNewPosition(), DS3DVectorMultiply(randomVelvec, initRadius)));
			flockSysElements[i].setNewVelocity(splinePath->TangentOnCurve(0.f));
			flockSysElements[i].setNewPosition(DS3DVectorAdd(flockSysElements[i].getInitialPosition(), flockSysElements[i].getNewVelocity()));
			

			
		}
	

	
	
	}


	DS3DVector FlockingSystem::collisionAvoidance(const int elementIndex, const float distanceLength, DS3DVector distanceVector)
	{
		int i = elementIndex;
		float distLength = distanceLength;
		DS3DVector distance = distanceVector;
		DS3DVector Vcollision;
					
		   if(distLength < minMemberDist)
		    {
							
				 Vcollision = DS3DVectorMultiply(DS3DVectorNormalize(distance), 0.9f);
				 //Vcollision = DS3DVectorNormalize(distance);

				 Vavoid = DS3DVectorAdd(flockSysElements[i].getNewVelocity(), Vcollision);
						
						
			 return Vavoid;
			}
		   
	
	}


	DS3DVector FlockingSystem::velocityMatching(const int elementIndex, DS3DVector totalVelocity, const int nOfMates)
	{
		DS3DVector Vtotal = totalVelocity;
		int numMates = nOfMates;
		int i = elementIndex;

		if(numMates!=0)
		{
			DS3DVector Vaverage = DS3DVectorMultiply(Vtotal, 1/numMates);
		
			Vmatching = DS3DVectorAdd(flockSysElements[i].getNewVelocity(), Vaverage);
		}
	
	  return Vmatching;
	}


	DS3DVector FlockingSystem::flockCentring(const int elementIndex, DS3DVector totalPosition, const int nOfMates)
	{
		DS3DVector Ptotal = totalPosition;
		int numMates = nOfMates;
		int i = elementIndex;

		if(numMates!=0)
		{
			DS3DVector Paverage = DS3DVectorMultiply(Ptotal, 1/numMates);
	
			DS3DVector Vcentre_dir = DS3DVectorNormalize(DS3DVectorSubtract(Paverage, flockSysElements[i].getNewPosition()));
	   
			Vcentring = DS3DVectorAdd(flockSysElements[i].getNewVelocity(), Vcentre_dir);
		}
	
	
	
	  return Vcentring;
	}


	void FlockingSystem::simulateFlockBehaviour(float dt)
	{
		DS3DVector Vnew, Vmult_by_mom, firstPart, secondPart, Pflock;

		DS3DVector distance;
		float distLength;

		DS3DVector Vmatestotal;
		DS3DVector Pmatestotal;
		int numOfFlockMates;
	

		for(int i=1; i<numOfElements; i++)
		{
			numOfFlockMates = 0;
			Vmatestotal = DS3DVectorMake(0.0f, 0.0f, 0.0f);
			Pmatestotal = DS3DVectorMake(0.0f, 0.0f, 0.0f);

			Vavoid = DS3DVectorMake(0.0f, 0.0f, 0.0f);
			Vmatching = DS3DVectorMake(0.0f, 0.0f, 0.0f);
			Vcentring = DS3DVectorMake(0.0f, 0.0f, 0.0f);
		
			for(int j=0; j<numOfElements; j++)
			{

				if(i!=j)
				{
				
					distance = DS3DVectorMake(flockSysElements[i].getNewPosition().x - flockSysElements[j].getNewPosition().x, flockSysElements[i].getNewPosition().y - flockSysElements[j].getNewPosition().y, flockSysElements[i].getNewPosition().z - flockSysElements[j].getNewPosition().z);

					distLength = sqrt((distance.x *distance.x) + (distance.y *distance.y) + (distance.z *distance.z));


					if(distLength < neighborhoodRange)
					{
						
						collisionAvoidance(i, distLength, distance);

						Vmatestotal = DS3DVectorAdd(Vmatestotal, flockSysElements[j].getNewVelocity());
						Pmatestotal = DS3DVectorAdd(Pmatestotal, flockSysElements[j].getNewPosition());

						numOfFlockMates++;

						
					}

				

				}

			

			}


			velocityMatching(i, Vmatestotal, numOfFlockMates);

			flockCentring(i, Pmatestotal, numOfFlockMates);


			//Finally compute the final weighted velocity of the current flock member based on the above rules
			Vmult_by_mom = DS3DVectorMultiply(flockSysElements[i].getNewVelocity(), momentum);
			firstPart = DS3DVectorMake(Vmult_by_mom.x + (1-momentum), Vmult_by_mom.y + (1-momentum), Vmult_by_mom.z + (1-momentum));
			secondPart = DS3DVectorAdd(DS3DVectorAdd(DS3DVectorAdd(DS3DVectorMultiply(Vavoid, Wavoid), DS3DVectorMultiply(Vmatching, Wmatching)), DS3DVectorMultiply(Vcentring, Wcentre)),  DS3DVectorMultiply(DS3DVectorNormalize(DS3DVectorSubtract(flockSysElements[0].getNewPosition(),flockSysElements[i].getNewPosition())), 1.2f));


			Vnew = DS3DVectorMake(firstPart.x * secondPart.x, firstPart.y * secondPart.y, firstPart.z * secondPart.z);


			//And set the flock member's current velocity as it is produced by the flock rules
	
			
			float AngleArc = acos(CLAMP(DS3DVectorDot(DS3DVectorNormalize(flockSysElements[i].getNewVelocity()), DS3DVectorNormalize(Vnew)), -1.f, 1.f));
			float alpha = (AngleArc > 0.f) ? ((dt * MaxAngleArcLengthChange * (3.14159f / 180.f)) / AngleArc) : 0.f;

			flockSysElements[i].setNewVelocity(DS3DVectorNormalize(DS3DVectorSlerp(DS3DVectorNormalize(flockSysElements[i].getNewVelocity()), DS3DVectorNormalize(Vnew), CLAMP(alpha, 0.f, 1.f))));
			//flockSysElements[i].setNewVelocity(DS3DVectorNormalize(DS3DVectorSlerp(DS3DVectorNormalize(flockSysElements[i].getNewVelocity()), DS3DVectorNormalize(Vnew), 0.2f)));
			Pflock = DS3DVectorAdd(flockSysElements[i].getInitialPosition(), DS3DVectorMultiply(flockSysElements[i].getNewVelocity(), speed));

			flockSysElements[i].setNewPosition(Pflock);

			flockSysElements[i].setInitialPosition(Pflock);





		  flockSysElements[i].sync();
		
		}
	
	
	
	
	}


	void FlockingSystem::sync()
	{
	
		//transform3d->setPos(DS3DVectorMake(flockLeader->getNewPosition().x, flockLeader->getNewPosition().y, flockLeader->getNewPosition().z));
		//transform3d->setPos(DS3DVectorMake(flockElements[5].getNewPosition().x, flockElements[5].getNewPosition().y, flockElements[5].getNewPosition().z));
		//transform3d->setRot(actorRot);

		transform3d->setPos(DS3DVectorMake(0.0f, 0.0f, 0.0f));
	
	
	}



	void FlockingSystem::step()
	{
	    

			float dt = 0.05f;
		     DS3DVector newPos, oldPos;

			 delta += dt;			 
			 delta = fmod(delta, 4.0f);
				 
		     
			 newPos = splinePath->PointOnCurve(delta);
			 
			 oldPos = newPos;

		     flockSysElements[0].setNewPosition(newPos);

			 flockSysElements[0].setNewVelocity(splinePath->TangentOnCurve(delta));

             flockSysElements[0].setInitialPosition(oldPos);

		
	         flockSysElements[0].sync();



			 SummedWeight = Wavoid + Wmatching + Wcentre;
		     Wavoid /= SummedWeight;
		     Wmatching /= SummedWeight;
		     Wcentre /= SummedWeight;


			 simulateFlockBehaviour(dt);

	
	}



	void FlockingSystem::update()
	{


		


		//Increment flock centring weight
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_R))
		{
		
			Wcentre += 0.01f;

			if(Wcentre >= 0.7f)Wcentre = 0.7f;
		
		
		}


		//Decrement flock centring weight
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_G))
		{

			Wcentre -= 0.01f;

			if(Wcentre < 0.05f)Wcentre = 0.05f;
			
		
		}



		//Increment velocity matching weight
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_E))
		{
		
				Wmatching += 0.01f;
			
			if(Wmatching >= 0.8f)Wmatching = 0.8f;
			
		
		}


		//Decrement velocity matching weight
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_F))
		{
		
			
				Wmatching -= 0.01f;
			
			if(Wmatching < 0.05f)Wmatching = 0.05f;
			
		
		}

	
		
		//Increment collision avoidance weight
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_W))
		{
		
			
			Wavoid += 0.01f;

			if(Wavoid >= 0.9f)Wavoid = 0.9f;
			
			
		}

		

		//Decrement collision avoidance weight
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_D))
		{
			Wavoid -= 0.01f;

			if(Wavoid < 0.3f)Wavoid = 0.3f;
			
		  
		}

		

		//Increment minimum desired distance between boids
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_S))
		{
		
			
				minMemberDist += 0.02f;
			
			if(minMemberDist >= 6.f)minMemberDist = 6.f;
			
		
		}



		//Decrement minimum desired distance between boids
		if(YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_X))
		{

			
				minMemberDist -= 0.02f;
			
			if(minMemberDist <= 1.f)minMemberDist = 1.f;
			
		
		}



		//Increment neighborhood range
		if (YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_A))
		{
			
				neighborhoodRange += 0.05f;
			
			if(neighborhoodRange >= 40.f)neighborhoodRange = 40.f;
		
		}


		//Decrement neighborhood range
		if (YGEInput::InputDevice::keyboardEvent.IsKeyDown(YGEInput::keys_Z))
		{
			
				neighborhoodRange -= 0.05f;
			
			if(neighborhoodRange <= 5.f)neighborhoodRange = 5.f;
		
		}
	
	
	}



	void FlockingSystem::addToPhase(Phase * const phase) 
	{

		DynamicActor::addToPhase(phase);

		for( int i = 0 ; i < numOfElements; i++)
		{
		
			phase->addInterpable(this->flockSysElements[i].transform3d);

		}

		phase->addSimultable(this);

		phase->addUpdateable(this);

		phase->addDeleteable(frameTransform);

	

	}



	void FlockingSystem::removeFromPhase(Phase * const phase) 
	{

		DynamicActor::removeFromPhase(phase);

		for( int i = 0 ; i < numOfElements; i++)
		{
		
			phase->remInterpable(this->flockSysElements[i].transform3d);

		}

		phase->remSimultable(this);

		phase->remUpdateable(this);

		phase->remDeleteable(frameTransform);

	}




	void FlockingSystem::moveTowards(DS3DVector destination) 
	{

	}



	void FlockingSystem::faceTowards(DS3DVector destination) 
	{

	}





}

