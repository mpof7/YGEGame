//AnimationPath.cpp

#include "AnimationPath.h"
#include "Debug.h"


using namespace std;

#define STOP __asm{int 3};


namespace YGEEngine
{

	//AnimationPath::AnimationPath(const char *fname)
	AnimationPath::AnimationPath()
	{
		
		

		//filename = NULL;

		//Initialize the set of control points
              controlPoints[0] = DS3DVectorMake(9.f, 0.f, 0.f);
              controlPoints[1] = DS3DVectorMake(0.f, -7.f, 0.f);
              controlPoints[2] = DS3DVectorMake(-9.f, 0.f, 0.f);
              controlPoints[3] = DS3DVectorMake(0.f, 7.f, 0.f);
 
              controlPoints[4] = DS3DVectorMake(0.f, -7.f, 0.f);
              controlPoints[5] = DS3DVectorMake(-9.f, 0.f, 0.f);
              controlPoints[6] = DS3DVectorMake(0.f, 7.f, 0.f);
              controlPoints[7] = DS3DVectorMake(9.f, 0.f, 0.f);
 
              controlPoints[8] = DS3DVectorMake(-9.f, 0.f, 0.f);
              controlPoints[9] = DS3DVectorMake(0.f, 7.f, 0.f);
              controlPoints[10] = DS3DVectorMake(9.f, 0.f, 0.f);
              controlPoints[11] = DS3DVectorMake(0.f, -7.f, 0.f);
 
              controlPoints[12] = DS3DVectorMake(0.f, 7.f, 0.f);
              controlPoints[13] = DS3DVectorMake(9.f, 0.f, -0.f);
              controlPoints[14] = DS3DVectorMake(0.f, -7.f, 0.f);
              controlPoints[15] = DS3DVectorMake(-9.f, 0.f, 0.f);
	
		//filename = fname;

		//controlPoints = loadCPointsFromFile(fname);

		numOfCPoints = 16;
	
	
	}


	AnimationPath::~AnimationPath()
	{
	
	}


	/*
	DS3DVector* AnimationPath::loadCPointsFromFile(const char *fileName)
	{
	
		 DS3DVector *tempControlPoints = NULL;

		 int count = 0;


		 ifstream inFile;

		 inFile.open(fileName, std::ios::in);
		
		
		 if(!inFile.is_open()) { STOP }

		
                
   
		
		 while (inFile.good()) 
		 {
			 inFile >> count;
		 }

				   //tempControlPoints = new DS3DVector[count];//(DS3DVector *) malloc(sizeof(DS3DVector));
				  
				  // for(unsigned int i=0;i<count;i++)
				   //{
					//myFile>>tempControlPoints[i].x>>tempControlPoints[i].y>>tempControlPoints[i].z;
				  // }

				   inFile.close();

		  return tempControlPoints;
	
	}

	*/


	DS3DVector AnimationPath::PointOnCurve(float dt)
	{
	
		DS3DVector posOnCurve; 


			 // calculate the new normalized local time on the subcurve 
			 float lt = fmod(dt,1.0f);
             index = 4*(int(dt));
		

			 // get the 4 intended control points
             DS3DVector P0 = DS3DVectorMake(controlPoints[index].x, controlPoints[index].y, controlPoints[index].z);
			 DS3DVector P1 = DS3DVectorMake(controlPoints[index + 1].x, controlPoints[index + 1].y, controlPoints[index + 1].z);
			 DS3DVector P2 = DS3DVectorMake(controlPoints[index + 2].x, controlPoints[index + 2].y, controlPoints[index + 2].z);
			 DS3DVector P3 = DS3DVectorMake(controlPoints[index + 3].x, controlPoints[index + 3].y, controlPoints[index + 3].z);



			 // processing the position of the point at t
             float x, y, z;
             float t2 = lt * lt;
             float t3 = t2 * lt;

			 // position x
			 x = 0.5f * ( ( 2.0f * P1.x ) + ( -P0.x + P2.x ) * lt + ( 2.0f * P0.x - 5.0f * P1.x + 4 * P2.x - P3.x ) * t2 + ( -P0.x + 3.0f * P1.x - 3.0f * P2.x + P3.x ) * t3 );

			 // position y
			 y = 0.5f * ( ( 2.0f * P1.y ) + ( -P0.y + P2.y ) * lt + ( 2.0f * P0.y - 5.0f * P1.y + 4 * P2.y - P3.y ) * t2 + ( -P0.y + 3.0f * P1.y - 3.0f * P2.y + P3.y ) * t3 );

			 // position z
			 z = 0.5f * ( ( 2.0f * P1.z ) + ( -P0.z + P2.z ) * lt + ( 2.0f * P0.z - 5.0f * P1.z + 4 * P2.z - P3.z ) * t2 + ( -P0.z + 3.0f * P1.z - 3.0f * P2.z + P3.z ) * t3 );



			 posOnCurve = DS3DVectorMake(x, y, z);
		
		
	
	  return posOnCurve;
	}




	DS3DVector AnimationPath::TangentOnCurve(float dt)
	{
	
		DS3DVector tangentOnCurve; 


			 // calculate the new normalized local time on the subcurve 
			 float lt = fmod(dt,1.0f);
             index = 4*(int(dt));
		

			 // get the 4 intended control points
             DS3DVector P0 = DS3DVectorMake(controlPoints[index].x, controlPoints[index].y, controlPoints[index].z);
			 DS3DVector P1 = DS3DVectorMake(controlPoints[index + 1].x, controlPoints[index + 1].y, controlPoints[index + 1].z);
			 DS3DVector P2 = DS3DVectorMake(controlPoints[index + 2].x, controlPoints[index + 2].y, controlPoints[index + 2].z);
			 DS3DVector P3 = DS3DVectorMake(controlPoints[index + 3].x, controlPoints[index + 3].y, controlPoints[index + 3].z);



			 // processing the position of the point at t
             float x, y, z;
             float t2 = lt * lt;
             float t3 = t2 * lt;

			 // position x
			 x = (1.5f * (-P0.x + (3.0f * P1.x) - (3.0f * P2.x) + P3.x) * t2) + (((2.0f * P0.x) - (5.0f * P1.x) + (4.0f * P2.x) - P3.x) * lt) + (0.5f * (-P0.x + P2.x));

			 // position y
			 y = (1.5f * (-P0.y + (3.0f * P1.y) - (3.0f * P2.y) + P3.y) * t2) + (((2.0f * P0.y) - (5.0f * P1.y) + (4.0f * P2.y) - P3.y) * lt) + (0.5f * (-P0.y + P2.y));

			 // position z
			 z = (1.5f * (-P0.z + (3.0f * P1.z) - (3.0f * P2.z) + P3.z) * t2) + (((2.0f * P0.z) - (5.0f * P1.z) + (4.0f * P2.z) - P3.z) * lt) + (0.5f * (-P0.z + P2.z));



			 tangentOnCurve = DS3DVectorNormalize(DS3DVectorMake(x, y, z));
		
		
	
	  return tangentOnCurve;
	}



}