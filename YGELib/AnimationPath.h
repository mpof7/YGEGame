//AnimationPath.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _ANIMATION_PATH_H
#define _ANIMATION_PATH_H


#include "DSVector.h"



namespace YGEEngine 
{


	//!  AnimationPath class
    /*!
        Produces Catmull-Rom Curves for animation paths
     */

	class AnimationPath
    {

	public:
		AnimationPath();
		//AnimationPath(const char *fname);
		~AnimationPath();

		DS3DVector PointOnCurve(float dt);          //calculates a point on a Catmull-Rom curve

		DS3DVector TangentOnCurve(float dt);     //calculates the normalized tangent of a point on the curve


		inline unsigned int getNumOfPoints()
		{
		
			return numOfCPoints;
		
		};


		DS3DVector controlPoints[15];         //a pointer to a set of control points

		//DS3DVector* loadCPointsFromFile(const char *filename);

		unsigned int numOfCPoints;

		int index;

	//private:

		//const char *filename;

		
	};


}

#endif 