//
//  DSQuat.h
//  DogstarXEngine
//
//  Created by Richard Henry on 01/04/2009.
//  Copyright 2009 Dogstar Diversions. http://www.dogstar.mobi
//

#ifndef _YGE_QUAT_H
#define _YGE_QUAT_H

#include "DSMatrix.h"

typedef DS4DVector DSQuat;
typedef DS4DVector DSBiQuat;

extern DSQuat DSQuatIdentity;


//
//  function DSQuatMultiply
//
//  Multiply 2 quaternions.
//

static inline DSQuat DSQuatMultiply(const DSQuat * const q1, const DSQuat * const q2) {
	
	DSQuat			newQuat;
	
	newQuat.w = (q1->w * q2->w) - (q1->x * q2->x) - (q1->y * q2->y) - (q1->z * q2->z);
	newQuat.x = (q1->w * q2->x) + (q1->x * q2->w) + (q1->y * q2->z) - (q1->z * q2->y);
	newQuat.y = (q1->w * q2->y) - (q1->x * q2->z) + (q1->y * q2->w) + (q1->z * q2->x);
	newQuat.z = (q1->w * q2->z) + (q1->x * q2->y) - (q1->y * q2->x) + (q1->z * q2->w);
	
	return newQuat;
}

//
//  function DSQuatUnitise
//
//  Unititise (normalise) the given quaternion.
//

static inline void DSQuatUnitise(DSQuat * const q) {
	
	float magnitude = 1.0f / sqrtf(q->w * q->w + q->x * q->x + q->y * q->y + q->z * q->z);
	
	q->w *= magnitude;
	q->x *= magnitude;
	q->y *= magnitude;
	q->z *= magnitude;
}

//
//  function DSQuatConjugate
//
//  Conjugate the given quaternion.
//

static inline void DSQuatConjugate(DSQuat * const q) {
	
	q->x *= -1.0f;
	q->y *= -1.0f;
	q->z *= -1.0f;
}

//
//  function DSQuatFromDS3DVector
//
//  Conjugate the given quaternion.
//

static inline DSQuat DSQuatFromDS3DVector(const DS3DVector * const v) {
	
	return DS4DVectorMake(v->x, v->y, v->z, 0.0f);
}

//
//  function DS3DVectorFromDSQuat
//
//  Conjugate the given quaternion.
//

static inline DS3DVector DS3DVectorFromDSQuat(const DSQuat * const q) {
	
	return DS3DVectorMake(q->x, q->y, q->z);
}

//
//  function DSQuatFromAxisAngle
//
//  Conjugate the given quaternion.
//

static inline DSQuat DSQuatFromAxisAngle(const DS3DVector * const axis, const float a) {
	
	float			angle = a * 0.5f;
	float			sinAngle = -sin(angle);
	
	return DS4DVectorMake(axis->x * sinAngle, axis->y * sinAngle, axis->z * sinAngle, cos(angle));
}

//
//  function AxisAngleFromDSQuat
//
//  Conjugate the given quaternion.
//

void AxisAngleFromDSQuat(const DSQuat * const q, DS3DVector *axis, float *angle);

//
//  function DS3DMatrixFromDSQuat
//
//  Conjugate the given quaternion.
//

DS4DMatrix DS4DMatrixFromDSQuat(const DSQuat * const q);

//
//  function DSQuatSlerp
//
//  Conjugate the given quaternion.
//

DSQuat DSQuatSlerp(const DSQuat * const q1, const DSQuat * const q2, const float alpha);

//
//  function DSQuatRotate
//
//  Conjugate the given quaternion.
//

static inline DSQuat DSQuatRotate(DSQuat * const q, const DS3DVector * const axis, const float angle) {
	
	DSQuat r = DSQuatFromAxisAngle(axis, angle);
	
	return DSQuatMultiply(q, &r);
}

#endif