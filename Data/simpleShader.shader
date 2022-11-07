//simpleShader.shader







//Vertex shader

#ifdef COMPILE_VS


void main()
{	

	// the following three lines provide the same result

//	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
//	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	gl_Position = ftransform();
}

#endif


//Fragment shader

#ifdef COMPILE_FS

void main()
{
	gl_FragColor = vec4(0.4,0.4,0.8,1.0);
}

#endif