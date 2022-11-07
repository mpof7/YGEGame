//Phase.cpp

#include "Phase.h"
#include "RenderDevice.h"
#include "Simulation.h"
#include <algorithm>
#include "Debug.h"


namespace YGEEngine
{

	Phase::Phase()
	{
	
		next = NULL;
		sceneGraph = 0L;
		finished();

		//Default rates for ticking
		phaseTickRate = 1000;
		simulatorTickRate = 1000;
	
	}


	SThrPhase::SThrPhase()
	{	
		DBG(std::cout << "Phase construction" << std::endl;)

	}


	SThrPhase::~SThrPhase()
	{

		DBG(std::cout << "Phase destruction" << std::endl;)
	
	}


	//Phase's general operations

	bool Phase::load()
	{
		finished();



		
        phaseTickAccumulator = 0;
		simulatorTickAccumulator = simulatorTickRate;
		phaseTime = 0;
		simulatorBaseTime = phaseTime - simulatorTickRate;

		return true;
	}


	bool Phase::unload()
	{
	
		// Clear content sets
		interpSet.clear();
		insertSet.clear();
		simulaSet.clear();
		updateSet.clear();
		syncroSet.clear();

		// Delete phase resources
		for (std::set<YGECore::Object *>::iterator iter = deleteSet.begin(); iter != deleteSet.end(); iter++)
		{

			delete (*iter);
		
		}


		deleteSet.clear();

		sceneGraph = 0LL;


		return true;	
	}




	void Phase::addPhaseObject(PhaseObject * const object) 
	{

		object->addToPhase(this);
	}




	void Phase::remPhaseObject(PhaseObject * const object) 
	{

		object->removeFromPhase(this);
	}




	void Phase::render(YGEGraphics::RenderDevice *device)
	{
	
		if(sceneGraph)
		{
			sceneGraph->draw(device);
		}

	}




	void Phase::prerender(YGEGraphics::RenderDevice *device) 
	{
		
		std::set<YGEGraphics::Insertable *>::iterator iter;

		// Insert all into the graphics context
		for (iter = insertSet.begin(); iter != insertSet.end(); iter++) 
		{

			(*iter)->insertIntoGraphicsContext(device);
		}

		// Remove from the array
		insertSet.clear();
	
	}



	
	void Phase::interpolate(float alpha) 
	{
		
		std::set<YGEGraphics::Interpable *>::iterator iter;

		for (iter = interpSet.begin(); iter != interpSet.end(); iter++) 
		{

			(*iter)->interpolate(alpha);
		}

	}




	void Phase::simulate() 
	{
		
		std::set<YGESimulator::Simultable *>::iterator iter;

		for (iter = simulaSet.begin(); iter != simulaSet.end(); iter++) 
		{

			(*iter)->step();
		}

	}

	
	void Phase::update() 
	{
		
		std::set<YGESimulator::Updateable *>::iterator iter;

		for (iter = updateSet.begin(); iter != updateSet.end(); iter++) 
		{

			(*iter)->update();
		}

	}




	void Phase::sync() 
	{
		
		std::set<YGESimulator::Syncroable *>::iterator iter;

		for (iter = syncroSet.begin(); iter != syncroSet.end(); iter++) 
		{

			(*iter)->sync();
		}

	}





	void PhaseObject::addToPhase(Phase * const phase) 
	{

		phase->addDeleteable(this);
	}





	void PhaseObject::removeFromPhase(Phase * const phase) 
	{

		phase->remDeleteable(this);
	}






	//Single threaded phase personal operations

	void SThrPhase::tick(unsigned long delta)
	{
	
		phaseTime += delta;

		phaseTickAccumulator += delta;

		if(phaseTickAccumulator >= phaseTickRate)
		{
		
			update();

			phaseTickAccumulator -= phaseTickRate;
		
		}


		simulatorTickAccumulator += delta;

		if(simulatorTickAccumulator >= simulatorTickRate)
		{
		
			sync();
			simulate();


			simulatorTickAccumulator -= simulatorTickRate;
			simulatorBaseTime += simulatorTickRate;
		
		}


		float alpha = (phaseTime - simulatorBaseTime) / (float)simulatorTickRate;

		interpolate(alpha);

	
	}


	void SThrPhase::draw(YGEGraphics::RenderDevice *device)
	{
	
		prerender(device);
		render(device);



		// Flush graphics context
		device->flush();
	
	
	}



}