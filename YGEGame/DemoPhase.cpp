//DemoPhase.cpp


#include "DemoPhase.h"
#include "Time.h"
#include "DrawNode.h"
#include "Cube.h"
#include "Texture.h"
#include "TextureBind.h"
#include "Debug.h"




DemoPhase::DemoPhase()
{

}


DemoPhase::~DemoPhase()
{


}


bool DemoPhase::load()
{
	#ifdef _DEBUG
	//Standard debug draw node
	YGEGraphics::DrawNode *framerate = new YGEGraphics::DebugDrawNode();
	deleteSet.insert(framerate);
    #endif

	YGEGraphics::DrawNode					*dn = new YGEGraphics::DrawNode();
	YGEGraphics::Texture                    *cubeTexture = new YGEGraphics::Texture();
	YGEGraphics::TextureBind                *createCubeTex = new YGEGraphics::TextureBind();
	YGEGraphics::Cube                       *cube = new YGEGraphics::Cube(0.5f);
	YGEGraphics::VBO                        *vbo = new YGEGraphics::VBO(cube);
	YGEGraphics::TransformNode				*tn = new YGEGraphics::TransformNode();
	YGEGraphics::Transform3D				*transform1 = new YGEGraphics::Transform3D();

	YGEGraphics::Texture                    *cubeTexture2 = new YGEGraphics::Texture();
	YGEGraphics::TextureBind                *createCubeTex2 = new YGEGraphics::TextureBind();
	YGEGraphics::TransformNode				*tn2 = new YGEGraphics::TransformNode();
	YGEGraphics::Transform3D				*transform2 = new YGEGraphics::Transform3D();


	//Insertion of phase's objects, to be deleted on phase's unload operation
	deleteSet.insert(dn);
	deleteSet.insert(tn);
	deleteSet.insert(transform1);
	deleteSet.insert(tn2);
	deleteSet.insert(transform2);
	deleteSet.insert(cube);
	deleteSet.insert(vbo);
	deleteSet.insert(cubeTexture);
	deleteSet.insert(createCubeTex);
	deleteSet.insert(cubeTexture2);
	deleteSet.insert(createCubeTex2);






	cubeTexture->loadTGAimage("../Data/osfp2.tga");

	insertSet.insert(cubeTexture);



	cubeTexture2->loadTGAimage("../Data/osfp.tga");

	insertSet.insert(cubeTexture2);

	
	
	DSQuat rot = DSQuatRotate(&DSQuatIdentity, &DSVector3DYAxis, 0.15f );

	//DSQuatRotate(&rot, &DSVector3DYAxis, -0.25f);

	//rot.w = -0.25f;
	//rot.x = 0.0f;
	//rot.y = 1.0f;
	//rot.z = 0.0f;

	DSQuat rot1 = DSQuatRotate(&DSQuatIdentity, &DSVector3DXAxis, 0.35f);

	//DSQuatRotate(&rot1, &DSVector3DXAxis, 0.35f);

	//rot1.w = 0.35f;
	//rot1.x = 1.0f;
	//rot1.y = 0.0f;
	//rot1.z = 0.0f;
	

	 DSQuat rot2 = DSQuatMultiply(&rot1, &rot);

	 DSQuatUnitise(&rot2);



	transform1->setRot(rot2);
	transform1->setPos(DS3DVectorMake(-0.3f, 0.0f, -3.0f));
	transform1->setScl(DS3DVectorMake(-0.55f, -0.55f, -0.55f));

	transform2->setPos(DS3DVectorMake(0.5f, 0.0f, -3.0f));
	transform2->setScl(DS3DVectorMake(-0.55f, -0.55f, -0.55f));


	//------

	createCubeTex->setTexture(cubeTexture);

	createCubeTex2->setTexture(cubeTexture2);

	tn->setTransform(transform1);

	tn2->setTransform(transform2);

	//------

	insertSet.insert(vbo);


	//Scene graph
	#ifdef _DEBUG
	framerate->child = dn;
    #endif
	dn->child = createCubeTex;
	createCubeTex->child = tn;
	tn->child = vbo;
	
	dn->group = createCubeTex2;
	createCubeTex2->child = tn2;
	tn2->child = vbo;

	#ifdef _DEBUG
	sceneGraph = framerate;
    #else
	sceneGraph = dn;
    #endif


	phaseStartTime = YGECore::Time::getMilliTime();

 return Phase::load();
}



bool DemoPhase::unload()
{

	


 return Phase::unload();
}



bool DemoPhase::finished()
{

  return (phaseTime > 20000);
}


void DemoPhase::prerender(YGEGraphics::RenderDevice *device) 
{
	
	Phase::prerender(device);



	DS4DVector clearCol;

	clearCol.x = 0.0f;
	clearCol.y = 0.0f;
	clearCol.z = 0.0f;
	clearCol.w = 1.0f;

	DS4DMatrix currentProjectionMatrix;

	DS4DMatrixPerspective(&currentProjectionMatrix, (float) 45.0, 1.0f, 0.5f, 20.0f);


	device->clearColourAndDepthBuffers(clearCol);

	device->setProjectionMatrix(currentProjectionMatrix);

	

}



void DemoPhase::render(YGEGraphics::RenderDevice *device) 
{

	
	device->enableDepthTest();

	Phase::render(device);

	device->disableDepthTest();


}
