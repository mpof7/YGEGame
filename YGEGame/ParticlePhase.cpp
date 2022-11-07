//ParticlePhase.cpp

#include "ParticlePhase.h"
#include "Debug.h"
#include "Sphere.h"
#include "Texture.h"
#include "TextureBind.h"
#include "PointEntity.h"


    bool ParticlePhase::load() 
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
		YGEGraphics::TransformNode *particleTransformNode = new YGEGraphics::TransformNode();
		YGEGraphics::Sphere        *sfera = new YGEGraphics::Sphere(0.5f, 40, 20);
		YGEEngine::PointEntity     *myPoint = new YGEEngine::PointEntity();
	
	

		//Insertion of phase's objects, to be deleted on phase's unload operation
		deleteSet.insert(dn);
		deleteSet.insert(texture);
		deleteSet.insert(textureBind);
		deleteSet.insert(sfera);
		deleteSet.insert(particleTransformNode);
		deleteSet.insert(myPoint);
		


		//Texturing
		texture->loadTGAimage("../Data/osfp2.tga");
	
		insertSet.insert(texture);
	
	
		textureBind->setTexture(texture);

	
	
		// Actor
		addPhaseObject(myPoint);
		

	
		//Transform node
		particleTransformNode->setTransform(myPoint->getTransform());

	
		//Scene graph
		#ifdef _DEBUG
	    framerate->child = dn;
        #endif

        
	    dn->child = textureBind;
		textureBind->child = particleTransformNode;
		particleTransformNode->child = sfera;
	
	
		#ifdef _DEBUG
		sceneGraph = framerate;
        #else
		sceneGraph = dn;
        #endif

	
	  return Phase::load();
    }



	bool ParticlePhase::unload() 
	{


	  return Phase::unload();
	}




	bool ParticlePhase::finished() 
	{

	
	  return (phaseTime > 10000);
	}




	void ParticlePhase::prerender(YGEGraphics::RenderDevice *device) 
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




	void ParticlePhase::render(YGEGraphics::RenderDevice *device) 
    {

	
		device->enableDepthTest();

		Phase::render(device);

		device->disableDepthTest();


    }
