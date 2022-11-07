//threeDActorPhase.cpp

#include "threeDActorPhase.h"
#include "Cube.h"
#include "TextureBind.h"
#include "threeDActor.h"
#include "Debug.h"



bool threeDActorPhase::load() 

	{
	
	
		simulatorTickRate = 20;
	
		phaseTickRate = 0;


		#ifdef _DEBUG
		// Standard debug draw node
	    YGEGraphics::DrawNode *framerate = new YGEGraphics::DebugDrawNode();
	    deleteSet.insert(framerate);
        #endif
	
		YGEGraphics::Texture       *texture = new YGEGraphics::Texture();
		YGEGraphics::TextureBind   *textureBind = new YGEGraphics::TextureBind();
		YGEGraphics::Cube          *cube = new YGEGraphics::Cube(0.5f);
		YGEGraphics::VBO           *vbo = new YGEGraphics::VBO(cube);
		YGEGraphics::TransformNode *modelTransformNode = new YGEGraphics::TransformNode();
		YGEEngine::threeDActor     *threedActor = new YGEEngine::threeDActor();
		
	

		//Insertion of phase's objects, to be deleted on phase's unload operation
		deleteSet.insert(texture);
		deleteSet.insert(textureBind);
		deleteSet.insert(vbo);
		deleteSet.insert(cube);
		deleteSet.insert(modelTransformNode);
		//deleteSet.insert(threedActor);
		


		//Texturing
		texture->loadTGAimage("../Data/osfp2.tga");
	
		insertSet.insert(texture);
	
	
		textureBind->setTexture(texture);



		// VBO and its cube
		insertSet.insert(vbo);
	
	
		// Actor
		addPhaseObject(threedActor);
		

		//updateSet.insert(threedActor);
	
		//Transform node
		modelTransformNode->setTransform(threedActor->getTransform());

		
	
		// Scene graph
		#ifdef _DEBUG
		framerate->child = textureBind;
        #endif
		textureBind->child = modelTransformNode;
		modelTransformNode->child = vbo;
	
	    #ifdef _DEBUG
		sceneGraph = framerate;
        #else
		sceneGraph = textureBind;
        #endif
	
	  return Phase::load();
    }



    bool threeDActorPhase::unload() 
	{


	  return Phase::unload();
	}




	bool threeDActorPhase::finished() 
	{

	
	  return (phaseTime > 60000);
	}




	void threeDActorPhase::prerender(YGEGraphics::RenderDevice *device) 
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




	void threeDActorPhase::render(YGEGraphics::RenderDevice *device) 
    {

	
		device->enableDepthTest();

		Phase::render(device);

		device->disableDepthTest();


    }