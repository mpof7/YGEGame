//
//  DSQuat.m
//  DogstarXEngine
//
//  Created by Richard Henry on 01/04/2009.
//  Copyright 2009 Dogstar Diversions. http://www.dogstar.mobi
//

#include "DSQuat.h"

DSQuat DSQuatIdentity = { 0.0f, 0.0f, 0.0f, 1.0f };
static const DSFloat kDSSlerpToLerpThreshold = 0.01f;


void AxisAngleFromDSQuat(const DSQuat * const q, DS3DVector *axis, float *angle) {
	
	float			sinAngle = sqrt(1.0f - (q->w * q->w));
	
	if (fabs(sinAngle) < 0.0005f) sinAngle = 1.0f;
	
	axis->x = (q->x / sinAngle);
	axis->y = (q->y / sinAngle);
	axis->z = (q->z / sinAngle);
	
	*angle = (acos(q->w) * 2.0f);
}

DS4DMatrix DS4DMatrixFromDSQuat(const DSQuat * const q) {
	
	DS4DMatrix		newMatrix = DS4DMatrixIdentity;
	
	newMatrix.m.m11 = 1.0f - (2.0f * ((q->y * q->y) + (q->z * q->z)));
	newMatrix.m.m12 =        (2.0f * ((q->x * q->y) + (q->z * q->w)));
	newMatrix.m.m13 =        (2.0f * ((q->x * q->z) - (q->y * q->w)));
	newMatrix.m.m21 =        (2.0f * ((q->x * q->y) - (q->z * q->w)));
	newMatrix.m.m22 = 1.0f - (2.0f * ((q->x * q->x) + (q->z * q->z)));
	newMatrix.m.m23 =        (2.0f * ((q->y * q->z) + (q->x * q->w)));
	newMatrix.m.m31 =        (2.0f * ((q->x * q->z) + (q->y * q->w)));
	newMatrix.m.m32 =        (2.0f * ((q->y * q->z) - (q->x * q->w)));
	newMatrix.m.m33 = 1.0f - (2.0f * ((q->x * q->x) + (q->y * q->y)));
	
	return newMatrix;
}

DSQuat DSQuatSlerp(const DSQuat * const q1, const DSQuat * const q2, const float alpha) {
	
	DSQuat			newQuat;
	float			startWeight, endWeight;
	
	float difference = (q1->x * q2->x) + (q1->y * q2->y) + (q1->z * q2->z) + (q1->w * q2->w);
	
	if ((1.0f - fabs(difference)) > kDSSlerpToLerpThreshold) {
		
		float theta = acos(fabs(difference));
		float oneOverSinTheta = 1.0f / sin(theta);
		
		startWeight = sin(theta * (1.0f - alpha)) * oneOverSinTheta;
		endWeight = sin(theta * alpha) * oneOverSinTheta;
		
		if (difference < 0.0f) startWeight = -startWeight;
		
	} else {
		
		startWeight = 1.0f - alpha;
		endWeight = alpha;
	}
	
	newQuat.x = (q1->x * startWeight) + (q2->x * endWeight);
	newQuat.y = (q1->y * startWeight) + (q2->y * endWeight);
	newQuat.z = (q1->z * startWeight) + (q2->z * endWeight);
	newQuat.w = (q1->w * startWeight) + (q2->w * endWeight);
	
	DSQuatUnitise(&newQuat);
	
	return newQuat;
}
