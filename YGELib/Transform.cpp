//Transform.cpp

#include "Transform.h"



namespace YGEGraphics
{


	// 2D Transform

	Transform2D::Transform2D() 
	{
		
		pos = DS2DVectorMake(0.0f, 0.0f);
		rot = 0.0f;
		scl = DS2DVectorMake(1.0f, 1.0f);

	}



    DS4DMatrix Transform2D::getTransformMatrix() 
    {
		
		transformMatrix = DS4DMatrixIdentity;
		
		DS4DMatrixRotate(&transformMatrix, &DSVector3DZAxis, rot);
		DS4DMatrixTranslate(&transformMatrix, pos.x, pos.y, 0.0f);
		DS4DMatrixScale(&transformMatrix, scl.x, scl.y, 1.0f);
		
		return transformMatrix;
	}



	// Interpolated 2D Transform

	InterpolatedTransform2D::InterpolatedTransform2D() 
	{
		
		oldPos = newPos = pos;
		oldRot = newRot = rot;
		oldScl = newScl = scl;

	}



	void InterpolatedTransform2D::interpolate(const float alpha) 
	{
		
		// Interpolate position
		pos = DS2DVectorInterpolate(oldPos, newPos, alpha);
		
		// Interpolate rotation
		rot = DSFloatInterpolate(oldRot, newRot, alpha);
		
		// Interpolate scaling
		scl = DS2DVectorInterpolate(oldScl, newScl, alpha);

	}



	// 3D Transform

	Transform3D::Transform3D() 
	{

		pos = DS3DVectorMake(0.0f, 0.0f, 0.0f);
		rot = DSQuatIdentity;
		scl = DS3DVectorMake(1.0f, 1.0f, 1.0f);

	}



	DS4DMatrix Transform3D::getTransformMatrix() 
	{
		
		transformMatrix = DS4DMatrixIdentity;
		
		transformMatrix = DS4DMatrixFromDSQuat(&rot);
		DS4DMatrixTranslate(&transformMatrix, pos.x, pos.y, pos.z);
		DS4DMatrixScale(&transformMatrix, scl.x, scl.y, scl.z);
		
		return transformMatrix;
	}



    // Interpolated 3D Transform

	InterpolatedTransform3D::InterpolatedTransform3D() 
	{
		
		oldPos = newPos = pos;
		oldRot = newRot = rot;
		oldScl = newScl = scl;

	}



	void InterpolatedTransform3D::interpolate(const float alpha) 
	{
		
		// Interpolate position
		pos = DS3DVectorInterpolate(oldPos, newPos, alpha);
		
		// Interpolate rotation
		rot = DSQuatSlerp(&oldRot, &newRot, alpha);
		
		// Interpolate scaling
		scl = DS3DVectorInterpolate(oldScl, newScl, alpha);

	}



}