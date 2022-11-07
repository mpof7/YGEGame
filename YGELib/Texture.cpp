//Textrure.cpp

#include "Texture.h"
#include <memory.h>
#include "Debug.h"


namespace YGEGraphics
{


	Texture::Texture()
	{
	
		filename = NULL;
	    tga =  NULL;
		fh = NULL;
	
	}


	Texture::~Texture()
	{
		//free up texture resources
		glDeleteTextures(1, &texId);
	
	}





/**
#
* An uncompressed TGA image loader.
#
*
#
* @author Tom Arnold
#
*/

	tgaData* Texture::loadTGAimage(const char *filename)
	{


           //Open the file in binary mode

            fh = fopen(filename, "rb");
		  

          //Problem opening file? 

           if (fh == NULL)
           {

                 DBG(fprintf(stderr, "Error: problem opening TGA file (%s).\n", filename);)

           }
           else
		   {

			    //Allocate memory for the info structure

               tga = (tgaData *) malloc(sizeof(tgaData));
			   

               // Load information about the tga header

                        // Seek to the width.

                        fseek(fh, 12, SEEK_SET);

						fread(&tga->w, sizeof(short int), 1, fh);

                       

                        // Seek to the height.

                        fseek(fh, 14, SEEK_SET);

						fread(&tga->h, sizeof(short int), 1, fh);

                        

                        // Seek to the depth.

                        fseek(fh, 16, SEEK_SET);

						fread(&tga->depth, sizeof(short int), 1, fh);



						
             // Load the actual image data.

                        // Mode = components per pixel.

                        colormode = tga->depth / 8;

 

                        // Total bytes = h * w * md.

                        total = tga->h * tga->w * colormode;

 

                        DBG(printf("Reading %d bytes.\n", total);)

 

                        // Allocate memory for the image data.

                     tga->data = (unsigned char*) malloc(sizeof(unsigned char) * total);

					 assert(tga->data);

                        // Seek to the image data.

                        fseek(fh, 18, SEEK_SET);

						fread(tga->data, sizeof(unsigned char), total, fh);

 

                        // We're done reading.

                        fclose(fh);



						
                       // Mode 3 = RGB, Mode 4 = RGBA

                       // TGA stores RGB(A) as BGR(A) 

                       // so we need to swap R and B

                        if (colormode >= 3)
                        {

                                unsigned char temp;


                                for (int i = 0; i < total; i= i + colormode)
                                {

                                        temp = tga->data[i];

                                        tga->data[i] = tga->data[i + 2];

                                        tga->data[i + 2] = temp;

                                }

                        }
                

				DBG(printf("Loaded texture is -> (%s)\nWidth: %d\nHeight: %d\nDepth: %d\n", filename, tga->w, tga->h, tga->depth);)

		   }  
	
	
	 return tga;
	}




	void Texture::insertIntoGraphicsContext(RenderDevice  *device)
	{


		GLenum ClMode;

		
		if (tga)
		{

			//Generate texture object
			glGenTextures(1, &texId);
			assert(texId);


			//Initially creates the object as a 2D texture
			glBindTexture(GL_TEXTURE_2D, texId);


			//Loads the specified image as a 2D texture into the graphics card memory
			if (colormode == 3) { ClMode = GL_RGB;}

			if (colormode == 4) { ClMode = GL_RGBA;}

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tga->w, tga->h, 0, ClMode, GL_UNSIGNED_BYTE, tga->data);



			//Unbind the texture object
			glBindTexture(GL_TEXTURE_2D, 0);

			free(tga);
		
		
		}
	
	
	
	}


}