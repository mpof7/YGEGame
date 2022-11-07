//
//  DSVector.h
//  DogstarXEngine
//
//  Created by Richard Henry on 01/04/2009.
//  Copyright 2009 Dogstar Diversions. http://www.dogstar.mobi
//

#ifndef _YGE_VECTOR_H
#define _YGE_VECTOR_H


#define _USE_MATH_DEFINES
#include <math.h>


//#pragma mark 1D

typedef float DSFloat;

//
//  function DSFloatInterpolate
//
//  Returns the interpolation between two values.
//

static inline DSFloat DSFloatInterpolate(const DSFloat v1, const DSFloat v2, const DSFloat s) {
	
	return v1 + (v2 - v1) * s;
}

//
//  function DSFastInverseRoot
//
//  Returns the approximated inverse root of the supplied value.
//

DSFloat DSFastInverseRoot(float x);


//#pragma mark 2D

typedef struct {
	
	DSFloat x, y;
	
} DS2DVector;

// Zero vector
extern DS2DVector DSVector2DZero;

// Convenience axes
extern DS2DVector DSVector2DXAxis;
extern DS2DVector DSVector2DYAxis;

//
//  function DS2DVectorMake
//
//  Make a 2D vector with the supplied dimensions.
//

static inline DS2DVector DS2DVectorMake(const DSFloat x, const DSFloat y) {
	
	DS2DVector		newVector;
	
	newVector.x = x;
	newVector.y = y;
	
	return newVector;
}

//
//  function DS2DVectorNegate
//
//  Returns the negative (opposite) of the point supplied.
//

static inline DS2DVector DS2DVectorNegate(const DS2DVector v) {
	
	return DS2DVectorMake(-v.x, -v.y);
}

//
//  function DS2DVectorAdd
//
//  Returns the sum of the points supplied.
//

static inline DS2DVector DS2DVectorAdd(const DS2DVector v1, const DS2DVector v2) {
	
	return DS2DVectorMake(v1.x + v2.x, v1.y + v2.y);
}

//
//  function DS2DVectorSubtract
//
//  Returns the difference between two vectors.
//

static inline DS2DVector DS2DVectorSubtract(const DS2DVector v1, const DS2DVector v2) {
	
	return DS2DVectorMake(v1.x - v2.x, v1.y - v2.y);
}

//
//  function DS2DVectorMultiply
//
//  Returns the supplied vector multiplied by the supplied factor.
//

static inline DS2DVector DS2DVectorMultiply(const DS2DVector v, const DSFloat s) {
	
	return DS2DVectorMake(v.x * s, v.y * s);
}

//
//  function DS2DVectorMidpoint
//
//  Returns the midpoint between two vectors.
//

static inline DS2DVector DS2DVectorMidpoint(const DS2DVector v1, const DS2DVector v2) {
	
	return DS2DVectorMultiply(DS2DVectorAdd(v1, v2), 0.5f);
}

//
//  function DS2DVectorInterpolate
//
//  Returns the interpolation between two vectors.
//

static inline DS2DVector DS2DVectorInterpolate(const DS2DVector v1, const DS2DVector v2, const DSFloat s) {
	
	return DS2DVectorAdd(v1, DS2DVectorMultiply(DS2DVectorSubtract(v2, v1), s));
}

//
//  function DS2DVectorDot
//
//  Returns the dot product of two vectors.
//

static inline DSFloat DS2DVectorDot(const DS2DVector v1, const DS2DVector v2) {
	
	return v1.x * v2.x + v1.y * v2.y;
}

//
//  function DS2DVectorDot
//
//  Returns the cross product of two vectors.
//

static inline DSFloat DS2DVectorCross(const DS2DVector v1, const DS2DVector v2) {
	
	return v1.x * v2.y - v1.y * v2.x;
}

//
//  function DS2DVectorPerp
//
//  Returns the perpendicular of v, rotated 90 degrees counter-clockwise -- cross(v, perp(v)) >= 0.
//

static inline DS2DVector DS2DVectorPerp(const DS2DVector v) {
	
	return DS2DVectorMake(-v.y, v.x);
}

//
//  function DS2DVectorRPerp
//
//  Returns the perpendicular of v, rotated 90 degrees counter-clockwise -- cross(v, perp(v)) <= 0.
//

static inline DS2DVector DS2DVectorRPerp(const DS2DVector v) {
	
	return DS2DVectorMake(v.y, -v.x);
}

//
//  function DS2DVectorProject
//
//  Returns the projection of vector v1 onto v2.
//

static inline DS2DVector DS2DVectorProject(const DS2DVector v1, const DS2DVector v2) {
	
	return DS2DVectorMultiply(v2, DS2DVectorDot(v1, v2) / DS2DVectorDot(v2, v2));
}

//
//  function DS2DVectorRotate
//
//  Returns the rotation of vector v1 onto v2.
//

static inline DS2DVector DS2DVectorRotate(const DS2DVector v1, const DS2DVector v2) {
	
	return DS2DVectorMake(v1.x * v2.x - v1.y * v2.y, v1.x * v2.y + v1.y * v2.x);
}

//
//  function DS2DVectorUnrotate
//
//  Returns the unrotation of vector v1 onto v2.
//

static inline DS2DVector DS2DVectorUnrotate(const DS2DVector v1, const DS2DVector v2) {
	
	return DS2DVectorMake(v1.x * v2.x + v1.y * v2.y, v1.y * v2.x - v1.x * v2.y);
}

//
//  function DS2DVectorLengthSquared
//
//  Returns the squared length of the vector supplied.
//

static inline DSFloat DS2DVectorLengthSquared(const DS2DVector v) {
	
	return DS2DVectorDot(v, v);
}

//
//  function DS2DVectorLength
//
//  Returns the length of the vector supplied.
//

DSFloat DS2DVectorLength(const DS2DVector v);

//
//  function DS2DVectorDistance
//
//  Returns the distance between the two point vectors supplied.
//

DSFloat DS2DVectorDistance(const DS2DVector v1, const DS2DVector v2);

//
//  function DS2DVectorNormalize
//
//  Returns the normalised vector supplied.
//

DS2DVector DS2DVectorNormalize(const DS2DVector v);

//
//  function DS2DVectorForAngle
//
//  Converts radian angle to a normalised vector.
//

DS2DVector DS2DVectorForAngle(const DSFloat a);

//
//  function DS2DVectorToAngle
//
//  Converts normalised vector to a radian angle.
//

DSFloat DS2DVectorToAngle(const DS2DVector v);


//#pragma mark 3D

typedef struct {
	
	DSFloat x, y, z;
	
} DS3DVector;

// Zero vector
extern DS3DVector DSVector3DZero;

// Convenience axes
extern DS3DVector DSVector3DXAxis;
extern DS3DVector DSVector3DYAxis;
extern DS3DVector DSVector3DZAxis;

//
//  function DS3DVectorMake
//
//  Make a 2D vector with the supplied dimensions.
//

static inline DS3DVector DS3DVectorMake(const DSFloat x, const DSFloat y, const DSFloat z) {
	
	DS3DVector		newVector;
	
	newVector.x = x;
	newVector.y = y;
	newVector.z = z;
	
	return newVector;
}

//
//  function DS2DVectorNormalize
//
//  Returns the normalised vector supplied.
//

DS3DVector DS3DVectorNormalize(const DS3DVector v);

//
//  function DS3DVectorNegate
//
//  Returns the negative (opposite) of the point supplied.
//

static inline DS3DVector DS3DVectorNegate(const DS3DVector v) {
	
	return DS3DVectorMake(-v.x, -v.y, -v.z);
}

//
//  function DS3DVectorAdd
//
//  Returns the sum of the points supplied.
//

static inline DS3DVector DS3DVectorAdd(const DS3DVector v1, const DS3DVector v2) {
	
	return DS3DVectorMake(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

//
//  function DS3DVectorSubtract
//
//  Returns the difference between two vectors.
//

static inline DS3DVector DS3DVectorSubtract(const DS3DVector v1, const DS3DVector v2) {
	
	return DS3DVectorMake(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

//
//  function DS3DVectorSubtract
//
//  Returns the supplied vector multiplied by the supplied factor.
//

static inline DS3DVector DS3DVectorMultiply(const DS3DVector v, const DSFloat s) {
	
	return DS3DVectorMake(v.x * s, v.y * s, v.z * s);
}

//
//  function DS3DVectorMidpoint
//
//  Returns the midpoint between two vectors.
//

static inline DS3DVector DS3DVectorMidpoint(const DS3DVector v1, const DS3DVector v2) {
	
	return DS3DVectorMultiply(DS3DVectorAdd(v1, v2), 0.5f);
}

//
//  function DS3DVectorInterpolate
//
//  Returns the interpolation between two vectors.
//

static inline DS3DVector DS3DVectorInterpolate(const DS3DVector v1, const DS3DVector v2, const DSFloat s) {
	
	return DS3DVectorAdd(v1, DS3DVectorMultiply(DS3DVectorSubtract(v2, v1), s));
}




//
//  function DS3DVectorDot
//
//  Returns the dot product of two vectors.
//

static inline DSFloat DS3DVectorDot(const DS3DVector v1, const DS3DVector v2) {
	
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}



//
//  function DS3DVectorSlerp
//
//  Returns the spherical linear interpolation between two vectors.
//

static inline DS3DVector DS3DVectorSlerp(const DS3DVector v1, const DS3DVector v2, const DSFloat s) {
	
	float Angle = acos(DS3DVectorDot(v1, v2));
	float SinAngle = sin(Angle);

	if(SinAngle>0.0f)
	{
		//return sin(Angle * (1.0f-s)) * v1/SinAngle + sin(Angle*s) * v2/SinAngle;
		return DS3DVectorAdd(DS3DVectorMultiply(DS3DVectorMultiply(v1, 1/SinAngle), sin(Angle * (1.0f-s))), DS3DVectorMultiply(DS3DVectorMultiply(v2, 1/SinAngle), sin(Angle*s)));
	}

}



//
//  function DS3DVectorDot
//
//  Returns the cross product of two vectors.
//

static inline DS3DVector DS3DVectorCross(const DS3DVector v1, const DS3DVector v2) {
	
	return DS3DVectorMake(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

//
//  function DS3DVectorPerp
//
//  Returns the perpendicular of v, rotated 90 degrees counter-clockwise -- cross(v, perp(v)) >= 0.
//

static inline DS3DVector DS3DVectorPerp(const DS3DVector v) {
	
	return DS3DVectorMake(-v.y, v.x, v.x);
}

//
//  function DS3DVectorRPerp
//
//  Returns the perpendicular of v, rotated 90 degrees counter-clockwise -- cross(v, perp(v)) <= 0.
//

static inline DS3DVector DS3DVectorRPerp(const DS3DVector v) {
	
	return DS3DVectorMake(v.y, -v.x, v.x);
}

//
//  function DS3DVectorProject
//
//  Returns the projection of vector v1 onto v2.
//

static inline DS3DVector DS3DVectorProject(const DS3DVector v1, const DS3DVector v2) {
	
	return DS3DVectorMultiply(v2, DS3DVectorDot(v1, v2) / DS3DVectorDot(v2, v2));
}

//
//  function DS3DVectorRotate
//
//  Returns the rotation of vector v1 onto v2.
//

static inline DS3DVector DS3DVectorRotate(const DS3DVector v1, const DS3DVector v2) {
	
	return DS3DVectorMake(v1.x * v2.x - v1.y * v2.y, v1.x * v2.y + v1.y * v2.x, v1.x);
}

//
//  function DS3DVectorUnrotate
//
//  Returns the unrotation of vector v1 onto v2.
//

static inline DS3DVector DS3DVectorUnrotate(const DS3DVector v1, const DS3DVector v2) {
	
	return DS3DVectorMake(v1.x * v2.x + v1.y * v2.y, v1.y * v2.x - v1.x * v2.y, v1.x);
}

//
//  function DS3DVectorLength
//
//  Returns the length of the vector supplied.
//

static inline DSFloat DS3DVectorLength(const DS3DVector v) {
	
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

//
//  function DS3DVectorLengthSquared
//
//  Returns the squared length of the vector supplied.
//

static inline DSFloat DS3DVectorLengthSquared(const DS3DVector v) {
	
	return DS3DVectorDot(v, v);
}


//#pragma mark 4D

typedef struct {
	
	DSFloat x, y, z, w;
	
} DS4DVector;


//
//  function DS4DVectorMake
//
//  Make a 2D vector with the supplied dimensions.
//

static inline DS4DVector DS4DVectorMake(const DSFloat x, const DSFloat y, const DSFloat z, const DSFloat w) {
	
	DS4DVector		newVector;
	
	newVector.x = x;
	newVector.y = y;
	newVector.z = z;
	newVector.w = w;
	
	return newVector;
}

#endif
