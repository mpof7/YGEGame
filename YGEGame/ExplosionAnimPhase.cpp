//ExplosionAnimPhase.cpp

#include "ExplosionAnimPhase.h"
#include "Debug.h"
#include "Sphere.h"
#include "Texture.h"
#include "TextureBind.h"
#include "ExplosionSystem.h"



    bool ExplosionAnimPhase::load() 
	{
	
	
		simulatorTickRate = 60;
	
		phaseTickRate = 1000;

		#ifdef _DEBUG
		//Standard debug draw node
	    YGEGraphics::DrawNode *framerate = new YGEGraphics::DebugDrawNode();
	    deleteSet.insert(framerate);
        #endif
	
		YGEGraphics::DrawNode	   *dn = new YGEGraphics::DrawNode();
		YGEGraphics::Texture       *texture = new YGEGraphics::Texture();
		YGEGraphics::TextureBind   *textureBind = new YGEGraphics::TextureBind();
		YGEGraphics::TransformNode *PSystemMember0TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *PSystemMember1TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *PSystemMember2TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *PSystemMember3TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::TransformNode *PSystemMember4TransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::Sphere        *sfera = new YGEGraphics::Sphere(0.5f, 40, 20);
		YGEEngine::ExplosionSystem *Xplode = new YGEEngine::ExplosionSystem(5);
	
	

		//Insertion of phase's objects, to be deleted on phase's unload operation
		deleteSet.insert(dn);
		deleteSet.insert(texture);
		deleteSet.insert(textureBind);
		deleteSet.insert(sfera);
		deleteSet.insert(PSystemMember0TransformNode);
		deleteSet.insert(PSystemMember1TransformNode);
		deleteSet.insert(PSystemMember2TransformNode);
		deleteSet.insert(PSystemMember3TransformNode);
		deleteSet.insert(PSystemMember4TransformNode);
		deleteSet.insert(Xplode);
		


		//Texturing
		texture->loadTGAimage("../Data/osfp2.tga");
	
		insertSet.insert(texture);
	
	
		textureBind->setTexture(texture);

	
	
		// Actor
		Xplode->initializeFlock();
		addPhaseObject(Xplode);
		

	
		//Transform node
		//flockMemberTransformNode->setTransform(flock->getTransform());
		PSystemMember0TransformNode->setTransform(Xplode->particleSysElements[0].getTransform());
		PSystemMember1TransformNode->setTransform(Xplode->particleSysElements[1].getTransform());
		PSystemMember2TransformNode->setTransform(Xplode->particleSysElements[2].getTransform());
		PSystemMember3TransformNode->setTransform(Xplode->particleSysElements[3].getTransform());
		PSystemMember4TransformNode->setTransform(Xplode->particleSysElements[4].getTransform());

	
		//Scene graph
		#ifdef _DEBUG
	    framerate->child = dn;
        #endif

        
	    dn->child = textureBind;
		textureBind->child = PSystemMember0TransformNode;
		PSystemMember0TransformNode->child = sfera;
		PSystemMember0TransformNode->group = PSystemMember1TransformNode;
		PSystemMember1TransformNode->child = sfera;
		PSystemMember1TransformNode->group = PSystemMember2TransformNode;
		PSystemMember2TransformNode->child = sfera;
		PSystemMember1TransformNode->group = PSystemMember3TransformNode;
		PSystemMember3TransformNode->child = sfera;
		PSystemMember3TransformNode->group = PSystemMember4TransformNode;
		PSystemMember4TransformNode->child = sfera;
	
	
		#ifdef _DEBUG
		sceneGraph = framerate;
        #else
		sceneGraph = dn;
        #endif

	
	  return Phase::load();
    }



	bool ExplosionAnimPhase::unload() 
	{


	  return Phase::unload();
	}



	bool ExplosionAnimPhase::finished() 
	{

	
	  return (phaseTime > 15000);
	}




	void ExplosionAnimPhase::prerender(YGEGraphics::RenderDevice *device) 
	{
	
		Phase::prerender(device);

		DS4DVector clearCol;

		clearCol.x = 0.0f;
		clearCol.y = 0.0f;
		clearCol.z = 0.0f;
		clearCol.w = 1.0f;

		DS4DMatrix currentProjectionMatrix;
	
		DS4DMatrixPerspective(&currentProjectionMatrix, (float) 60.0, 1.0f, 1.0f, 100.0f);

	
		device->clearColourAndDepthBuffers(clearCol);

		device->setProjectionMatrix(currentProjectionMatrix);

	}




	void ExplosionAnimPhase::render(YGEGraphics::RenderDevice *device) 
    {

	
		device->enableDepthTest();

		Phase::render(device);

		device->disableDepthTest();


    }