//InterpolationPhase.cpp


#include "InterpolationPhase.h"
#include "Time.h"
#include "DrawNode.h"
#include "Cube.h"
#include "Debug.h"









InterpolationPhase::InterpolationPhase() 
{
	
	
}


InterpolationPhase::~InterpolationPhase() 
{
	
}


bool InterpolationPhase::load() 
{
	#ifdef _DEBUG
	// Standard debug draw node
	YGEGraphics::DrawNode *framerate = new YGEGraphics::DebugDrawNode();
	deleteSet.insert(framerate);
    #endif

	//Actual phase loading
	YGEGraphics::DrawNode					*dn = new YGEGraphics::DrawNode();
	YGEGraphics::TransformNode				*tn = new YGEGraphics::TransformNode();
	YGEGraphics::Transform3D				*transform1 = new YGEGraphics::Transform3D();
	YGEGraphics::InterpolatedTransform3D	*transform2 = new YGEGraphics::InterpolatedTransform3D();
	YGEGraphics::Cube						*cube = new YGEGraphics::Cube(0.5f);
	YGEGraphics::VBO						*vbo = new YGEGraphics::VBO(cube);               

	//Insertion of phase's objects, to be deleted on phase's unload operation
	deleteSet.insert(dn);
	deleteSet.insert(tn);
	deleteSet.insert(transform1);
	deleteSet.insert(transform2);
	deleteSet.insert(cube);
	deleteSet.insert(vbo);



	//Set transforms
	transform1->setPos(DS3DVectorMake(-0.04f, 0.0f, -3.0f));
	transform1->setScl(DS3DVectorMake(-0.77f, -0.77f, -0.77f));



	DSQuat rot;
	rot.w = 1.0f;
	rot.x = 0.0f;
	rot.y = 0.0f;
	rot.z = 0.0f;

	

	transform1->setRot(rot);


	//------------

	
	transform2->setPos(DS3DVectorMake(-0.04f, 0.0f, -3.0f));
	transform2->setScl(DS3DVectorMake(-0.77f, -0.77f, -0.77f));

	DSQuat rot1;
	rot1.w = 1.0f;
	rot1.x = 0.0f;
	rot1.y = 1.0f;
	rot1.z = 0.0f;


	transform2->setRot(rot1);

	interpSet.insert(transform2);



	tn->setTransform(transform1);

	tn->setTransform(transform2);

	
	insertSet.insert(vbo);


	//Scene graph
	#ifdef _DEBUG
	framerate->child = dn;
    #endif
	dn->child = tn;
	tn->child = vbo;


	
	#ifdef _DEBUG
	sceneGraph = framerate;
    #else
	sceneGraph = dn;
    #endif

	

	return Phase::load();
}


bool InterpolationPhase::unload() 
{

	

	return Phase::unload();
}


bool InterpolationPhase::finished() 
{

	return (phaseTime > 20000);
}


void InterpolationPhase::prerender(YGEGraphics::RenderDevice *device) 
{
	
	Phase::prerender(device);

	DS4DVector clearCol;

	clearCol.x = 0.0f;
	clearCol.y = 0.0f;
	clearCol.z = 0.0f;
	clearCol.w = 1.0f;

	DS4DMatrix currentProjectionMatrix;

	DS4DMatrixPerspective(&currentProjectionMatrix, (float) 45.0, 1.0f, 0.5f, 10.0f);

	//device->enableDepthTest();

	device->clearColourAndDepthBuffers(clearCol);

	device->setProjectionMatrix(currentProjectionMatrix);

}


void InterpolationPhase::render(YGEGraphics::RenderDevice *device) 
{
	

	//graphics rendering
	device->enableDepthTest();

	Phase::render(device);

	device->disableDepthTest();

}
