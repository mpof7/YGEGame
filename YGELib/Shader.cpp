//Shader.cpp


#include "Shader.h"
#include "Debug.h"


namespace YGEGraphics
{

	// Compile time parameters for unified shader source
	static const char  *vertShaderConditional = "#define COMPILE_VS";
	static const char  *fragShaderConditional = "#define COMPILE_FS";

	// Forward declarations of utility functions
	static void shader_show_info_log(GLhandleARB object);
	static void check_shader_compiled_okay(GLhandleARB object);
	static void check_programme_linked_okay(GLhandleARB object);







	Shader::Shader(const char *fn)
	{
	
		fileName = fn;
		object = 0L;
		source = loadShaderFile(fileName);
	
	}



	const char  *Shader::loadShaderFile(const char *fileName)
	{
	
		// Open the shader file
		FILE *fileHandle = fopen(fileName, "r");
		assert(fileHandle);

		// Find the shader file's length
		fseek(fileHandle, 0, SEEK_END);
		long length = ftell(fileHandle);
		fseek(fileHandle, 0, SEEK_SET);

		// Allocate some memory for the shader source
		char *source = (char *)malloc(length);
		assert(source);

		// Read the shader source from the file and close file
		fread(source, sizeof(char), length, fileHandle);
		fclose(fileHandle);




	  return source;
	}



	bool Shader::compileShader(const char *source)
	{

		vertShaderHandle = glCreateShader(GL_VERTEX_SHADER);
		fragShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
		assert(vertShaderHandle && fragShaderHandle);
		
		// Unified shader. The same source for vertex and fragment shaders (parameter 1)
		char const *compileParamString[2];
		compileParamString[1] = source;
		
		// Conditional compilation for the vertex shader
		compileParamString[0] = vertShaderConditional;
		glShaderSource(vertShaderHandle, 2, compileParamString, NULL);
	
		// Conditional compilation for the fragment shader
		compileParamString[0] = fragShaderConditional;
		glShaderSource(fragShaderHandle, 2, compileParamString, NULL);
		
		// Compile both shaders
		glCompileShader(vertShaderHandle);
		glCompileShader(fragShaderHandle);
		
		// Check the results of compilation
		check_shader_compiled_okay(vertShaderHandle);
		check_shader_compiled_okay(fragShaderHandle);
		
		// Create the programme and attach the shaders
		programmeHandle = glCreateProgram();
		assert(programmeHandle);
		glAttachShader(programmeHandle, vertShaderHandle);
		glAttachShader(programmeHandle, fragShaderHandle);
		
		// Link the programme
		glLinkProgram(programmeHandle);
		
		// Check the results of linking
		check_programme_linked_okay(programmeHandle);

		free((void *)source);

	
	 return true;
	}



	void Shader::insertIntoGraphicsContext(RenderDevice *device)
	{
	
		compileShader(source);
	
	}








	static void shader_show_info_log(GLhandleARB object) 
	{

		GLint			length;
		
		glGetShaderiv(object, GL_INFO_LOG_LENGTH, &length);
		

		if (length > 0) 
		{
			
			GLcharARB *log;
			
			log = (GLcharARB *)malloc(length+1);
			
			log[0] = 0;
			glGetShaderInfoLog(object, length, NULL, log);
			log[length] = 0;
			DBG(printf("%s", log);)
		}


	}


	static void check_shader_compiled_okay(GLhandleARB object) 
	{

		GLint			status;
		
		glGetShaderiv(object, GL_COMPILE_STATUS, &status);
		

		if (!status) 
		{

			DBG(printf("Shader compile error\n");)
			shader_show_info_log(object);
		}


	}


	static void check_programme_linked_okay(GLhandleARB object) 
	{

		GLint			status;
		
		glGetProgramiv(object, GL_LINK_STATUS, &status);
		

		if (!status) 
		{

			DBG(printf("Shader link error\n");)
			shader_show_info_log(object);
		}


	}



}