varying vec2 vTexCoord;
void main()
{
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
//	gl_Position = gl_ModelViewProjectionMatrix;
 gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
//	gl_TexCoord[0] = gl_MultiTexCoord0;
//	vTexCoord = gl_MultiTexCoord0;
	 vec2 Pos;
	  Pos = sign(gl_Vertex.xy); // This rotates screen
	 //gl_Position = vec4(Pos, 0.0, 1.0);
       // Image-space


  	    Pos = sign(gl_TexCoord[0].xy); // This is correct
     
//    gl_Position = vec4(Pos, 0.0, 1.0);
   // Image-space */
   vTexCoord = Pos;
//   vTexCoord = vec2()gl_Position;
	    gl_FrontColor = gl_Color;

} 
