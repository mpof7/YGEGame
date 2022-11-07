//Phase.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_PHASE_H
#define _YGE_PHASE_H

#include "Object.h"
#include "Time.h"
#include <set>
#include "Transform.h"


namespace YGECore { class Object; }

namespace YGEGraphics { class RenderDevice; class Drawable; class Insertable; }

namespace YGESimulator { class Simultable; class Updateable; class Syncroable; }


namespace YGEEngine
{

	class PhaseObject;



	//!  Phase class
    /*!
        Generic phase interface
     */

	class Phase 
	{
	
	public:

		 Phase();                //constructor
		 virtual ~Phase(){};     //virtual destructor


		 virtual bool load();     //loading of needed by the phase resources 
		 virtual bool unload();   //unloading of unneeded resources 

		 virtual void tick(unsigned long delta) = 0;       //actual phase's tick which takes a delta time parameter from the engine's tick

		 virtual bool finished() {return false;};   //is the phase finished? 

		 virtual void draw(YGEGraphics::RenderDevice *device) = 0;         //phase's draw operation which actually contains the pre-render and render operations

		

		 // Adding and removing from phase content sets
		inline void addInterpable(YGEGraphics::Interpable *obj) { interpSet.insert(obj); }
		inline void remInterpable(YGEGraphics::Interpable *obj) { interpSet.erase(obj);  }
		inline void addInsertable(YGEGraphics::Insertable *obj) { insertSet.insert(obj); }
		inline void remInsertable(YGEGraphics::Insertable *obj) { insertSet.erase(obj);  }
		inline void addSimultable(YGESimulator::Simultable *obj) { simulaSet.insert(obj); }
		inline void remSimultable(YGESimulator::Simultable *obj) { simulaSet.erase(obj);  }
		inline void addUpdateable(YGESimulator::Updateable *obj) { updateSet.insert(obj); }
		inline void remUpdateable(YGESimulator::Updateable *obj) { updateSet.erase(obj);  }
		inline void addSyncroable(YGESimulator::Syncroable *obj) { syncroSet.insert(obj); }
		inline void remSyncroable(YGESimulator::Syncroable *obj) { syncroSet.erase(obj);  }
		
		inline void addDeleteable(YGECore::Object *obj) { deleteSet.insert(obj); }
		inline void remDeleteable(YGECore::Object *obj) { deleteSet.erase(obj);  }


		// Initialisation and destruction of phase objects
		virtual void addPhaseObject(PhaseObject * const object);									// Add a phase object
		virtual void remPhaseObject(PhaseObject * const object);									// Remove a phase object



		 Phase          *next;        //next phase in the list to be processed


	protected:

		  YGEGraphics::Drawable   *sceneGraph;            //phase's scene graph oblect

		  unsigned long phaseTickRate;                    //how much ticks to be passed in order a phase tick to takes place
	      unsigned long simulatorTickRate;                //how much ticks to be passed in order a simulation step to takes place
	      unsigned long phaseTickAccumulator;             //phase's tick accumulator
	      unsigned long simulatorTickAccumulator;         //simulator's tick accumulator
	     
		  signed long simulatorBaseTime;                  //time passed for the simulator to complete a simulation step
		  unsigned long phaseTime;                        //time passed for a phase to complete a tick
	     


		  // Phase content sets
		std::set<YGEGraphics::Interpable *>	interpSet;										// Objects in this set will get interpolated
		std::set<YGEGraphics::Insertable *>	insertSet;										// Objects in this set will get inserted into the current context
		std::set<YGESimulator::Simultable *> simulaSet;										// Objects in this set will get simulated
		std::set<YGESimulator::Updateable *> updateSet;										// Objects in this set will get updated
		std::set<YGESimulator::Syncroable *> syncroSet;										// Objects in this set will get synced

		std::set<YGECore::Object *>			deleteSet;												// Objects in this set will get deleted as the phase unloads


		 virtual void interpolate(float alpha);        //phase's interpolation operation which takes a calculated into the phase's alpha factor
		 virtual void simulate();                      //phase's simulation operation
		 virtual void update();                        //phase's update operation
		 virtual void sync();                          //phase's synchronisation operation

		 
		 virtual void prerender(YGEGraphics::RenderDevice *device);    //phase's pre-render operation
		 virtual void render(YGEGraphics::RenderDevice *device);       //phase's render operation
	
	};




	//!  PhaseObject class
    /*!
        Generic game phase object
		Extended by Actor classes
     */

	class PhaseObject : public YGECore::Object
	{

	public:

		inline bool isActive() const { return active; }

		virtual void addToPhase(Phase * const phase);
		virtual void removeFromPhase(Phase * const phase);

	protected:

		bool						active;

	};
	


	

	//!  SThrPhase class
    /*!
        A singe threaded game phase which inherrits from the Phase interface
     */

	class SThrPhase : public Phase
	{
	
	public:

		SThrPhase();
	   ~SThrPhase();


	   void tick(unsigned long delta);

	   

	   void draw(YGEGraphics::RenderDevice *device);
	    
		
	};



}
#endif