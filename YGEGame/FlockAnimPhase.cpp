//FlockAnimPhase.cpp

#include "FlockAnimPhase.h"
#include "Debug.h"
#include "Sphere.h"
#include "Texture.h"
#include "TextureBind.h"
#include "FlockingSystem.h"
#include "AnimationPath.h"



    bool FlockAnimPhase::load() 
	{
	
	
		simulatorTickRate = 100;
	
		phaseTickRate = 0;

		#ifdef _DEBUG
		//Standard debug draw node
	    YGEGraphics::DrawNode *framerate = new YGEGraphics::DebugDrawNode();
	    deleteSet.insert(framerate);
        #endif
	
		YGEGraphics::DrawNode	   *dn = new YGEGraphics::DrawNode();
		YGEGraphics::Texture       *texture = new YGEGraphics::Texture();
		YGEGraphics::TextureBind   *textureBind = new YGEGraphics::TextureBind();
		YGEGraphics::TransformNode *FSystemMember0TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember1TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember2TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember3TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember4TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember5TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember6TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember7TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember8TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember9TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember10TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember11TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember12TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember13TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember14TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember15TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember16TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember17TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember18TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *FSystemMember19TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::Sphere        *sfera = new YGEGraphics::Sphere(0.3f, 40, 20);
		YGEEngine::FlockingSystem  *flock = new YGEEngine::FlockingSystem(20);
		//YGEEngine::AnimationPath   *path = new YGEEngine::AnimationPath();
	
	

		//Insertion of phase's objects, to be deleted on phase's unload operation
		deleteSet.insert(dn);
		deleteSet.insert(texture);
		deleteSet.insert(textureBind);
		deleteSet.insert(sfera);
		deleteSet.insert(FSystemMember0TransformNode);
		deleteSet.insert(FSystemMember1TransformNode);
		deleteSet.insert(FSystemMember2TransformNode);
		deleteSet.insert(FSystemMember3TransformNode);
		deleteSet.insert(FSystemMember4TransformNode);
		deleteSet.insert(FSystemMember5TransformNode);
		deleteSet.insert(FSystemMember6TransformNode);
		deleteSet.insert(FSystemMember7TransformNode);
		deleteSet.insert(FSystemMember8TransformNode);
		deleteSet.insert(FSystemMember9TransformNode);
		deleteSet.insert(FSystemMember10TransformNode);
		deleteSet.insert(FSystemMember11TransformNode);
		deleteSet.insert(FSystemMember12TransformNode);
		deleteSet.insert(FSystemMember13TransformNode);
		deleteSet.insert(FSystemMember14TransformNode);
		deleteSet.insert(FSystemMember15TransformNode);
		deleteSet.insert(FSystemMember16TransformNode);
		deleteSet.insert(FSystemMember17TransformNode);
		deleteSet.insert(FSystemMember18TransformNode);
		deleteSet.insert(FSystemMember19TransformNode);
		deleteSet.insert(flock);
		


		

		//Texturing
		texture->loadTGAimage("../Data/beetex.tga");
	
		insertSet.insert(texture);
	
	
		textureBind->setTexture(texture);

	   //path->loadCPointsFromFile("..//Data//test.txt");
	
		// Actor
		flock->initializeFlock();
		addPhaseObject(flock);
		

	
		//Transform node
		//flockMemberTransformNode->setTransform(flock->getTransform());
		FSystemMember0TransformNode->setTransform(flock->flockSysElements[0].getTransform());
		FSystemMember1TransformNode->setTransform(flock->flockSysElements[1].getTransform());
		FSystemMember2TransformNode->setTransform(flock->flockSysElements[2].getTransform());
		FSystemMember3TransformNode->setTransform(flock->flockSysElements[3].getTransform());
		FSystemMember4TransformNode->setTransform(flock->flockSysElements[4].getTransform());
		FSystemMember5TransformNode->setTransform(flock->flockSysElements[5].getTransform());
		FSystemMember6TransformNode->setTransform(flock->flockSysElements[6].getTransform());
		FSystemMember7TransformNode->setTransform(flock->flockSysElements[7].getTransform());
		FSystemMember8TransformNode->setTransform(flock->flockSysElements[8].getTransform());
		FSystemMember9TransformNode->setTransform(flock->flockSysElements[9].getTransform());
		FSystemMember10TransformNode->setTransform(flock->flockSysElements[10].getTransform());
		FSystemMember11TransformNode->setTransform(flock->flockSysElements[11].getTransform());
		FSystemMember12TransformNode->setTransform(flock->flockSysElements[12].getTransform());
		FSystemMember13TransformNode->setTransform(flock->flockSysElements[13].getTransform());
		FSystemMember14TransformNode->setTransform(flock->flockSysElements[14].getTransform());
		FSystemMember15TransformNode->setTransform(flock->flockSysElements[15].getTransform());
		FSystemMember16TransformNode->setTransform(flock->flockSysElements[16].getTransform());
		FSystemMember17TransformNode->setTransform(flock->flockSysElements[17].getTransform());
		FSystemMember18TransformNode->setTransform(flock->flockSysElements[18].getTransform());
		FSystemMember19TransformNode->setTransform(flock->flockSysElements[19].getTransform());

	
		//Scene graph
		#ifdef _DEBUG
	    framerate->child = dn;
        #endif

        
	    dn->child = textureBind;
		textureBind->child = FSystemMember0TransformNode;
		FSystemMember0TransformNode->child = sfera;
		FSystemMember0TransformNode->group = FSystemMember1TransformNode;
		FSystemMember1TransformNode->child = sfera;
		FSystemMember1TransformNode->group = FSystemMember2TransformNode;
		FSystemMember2TransformNode->child = sfera;
		FSystemMember2TransformNode->group = FSystemMember3TransformNode;
		FSystemMember3TransformNode->child = sfera;
		FSystemMember3TransformNode->group = FSystemMember4TransformNode;
		FSystemMember4TransformNode->child = sfera;
		FSystemMember4TransformNode->group = FSystemMember5TransformNode;
		FSystemMember5TransformNode->child = sfera;
		FSystemMember5TransformNode->group = FSystemMember6TransformNode;
		FSystemMember6TransformNode->child = sfera;
		FSystemMember6TransformNode->group = FSystemMember7TransformNode;
		FSystemMember7TransformNode->child = sfera;
		FSystemMember7TransformNode->group = FSystemMember8TransformNode;
		FSystemMember8TransformNode->child = sfera;
		FSystemMember8TransformNode->group = FSystemMember9TransformNode;
		FSystemMember9TransformNode->child = sfera;
		FSystemMember9TransformNode->group = FSystemMember10TransformNode;
		FSystemMember10TransformNode->child = sfera;
		FSystemMember10TransformNode->group = FSystemMember11TransformNode;
		FSystemMember11TransformNode->child = sfera;
		FSystemMember11TransformNode->group = FSystemMember12TransformNode;
		FSystemMember12TransformNode->child = sfera;
		FSystemMember12TransformNode->group = FSystemMember13TransformNode;
		FSystemMember13TransformNode->child = sfera;
		FSystemMember13TransformNode->group = FSystemMember14TransformNode;
		FSystemMember14TransformNode->child = sfera;
		FSystemMember14TransformNode->group = FSystemMember15TransformNode;
		FSystemMember15TransformNode->child = sfera;
		FSystemMember15TransformNode->group = FSystemMember16TransformNode;
		FSystemMember16TransformNode->child = sfera;
		FSystemMember16TransformNode->group = FSystemMember17TransformNode;
		FSystemMember17TransformNode->child = sfera;
		FSystemMember17TransformNode->group = FSystemMember18TransformNode;
		FSystemMember18TransformNode->child = sfera;
		FSystemMember18TransformNode->group = FSystemMember19TransformNode;
		FSystemMember19TransformNode->child = sfera;
	
	
		#ifdef _DEBUG
		sceneGraph = framerate;
        #else
		sceneGraph = dn;
        #endif

	
	  return Phase::load();
    }



	bool FlockAnimPhase::unload() 
	{


	  return Phase::unload();
	}



	bool FlockAnimPhase::finished() 
	{

	
	  return (phaseTime > 120000);
	   //return false;
	}




	void FlockAnimPhase::prerender(YGEGraphics::RenderDevice *device) 
	{
	
		Phase::prerender(device);

		DS4DVector clearCol;

		clearCol.x = 0.0f;
		clearCol.y = 0.0f;
		clearCol.z = 0.0f;
		clearCol.w = 1.0f;

		DS4DMatrix currentProjectionMatrix;
	
		DS4DMatrixPerspective(&currentProjectionMatrix, (float) 60.0, 1.0f, 1.0f, 1000.0f);

	
		device->clearColourAndDepthBuffers(clearCol);

		device->setProjectionMatrix(currentProjectionMatrix);

	}




	void FlockAnimPhase::render(YGEGraphics::RenderDevice *device) 
    {

	
		device->enableDepthTest();

		Phase::render(device);

		device->disableDepthTest();


    }