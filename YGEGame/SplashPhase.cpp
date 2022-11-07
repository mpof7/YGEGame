//SplashPhase.cpp

#include "SplashPhase.h"
#include "Time.h"
#include "DrawNode.h"
#include "TextureBind.h"
#include "Quad.h"
#include "Debug.h"



SplashPhase::SplashPhase()
{

}


SplashPhase::~SplashPhase()
{

}



bool SplashPhase::load() 
{
	

	//Actual phase loading
	YGEGraphics::DrawNode					*dn = new YGEGraphics::DrawNode();
	YGEGraphics::TransformNode				*tn = new YGEGraphics::TransformNode();
	YGEGraphics::Transform2D				*transform1 = new YGEGraphics::Transform2D();
	YGEGraphics::Texture                    *texture = new YGEGraphics::Texture();
	YGEGraphics::TextureBind                *textureBind = new YGEGraphics::TextureBind();
	YGEGraphics::Quad						*quad = new YGEGraphics::Quad(0.5f, 0.5f);
	YGEGraphics::VBO						*vbo = new YGEGraphics::VBO(quad);


	//Insertion of phase's objects, to be deleted on phase's unload operation
	deleteSet.insert(dn);
	deleteSet.insert(tn);
	deleteSet.insert(transform1);
	deleteSet.insert(texture);
	deleteSet.insert(textureBind);
	deleteSet.insert(quad);
	deleteSet.insert(vbo);




	//Texturing
	texture->loadTGAimage("../Data/splash_mes.tga");
	
	insertSet.insert(texture);
	
	
	textureBind->setTexture(texture);




	//Set transforms
	transform1->setPos(DS2DVectorMake(0.0f, 0.0f));
	


	//------------



	tn->setTransform(transform1);


	insertSet.insert(vbo);

	

	//Scene graph
	dn->child = textureBind;
	textureBind->child = tn;
	tn->child = vbo;


	sceneGraph = dn;


	return Phase::load();
}



bool SplashPhase::unload() 
{

	

	return Phase::unload();
}




bool SplashPhase::finished() 
{

	return (phaseTime > 3000);
}



void SplashPhase::prerender(YGEGraphics::RenderDevice *device) 
{
	
	Phase::prerender(device);

	DS4DVector clearCol;

	clearCol.x = 0.0f;
	clearCol.y = 0.0f;
	clearCol.z = 0.0f;
	clearCol.w = 1.0f;


	device->clearColourAndDepthBuffers(clearCol);


}



void SplashPhase::render(YGEGraphics::RenderDevice *device) 
{

	Phase::render(device);

}
