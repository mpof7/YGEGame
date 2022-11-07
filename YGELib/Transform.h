//Transform.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_TRANSFORM_H
#define _YGE_TRANSFORM_H

#include "DSQuat.h"
#include "Object.h"


namespace YGEGraphics 
{


	//!  Transform class
    /*!
        A generic transformation interface class
     */

	class Transform : public YGECore::Object
	{

	public:

		Transform() { transformMatrix = DS4DMatrixIdentity; }
		
		virtual DS4DMatrix getTransformMatrix() { return transformMatrix; }				// Matrix getter
		
	protected:

		DS4DMatrix			transformMatrix;

	};




	//!  Interpable class
    /*!
        Describes an object that can be interpolated
     */

	class Interpable 
	{
		
	public:
		
		virtual void interpolate(const float alpha) = 0;

	};




	//!  Transform2D class
    /*!
        A 2D transformation base class
     */

	class Transform2D : public Transform 
	{
		
	public:

		Transform2D();
		
		DS4DMatrix getTransformMatrix();
		
		inline DS2DVector getPos()                { return pos; }				// Position getter
		inline DSFloat getRot()                   { return rot; }		        // Rotation getter
		inline DS2DVector getScl()                { return scl; }				// Scaling getter
		
		inline void setPos(const DS2DVector p)    { pos = p; }	          // Position setter
		inline void setRot(const DSFloat r)       { rot = r; }		     // Rotation setter
		inline void setScl(const DS2DVector s)    { scl = s; }	        // Scaling setter
		
	protected:

		DS2DVector			pos;
		DSFloat			    rot;
		DS2DVector			scl;

	};




	//!  InterpolatedTransform2D class
    /*!
        A 2D transformation and interpolation base class
     */

	class InterpolatedTransform2D : public Transform2D, public Interpable 
	{
		
	public:

		InterpolatedTransform2D();
		
		inline void setPos(const DS2DVector p)   { oldPos = newPos; newPos = p; }	     // Position setter
		inline void setRot(const DSFloat r)      { oldRot = newRot; newRot = r; }		// Rotation setter
		inline void setScl(const DS2DVector s)   { oldScl = newScl; newScl = s; }	   // Scaling setter
		
		void interpolate(const float alpha);
		
	protected:

		DS2DVector			oldPos, newPos;
		DSFloat			    oldRot, newRot;
		DS2DVector			oldScl, newScl;

	};




	//!  Transform3D class
    /*!
        A 3D transformation base class
     */

	class Transform3D : public Transform 
	{
		
	public:

		Transform3D();
		
		DS4DMatrix getTransformMatrix();
		
		inline DS3DVector getPos()   { return pos; }				// Position getter
		inline DSQuat getRot()       { return rot; }				// Rotation getter
		inline DS3DVector getScl()   { return scl; }				// Scaling getter
		
		inline void setPos(const DS3DVector p)   { pos = p; }	     // Position setter
		inline void setRot(const DSQuat r)       { rot = r; }		// Rotation setter
		inline void setScl(const DS3DVector s)   { scl = s; }	   // Scaling setter
		
	protected:

		DS3DVector			pos;
		DSQuat				rot;
		DS3DVector			scl;

	};




	//!  InterpolatedTransform3D class
    /*!
        A 3D transformation and interpolation base class
     */

	class InterpolatedTransform3D : public Transform3D, public Interpable 
	{
		
	public:

		InterpolatedTransform3D();
		
		inline void setPos(const DS3DVector p)    { oldPos = newPos; newPos = p; }	     // Position setter
		inline void setRot(const DSQuat r)        { oldRot = newRot; newRot = r; }		// Rotation setter
		inline void setScl(const DS3DVector s)    { oldScl = newScl; newScl = s; }	   // Scaling setter
		
		void interpolate(const float alpha);
		
	protected:

		DS3DVector			oldPos, newPos;
		DSQuat				oldRot, newRot;
		DS3DVector			oldScl, newScl;

	};


	}
#endif