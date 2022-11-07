//
//  DSVector.m
//  DogstarXEngine
//
//  Created by Richard Henry on 01/04/2009.
//  Copyright 2009 Dogstar Diversions. http://www.dogstar.mobi
//

#include "DSVector.h"


// Zero vectors
DS2DVector DSVector2DZero = { 0.0f, 0.0f };
DS3DVector DSVector3DZero = { 0.0f, 0.0f, 0.0f };

// 2D axes
DS2DVector DSVector2DXAxis = { 1.0f, 0.0f };
DS2DVector DSVector2DYAxis = { 0.0f, 1.0f };

// 3D axes
DS3DVector DSVector3DXAxis = { 1.0f, 0.0f, 0.0f };
DS3DVector DSVector3DYAxis = { 0.0f, 1.0f, 0.0f };
DS3DVector DSVector3DZAxis = { 0.0f, 0.0f, 1.0f };


DSFloat DSFastInverseRoot(float x) {
	
	float	xhalf = 0.5f * x;
	
	int i = *(int *)&x;						// store floating-point bits in integer
	i = 0x5f3759d5 - (i >> 1);				// initial guess for Newton's method
	x = *(float *)&i;						// convert new bits into float
	x = x * (1.5f - xhalf * x * x);			// One round of Newton's method
	
	return (DSFloat)x;
}

//#pragma mark 2D functions

DSFloat DS2DVectorLength(const DS2DVector v) {
	
	return sqrtf(DS2DVectorLengthSquared(v));
}

DSFloat DS2DVectorDistance(const DS2DVector v1, const DS2DVector v2) {
	
	return DS2DVectorLength(DS2DVectorSubtract(v1, v2));
}

DS2DVector DS2DVectorNormalize(const DS2DVector v) {
	
	return DS2DVectorMultiply(v, 1.0f / DS2DVectorLength(v));
}

DS2DVector DS2DVectorForAngle(const DSFloat a) {
	
	return DS2DVectorMake(cosf(a), sinf(a));
}

DSFloat DS2DVectorToAngle(const DS2DVector v) {
	
	return atan2f(v.y, v.x);
}

//#pragma mark 3D functions

DS3DVector DS3DVectorNormalize(const DS3DVector v) {
	
	return DS3DVectorMultiply(v, 1.0f / DS3DVectorLength(v));
}

