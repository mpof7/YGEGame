//SpherePhase.cpp


#include "SpherePhase.h"
#include "Sphere.h"
#include "DrawNode.h"
#include "Texture.h"
#include "TextureBind.h"
#include "Debug.h"







SpherePhase::SpherePhase()
{


}



SpherePhase::~SpherePhase()
{


}




bool SpherePhase::load()
{
	#ifdef _DEBUG
	//Standard debug draw node
	YGEGraphics::DrawNode *framerate = new YGEGraphics::DebugDrawNode();
	deleteSet.insert(framerate);
    #endif

	YGEGraphics::DrawNode					*dn = new YGEGraphics::DrawNode();
	YGEGraphics::Texture                    *cubeTexture = new YGEGraphics::Texture();
	YGEGraphics::TextureBind                *createCubeTex = new YGEGraphics::TextureBind();
	YGEGraphics::Sphere                     *sfera = new YGEGraphics::Sphere(1.0f, 40, 20);
	YGEGraphics::TransformNode				*tn = new YGEGraphics::TransformNode();
	YGEGraphics::Transform3D				*transform1 = new YGEGraphics::Transform3D();

	


	//Insertion of phase's objects, to be deleted on phase's unload operation
	deleteSet.insert(dn);
	deleteSet.insert(tn);
	deleteSet.insert(transform1);
	deleteSet.insert(sfera);
	deleteSet.insert(cubeTexture);
	deleteSet.insert(createCubeTex);
	






	cubeTexture->loadTGAimage("../Data/osfp2.tga");

	insertSet.insert(cubeTexture);


	
	
	transform1->setPos(DS3DVectorMake(-0.3f, 0.0f, -3.0f));
	//transform1->setScl(DS3DVectorMake(-0.55f, -0.55f, -0.55f));


	//------

	createCubeTex->setTexture(cubeTexture);


	tn->setTransform(transform1);


	//------


	//Scene graph
	#ifdef _DEBUG
	framerate->child = dn;
    #endif
	dn->child = createCubeTex;
	createCubeTex->child = tn;
	tn->child = sfera;


	//
	#ifdef _DEBUG
	sceneGraph = framerate;
    #else
	sceneGraph = dn;
    #endif

	//phaseStartTime = YGECore::Time::getMilliTime();

 return Phase::load();
}



bool SpherePhase::unload()
{

	


 return Phase::unload();
}




bool SpherePhase::finished()
{

  return (phaseTime > 15000);
}






void SpherePhase::prerender(YGEGraphics::RenderDevice *device) 
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



void SpherePhase::render(YGEGraphics::RenderDevice *device) 
{

	
	device->enableDepthTest();

	Phase::render(device);

	device->disableDepthTest();


}