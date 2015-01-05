varying vec2 vTexCoord;
void main()
{
	
	
	
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	//gl_TexCoord[0] = gl_MultiTexCoord0;
	
	
	vTexCoord = gl_MultiTexCoord0;
	
	 vec2 Pos;
	  //Pos = sign(gl_Vertex.xy);
 
	 //gl_Position = vec4(Pos, 0.0, 1.0);
   // Image-space
///	    Pos = sign(gl_Vertex.xy);
 
  // gl_Position = vec4(Pos, 0.0, 1.0);
   // Image-space
   vTexCoord = gl_MultiTexCoord0;
	
}