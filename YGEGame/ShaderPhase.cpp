//ShaderPhase.cpp

#include "ShaderPhase.h"
#include "Time.h"
#include "DrawNode.h"
#include "Cube.h"
#include "Shader.h"
#include "ShaderBind.h"
#include "Debug.h"







ShaderPhase::ShaderPhase()
{

}


ShaderPhase::~ShaderPhase()
{


}


bool ShaderPhase::load()
{

	#ifdef _DEBUG
	//Standard debug draw node
	YGEGraphics::DrawNode *framerate = new YGEGraphics::DebugDrawNode();
	deleteSet.insert(framerate);
    #endif

	YGEGraphics::DrawNode					*dn = new YGEGraphics::DrawNode();
	YGEGraphics::Cube                       *cube = new YGEGraphics::Cube(0.5f);
	YGEGraphics::VBO                        *vbo = new YGEGraphics::VBO(cube);
	YGEGraphics::Shader                     *first_shader = new YGEGraphics::Shader("../Data/simpleShader.shader");
	YGEGraphics::ShaderBind                 *create_shader = new YGEGraphics::ShaderBind();
	YGEGraphics::TransformNode				*tn = new YGEGraphics::TransformNode();
	YGEGraphics::Transform3D				*transform1 = new YGEGraphics::Transform3D();


	//Insertion of phase's objects, to be deleted on phase's unload operation
	deleteSet.insert(dn);
	deleteSet.insert(tn);
	deleteSet.insert(transform1);
	deleteSet.insert(first_shader);
	deleteSet.insert(create_shader);
	deleteSet.insert(cube);
	deleteSet.insert(vbo);


	create_shader->setShader(first_shader);

	insertSet.insert(first_shader);


	//------

	transform1->setPos(DS3DVectorMake(-0.3f, 0.0f, -3.0f));
	transform1->setScl(DS3DVectorMake(-0.55f, -0.55f, -0.55f));

	//------

	tn->setTransform(transform1);

	//------

	insertSet.insert(vbo);

	//Scene graph
	#ifdef _DEBUG
	framerate->child = dn;
    #endif
	dn->child = tn;
	tn->child = create_shader;
	create_shader->child = vbo;

	
	
	#ifdef _DEBUG
	sceneGraph = framerate;
    #else
	sceneGraph = dn;
    #endif

	//phaseStartTime = YGECore::Time::getMilliTime();

 return Phase::load();
}



bool ShaderPhase::unload()
{

	


 return Phase::unload();
}



bool ShaderPhase::finished()
{

  return (phaseTime > 15000);
}




void ShaderPhase::prerender(YGEGraphics::RenderDevice *device) 
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



void ShaderPhase::render(YGEGraphics::RenderDevice *device) 
{

	
	device->enableDepthTest();
	
	Phase::render(device);

	device->disableDepthTest();


}
