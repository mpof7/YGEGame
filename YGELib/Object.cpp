//Object.cpp

#include "Debug.h"
#include "Object.h"



namespace YGECore
{

	static unsigned long long objectCount = 0;

	Object::Object()
	{
	
		objectCount++;
		DBG(std::cout << "Object Created : " << this << std::endl;)
	
	
	}



	Object::~Object()
	{
	
		objectCount--;
		DBG(std::cout << "Object Deleted : " << this << " (" << objectCount << " objects)" << std::endl;)
	
	
	}



}