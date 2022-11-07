//Simulation.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_SIMULATION_H
#define _YGE_SIMULATION_H


namespace YGESimulator 
{

	//!  Simultable class
    /*!
        Describes an object that can be simulated
     */

	class Simultable 
	{

	public:

		virtual void step() = 0;

	};



	//!  Updateable class
    /*!
        Describes an object that can be updated
     */

	class Updateable {

	public:

		virtual void update() = 0;

	};


	//!  Syncroable class
    /*!
        Describes an object that can be synchronized
     */

	class Syncroable 
	{

	public:

		virtual void sync() = 0;

	};



	//!  Simulator class
    /*!
        Describes a simulation object
     */

	class Simulator 
	{

	public:

		Simulator();
		~Simulator();

	};


}

#endif