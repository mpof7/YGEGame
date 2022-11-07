//Texture.h

// Header file 

//Created by Nick Bofilios 2010


#ifndef _YGE_TEXTURE_H
#define _YGE_TEXTURE_H

#include "RenderDevice.h"
#include "Object.h"

namespace YGEGraphics
{
  

	typedef struct
     {
            unsigned char depth;

            short int w;

			short int h;

            unsigned char* data;

      } tgaData;


	//!  Tecture class
    /*!
        Describes a 2D image object
     */


	class Texture : public YGECore::Object, public Insertable
	{
	
	public:

		Texture();
		virtual ~Texture();


		tgaData* loadTGAimage(const char *filename);

		void insertIntoGraphicsContext(RenderDevice *device);


		GLuint  texId;

	protected:

		char      *filename;
		int        colormode;
		int        total;	

		tgaData   *tga;
        FILE      *fh;
       
	};


}
#endif