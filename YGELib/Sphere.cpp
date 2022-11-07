//Sphere.cpp

#include "Sphere.h"




namespace YGEGraphics
{



	Sphere::Sphere(const float r, const int sl, const int st)
	{
	
		radious = r;
		slices = sl;
		stacks = st;
	
	}





	/*void CALLBACK Sphere::errorCallback(GLenum errorCode)
	{
	
		const GLubyte *estring;

		estring = gluErrorString(errorCode);

		fprintf(stderr, "Quadric Error: %s\n", estring);

		exit(0);
	
	}*/





	void Sphere::init()
	{
	
		GLUquadricObj  *qobj;

		displaylist = glGenLists(1);

		qobj = gluNewQuadric();

		//gluQuadricCallback(qobj, GLU_ERROR, errorCallback);

		gluQuadricCallback(qobj, GLU_ERROR, NULL);

		gluQuadricDrawStyle(qobj, GLU_FILL);  

		gluQuadricNormals(qobj, GLU_SMOOTH);

		gluQuadricTexture(qobj, GL_TRUE);



		glNewList(displaylist, GL_COMPILE);

		  gluSphere(qobj, radious, slices, stacks);

		glEndList();
	
	
	}




	void Sphere::draw(RenderDevice *device)
	{
	
		init();

		glShadeModel(GL_SMOOTH);

		glCallList(displaylist);
	
	
	}




}