//PhysicsActorPhase.cpp


#include "PhysicsActorPhase.h"
#include "Cube.h"
#include "TextureBind.h"
#include "PhysicsActor3D.h"
#include "Sphere.h"
#include "Debug.h"





 bool PhysicsActorPhase::load() 

	{
	
	
		simulatorTickRate = 60;
	
		phaseTickRate = 1000;

	    #ifdef _DEBUG
		// Standard debug draw node
	    YGEGraphics::DrawNode *framerate = new YGEGraphics::DebugDrawNode();
	    deleteSet.insert(framerate);
        #endif
	
		YGEGraphics::Texture       *texture = new YGEGraphics::Texture();
		YGEGraphics::TextureBind   *textureBind = new YGEGraphics::TextureBind();
		//YGEGraphics::Cube          *cube = new YGEGraphics::Cube(0.5f);
		//YGEGraphics::VBO           *vbo = new YGEGraphics::VBO(cube);
		YGEGraphics::Sphere        *ball = new YGEGraphics::Sphere(0.5f, 40, 50);
		YGEGraphics::TransformNode *actorTransformNode = new YGEGraphics::TransformNode();
		YGEEngine::PhysicsActor3D  *physicsActor = new YGEEngine::PhysicsActor3D();
	     

		//Insertion of phase's objects, to be deleted on phase's unload operation
		deleteSet.insert(texture);
		deleteSet.insert(textureBind);
		//deleteSet.insert(vbo);
		//deleteSet.insert(cube);
		deleteSet.insert(ball);
		deleteSet.insert(actorTransformNode);
		
		


		//Texturing
		//texture->loadTGAimage("osfp2.tga");
		texture->loadTGAimage("../Data/billard_ball.tga");

		insertSet.insert(texture);
	
	
		textureBind->setTexture(texture);



		// VBO and its cube
		//insertSet.insert(vbo);
	
	
		// Actor
		addPhaseObject(physicsActor);
		//addPhaseObject(actor);

	
		//Transform node
		actorTransformNode->setTransform(physicsActor->getTransform());

	
		// Scene graph
		#ifdef _DEBUG
		framerate->child =textureBind;
        #endif   
		textureBind->child = actorTransformNode;
		//actorTransformNode->child = vbo;
		actorTransformNode->child = ball;
	
	    #ifdef _DEBUG
		sceneGraph = framerate;
        #else
		sceneGraph = textureBind;
        #endif

	
	YGESimulator::BPSimulator *sim = new YGESimulator::BPSimulator();
	simulaSet.insert(sim);
	deleteSet.insert(sim);

	physicsActor->addBPSimulation(sim);

	
	  return Phase::load();
    }







 bool PhysicsActorPhase::unload() 
 {


	 return Phase::unload();

 }






bool PhysicsActorPhase::finished() 
{


	return (phaseTime > 25000);
}






void PhysicsActorPhase::prerender(YGEGraphics::RenderDevice *device) 
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





void PhysicsActorPhase::render(YGEGraphics::RenderDevice *device) 
    {

	
		device->enableDepthTest();

		Phase::render(device);

		device->disableDepthTest();


    }