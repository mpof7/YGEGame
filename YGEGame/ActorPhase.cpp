//ActorPhase.cpp

#include "ActorPhase.h"
#include "Cube.h"
#include "TextureBind.h"
#include "Shader.h"
#include "SpriteActor.h"
#include "Debug.h"




    bool ActorPhase::load() 

	{
	
	
		simulatorTickRate = 20;
	
		phaseTickRate = 1000;

		#ifdef _DEBUG
		//Standard debug draw node
	    YGEGraphics::DrawNode *framerate = new YGEGraphics::DebugDrawNode();
	    deleteSet.insert(framerate);
        #endif
	
		YGEGraphics::DrawNode	   *dn = new YGEGraphics::DrawNode();
		YGEGraphics::Texture       *texture = new YGEGraphics::Texture();
		YGEGraphics::TextureBind   *textureBind = new YGEGraphics::TextureBind();
		YGEGraphics::Cube          *cube = new YGEGraphics::Cube(0.5f);
		YGEGraphics::VBO           *vbo = new YGEGraphics::VBO(cube);
		YGEGraphics::TransformNode *spriteTransformNode = new YGEGraphics::TransformNode();
		YGEEngine::SpriteActor     *spriteActor = new YGEEngine::SpriteActor();
	
	

		//Insertion of phase's objects, to be deleted on phase's unload operation
		deleteSet.insert(dn);
		deleteSet.insert(texture);
		deleteSet.insert(textureBind);
		deleteSet.insert(vbo);
		deleteSet.insert(cube);
		deleteSet.insert(spriteTransformNode);
		deleteSet.insert(spriteActor);
		


		//Texturing
		texture->loadTGAimage("../Data/osfp2.tga");
	
		insertSet.insert(texture);
	
	
		textureBind->setTexture(texture);



		// VBO and its cube
		insertSet.insert(vbo);
	
	
		// Actor
		addPhaseObject(spriteActor);
		//addPhaseObject(actor);

	
		//Transform node
		spriteTransformNode->setTransform(spriteActor->getTransform());

	
		//Scene graph
		#ifdef _DEBUG
	    framerate->child = dn;
        #endif

        
	    dn->child = textureBind;
		textureBind->child = spriteTransformNode;
		spriteTransformNode->child = vbo;
	
	
		#ifdef _DEBUG
		sceneGraph = framerate;
        #else
		sceneGraph = dn;
        #endif

	
	  return Phase::load();
    }




	bool ActorPhase::unload() 
	{


	  return Phase::unload();
	}




	bool ActorPhase::finished() 
	{

	
	  return (phaseTime > 12000);
	}



	void ActorPhase::prerender(YGEGraphics::RenderDevice *device) 
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



	void ActorPhase::render(YGEGraphics::RenderDevice *device) 
    {

	
		device->enableDepthTest();

		Phase::render(device);

		device->disableDepthTest();


    }
