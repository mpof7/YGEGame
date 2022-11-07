//
//  DSMatrix.h
//  DogstarXEngine
//
//  Created by Richard Henry on 01/04/2009.
//  Copyright 2009 Dogstar Diversions. http://www.dogstar.mobi
//

#ifndef _YGE_MATRIX_H
#define _YGE_MATRIX_H

#include "DSVector.h"


// A 4D transformation matrix

typedef union {
	
#ifdef __DS_ROW_MAJOR__
	
	struct {			// Row major (Direct3D). m31 is row 3 and column 1
		
		DSFloat	m11, m12, m13, m14;
		DSFloat	m21, m22, m23, m24;
		DSFloat	m31, m32, m33, m34;
		DSFloat	m41, m42, m43, m44;
	} m;
	
#else
	
	struct {			// Column major (OpenGL). m31 is row 1 and column 3
		
		DSFloat	m11, m21, m31, m41;
		DSFloat	m12, m22, m32, m42;
		DSFloat	m13, m23, m33, m43;
		DSFloat	m14, m24, m34, m44;
	} m;
	
#endif
	
	DSFloat raw[16];	// Raw values for access by the graphics system
	
} DS4DMatrix;

//  A 4D identity matrix.

extern DS4DMatrix DS4DMatrixIdentity;

//#pragma mark Accessors and general matrix maths

//
//  function DS4DMatrixGetTranslate
//
//  Extract the translation from a 4D matrix.
//

static inline DS3DVector DS4DMatrixGetTranslate(DS4DMatrix * const matrix) {
	
	return DS3DVectorMake(matrix->m.m14, matrix->m.m24, matrix->m.m34);
}

//
//  function DS4DMatrixGetTranslate
//
//  Extract the translation from a 4D matrix.
//

static inline DS4DMatrix DS4DMatrixMultiply(DS4DMatrix * const m1, DS4DMatrix * const m2) {
	
	DS4DMatrix m;
	
	m.m.m11 = m1->m.m11 * m2->m.m11 + m1->m.m12 * m2->m.m21 + m1->m.m13 * m2->m.m31 + m1->m.m14 * m2->m.m41;
	m.m.m12 = m1->m.m11 * m2->m.m12 + m1->m.m12 * m2->m.m22 + m1->m.m13 * m2->m.m32 + m1->m.m14 * m2->m.m42;
	m.m.m13 = m1->m.m11 * m2->m.m13 + m1->m.m12 * m2->m.m23 + m1->m.m13 * m2->m.m33 + m1->m.m14 * m2->m.m43;
	m.m.m14 = m1->m.m11 * m2->m.m14 + m1->m.m12 * m2->m.m24 + m1->m.m13 * m2->m.m34 + m1->m.m14 * m2->m.m44;
	m.m.m21 = m1->m.m21 * m2->m.m11 + m1->m.m22 * m2->m.m21 + m1->m.m23 * m2->m.m31 + m1->m.m24 * m2->m.m41;
	m.m.m22 = m1->m.m21 * m2->m.m12 + m1->m.m22 * m2->m.m22 + m1->m.m23 * m2->m.m32 + m1->m.m24 * m2->m.m42;
	m.m.m23 = m1->m.m21 * m2->m.m13 + m1->m.m22 * m2->m.m23 + m1->m.m23 * m2->m.m33 + m1->m.m24 * m2->m.m43;
	m.m.m24 = m1->m.m21 * m2->m.m14 + m1->m.m22 * m2->m.m24 + m1->m.m23 * m2->m.m34 + m1->m.m24 * m2->m.m44;
	m.m.m31 = m1->m.m31 * m2->m.m11 + m1->m.m32 * m2->m.m21 + m1->m.m33 * m2->m.m31 + m1->m.m34 * m2->m.m41;
	m.m.m32 = m1->m.m31 * m2->m.m12 + m1->m.m32 * m2->m.m22 + m1->m.m33 * m2->m.m32 + m1->m.m34 * m2->m.m42;
	m.m.m33 = m1->m.m31 * m2->m.m13 + m1->m.m32 * m2->m.m23 + m1->m.m33 * m2->m.m33 + m1->m.m34 * m2->m.m43;
	m.m.m34 = m1->m.m31 * m2->m.m14 + m1->m.m32 * m2->m.m24 + m1->m.m33 * m2->m.m34 + m1->m.m34 * m2->m.m44;
	m.m.m41 = m1->m.m41 * m2->m.m11 + m1->m.m42 * m2->m.m21 + m1->m.m43 * m2->m.m31 + m1->m.m44 * m2->m.m41;
	m.m.m42 = m1->m.m41 * m2->m.m12 + m1->m.m42 * m2->m.m22 + m1->m.m43 * m2->m.m32 + m1->m.m44 * m2->m.m42;
	m.m.m43 = m1->m.m41 * m2->m.m13 + m1->m.m42 * m2->m.m23 + m1->m.m43 * m2->m.m33 + m1->m.m44 * m2->m.m43;
	m.m.m44 = m1->m.m41 * m2->m.m14 + m1->m.m42 * m2->m.m24 + m1->m.m43 * m2->m.m34 + m1->m.m44 * m2->m.m44;
	
	return m;
}

//#pragma mark Transformations

//
//  function DS4DMatrixTranslate
//
//  Set the translation component of a 4D matrix.
//

static inline void DS4DMatrixTranslate(DS4DMatrix * const matrix, const DSFloat x, const DSFloat y, const DSFloat z) {
	
	matrix->m.m14 = x;
	matrix->m.m24 = y;
	matrix->m.m34 = z;
}

//
//  function DS4DMatrixRotate
//
//  Set the orientation component of a 4D matrix.
//

static inline void DS4DMatrixRotate(DS4DMatrix * const matrix, const DS3DVector * const axis, const DSFloat theta) {
	
	float				sin = -sinf(theta);
	float				cos = cosf(theta);
	const DS3DVector	rotateAxis = DS3DVectorMultiply(*axis, 1.0f - cos);
	
	matrix->m.m11 = rotateAxis.x * axis->x + cos;
	matrix->m.m12 = rotateAxis.x * axis->y + axis->z * sin;
	matrix->m.m13 = rotateAxis.x * axis->z - axis->y * sin;
	
	matrix->m.m21 = rotateAxis.y * axis->x - axis->z * sin;
	matrix->m.m22 = rotateAxis.y * axis->y + cos;
	matrix->m.m23 = rotateAxis.y * axis->z + axis->x * sin;
	
	matrix->m.m31 = rotateAxis.z * axis->x + axis->y * sin;
	matrix->m.m32 = rotateAxis.z * axis->y - axis->x * sin;
	matrix->m.m33 = rotateAxis.z * axis->z + cos;
}

//
//  function DS4DMatrixScale
//
//  Set the scaling component of a 4D matrix.
//

static inline void DS4DMatrixScale(DS4DMatrix * const matrix, const DSFloat x, const DSFloat y, const DSFloat z) {
	
	matrix->m.m11 *= x;
	matrix->m.m22 *= y;
	matrix->m.m33 *= z;
}

//#pragma mark Projections

//
//  function DS4DMatrixOrtho
//
//  Make a 4D orthographic projection matrix.
//

static inline void DS4DMatrixOrtho(DS4DMatrix * const matrix, const DSFloat left, const DSFloat right, const DSFloat bottom, const DSFloat top, const DSFloat nearest, const DSFloat farest) {
	
	*matrix = DS4DMatrixIdentity;
	
	matrix->m.m11 = 2.0F / (right - left);
	matrix->m.m14 = -(right + left) / (right - left);
	
	matrix->m.m22 = 2.0F / (top - bottom);
	matrix->m.m24 = -(top + bottom) / (top - bottom);
	
	matrix->m.m33 = -2.0F / (farest - nearest);
	matrix->m.m34 = -(farest + nearest) / (farest - nearest);
}

//
//  function DS4DMatrixPerspective
//
//  Make a 4D perspective projection matrix.
//

static inline void DS4DMatrixPerspective(DS4DMatrix * const matrix, const DSFloat fovy, const DSFloat aspect, const DSFloat zNear, const DSFloat zFar) {
	
	DSFloat			deltaZ = zFar - zNear;
	DSFloat			radians = fovy / 2 * M_PI / 180;
	DSFloat			sine = sinf(radians);
	
	if ((deltaZ == 0.0f) || (sine == 0.0f) || (aspect == 0.0f)) return;

	DSFloat cotangent = cosf(radians) / sine;
	
	*matrix = DS4DMatrixIdentity;
	
	matrix->m.m11 = cotangent / aspect;

	matrix->m.m22 = cotangent;
	
	matrix->m.m33 = -(zFar + zNear) / deltaZ;
	matrix->m.m34 = -2 * zNear * zFar / deltaZ;
	
	matrix->m.m43 = -1;
	matrix->m.m44 = 0.0f;
}

#endif